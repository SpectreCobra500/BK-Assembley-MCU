#include <unordered_map>
#include <string>

enum InstrType
{
    jump,
    singleReg,
    dualReg,
    tripReg
};

std::unordered_map<char*, InstrType> decodeTable = {
    // N single reg
    {"load", singleReg},
    {"jr", singleReg},

    // N dual reg
    {"iadd", dualReg},
    {"isub", dualReg},
    {"isrl", dualReg},
    {"isll", dualReg},
    {},

    // N trip reg

    // 7 Jump instruction
    {"j", jump},
    {"jnz", jump},
    {"jz", jump},
    {"jeq", jump},
    {"jneq", jump},
    {"jlt", jump},
    {"jgt", jump},
};