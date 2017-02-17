# Duologic
It is a simple logical game for 2 players based on propositional calculus, using 3-valued logic.

----

## Description
The game instruction: In the game take part 2 players (player of truth and player of false). Each one of them wants to win the game by evaluating vertical and horizontal sentences to truth (PoTruth) or to false (PoFalse). They can only use 3 operands: and, or and not. Every player can use every one of possible operands, but PoTruth usually will need "or" and PoFalse "and". They both can use the "not" operand but only when not all places for "and" and "or" are filled.

----

## Copilation and usage:
The game uses external library (curses), but all the files needed to compilation and run are in ./lib and ./include

### UNIX
#### Compilation
to compile, simply type:
```bash
make
```
in the project directory.

#### Run
to compile and run type:
```bash
make run
```

#### Clean
to clean execuable, backup and object files from the directory type:
```bash 
make clean
```

NOTE: Before every commit to the git remember to clean the directory with command "make clean"

### Windows:
Install library pdcurses and add compilation and linking flags to the IDE you will use.

----

## Description of files placed in the project

./additional contains files needed to run the game (definitions of the logical operators). 2-unknown 1-truth 0-false

./include contains headers to the ncurses library

./lib contains executables of the ncurses library that are nessesary to the compilation

./src contains all the *.cpp - project files needed to compilation. Names of those files are also their desrciption.

The directory ./obj is created during compilation to keep all the *.o files that are essential in the project. The directory will be deleted as soon as you type "make clean" to erase all executable files.
