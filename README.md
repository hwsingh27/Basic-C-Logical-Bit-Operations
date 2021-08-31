# PES-Assignment-1
@file main.c
@author Harshwardhan Singh
@date August 30th 2021

There are five functions created and programmed accordingly. There are test case functions that are used to test several test cases.
There are two additional functions: length_str() and reverse() for finding the length of an array and reversing an array respectively, these functions are used in other main functions.

Visual Studio Code for C-language is used to accomplish this task. Main function files, main() and test function files are in the main.c C-program file.
The test functions return '1' when all the testcases have passed else they return '0'' if any one of the test cases fails. 
Hence, the main() calls the test functions then test functions call the main function where the program is written.

I have considered 'size_t size' as (size > nbits+3) as it should always be greater than or equal to (nbits+3).
nbits + 2 (for trailing 'b' and '0') + 1 (for '\0' NULL character at the end of an array). Hence, put (nbits+3).
Used sizeof() to store the size of a declared buffer in every test function.
Test cases have checked for 'size' if it fails then the function returns '-1' otherwise it executes the complete program.

