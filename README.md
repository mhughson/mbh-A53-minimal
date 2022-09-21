# Minial Action 53/Mapper 28 Project
This project is a very minimal project compatible with the annual nesdev competition. It is a stripped down version of the Witch n' Wiz Action 53 project released earlier this year (https://github.com/mhughson/mbh-A53-witchnwiz).

My goal is to provide this as a starting point for other NESDev coding works in C, who want to make a nesdev compeition entry requiring Mapper 28 compatibility.

However, targetting Mapper 0 (NROM) is *by far* the simplest approach if you are new to NES development. The downside is you will be limited in terms of ROM size.

For the NESDev Competition, entries must be compatible with the [Action 53 Mapper (Mapper 28)](https://www.nesdev.org/wiki/Action_53_mapper), which may not be straight forward depending on you technical backround. Witch n' Wiz was targetting Mapper 1 (MMC1) prior to the competition, and the transition was not straight forward for me. My hope is that this project can be a starting point for others wanting to create NES games in C for the compo.

# Credits

* Shiru (neslib, famitone)
* nesdoug (nesdoug library)
* norill (donut integration, and general Mapper 28 support)
* JRoatch (donut compression library)

# Compiling

Currently only Windows is supported. It requires Python to be installed and for the "python" command to work. You can test this by opening command prompt and simply typing "python" without quotes. If this is unrecognized, you need to install Python.

How to build:

1. In VSCode open root folder of project.
2. Press Ctrl + Shift + B to open the "Built Task to Run" prompt.
3. Select "Build All". This will build all aspects of the game (music, sound, art, code).
4. ROM will be found in "game/BUILD/main.nes"

I recommend that you associate ".nes" files with your prefered emulator. This will allow you to use the "Build & Run" commands to automatically open the game after building.

![image](https://user-images.githubusercontent.com/310185/162886996-6b8b58e1-b8ad-4b0f-a57a-3f8460028f7f.png)

# Things of Note

1. The Root directory is almost entirely the compiler for the game (CC65 toolchain). The game itself can be found in the "game" sub-directory.
2. Compiling the project happens in [compile_master.bat](game/compile_master.bat).
3. CHR data is split arcross multiple banks ([chrrom_bank0.chr](game/chrrom_bank0.chr), chrrom_bank1.chr, ...).
4. You can add addtional banks of CHR in [compile_master.bat](game/compile_master.bat).
5. Code is also spread across multiple banks named [game/PRG0.c](PRG0.c), PRG1.c, ...
6. [game/main.c](main.c) is the fixed bank.
7. Building graphics will generate a new CHR file, "0xor1.chr". This is a delta between CHR0 and CHR1 used to compress mostly duplicate CHR. If not needed remove from [compile_master.bat].
8. This project includes music from Witch n' Wiz as a placeholder.
9. This project includes bits and pieces of the map and metatile format from Witch n' Wiz. It can be stripped out as needed. 
