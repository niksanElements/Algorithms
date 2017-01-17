#include <iostream>
#include<vector>
#include <queue>

#define MAX_N 10000

using namespace std;

struct node
{
    int first;
    int second;
    int value;
};

int graph[MAX_N][MAX_N];
int V;

template<typename T> void print_queue(T& q) {
    while(!q.empty()) {
        cout << "(" <<q.top().first  << "-" <<q.top().second << ")" <<" -> " << q.top().value << endl;
        q.pop();
    }
    std::cout << '\n';
}

int main()
{
    auto cmp = [](node left,node right){ return left.value > right.value;};
    priority_queue<node,vector<node>,decltype(cmp)> q(cmp);
    int e;
    cin >> V >> e;
    for(int i = 0;i < e;i++){
        node temp;
        cin >> temp.first >> temp.second >> temp.value;
        q.push(temp);
    }

    while(!q.empty()){
        node currnet = q.top();
        q.pop();
        bool connect =true;
        for(int i = 0;i < V;i++){
            if(graph[currnet.first][i]){
                connect = false;
                break;
            }
        }
        if(connect){
            graph[currnet.first][currnet.second] = currnet.value;
            graph[currnet.second][currnet.first] = currnet.value;
            cout << "(" <<currnet.first  << "-" <<currnet.second << ")" <<" -> " << currnet.value << endl;
        }
        connect = true;
        for(int i = 0;i < V;i++){
            if(graph[currnet.second][i]){
                connect = false;
                break;
            }
        }
        if(connect){
            graph[currnet.first][currnet.second] = currnet.value;
            graph[currnet.second][currnet.first] = currnet.value;
            cout << "(" <<currnet.first  << "-" <<currnet.second << ")" <<" -> " << currnet.value << endl;
        }
    }

    return 0;
}
