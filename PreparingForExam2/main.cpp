#include <iostream>
#define MAX_N 6

using namespace std;

int countPaths(int,int,int);


int graph[MAX_N][MAX_N];
int paths[MAX_N][MAX_N];

int V,E;

int main()
{
    cin >> V >> E;
    for(int i = 0;i < E;i++){
        int vi,vj;
        cin >> vi >> vj;
        graph[vi][vj] += 1;
    }
    cout << countPaths(1,5,2) << endl;;
    return 0;
}
