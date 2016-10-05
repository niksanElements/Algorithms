#include <iostream>
#include <vector>

using namespace std;

bool binarySearch(int num,const vector<int> &v);
bool binarySearch(int num,int* arr,int end);
void enterNums(int size,int* arr);
void Complement(int*arr,int size,const vector<int> &v);

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
    bool changeMod = 0;
    cout << "Enter 1 for A - B or 0 for B - A: ";
    cin >> changeMod;
    if(changeMod){
        Complement(A,sizeA,sectional);
    }
    else{
        Complement(B,sizeB,sectional);
    }
    return 0;
}

void Complement(int*arr,int size,const vector<int> &v){
    for(int i = 0;i < size;i++){
        if(!binarySearch(arr[i],v)){
            cout << arr[i] << " ";
        }
    }
    cout << endl;
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

