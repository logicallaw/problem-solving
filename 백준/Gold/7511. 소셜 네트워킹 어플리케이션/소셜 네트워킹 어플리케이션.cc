#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int findLeader(int x) {
	if (parent[x] < 0) {
		return x;
	}
	return findLeader(parent[x]);
}

void uni(int a, int b) {
	int u = findLeader(a);
	int v = findLeader(b);

	if (u == v) {
		return;
	}

	if (parent[u] > parent[v]) {
		swap(u, v);
	}
	if (parent[u] == parent[v]) {
		parent[u]--;
	}
	parent[v] = u;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;

	for (int cnt = 1; cnt <= T; cnt++) {
		cout << "Scenario " << cnt << ":\n";
		int N;
		cin >> N;

		parent = vector<int>(N, -1);

		int K;
		cin >> K;

		for (int i = 0; i < K; i++) {
			int a, b;
			cin >> a >> b;
			uni(a, b);
		}

		int M;
		cin >> M;
		for (int i = 1; i <= M; i++) {
			int u, v;
			cin >> u >> v;
			cout << (findLeader(u) == findLeader(v)) << "\n";
		}
		cout << "\n";
	}

}