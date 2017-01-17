#include <iostream>

#define MAX_N 1000

using namespace std;

void dfs(int node,int parent);

int graph[MAX_N][MAX_N];
int used[MAX_N];
int nodes[MAX_N];

int N;

int main()
{
    int e;
    int index = 0;
    cin >> N >> e;
    for(int i =0 ;i < e;i++){
        char v1,v2;
        cin >> v1 >> v2;
        int vi = v1 - 'A'+1;
        int vj = v2 - 'A'+1;
        graph[vi][++graph[vi][0]] = vj;
        graph[vj][++graph[vj][0]] = vi;
        nodes[index++] = vi;
    }
    for(int i = 0;i < index;i++){
        if(!used[nodes[i]]){
            dfs(nodes[i],0);
        }
    }
    return 0;
}

void dfs(int node,int parent)
{
    used[node] = 1;
    for(int i = 1;i <= graph[node][0];i++){
        int temp = graph[node][i];
        if(used[temp] && parent != temp){
            cout << (char)(node+65-1) << " - " << (char)(temp   +65-1)<< endl;
            return;
        } else if(!used[temp] && temp != parent){
            dfs(temp,node);
        }
    }
}
