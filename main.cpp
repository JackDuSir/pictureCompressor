#include <iostream>
#include "MinHeap.h"
#include "HuffmanTree.h"
#include <map>
#include "Compressor.h"
using namespace std;

int main() {
    /*
    int a[] = {20,12,35,15,10,80,30,17,2,1};
    MinHeap<int>* heap = new MinHeap<int>(a,10,20);
     */
    /*int a[] = {7,5,2,4};
    char b[] = {'a','b','c','d'};
    HuffmanTreeNode<char>*nodeList = HuffmanTree<char>::getNodelist(a,b,4);
    HuffmanTree<char>* tree = new HuffmanTree<char>(nodeList,4);
    map<char,string>::iterator my_itr;
    map<char,string>*cltable = tree->getMap();
    for(my_itr=cltable->begin();my_itr!=cltable->end();++my_itr){
        cout<<my_itr->first<<"----"<<my_itr->second<<endl;
    }
    getchar();*/
    Compressor com("/home/miller/ClionProjects/HuffmanTree/client.dat");
    return 0;
}