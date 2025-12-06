#include <iostream>
#include <vector>

using namespace std;

int p[1000001];

int findLeader(int x) {
    if (p[x] < 0) {
        return x;
    }
    return findLeader(p[x]);
}

void uni(int a, int b) {
    int u = findLeader(a);
    int v = findLeader(b);

    if (u == v) {
        return;
    }

    if (p[u] > p[v]) {
        swap(u, v);
    }
    if (p[u] == p[v]) {
        p[u]--;
    }

    p[v] = u;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i <=n; i++) {
        p[i] = -1;
    }

    while (m--) {
        int c, a, b;
        cin >> c >> a >> b;

        if (c == 0) {
            uni(a, b);
        } else if (c == 1) {
            int u = findLeader(a);
            int v = findLeader(b);
            cout << ((u==v) ? "YES" : "NO") << "\n";
        }
    }
}