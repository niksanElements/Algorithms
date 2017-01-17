#include <iostream>
#include <map>

#define MAX_N 10000

using namespace std;

void dfsAll();

int graph[MAX_N][MAX_N];
int used[MAX_N][MAX_N];
map<char,int> result;
int N,M;

int main()
{
    cin >> N >> M;

    for(int i = 0;i < N;i++){
        for(int j = 0;j < M;j++){
            char ch;
            cin >> ch;
            graph[i][j] = ch;
        }
    }
    dfsAll();
    map<char,int>::iterator it;
    for(it = result.begin();it != result.end();it++){
        cout << it->first << " -> " << it->second << endl;
    }
    cout << endl;
    return 0;
}
void dfs(int i,int j,char ch)
{
    used[i][j] = 1;
    if(j-1 >= 0 && !used[i][j-1] && graph[i][j-1] == ch){
        dfs(i,j-1,ch);
    }
    if (j+1 < M && !used[i][j+1] && graph[i][j+1] == ch){
        dfs(i,j+1,ch);
    }
    if(i-1 >= 0 && !used[i-1][j] && graph[i-1][j] == ch){
        dfs(i-1,j,ch);
    }
    if(i+1 < N && !used[i+1][j] && graph[i+1][j] == ch){
        dfs(i+1,j,ch);
    }
}

void dfsAll()
{
    for(int i = 0;i < N;i++){
        for(int j = 0;j < M;j++){
            if(!used[i][j]){
                char latter = graph[i][j];
                dfs(i,j,latter);
                result[latter] += 1;
            }
        }
    }
}

