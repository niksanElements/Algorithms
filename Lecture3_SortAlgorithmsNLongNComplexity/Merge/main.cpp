#include <iostream>

using namespace std;
int* merge(int* arr_1,int* arr_2,int size_1,int size_2);

int main()
{
    int arr_1[] = {1,3,5,6,9,36,236,347};
    int arr_2[] = {2,4,8,10,12,34,54,6545,234453};
    int* arr = merge(arr_1,arr_2,8,9);
    for(int i = 0;i < 17;i++){
        cout << arr[i] << " ";
    }
    return 0;
}

int* merge(int* arr_1,int* arr_2,int size_1,int size_2)
{
    int* arr = new int[size_1+size_2];
    int i = 0,j = 0,k = 0;
    while(i < size_1 && j < size_2){
        if(arr_1[i] <= arr_2[j]){
            arr[k] = arr_1[i];
            i++;
        }
        else{
            arr[k] = arr_2[j];
            j++;
        }
        k++;
    }
    while(i < size_1){
        arr[k]=arr_1[i];
        i++;k++;
    }
    while(j < size_2){
        arr[k] = arr_2[j];
        j++;k++;
    }
    return arr;
}
