//
// Created by miller on 15-12-6.
//

#ifndef HUFFMANTREE_HUFFMANTREE_H
#define HUFFMANTREE_HUFFMANTREE_H
#include "MinHeap.h"
#include <ostream>
#include <queue>
template <class T>
class HuffmanTreeNode{
public:
    HuffmanTreeNode<T>*parent,*leftChild,*rightChild;
    int weight;
    HuffmanTreeNode();
    T element;
    HuffmanTreeNode<T>& operator =(const HuffmanTreeNode<T>src);
    bool operator<(const HuffmanTreeNode<T>rt);
    bool operator>(const HuffmanTreeNode<T>rt);
};
template <class T>
HuffmanTreeNode<T>::HuffmanTreeNode(){
    weight = 0;parent = leftChild = rightChild = 0;
    element = 0;
}
template <class T>
HuffmanTreeNode<T>& HuffmanTreeNode<T>::operator=(const HuffmanTreeNode<T> src) {
    this->weight = src.weight;
    this->leftChild = src.leftChild;
    this->rightChild = src.rightChild;
    this->parent = src.parent;
    this->element = src.element;
    return *this;
}
template <class T>
bool HuffmanTreeNode<T>::operator<(const HuffmanTreeNode<T> rt) {
    return this->weight < rt.weight;
}
template <class T>
bool HuffmanTreeNode<T>::operator>( const HuffmanTreeNode<T> rt) {
    return this->weight > rt.weight;
}

template <class T>
class HuffmanTree{
private:
    HuffmanTreeNode<T> * root;
    void MergeTree(HuffmanTreeNode<T> *ht1, HuffmanTreeNode<T> *ht2, HuffmanTreeNode<T> *parent);
    void DeleteTree(HuffmanTreeNode<T>*root);
public:
    HuffmanTree(HuffmanTreeNode<T> nodeList[], int n);
    HuffmanTree(int weight[], T ele[],int n);
    std::ostream&operator<<(std::ostream&out,HuffmanTree<T>*src);
    virtual ~HuffmanTree(){DeleteTree(root);}
};
template <class T>
HuffmanTree<T>::HuffmanTree(int weight[], T *ele, int n) {
    HuffmanTreeNode<T>*nodeList = new HuffmanTreeNode<T>[n];
    for(int i = 0;i<n;i++){
        nodeList[i].element = ele[i];
        nodeList[i].weight = weight[i];
    }
    HuffmanTree(nodeList,n);
}
template <class T>
HuffmanTree<T>::HuffmanTree(HuffmanTreeNode<T> nodeList[], int n) {
    MinHeap<HuffmanTreeNode<T>>heap(n);
    HuffmanTreeNode<T>*parent,*firChild,*secChild;
    for(int i=0;i<n;i++){
        heap.insert(nodeList[i]);
    }
    for(int i = 0;i < n - 1;i++){
        parent = new HuffmanTreeNode<T>;
        firChild = new HuffmanTreeNode<T>;
        secChild = new HuffmanTreeNode<T>;
        heap.removeMin(*firChild);
        heap.removeMin(*secChild);
        MergeTree(firChild,secChild,parent);
        heap.insert(*parent);
        root = parent;
    }
    delete[] nodeList;
}
template <class T>
void HuffmanTree<T>::MergeTree(HuffmanTreeNode<T> *ht1, HuffmanTreeNode<T> *ht2, HuffmanTreeNode<T> *parent) {
    parent->leftChild = ht1;
    parent->rightChild = ht2;
    parent->weight = ht1->weight + ht2->weight;
}
template  <class T>
void HuffmanTree<T>::DeleteTree(HuffmanTreeNode<T> *root) {
    if(root == 0)
        return ;
    if(root->leftChild != 0)
        DeleteTree(root->leftChild);
    if(root->rightChild != 0)
        DeleteTree(root->rightChild);
    delete root;
}

#endif //HUFFMANTREE_HUFFMANTREE_H
