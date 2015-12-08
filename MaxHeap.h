//
// Created by miller on 15-12-8.
//

#ifndef HUFFMANTREE_MAXHEAP_H
#define HUFFMANTREE_MAXHEAP_H
template <class T>
class MaxHeap{
private:
    T* heapArray;
    int CurrentPos;
    int maxSize;
public:
    MaxHeap(int max);
    MaxHeap(T*array,int num,int max);
    virtual ~MinHeap(){CurrentPos = -1;maxSize = -1;delete[]heapArray;};
    void buildHeap();
    bool isLeaf(int pos)const;
    int leftChild(int pos)const;
    int rightChild(int pos)const;
    int getParent(int pos)const;
    bool remove(int pos,T&node);
    void siftDown(int left);
    void siftUp(int pos);
    bool insert(const T&newNode);
    bool removeMax(T&targ);
};
template <class T>
MaxHeap<T>::MaxHeap(int max) {
    this->maxSize = max;
    this->CurrentPos = -1;
    this->heapArray = new T[max];
}
template <class T>
MaxHeap<T>::MaxHeap(T *array, int num, int max) {
    this->maxSize = max;
    this->CurrentPos =num - 1;
    heapArray = new T[max];
    for(; num > 0 ; num--){
        heapArray[CurrentPos + 1 - num] = array[CurrentPos + 1 - num];
    }
    buildHeap();
}
template <class T>
int MaxHeap<T>::getParent(int pos) const {
    if(pos == 0)
        return -1;
    else{
        if(pos % 2 == 0)
            return (pos - 2) / 2;
        else
            return (pos - 1) / 2;
    }
}
template <class T>
int MaxHeap<T>::leftChild(int pos) const {
    int lcPos = pos * 2 + 1;
    if(lcPos > CurrentPos)
        return -1;
    else
        return lcPos;
}
template <class T>
int MaxHeap<T>::rightChild(int pos) const {
    int rcPos = pos * 2 + 2;
    if(rcPos > CurrentPos)
        return -1;
    else
        return rcPos;
}
template <class T>
bool MaxHeap<T>::isLeaf(int pos) const {
    if(pos > CurrentPos)
        return false;
    else if((pos * 2 + 2) <= CurrentPos)
        return false;
    else
        return true;
}

template <class T>
void MaxHeap<T>::siftDown(int left) {
    int i = left;
    int j = 2 * i + 1;
    if(j > CurrentPos)
        return ;
    T temp= heapArray[i];
    while(j <= CurrentPos){
        if((j < CurrentPos)&&(heapArray[j] < heapArray[j + 1]))
            j++;
        if(temp < heapArray[j]){
            heapArray[i] = heapArray[j];
            i = j;
            j = j * 2 + 1;
        }
        else
            break;
    }
    heapArray[i] = temp;
}
template <class T>
void MaxHeap<T>::siftUp(int pos) {
    int i = pos;
    int j = (i - 1) / 2;
    if(j < 0)
        return ;
    T temp = heapArray[i];
    while(j >= 0 && i != 0){
        if(temp > heapArray[j]){
            heapArray[i] = heapArray[j];
            i = j;
            j = (i - 1) / 2;
        }
        else
            break;
    }
    heapArray[i] = temp;
}
template <class T>
bool MaxHeap<T>::insert(const T &newNode) {
    if(CurrentPos >= maxSize - 1)
        return false;
    heapArray[++CurrentPos] = newNode;
    siftUp(CurrentPos);
}
template <class T>
void MaxHeap<T>::buildHeap(){
    for(int i = (CurrentPos - 1) / 2;i >= 0;i--)
        siftDown(i);
}
template <class T>
bool MaxHeap<T>::remove(int pos, T &node) {
    if(pos > CurrentPos)
        return false;
    node = heapArray[pos];
    heapArray[pos] = heapArray[CurrentPos];
    CurrentPos--;
    siftDown(pos);
    return true;
}
template <class T>
bool MaxHeap<T>::removeMax(T&targ) {
    if(CurrentPos == -1)
        return false;
    targ = heapArray[0];
    heapArray[0] = heapArray[CurrentPos];
    CurrentPos -- ;
    if(CurrentPos > 0)
        siftDown(0);
    return true;
}
#endif //HUFFMANTREE_MAXHEAP_H
