#include <iostream>

using namespace std;
void matricsSort(int** matrics,int size);

int main()
{
    int n = 0; cin >> n;
    int** matrics = new int*[n];
     for(int i = 0;i < n;i++){
            matrics[i] = new int[n];
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cin >> matrics[i][j];
        }
    }
    matricsSort(matrics,n);
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cout << matrics[i][j] << " ";
        }
        cout << endl;
    }

    for(int i = 0;i < n;i++){
            delete []matrics[i];
    }
    delete []matrics;
    return 0;
}
void swapMy(int* row1,int* row2,int size)
{
    int* temp = new int[size];
    for(int i = 0;i < size;i++){
        temp[i] = row1[i];
    }
    for(int i = 0;i < size;i++){
        row1[i] = row2[i];
    }
    for(int i = 0;i < size;i++){
        row2[i] = temp[i];
    }
}

void matricsSort(int** matrics,int size)
{
    for(int i = size-2;i >= 0;i--){
        for(int j = 0;j <= i;j++){
            bool isForSwap = false;
            for(int k = 0;k < size && !isForSwap;k++){
                if(matrics[j][k] > matrics[j+1][k]){
                    isForSwap = true;
                }
                else if(matrics[j][k] < matrics[j+1][k]){
                    break;
                }
            }
            if(isForSwap){
                swapMy(matrics[j],matrics[j+1],size);
            }
        }
    }
}


