#include <iostream>
#include <queue>
#include <vector>

#define MAX_N 10000
#define INFINITY 1000000

using namespace std;

void Dikstra(int source);
void print(int from);

struct node
{
    int n;
    int coast;
};

int graph[MAX_N][MAX_N];
int pred[MAX_N];//used or not node
int dist[MAX_N]; // Distance on the nodes
auto comp = [](node left,node right)->bool {return left.coast > right.coast;};
priority_queue<node,vector<node>,decltype(comp)> set(comp);

int V;

int main()
{
    int e;
    cin >> V >> e;
    for(int i = 0;i < e;i++){
        int f,s,coast;
        cin >> f >> s >> coast;
        graph[f][s] = coast;
        graph[s][f] = coast;
    }
    int tr;
    cin >> tr;
    for(int i = 0;i < tr;i++){
        int from,to;
        cin >> from >> to;
        Dikstra(from);
        print(to);
        cout << to << endl;
    }
    return 0;
}
void print(int from)
{
    if(!pred[from]){
        return;
    }
    print(pred[from]);
    cout << pred[from] << " ";
}
void init()
{
    for(int i = 1;i <= V;i++){
        pred[i] = 0;
        dist[i] = INFINITY;
    }
}

void Dikstra(int source)
{
    init();
    dist[source] = 0;
    node temp;temp.n = source;temp.coast = 0;
    set.push(temp);
    while(!set.empty()){
        node next = set.top(); set.pop();
        for(int i = 1;i <= V;i++){
            if(graph[next.n][i]){
                int alt = dist[next.n] + graph[next.n][i];
                if(alt < dist[i]){
                    dist[i] = alt;
                    pred[i] = next.n;
                    node min;min.coast = alt;min.n = i;
                    set.push(min);
                }
            }
        }
    }

}
