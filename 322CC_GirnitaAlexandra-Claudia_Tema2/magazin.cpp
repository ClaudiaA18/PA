#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

vector<int> depozite[MAXN];
int timp[MAXN], timp_start[MAXN], timp_stop[MAXN];
int contor = 0;

void dfs(int nod) {
    timp_start[nod] = ++contor;
    timp[contor] = nod;  // înregistrează timpul de descoperire
    for (auto x : depozite[nod]) {
        dfs(x);
    }
    timp_stop[nod] = contor;
}

int main() {
    ifstream fin("magazin.in");
    ofstream fout("magazin.out");

    int N, Q;
    fin >> N >> Q;

    for (int i = 2; i <= N; i++) {
        int x;
        fin >> x;
        depozite[x].push_back(i);
    }

    dfs(1);

    int i = 1;
    while (i <= Q) {
    int D, E;
    fin >> D >> E;
    // calculează numărul total de noduri accesibile
    int numar_noduri_accesibile = timp_stop[D] - timp_start[D];
    if (E > numar_noduri_accesibile) {
        fout << -1 << "\n";
    } else {
        fout << timp[timp_start[D] + E] << "\n";
    }
    i++;
}

    return 0;
}

