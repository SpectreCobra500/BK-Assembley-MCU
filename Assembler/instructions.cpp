#include <unordered_map>
#include <string>

enum InstrType
{
    jump,
    singleReg,
    dualReg
};

std::unordered_map<char*, InstrType> decodeTable = {
    // N single reg
    {"load", singleReg},

    // 7 Jump instruction
    {"j", jump},
    {"jr", jump},
    {"jnz", jump},
    {"jz", jump},
    {"jeq", jump},
    {"jneq", jump},
    {"jlt", jump},
    {"jgt", jump},
};