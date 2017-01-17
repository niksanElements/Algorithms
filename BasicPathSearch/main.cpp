#include <iostream>
#define MAX_V 1000
#define MAX_E 1000
using namespace std;

void dfsAll(int,int);

int graph[MAX_V][MAX_E];
int used[MAX_V];

int path[MAX_V];
int count;


int main()
{
    int node,edge;
    cin >> node >> edge;
    for(int i = 1;i <= node;i++){
        used[i] = 0;
        graph[i][0] = 0;
    }
    while(edge--){
        int first,second;
        cin >> first >> second;
        graph[first][++graph[first][0]] = second;
        graph[second][++graph[second][0]] = first;
    }
    dfsAll(1,10);
    return 0;
}

void print()
{
    for(int i = 0;i < count;i++){
        cout << path[i] << " ";
    }
    cout << endl;
}

void dfsAll(int start,int end)
{
    if(start == end){
        path[count++] = end;
        print();
        return;
    }
    used[start] = 1;
    path[count++] = start;
    for(int i = 1;i <= graph[start][0];i++){
        int temp = graph[start][i];
        if(!used[temp]){
            dfsAll(temp,end);
        }
    }
    used[start] = 0;count--;
}
