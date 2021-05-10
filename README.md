# Reverse Engineering notes on Maze-maze-mix: Punitapi-chan

## Hardware

- IC1: MCU: GeneralPlus GPL95101UB-002A-QL241
  - High-end LCD toy controller
  - 16-bit u'nSP architecture
  - Built-in sound processing unit and picture processing unit
  - Difference from GPL95101UA: faster (quad) SPI?
  - [Datasheet for GPL95101UA](docs/datasheet/GPL95101UA.pdf)
- IC2: SPI flash: GeneralPlus GPR25L6403F-QS131
  - 3V 64Mbit SPI NOR flash
  - Actually a rebadged MX25L6433FM2I-08
  - [Datasheet](docs/datasheet/GPR25L6403F-Generalplus.pdf)
  - [MXIC Datasheet](<docs/datasheet/MX25L6433F, 3V, 64Mb, v1.6.pdf>)
- IC3: ???
  - Full markings covered by glue
  - Best guess is it's some sort of voltage regulator due to its proximity to
    power input
- LCD controller: Sitronix ST7735 or variant thereof
  - Parallel interface
  - You'll have to find your own datasheet because I'm not sure which variant
    it is

## Additional resources

- Programming manuals
  - [GPL162002A/162003A Programming Guide](docs/other_guides/7164807.pdf) -
    A somewhat similar u'nSP-based chip, but missing information for some
    peripherals
  - [GPL32900A Programming Guide](docs/other_guides/GPL32900AV01_pro.pdf) -
    An ARM-based processor, but has very similar PPU, SPU, and RTC peripherals
- [Registers header file](docs/GPL951_Body.h) - lists memory addresses of
  almost all the peripherals and registers
