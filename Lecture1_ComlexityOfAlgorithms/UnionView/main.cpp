#include <iostream>
#include <SortedTree.h>

using namespace std;
void enterNums(int size,int* arr);
bool binarySearch(int num,int* arr,int end);

int main()
{
    int sizeA, sizeB;
    cin >> sizeA >> sizeB;
    int* A = new int[sizeA];
    int* B = new int[sizeB];
    enterNums(sizeA,A);
    enterNums(sizeB,B);
    SortedTree tree;
    for(int i = 0;i < sizeA;i++){
        tree.insert(A[i]);
    }
    for(int i = 0;i < sizeB;i++){
        tree.insert(B[i]);
    }
    tree.print();
    return 0;
}

void enterNums(int size,int* arr){
    for(int i = 0;i < size;i++){
        cin >> arr[i];
    }
}
