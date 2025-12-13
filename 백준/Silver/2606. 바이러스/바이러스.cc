#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[100];
bool visited[100] {};

int result = 0;

void dfs(int vertex) {
    visited[vertex] = true;
    for(int i{ 0 }; i < graph[vertex].size(); i++) {
        int curr_v = graph[vertex][i];
        if(!visited[curr_v]) {
            result++;
            dfs(curr_v);
        }
    }
}

int main(void) {
    int n;
    cin >> n;
    int m;
    cin >> m;

    for(int i{ 0 }; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1);
    cout << result;
    return 0;
}