- Architecture documentation
  - [u'nSP Programmer's Guide](<docs/arch/unSP%20Programmer's Guide.pdf>) -
    architecture documentation, with all the instructions between different
    versions of u'nSP
  - [u'nSP Instruction Set Summary](<docs/arch/unSP Instruction Set Summary.pdf>) -
    an extract of section 6.2.3 from the u'nSP Programmer's Guide, when you need
    a quick reference for decoding machine code
  - [u'nSP Programming Tools User's Manual](<docs/arch/unSP Programming Tools User's Manual.pdf>) -
    compiler documentation; documents calling conventions, and usage of
    assembler if you want to test-assemble some code
  - [GCC for u'nSP source code](https://sourceforge.net/projects/unspgcc/) -
    just here for completeness
- [Ghidra processor for u'nSP](https://github.com/GMMan/sleigh-unsp/tree/discrete-registers) - 
  add this if you want to reverse engineer the ROM inside Ghidra

## Software

Note: `int` is a 16-bit value, `long` is a 32-bit value. `char` is still 8-bit
for the purposes here, although actual strings in firmware tend to use 16-bit
chars.

### ROM layout

SPI flash starts at 0x9000 in address space. Note that the system only uses
word-addressing, so each increment of the address represents an increment of
two bytes. Most if not all addresses and offsets found in data structures will
be based on word-addressing. For this section, we'll use byte addressing
relative to beginning of flash since you're likely looking at a ROM dump.

There's no internal flash inside the MCU, so the SPI flash contains the entirety
of the firmware.

- 0x0 - 0x80: GeneralPlus SPI firmware header
- 0x80 - 0x6e000: Firmware
- 0x6e000 - 0x6f000: Save file 1
- 0x6f000 - 0x70000: Save file 2
- 0x70000 - ...: Resources package
- ...: ROM footer

#### GeneralPlus SPI firmware header

Per code in the IDE, its format is:
```
//		Word0   Word1   Word2   Word3   Word4   Word5   Word6   Word7     start
	.DW 0x5047, 0x532D, 0x4950, 0x2D46, 0x4548, 0x4441, 0x5245, 0x2D2D	//0x9000
	.DW 0x3130, 0x3332, 0x3534, 0x3736, 0x3938, 0x6261, 0x6463, 0x6665	//0x9008
//	.DW	SumL  , SumH  , SumL  , SumH  , flag  , clk   , timing, mode	//0x9010
//	.DW EndAdr, EndAdr, CLK   , NC	  , NC	  , NC	  , NC	  , NC	  	//0x9018
//	.DW NC	  , NC	  , NC	  , NC	  , NC	  , NC	  , NC	  , NC	  	//0x9020
//	.DW NC	  , NC	  , NC	  , NC	  , NC	  , NC	  , NC	  , NC	  	//0x9028
//	.DW NC	  , NC	  , NC	  , NC	  , NC	  , NC	  , NC	  , NC	  	//0x9030
//	.DW NC	  , NC	  , NC	  , NC	  , NC	  , NC	  , NC	  , NC	  	//0x9038
```
See `Calibration.asm` from the IDE for what the fields mean.

In practice, the last dword is the address of the entry point. Note that in
u'nSP the vector table starts at 0x00fff5 by default, and after the flash is
mapped the vector table from flash occupies the same space.

#### Firmware

This contains the main code and some data of the firmware. Of note, there is an
unknown SPU audio file near the end of it that doesn't seem to be in a format
produced by G+ Audio Batch Converter, so perhaps it's part of the BSP.

#### Save files
Save file starts with a CRC16 of the next 142 bytes, followed by the signature
of `0x5461 0x7069` (which spells `Tapi`, except the bytes of each word are
flipped, so you actually see `aTip`).

Format TBD.

#### Resources package

A package can be identified by the magic number `GARC` at the start of the file.
Packages may be nested inside other packages.

```c
struct garc_entry {
    long length;
    long offset;
};

struct garc_header {
    char magic[4] = "GARC";
    long data_offset;
    int num_entries;
    struct garc_entry entries[num_entries];
};
```

File offset is relative to `data_offset`, which is relative to the beginning of
the package. Remember that offsets and lengths are in number of words.

In the code, locating a particular resource is like navigating folders by index
numbers. A variable number of indexes may be specified to index nested packages.

There is actually some additional data after the last file of the outermost
resource package. It is unclear what this data is used for. It starts out with
incrementing 32-bit values, then decrementing and incrementing 16-bit values.
Best guess is perhaps some additional unused graphics, or maybe something for
the RNG, though blanking out the region doesn't seem to make any immediately
obvious difference.

#### ROM footer

This identifies the end of the ROM and provides version info and a checksum.

```c
struct rom_footer {
    char magic[6] = "TAPIOC";
    char build_type; // 'R' for release, not referenced
    char padding; // not referenced
    byte build_year;
    byte build_month;
    byte build_day;
    char build_revision;
    long checksum;
};
```

The ROM info is shown in the factory test mode, which you can get to by holding
the left and right buttons and pressing reset on the back.

The checksum is a literal sum of all ROM words up to the beginning of the
footer. Remember that each word is 16-bits, so it is a summation of each 16 bits
of the ROM. The ROM checksum is only performed during factory test mode.

### Graphics

There are two types of graphics: TEXTs (tile-based) and sprites. Both use
palettes and characters.

Note for palletes, TEXTs, and sprites, they can be identified by inspecting
the data and comparing expected file size.

#### Palettes

In general, palettes are arrays of 16-bit ARGB1444 colors. As a resource, it
has the following format:

```c
struct palette {
    int num_colors;
    uint colors[num_colors];
};
```

Palette resources may contain more or less colors than the number of colors for
the color mode the TEXT or sprite using it has specified. Often, to facilitate
color fading of sprites, the palette may contain multiple sets of colors.
Offset your palette to use different colors.

Note that the alpha channel is opposite of what it is conventionally. A `1` bit
indicated transparency, and a `0` bit indicates opacity.

#### Characters

Characters are blocks that make up the pixels of an image. Each character list
contains characters of a certain size, usually 8x8, 16x16, or 32x32, although
dimensions can be specified independently. Each pixel in a character is an
index into a palette, usually 2, 4, or 6 bits per pixel.

Character resources do not contain any metadata, and relies on arguments in code
for TEXTs and info in sprites to be interpreted correctly.

To convert color mode to bits per pixel, use this formula:
```
bpp = 2 + color_mode * 2
```

#### TEXTs

TEXTs are generally used for background elements and images that do not require
too much free movement or rotation. A TEXT resource has the following format:

```c
struct text_res {
    int char_width; // width in characters
    int char_height; // height in characters
    int char_nums[char_width * char_height];
};
```

TEXT resources do not contain information such as character resource path,
character width, height, or color mode, so they need to be guesssed or obtained
from code.

`char_nums` are character indexes, where index 0 refers to the first character
in the corresponding resource, except in package path 35, where character
numbers reset to 0 with each TEXT.

#### Sprites

Sprites are the other kind of graphics that can be moved anywhere, zoomed,
and rotated. Each sprite corresponds to one character. It has the following
format:

```c
struct sprite_def {
    long base_charnum;
    int pivot_x;
    int pivot_y;
    uint attributes;
};

struct sprite_res {
    int num_sprites;
    long sprite_def_offsets[num_sprites];
    struct sprite_def defs[];
};
```

For the resource:
- `num_sprite`: a sprite resource is actually a set of sprites, which can have
  multiple variants as necessary.
- `sprite_def_offsets`: word offset relative to this field to the first sprite
  definition of each sprite. To support various different sprite sizes, sprites
  may be split into multiple sub-sprites that the PPU can render, so a sprite
  may have multiple sprite definitions.

For sprite definitions:
- `base_charnum`: the byte offset right shifted by 4 into the characters list
  for the current sprite definition.
- `pivot_x`: relative X position of the sprite
- `pivot_y`: relative Y position of the sprite
- `attributes`: `P_SpriteN_Attribute0` register contents, which includes
  color mode, image flip mode, character horizontal size, and vertical size.
  The most significant bit indicates whether this is the last sprite definition
  for the current sprite.

Note that `base_charnum` is relative to the starting character, not relative
to the start of the resource.

Sprite characters are found in one of three locations:
- Global: package path `0/0`, where all the tapichans, drinks, ingredient
  sprites, and various other sprites for screens that use the above are found.
- Minigame: package path `31/0`, where all the sprites for minigames are
  located.
- Per-screen: usually the last, but sometimes first, resource in the
  corresponding subpackage, used when sprites are not in global or minigame
  characters resource.

Note the same sprite definition may be reused but with different character
bases and palettes. They are usually stored contiguously, both inside the
characters resource and contiguously numbered palette resources.

Also note that changing the sprite size is generally impractical due to heavy
use of shared characters. Sprite base addresses are embedded in code, so unless
you want to tack replaced sprites on to the end of the characters resource, you
will have to find other base address references and update them too.

### Graphics functions in code

The following functions are useful to know about when trying to extract
graphics. Note that pointers use similar notation as in Ghidra to denote
addresses outside the range of 16-bits. Although addresses may appear as
32-bits, keep in mind that the address space in u'nSP is only 22 bits wide.

#### General

`0x03d330`
```c
void *32 garc_traverse(void *32 head, int num_levels, ...);
```
This function returns the pointer to the requested resource. An arbitrary
number of indexes can be specified to retrieve files from sub-packages.

`0x038a3f`
```c
void load_palettes(void *32 garc_head, struct palette_entry *32 entries);
```
This function loads palettes from a package. A palette entry is defined as
the following:
```c
struct palette_entry {
    int index;
    int base;
    int base_bank;
};
```

- `index`: the resource index inside the package to load.
- `base`: word offset within the PPU palette RAM bank.
- `base_bank`: bank to load palette into.

`0x038986`
```c
void ppu_write_palette(void *32 colors, int base, int bank, uint num_entries);
```
This function writes colors into PPU palette RAM.

#### TEXTs

`0x02eb31`
```c
void ppu_text_set_atts(int text, int size, uint width, uint height,
                       uint color_mode, text_res *32 res);
```
This function sets the attributes for a TEXT.
- `text`: TEXT index
- `size`: size of TEXT
- `width`: width of characters
- `height`: height of characters
- `color_mode`: color mode, see calculation in Characters section
- `res`: pointer to TEXT resource file

`0x02ec84`
```c
void ppu_text_set_palette(int text, int seg_h, int palette);
```
This function sets the palette for a TEXT.
- `text`: TEXT index
- `seg_h`: palette RAM bank
- `palette`: offset inside palette RAM bank

Use this function to map back to the palette resource loaded in
`load_palettes()`.

`0x02efb9`
```c
void ppu_text_set_characters(int text, void *32 characters, ...);
```
This function sets the characters list for a TEXT, among other things.
- `text`: TEXT index
- `characters`: pointers to characters
- `...`: other parameters that are not super important and I didn't look into

#### Sprites

`0x03926c`
```c
void ppu_sprites_set_characters(void *32 characters);
```
This function sets the characters to be used in the current screen.

Sprites are more complex, and has its own rendering system. They are kept with
this struct:

```c
struct sprite {
    int index;
    int x;
    int y;
    int order; // descending
    uint attribute0;
    uint attribute1;
    long charnum;
    struct sprite_def *32 sprite_def;
    struct sprite *next_sprite;
};
```

`0x0392ab`
```c
void sprite_add(struct sprite *32 sprite);
```
This function adds a sprite to be rendered the next frame.

Use this function to find usages of `struct sprite`, and to find the
corresponding character base and palette.

Usually you can find this sequence of assembly (disassembled with `unidasm`,
where all literals are in hex):

```
02bb53: 2045            sp -= 05        // allocate 5 words for call args
02bb54: 950a 1000       r2 = 1000
02bb56: 9644            r3 = 04
02bb57: 0908 0001       r4 = sp + 0001
02bb59: d4d4            [r4++] = r2
02bb5a: d6c4            [r4] = r3       // head = 0x41000
02bb5b: 9642            r3 = 02
02bb5c: 0908 0003       r4 = sp + 0003
02bb5e: d6c4            [r4] = r3       // num_levels = 2
02bb5f: 9660            r3 = 20
02bb60: 0908 0004       r4 = sp + 0004
02bb62: d6c4            [r4] = r3       // ind0 = 32
02bb63: 9650            r3 = 10
02bb64: 0908 0005       r4 = sp + 0005
02bb66: d6c4            [r4] = r3       // ind1 = 16
02bb67: f043 d330       call 03d330     // call garc_traverse
02bb69: 0045            sp += 05        // deallocate call args
02bb6a: 9800            r4 = [bp+00]
02bb6b: 9601            r3 = [bp+01]
02bb6c: 0849            r4 += 09
02bb6d: 1640            r3 += 00, carry
02bb6e: f02b            ds = r3
02bb6f: d2f4            ds:[r4++] = r1
02bb70: d4e4            ds:[r4] = r2    // set sprite resource
02bb71: 9309 18fc       r1 = 18fc       // r2:r1 is character base address >> 4
02bb73: 9440            r2 = 00
02bb74: 9800            r4 = [bp+00]
02bb75: 9601            r3 = [bp+01]
02bb76: 0847            r4 += 07
02bb77: 1640            r3 += 00, carry
02bb78: f02b            ds = r3
02bb79: d2f4            ds:[r4++] = r1
02bb7a: d4e4            ds:[r4] = r2
02bb7b: 9600            r3 = [bp+00]
02bb7c: 9801            r4 = [bp+01]
02bb7d: 0645            r3 += 05
02bb7e: 1840            r4 += 00, carry
02bb7f: f02c            ds = r4
02bb80: 98e3            r4 = ds:[r3]
02bb81: b90c ff0f       r4 = r4 & ff0f  // mask palette address
02bb83: a50c 0070       r2 = r4 | 0070  // set palette address
02bb85: 9600            r3 = [bp+00]
02bb86: 9801            r4 = [bp+01]
02bb87: 0645            r3 += 05
02bb88: 1840            r4 += 00, carry
02bb89: f02c            ds = r4
02bb8a: d4e3            ds:[r3] = r2
```

In the sequence, you can identify the sprite resource referenced, the base
address within the character, and the palette used. Use the palette address
to map back to the palette resource.

### Audio

Audio files are index 46 to 107 in the resource package. 46-63 are BGM, while
the rest are sound effects. Audio files are stored in GeneralPlus' "DRM"
format, which has the following structure:

```c
struct drm {
    char magic[16] = "SPF2ALP";
    long sample_rate;
    long audio_length; // word length, immediately follows header
    long unknown1; // used for events, not used here
    long unknown2; // probably also for events, not used here
    ulong id1;
    ulong id2;
};
```

In Punitapi-chan, the codec used is called ADPCM36, where `id1` is `0x007F3CD5`
and `id2` is `0x64407F00`. To convert files to this format, select the "ADPCM
(DRM)" algorithm in G+ Audio Batch Converter.

To convert this format back to WAV, replace the DRM header with length of audio
in bytes, and use this function from `A3600.dll` to perform the conversion:

```c
int a3600_dec(char *inFile, char *outFile, int unknown, void* processor);
```

Use `0` for `unknown` and `NULL` for `processor`. The output will be in WAV
format, but have the incorrect sample rate. You will have to update the sample
rate in the WAV header and recalculate the byte rate.

## Code dive

### Screens and updaters

Core to the game are screens and updaters. Screens serve a particular gameplay
function. Examples include main menu, tapikatsu selection, each tapikatsu stage,
various database menus, and individual minigames. A transition between screens
is characterized by a fade to black. Each screen has a setup function that
sets up the resources used for the current screen, such as TEXTs, sprite
characters, and palettes. It registers an updaters list for the main game
loop to register updaters that get called every frame. The array of
screen setup function pointers is found at `0x03f4ce`, and there are 43 entries.
When the game first boots, it enters screen 41, unless factory test mode is
selected, which is screen 39. There is an unused screen 43 that is likely
used as a quick debug jump to a different screen during development.

An updater definition has the following structure:
```c
typedef void (*game_updater_func)(struct game_updater *32 updater);

struct game_updater_spec {
    int id;
    int init_updater_state; // some sort of parameter for updater function
                            // most significant bit marks end of updater list
    game_updater_func *32 updater_func;
    int additional_alloc;
};
```

A registered updater has this structure:
```c
struct game_updater {
    int id;
    int updater_state;
    game_updater_func *32 updater_func;
    struct game_updater *32 prev_updater;
    struct game_updater *32 next_updater;
    void *32 additional_data;
};
```

Each updater struct is the base size of the updater plus the additional space
specified in the definition. `additional_data` points to the additional space.

`0x03a6ac`
```c
void game_register_updater_list(struct game_updater_spec *32 updater_list);
```
This function registers each updater inside the definition list.

### Main game loop

`0x03c8f1`
```c
void game_main(void);
```

The main game loop first sets up the screen by clearing palette, TEXTs, and
sprites, and removing updaters. It sets previous and next screen IDs, and
runs the setup function for the current screen. Then it loops to update
input, run updaters, handle global input (such as holding the power button
and handling low battery readings), then renders sprites and sends the
frame to the LCD. It also checks BGM looping.

After the screen has indicated it wants to switch screens, the loop will
send the frame to the LCD, then fade out the LCD and audio, free memory,
and save the game before moving on to the next screen.

### Memory pool

The game uses an interesting garbage collected memory pool, where memory only
needs to be allocated generally and not freed. Freeing comes when the screen
changes.

`0x3cfa4`
```c
void *32 game_malloc(size_t size);
```
This function allocates a block of memory in the memory pool and tracks it.

`0x03cfbc`
```c
void game_free(void *32 mem);
```
This function frees a block of memory allocated from the pool. It is generally
not necessary to use this unless the requested memory is transient and large.

`0x03cfe7`
```c
void game_free_all(void);
```
This function frees all blocks of memory allocated from the pool. This works
because the game logic has been designed to not require any additional data
between screens aside from what's stored in the save file and a small
parameters area for passing arguments to the next screen, allocated in the
game context.

## Tapichan sprites

There are several sprites to a tapichan:
- Small sprites in package path `0/0`: each sprite has 4 variants: normal,
  happy, sad, very sad. Happy is used when you press the straw on the standby
  screen, while sad is when the drink level is low, and very sad is when drink
  level is very low. Size for each variant is 64x64.
- Tapichan names in package path `0/1`: tapichan name on first line, the word
  "tapichan" on second line. Palette is shared across all names. Size is 72x24.
- Large sprites in package path `0/2`: Size is 96x72.

For small sprites, palette index is tapichan index plus 1. For large sprites,
palette index is same as tapichan. Index 0 is used for tapichans in tapikatsu,
so for small sprites its palette has multiple sets of colors, but for large
sprites, it would lead to an resource that is not a palette, so the sprite is
invalid, which is OK because it's never used. However if you did try to
extract it, you'll find it's a copy of the pig tapichan.

Note that tapichans in the package are not in the same order as in the database.

## Unlockable tapichans

There are four tapichans that can be unlocked if you press select and enter on
the tapikatsu screen before you've stirred the drink a lot. See [this tweet
thread](https://twitter.com/GMMan_BZFlag/status/1378446765532311557).

They were used in a special promotion with Toys "R" Us in Japan where you could
get a code sheet if you bought a Punitapi-chan on specific dates. See
[here](https://twitter.com/GMMan_BZFlag/status/1378446765532311557) for
the announcement.

## Factory test mode

Factory test mode lets you check whether the hardware is functioning correctly.
See [this tweet thread](https://twitter.com/GMMan_BZFlag/status/1378114944181305349).

## Questions to explore

- How are tapichans picked? There are special tapichans that are obtained on
  specific dates. Where are those dates stored, and what is the window for
  them? When there's no special tapichan, what determines the tapichan picked?
  How much of a role does selecting drink base, ice, and sugar play in the
  tapichan picked? Does the amount of time between tapikatsu affect the
  tapichan given?
- Standby screen: how quickly does the drink level go down?
- Extra secret tapichans: there are two tapichans that don't show up anywhere
  in the game but the sprites are present: Waon dog and witch. Are these
  actually unreferenced, or is there a way to obtain them?
- Sweeping minigame: how does the game determine whether you find 500p?
- Ingredients inventory: Bandai Mania video showed an inventory of 99
  of each ingredient. Was that a special debug build, or is there a way to
  trigger this on the production game too?
- Mysterious data after resources package: what is this exactly? Is it
  referenced anywhere? Is it graphics, or just padding?
