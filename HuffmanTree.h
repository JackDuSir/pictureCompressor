//
// Created by miller on 15-12-6.
//

#ifndef HUFFMANTREE_HUFFMANTREE_H
#define HUFFMANTREE_HUFFMANTREE_H
#include "MinHeap.h"
template <class T>
class HuffmanTreeNode{

};
template <class T>
class HuffmanTree{
private:
    HuffmanTree<T> * root;
    void MergeTree(HuffmanTree<T> &ht1,HuffmanTree<T> &ht2,HuffmanTree<T>*parent);
    void DeleteTree(HuffmanTree<T>*root);
public:
    HuffmanTree(T weight[],int n);
    virtual ~HuffmanTree(){DeleteTree(root);}
};
template <class T>
HuffmanTree<T>::HuffmanTree(T *weight, int n) {
    MinHeap<HuffmanTree>
}
template <class T>
void HuffmanTree<T>::MergeTree(HuffmanTree &ht1, HuffmanTree &ht2, HuffmanTree *parent) {

}
#endif //HUFFMANTREE_HUFFMANTREE_H
