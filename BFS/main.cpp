#include <iostream>
#include <queue>

#define MAX_V 100
#define MAX_E 100

using namespace std;

bool bfs(int,int);
void print(int,int);


int graph[MAX_V][MAX_E + 1];
int pred[MAX_E];

int used[MAX_V];

int n;

int main()
{
    cin >> n;
    int examples;
    cin >> examples;
    for(int i = 1;i <= n;i++){
        used[n] = 0;
        graph[i][0] = 0;
        pred[i] = -1;
    }
    while(examples--){
        int f,s;
        cin >> f >> s;
        graph[f][++graph[f][0]] = s;
        graph[s][++graph[s][0]] = f;
    }
    int first,second;
    cin >> first>>second;
    bool hasPath = bfs(first,second);
    if(hasPath){
        print(first,second);
    }
    return 0;
}

void print(int first,int second)
{
    if(first == second){
        cout << first << " ";
        return;
    }
    print(first,pred[second]);
    cout << second << " ";
}

bool bfs(int start,int end)
{
    queue<int> visite;
    used[start] = 1;
    visite.push(start);
    while(!visite.empty()){
        int currnet = visite.front();
        if(currnet == end){
            return true;
        }
        visite.pop();
        for(int i = 1;i <= graph[currnet][0];i++){
            int temp = graph[currnet][i];
            if(!used[temp]){
                visite.push(temp);
                used[temp] = 1;
                pred[temp] = currnet;
            }
        }
    }
    return false;
}

