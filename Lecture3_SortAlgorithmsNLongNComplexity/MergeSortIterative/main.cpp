#include <iostream>
#include <math.h>

using namespace std;

void mergeSort(int);

int* arr;

int main()
{
    int n;cin >>n;
    arr = new int[n];
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    mergeSort(n);
    for(int i = 0;i < n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}

void merge(int start,int middle,int end)
{
    int left_size = middle - start + 1;
    int right_size = end - middle;
    int* left = new int[left_size];//temp array
    int* right = new int[right_size];//temp array
    for(int i = 0;i < left_size;i++){
        left[i] = arr[i + start];
    }
    for(int i = 0;i < right_size;i++){
        right[i] = arr[i + middle + 1];
    }
    int k = start,i = 0,j = 0;
    while(i < left_size && j < right_size){
        if(left[i] <= right[j]){
            arr[k] = left[i];
            i++;
        }
        else{
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while(i < left_size){
        arr[k] = left[i];
        i++;k++;
    }
    while(j < right_size){
        arr[k] = right[j];
        j++;k++;
    }
    delete []left;
    delete []right;
}

void mergeSort(int n)
{
    for(int current_size = 1;current_size <= n-1;current_size *= 2){
        for(int left = 0;left <= n - 1;left += 2*current_size){
            int middle = left + current_size - 1;
            //cout << middle << endl;
            int end = min(left+2*current_size - 1,n-1);

            merge(left,middle,end);
        }
    }
}
