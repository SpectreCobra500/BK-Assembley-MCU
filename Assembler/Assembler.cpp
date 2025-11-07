/*
Engineer: Tyler Burkley
Used Resources: None
Workspace: California Polytechnic University San Luis Obispo

Feel free to take and use the code as you will for your own projects (if for some reason this has inspired you)

Purpose: A personal project, intended to further my understanding of MCU architecture, and how to create an instruction set 
(with inspiration from RISC-V, the architecture I learned in my computer design & asm prog class) myself while also creating an
MCU to go with it. This is a very amateur project, so dont expect professional quality.

DOCUMENTATION:
This my_assembler.cpp file intakes a command line argument, called using:
./my_assembler <your .bk assembly file here> <new binary file name here>
It takes an assembly file given by <insert document of .bk manual here> and assembles it line by line to output a bitstream.

Instruction Class: has 4 char[4] arrays. The single char[8] will hold the instruction name itself, ie beq, blt, add, it is 8
because some instructions will go beyond the 4 byte name limit, and thus to avoid unnecessary padding issues, it becomes 8.
The first is the type, this will tell the assembler how to actually interpret the instruction.
sr1, sr2, and dr stand for source register 1, 2 and destination register, similar to the RISC-V format.

Main:
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <unordered_map>
typedef unsigned char BYTE;

enum InstrType
{
    jump,
    singleReg,
    dualReg
};
class Instruction
{
    BYTE bits[32];
    int type;
};

int main(int argc, char *argv[])
{
    const int numLines = 5;
    FILE* assemblyCodeFile = NULL;
    FILE* assembledFile = NULL;
    FILE* decodingFile = NULL;
    const char *decodingFileName = "decodeFile";
    const char *assembledFileName = "test.bin";
    const char *assemblyCodeFileName = "test.bk";
    Instruction *decodingList = (Instruction*)malloc(numLines);

    // start the decoding dictionary here:
    
    assemblyCodeFile = fopen(assemblyCodeFileName, "r");
    assembledFile = fopen(assembledFileName, "wb");

    if (assemblyCodeFile == NULL) 
    {
        std::cerr << "Wrong file name, or other error:  " << assemblyCodeFileName << std::endl;
        return 1;
    }
    if (assembledFile == NULL) 
    {
        std::cerr << "Wrong file name, or other error:  " << assembledFileName << std::endl;
        return 1;
    }

    char line[256];
    std::vector<Instruction> instructionVector;

    // where the magic happens, process each line of code
    while (fgets(line, sizeof(line), assemblyCodeFile)) 
    {
        // skip if comment
        if(line[0] == '#') continue;
        Instruction currentInstruction;
        std::cout << line;

        char *token = strtok(line, " ");
        while (token != NULL) 
        {
            // removes the commas for processing
            char *comma = strchr(token, ',');
            if (comma) 
            {
                *comma = '\0';
            }
            std::cout << token << std::endl;

            // sets token to null to break the loop
            token = strtok(NULL, " ");
        }
    }
    
    fclose(assemblyCodeFile);
    fclose(assembledFile);
    free(decodingList);
    return 0;
}