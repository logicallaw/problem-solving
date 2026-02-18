#include <iostream>
#include <vector>

using namespace std;

int arr[51];
vector<int> V[51];

int findPar(int v) {
    if (arr[v] < 0) {
        return v;
    }
    return findPar(arr[v]);
}

void uni(int x, int y) {
    int par_x = findPar(x);
    int par_y = findPar(y);

    if (par_x == par_y) return;

    if (arr[par_x] > arr[par_y]) {
        swap(par_x, par_y);
    }

    if (arr[par_x] == arr[par_y]) {
        arr[par_x]--;
    }

    arr[par_y] = par_x;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i <= N; i++) {
        arr[i] = -1;
    }

    int x;
    cin >> x;

    int par;
    if (x == 0) {
        par = 0;
    }  else {
        int y;
        cin >> y;

        par = y;

        for (int i = 1; i < x; i++) {
            cin >> y;
            uni(par, y);
        }
    }

    for (int i = 0; i < M; i++) {
        int a;
        cin >> a;

        if (a == 1) {
            int b; 
            cin >> b;
            V[i].push_back(b);
        } else {
            int prev;
            cin >> prev;
            V[i].push_back(prev);

            for (int j = 1; j < a; j++) {
                int cur;
                cin >> cur;
                V[i].push_back(cur);
                uni(prev, cur);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < M; i++) {
        bool pass = true;
        for (auto a : V[i]) {
            if (findPar(a) == findPar(par)) {
                pass = false;
                break;
            }
        }
        if (pass) ans++;
    }

    // for (int i = 0; i <= N; i++) {
    //     cout << arr[i] << " ";
    // }
    // cout << "\n";
    cout << ans;
}