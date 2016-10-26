#include <iostream>

using namespace std;

int main()
{
    int n;cin >> n;
    int* arr = new int[n];
    int max = INT_MIN;

    for(int i = 0;i < n;i++){
        cin >> arr[i];
        if(max < arr[i]){
            max = arr[i];
        }
    }
    max++;
    int *b = new int[max];
    for(int i =0 ;i < max;i++){
        b[i] = 0;
    }
    for(int i = 0;i < max;i++){
        b[arr[i]]++;
    }
    int count = 0;
    for(int i = 0;i < max;i++){
        if(b[i] > 0){
            for(int j = 1;j <= b[i];j++){
                arr[count++] = i;
            }
        }
    }
    for(int i = 0;i < n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}
