#include <iostream>

#define NOT_CALCULATE (unsigned) (-1)
#define MAXN 30
#define MAXM 100

using namespace std;

char set[MAXM][MAXN];
unsigned int Fn[MAXN];

const unsigned m[MAXN] = {0,30,15,50,10,20,40,5,65}; /* Тегла */
const unsigned c[MAXN] = {0,5,3,9,1,2,7,1,12}; /* Стойности */
const unsigned M = 70; /* Обща вместимост на раницата */
const unsigned N = 8; /* Брой предмети */

void F(int k)
{
    int bestI = 0,fnBest = 0;
    int fnCur;
    for(int i = 1;i <= N;i++){
        if(k>=m[i]){
            if(NOT_CALCULATE == Fn[k-m[i]]){
                F(k-m[i]);
            }
            if(!set[k-m[i]][i]){
                fnCur = c[i] + Fn[k - m[i]];
            }
            else{
                fnCur = 0;
            }
            if(fnCur > fnBest){
                bestI = i;
                fnBest = fnCur;
            }
        }
    }
    Fn[k] = fnBest;
    if (bestI > 0) {
        memcpy(set[k], set[k - m[bestI]], N);
        set[k][bestI] = 1;
    }
}

void Calculate()
{
    for(int i = 0;i <= M;i++){
        Fn[i] = NOT_CALCULATE;
    }
    int sum = 0;
    for(int i = 0;i < N;i++){sum += m[i];}

    if(M > sum){
        cout << "We can take all items!"<< endl;
    }
    else{
        F(M);
    }

    for (int i = 1; i <= N; i++){
        if (set[M][i]){
            cout << i << " ";
        }
    }
    cout << endl;
}

int main()
{
    Calculate();
    return 0;
}
