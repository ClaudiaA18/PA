#include <bits/stdc++.h>
using namespace std;

const int DIM = 100001;

vector<int> v[DIM], rev[DIM], ctc[DIM];
vector<bool> viz(DIM, false);
stack<int> st;
int group[DIM], gr[DIM], s;
set<int> zero_indegree;

void DFS1(int node) {
    viz[node] = true;
    for (auto &it : v[node]) {
        if (!viz[it]) {
            DFS1(it);
        }
    }
    st.push(node);
}

void DFS2(int node, int id) {
    viz[node] = false;
    group[node] = id;
    if (node == s) zero_indegree.insert(id);
    for (auto &it : rev[node]) {
        if (viz[it]) {
            DFS2(it, id);
        }
    }
}

int main() {
    ifstream fin("ferate.in");
    ofstream fout("ferate.out");

    int n, m;
    fin >> n >> m >> s;

    for (int i = 1; i <= m; ++i) {
        int x, y;
        fin >> x >> y;
        v[x].push_back(y);
        rev[y].push_back(x);
    }

    for (int i = 1; i <= n; ++i) {
        if (!viz[i]) {
            DFS1(i);
        }
    }

    int cnt = 0;
    while (!st.empty()) {
        int node = st.top();
        st.pop();
        if (viz[node]) {
            DFS2(node, ++cnt);
        }
    }

    for (int node = 1; node <= n; ++node) {
        for (auto &it : v[node]) {
            if (group[node] != group[it]) {
                gr[group[it]]++;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= cnt; ++i) {
        if (gr[i] == 0 && zero_indegree.count(i) == 0) {
            ans++;
        }
    }

    fout << ans << "\n";

    return 0;
}

