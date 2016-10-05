#include <iostream>
#include <vector>
#include <SortedTree.h>


using namespace std;

bool binarySearch(int num,const vector<int> &v);
bool binarySearch(int num,int* arr,int end);
void enterNums(int size,int* arr);
void Complement(int*arr,int size,const vector<int> &v,SortedTree &tree);

int main()
{
    int sizeA, sizeB;
    cin >> sizeA >> sizeB;
    int* A = new int[sizeA];
    int* B = new int[sizeB];
    enterNums(sizeA,A);
    enterNums(sizeB,B);
    vector<int> sectional;
    for(int i = 0;i < sizeA;i++){
        if(binarySearch(A[i],B,sizeB)){
            sectional.push_back(A[i]);
        }
    }
    SortedTree tree;
    Complement(A,sizeA,sectional,tree);
    Complement(B,sizeB,sectional,tree);
    tree.print();
    return 0;
}

void Complement(int*arr,int size,const vector<int> &v,SortedTree &tree){
    for(int i = 0;i < size;i++){
        if(!binarySearch(arr[i],v)){
            tree.insert(arr[i]);
        }
    }
}

bool binarySearch(int num,int* arr,int end){
    int start = 0;
    end--;
    while(start <= end){
        int mid = start + (end - start)/2;
        if(arr[mid] > num){
            end = mid - 1;
        }
        else if(arr[mid] < num){
            start = mid + 1;
        }
        else{
            return true;
        }
    }
    return false;
}

bool binarySearch(int num,const vector<int>& v){
    int start = 0;
    int end = v.size() - 1;
    while(start <= end){
        int mid = start + (end - start)/2;
        if(v[mid] > num){
            end = mid - 1;
        }
        else if(v[mid] < num){
            start = mid + 1;
        }
        else{
            return true;
        }
    }
    return false;
}

void enterNums(int size,int* arr){
    for(int i = 0;i < size;i++){
        cin >> arr[i];
    }
}
