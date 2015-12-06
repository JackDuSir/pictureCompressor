//
// Created by miller on 15-12-6.
//

#ifndef HUFFMANTREE_HCODE_H
#define HUFFMANTREE_HCODE_H
#include <string>
using namespace std;
class HCode{
private:
    int codeLen;
    int maxLen;
    string code;
public:
    HCode();
    ~HCode();
    int getCodeLen(){ return codeLen; };
    bool getBitAt(int inidx);
    void addBit(bool bit);
    void Tranverse();
    HCode&operator<<(int cnt);
    int getCharPtr(char ptr);
};

HCode::HCode(){
    codeLen = 0;
    maxLen = 8;


}
#endif //HUFFMANTREE_HCODE_H
