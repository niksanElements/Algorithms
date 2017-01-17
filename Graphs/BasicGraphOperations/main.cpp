#include <iostream>
#include <queue>
#include <stack>

#define MAXN 100

using namespace std;

void enterAdjacencyList();
void BFS(int start);
void DFS(int start);
    void DFS_R(int start);
    void DFS_I(int start);

int graph[MAXN][MAXN];
int visited[MAXN];
int numberV;int numberE;


int main()
{
    enterAdjacencyList();
    DFS(1);
    return 0;
}

void enterAdjacencyList()
{
    cin >> numberV >> numberE;
    for(int i = 1;i <= numberV;i++){ graph[i][0] = 0; }
    for(int i = 0;i < numberE;i++)
    {
        int a,b;
        cin >> a >> b;
        graph[a][++graph[a][0]] = b;
        graph[b][++graph[b][0]] = a;
    }
}

void DFS(int start)
{
    for(int i = 0;i <= numberV;i++){ visited[i] = 0; }
    DFS_R(start);
    cout << endl;
    for(int i = 0;i <= numberV;i++){ visited[i] = 0; }
    DFS_I(start);
}

void DFS_R(int start)
{
    visited[start] = 1;
    cout << start << " ";
    for(int i = 1;i <= graph[start][0];i++)
    {
        int temp = graph[start][i];
        if(0 == visited[temp])
        {
            DFS_R(temp);
        }
    }
}

void DFS_I(int start)
{
    stack<int> visite;
    visite.push(start);
    cout << start << " ";
    visited[start] = 1;
    while(!visite.empty())
    {
        int currentElement = visite.top();
        if(graph[currentElement][0] > 0)
        {
            int element = graph[currentElement][graph[currentElement][0]--];
            if(visited[element] == 0)
            {
                cout << element << " ";
                visited[element] = 1;
                visite.push(element);
            }
        }
        else
        {
            visite.pop();
        }
    }
}

void BFS(int start)
{
    queue<int> visite;
    int* used = new int[numberV + 1];
    visite.push(start);
    cout << start << endl;
    for(int i = 1;i <= numberV;i++){ used[i] = 0; }
    used[start] = 1;
    while(!visite.empty())
    {
        int currentNode = visite.front();
        visite.pop();
        for(int i = 1;i <= graph[currentNode][0];i++)
        {
            int temp = graph[currentNode][i];

            if(0 == used[temp])
            {
                visite.push(temp);
                cout << temp << " ";
                used[temp] = 1;
            }

        }
        cout << endl;
    }
}
