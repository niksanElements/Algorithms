#include <iostream>

using namespace std;

bool binarySearch(int num,int* arr,int end);
void enterNums(int size,int* arr);

int main()
{
    int sizeA, sizeB;
    cin >> sizeA >> sizeB;
    int* A = new int[sizeA];
    int* B = new int[sizeB];
    enterNums(sizeA,A);
    enterNums(sizeB,B);

    /*
        Homework ex.2
        The complexity on the algorithm is m*n/2
    */

    for(int i = 0;i < sizeA;i++){
        if(binarySearch(A[i],B,sizeB)){
            cout << A[i] << " ";
        }
    }
    cout << endl;
    return 0;
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

void enterNums(int size,int* arr){
    for(int i = 0;i < size;i++){
        cin >> arr[i];
    }
}
