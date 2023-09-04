# Quark Lib - A small C library with no external dependencies

I started working on Quark Lib with the intention of creating a micro sized library that would run just about anywhere, and without the need for any dependencies. 
Everything is written to the C89 standard and does not utilize any of the C standardized library files. Everything was written using only what comes pre-built into
C89 and was tested using GNU GCC with extensions disabled.

This is not meant to be a replacement library for anything in the C standard library, however, I have recreated some of the functions that I utilize the most in my own vision, as well as a few brand new features. This library is not meant to be any faster or more efficient than what you might find in any of the official C library files. It is just a way for me to consolidate a lot of my favorite functions in a central place where I can design them in a way that makes sense to me.

This repository contains the project file that I used for the library's development and does not require anything to start using it. Just take the quark.c and quark.h files out of the source folder and place them inside of your own project. The main.c file is just for testing and running the demo program that shows each function running and displaying their results. It is not part of the actual Quark library files and should not be added to your own project.

This code will compile inside of Visual Studio using their own C and C++ compiler, however, if you want to modify and build the project using the build.bat file that comes with the project you will need to install GNU GCC. Make sure that the project
structure remains the same by leaving the source and misc folder next to each other. If you are going to modify the file structure then you will also need to adjust the search path within the build.bat and run.bat files.
