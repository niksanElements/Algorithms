#include <iostream>

using namespace std;
void insertSort(int* arr,int size);

int main()
{
    int n;
    cin >> n;
    int* arr = new int[n];
    for(int i = 0;i < n;i++) cin >> arr[i];
    insertSort(arr,n);
    for(int i = 0;i < n;i++) cout << arr[i] << " ";
    delete []arr;
    return 0;
}

void insertSort(int *arr,int size)
{
    for(int i = 1;i < size - 1;i++){
        int j = i;
        while(j > 0 && arr[j] < arr[j-1]){
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
    }
}
