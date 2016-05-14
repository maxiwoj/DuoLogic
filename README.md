# DUOLOGIC
This is the ReadMe file for the second task from the third homework made by Maksymilian Wojczuk.
The instruction below is prepared for Unix platform:

Copilation and usage:
The game uses external library (curses), but all the files needed to compilation and run are in ./lib and ./include

COMPILATION: to compile simply type "make" in the project directory.

RUN: to compile and run type "make run". Before running for the best game expirience try to change the window size to the bigger, the best option is when all the instruction (chosen from the game menu) fits the window size.

CLEAN: to clean execuable, backup and object files from the directory type "make clean"

NOTE: Before every commit to the git remember to clean the directory with command "make clean"


On Windows: Install library pdcurses and add compilation and linking flags to the IDE you will use.

The game instruction: In the game take part 2 players (player of truth and player of false). Each one of them wants to win the game by evaluatin vertical and horizontal sentences to truth (PoTruth) or to false (PoFalse). They can only use 3 operands: and, or and not. Every player can use every one of possible operands, but PoTruth usually will need "or" and PoFalse "and". They both can use the "not" operand but only when not all places for "and" and "or" are filled.

DESCRIPTION OF FILES IN THE PROJECT:
In ./additional are files needed to run the game (definitions of the logical operators). 2-unknown 1-truth 0-false
In ./include are headers to the ncurses library
In ./lib are executables of the ncurses library that are nessesary to the compilation
In ./src are all the *.cpp - project files needed to compilation. Names of those files are also their desrciption.
The directory ./obj is created during compilation to keep all the *.o files that are essential in the project. The directory will be deleted as soon as you type "make clean" to erase all executable files.
