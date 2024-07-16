# Cpp Chess
chess made with C++ and sfml
![Screenshot from 2024-07-16 17-11-06](https://github.com/user-attachments/assets/bc3b9ffb-0020-42cc-aa64-2a214d9df631)

check out https://www.sfml-dev.org/ if you are interested in sfml

some of the assets used are created by WildlifeStudios and are available here:
https://wildlifestudios.itch.io/chess-set-pixel-art

the executable files can be found under the name chess-linux-mac and chess-windows.exe.

the program consists of:
the main.cpp file containing the game loop,
a utilities.h file containing most functions/methods and
the pieceClass.h containing the class i used for the chess pieces.

these files can be found in the src/ folder.

the build/ folder consist of a makefile used for compiling code and other files sfml needs to be able to run on windows.

the assets/ folder contains images for every chesspiece and a font used to display text in the game.

# Compile yourself
if you have any interest in compiling this game yourself there is a makefile in build/ take a look there.
i used linux for compiling so you might need to chnage some commands here and there.

in the makefile itself there are these two variables:

SFML_INC_WIN = "/path/to/sfml"/include
SFML_LIB_WIN = "/path/to/sfml"/lib

these are used for finding the needed sfml files when compiling a windows executable file, you might want to check https://www.sfml-dev.org/download.php out if you are interested in compiling a windows executable yourself


