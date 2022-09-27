# This is a simple READ/WRITE application made in C++ for learning purposes

It can print and create new .txt files on the terminal.

to compile: 
>$g++ -std=c++20 -o (binary_name) App.cpp UnitTests.cpp

The binary needs a directory named "/Files" where it reads/writes from.

# commands
list - lists all .txt files on "/Files"

read (file_name) - prints all the lines on the console

write (file_name) - creates a new .txt file and starts the input stream. To finish the stream type END.
