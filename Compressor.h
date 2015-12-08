//
// Created by miller on 15-12-6.
//
#ifndef HUFFMANTREE_COMPRESSOR_H
#define HUFFMANTREE_COMPRESSOR_H
#include <string>
#include <fstream>
#include <map>
using namespace std;
class Compressor{
private:
    char* fileSymbol;
    unsigned long colorCounter;
    map<char,int> cbtable;
    map<char,string> cltable;
public:
    Compressor(char* path);
};

#endif //HUFFMANTREE_COMPRESSOR_H
