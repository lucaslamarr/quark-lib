# Quark Lib - A small ANSI C (89) library with no external dependencies

I started working on Quark Lib with the intention of creating a micro sized library that would run just about anywhere, and without the need for any dependencies. 

Initially, there were zero additional include files that were not written by me, however, a handful of C Standard Library files are now included to
help support custom data structures, algorithms, and smart memory management features that are planned for the future. The only additional included files
are those that are required to communicate directly with the target platform. This allows for the addition of things like window creation and a small graphics library that will have native code written for Windows, MacOS, and Linux without the use of some third party cross platform library.

Written to standard for ANSI C (89) and was tested using GNU GCC with extensions disabled.

-----------------------------------------------------------------------------------------------------------------------------------------------------------
 
  quark.h - Includes all of the modules / files in the library.

  quarkcore.h - General use features, such as min and max values of data types, custom bool implementation, Vector 2 and 3, and more.

  quarkmath.h - A variety of common math functions such as square root, absolute value, rounding, and more.

  quarkgraphics.h - Cross platform (Windows, Linux, MacOS) and simplified window creation and rendering.

  quarkds.h (COMING SOON) - A handful of useful data structures such as a stack, queue, linked list, and more.

  quarkalgo.h (COMING SOON) - Common algorithms for sorting and searching.

-----------------------------------------------------------------------------------------------------------------------------------------------------------

This is not meant to be a replacement library for anything in the C standard library, however, I have recreated some of the functions that I utilize the most in my own vision, as well as a few brand new features. This library is not meant to be any faster or more efficient than what you might find in any of the official C library files. It is just a way for me to consolidate a lot of my favorite functions in a central place where I can design them in a way that makes sense to me. Additionally, I wanted to create my own implementations for things like window creation or 2D graphics that will run natively on different platforms without using third party libraries.

This repository contains the project file that I used for the library's development and does not require anything to start using it. Just take these header and C source files and put them somewhere inside of your own project directory that will allow you to #include them. The main.c file is just for testing and running the demo program that shows each function running and displaying their results. It is not part of the actual Quark library files and should not be added to your own project.

This code will compile inside of Visual Studio using their own C and C++ compiler, however, if you want to modify and build the project using the build.bat file that comes with the project you will need to install GNU GCC. Make sure that the project
structure remains the same by leaving the source and misc folder next to each other. If you are going to modify the file structure then you will also need to adjust the search path within the build.bat and run.bat files in order for them to run correctly.
