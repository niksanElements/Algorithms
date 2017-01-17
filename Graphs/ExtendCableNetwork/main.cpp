#include <iostream>
#include <queue>
#include <algorithm>

#define MAX_N 1000

using namespace std;

struct Node
{
    int firstNode;
    int secondNode;
    int coast;
};

int graph[MAX_N][MAX_N];
Node forConnect[MAX_N];
int N;
int lengthForConnect;


int main()
{
    int edges;
    cin >> N >> edges;
    for(int i = 0;i < edges;i++){
       int vi,vj;
       int coast;
       bool isConnected;
       cin >> vi >> vj >> coast >> isConnected;
       if(isConnected){
            graph[vi][vj] = coast;
            graph[vj][vi] = coast;
       } else {
           forConnect[lengthForConnect].firstNode = vi;
           forConnect[lengthForConnect].secondNode = vj;
           forConnect[lengthForConnect].coast = coast;
           lengthForConnect++;
       }
    }
    for(int i = 0;i < lengthForConnect;i++){
        cout << forConnect[i].coast << " ";
     }
     cout << endl;
    sort(forConnect,forConnect+lengthForConnect,[](Node a,Node b)->bool{
            return a.coast < b.coast;
     });
     for(int i = 0;i < lengthForConnect;i++){
        cout << "{" << forConnect[i].firstNode << " - " << forConnect[i].secondNode << "}" << " -> ";
        cout << forConnect[i].coast << " " << endl;
     }
    return 0;
}

void connect(int budget)
{

}
