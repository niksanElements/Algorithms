#include <iostream>
#define MAX_V 1000
#define MAX_E 1000
using namespace std;

int dfs(int,int);

int graph[MAX_V][MAX_E];
int used[MAX_V];



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
    cout << dfs(1,0) << endl;
    return 0;
}

int dfs(int node,int parent)
{
    used[node] = 1;
    cout << node << " ";
    for(int i = 1;i <= graph[node][0];i++){
        int temp = graph[node][i];
        if(!used[temp]){
            dfs(temp,node);
        }
        else if(temp != parent){
            return 1;
        }
    }
    return 0;
}

