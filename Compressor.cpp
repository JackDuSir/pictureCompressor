//
// Created by miller on 15-12-7.
//

#include <iostream>
#include "Compressor.h"
#include "HuffmanTree.h"
using namespace std;
Compressor::Compressor(char* path) {
    fileSymbol = "SCNH";
    ifstream file(path,ios::ate);
    cout<<"正在加载中..\n";
    char buffer;
    map<char,int>::iterator it;
    if(file.good()){
        while(!file.eof()){
            file>>buffer;
            if( (it =cbtable.find(buffer))!=cbtable.end())
                (it->second)++;
            else
                cbtable.insert(pair<char,int>(buffer,1));
        }
    }
    it->second--;
    file.close();
    colorCounter = cbtable.size();
    HuffmanTreeNode<char>*nodeList = HuffmanTree<char>::getNodelist(&cbtable);
    HuffmanTree<char>tree(nodeList,colorCounter);
    cltable = *tree.getMap();
}