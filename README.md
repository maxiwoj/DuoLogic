# DUOLOGIC
This is the ReadMe file for the second task from the third homework made by Maksymilian Wojczuk.
The instruction below is prepared for Unix platform:

Copilation and usage:
The game uses external library (curses) so if you have the library installed on your computer you can skip the first step
1. Instaliing the library: type "make config" in the directory you git cloned the game to download and install the library on your computer. You will be asked for the password of the root user (installing external libraries requires the administrator's permission)

Compilation: to compile simply type "make"
Run: to compile and run type "make run"
Clean: to clean execuable,backup and object files from the directory type make clean

NOTE: Before every commit to the git remember to clean the directory with command "make clean"

The game instruction: In the game take part 2 players (player of truth and player of false). Each one of them wants to win the game by evaluatin vertical and horizontal sentences to truth (PoTruth) or to false (PoFalse). They can only use 3 operands: and, or and not. Every player can use every one of possible operands, but PoTruth usually will need "or" and PoFalse "and". They both can use the "not" operand but only when not all places for "and" and "or" are filled.

