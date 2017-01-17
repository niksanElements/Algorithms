/**
    In this problem i have to find the shortest path between two nodes.
**/

#include <iostream>
#include <queue>

#define MAX_N 10000

using namespace std;

int bfs(int from,int to);

int graph[MAX_N][MAX_N];
int used[MAX_N];
int pred[MAX_N];
int V,E;
int count;

int main()
{
    cin >> V >> E;
    for(int i = 0;i < E;i++){
        int v1,v2;
        cin >> v1 >> v2;
        graph[v1][++graph[v1][0]] = v2;
    }
    int ctf;
    cin >> ctf;
    for(int i = 0;i < ctf;i++){
        int v1,v2;
        cin >> v1 >> v2;
        cout << "{" << v1 << "-" << v2 << "} -> " << bfs(v1,v2) << endl;
    }
    return 0;
}

int counting(int from,int to){
    if(from == to){
        return 0;
    }
    return 1+counting(from,pred[to]);
}

int bfs(int from,int to)
{
    for(int i = 1;i <= V;i++){used[i] = 0;pred[i] = 0;}
    queue<int> q;

    q.push(from);
    used[from] = 1;
    while(!q.empty()){
        int currnetNode = q.front();
        q.pop();
        for(int i = 1;i <= graph[currnetNode][0];i++){
            int temp = graph[currnetNode][i];
            if(!used[temp]){
                q.push(temp);
                used[temp] = 1;
                pred[temp] = currnetNode;
            }
            if(temp == to){
                count = 0;
                return counting(from,to);
            }
        }
    }
    return -1;
}
