#include <iostream>

using namespace std;
void bubbleSort(int*,int);

int main()
{
    int n;
    cin >> n;
    int* arr = new int[n];
    for(int i = 0;i < n;i++) cin >> arr[i];
    bubbleSort(arr,n);
    for(int i = 0;i < n;i++) cout << arr[i] << " ";
    delete []arr;
    return 0;
}

void bubbleSort(int* arr,int size)
{
    for(int i = size-2;i >= 0;i--){
        for(int j = 0;j <= i;j++){
            if(arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
