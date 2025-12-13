#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[100001];
bool visited[100001] {};

int result[100001] {};

void dfs(int vertex) {
    visited[vertex] = true;
    for(int i{ 0 }; i < graph[vertex].size(); i++) {
        int curr_v = graph[vertex][i];
        if(result[curr_v] == 0) {
            result[curr_v] = vertex;
        }
        if(!visited[curr_v]) {
            dfs(curr_v);
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i{ 0 }; i < (n-1); i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1);
    for(int i{ 2 }; i <= n; i++) {
        cout << result[i] << "\n";
    }
    return 0;
}