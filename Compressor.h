//
// Created by miller on 15-12-6.
//
#include <string>
#include <map>
#ifndef HUFFMANTREE_COMPRESSOR_H
#define HUFFMANTREE_COMPRESSOR_H
using namespace std;
class Compressor{
private:
    int colorCnt;
    int imgWidth;
    int imgHeight;
    string fileSymbol;
    map cbtable;

};
#endif //HUFFMANTREE_COMPRESSOR_H
