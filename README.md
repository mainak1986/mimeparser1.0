# What is this?
This is an MIME format parser.

# Where are things?
'build/' is where code is built.
'parserCore/' is where parser source code is located.
'parserCore/test/' is where parser tests are located.
'third-party/' is where Google test and Google mock is located.
'main.cpp' is where main function is located.

# How to compile?

## Linux
First run cmake. In the project root:

    mkdir build
    cd build
    cmake ..

Compile source code. In build directory:

    make

Run tests. In build directory:

    make test

## Windows / Visual studio
Create directory 'build' in your checkout location '{MimeParser}'. 
Run cmake. 
Set source code directory to '{MimeParser}' and build directory to '{MimeParser}/build'. 
Generate build files.
