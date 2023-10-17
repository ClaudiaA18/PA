#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include <algorithm>

using namespace std;

int64_t SolveTask1(int n, vector < int > & a, vector < int > & b) {
    long long int scor = 0;

    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());

    for (int i = 0; i < n; i++) {
        scor += max(a[i], b[i]);
    }

    return scor;
}

int64_t SolveTask2(int n, vector < int > & a, vector < int > & b, int moves) {
    long long int scor = 0;
    vector < int > maxx(n);
    vector < int > minn(n);

    for (int i = 0; i < n; i++) {
        scor += max(a[i], b[i]);
        maxx[i] = max(a[i], b[i]);
        minn[i] = min(a[i], b[i]);
    }

    sort(maxx.begin(), maxx.end());
    sort(minn.rbegin(), minn.rend());

    for (int i = 0; i < moves; i++) {
        if (maxx[i] < minn[i]) {
            scor -= maxx[i];
            scor += minn[i];
        }
    }
    return scor;
}

vector < int > ReadVector(istream & is, int size) {
    vector < int > vec(size);
    for (auto & num : vec) {
        is >> num;
    }
    return vec;
}

int main() {
    ifstream fin("nostory.in");
    ofstream fout("nostory.out");

    int task;
    fin >> task;

    int n, moves;
    if (task == 1) {
        fin >> n;
    } else {
        fin >> n >> moves;
    }

    auto a = ReadVector(fin, n);
    auto b = ReadVector(fin, n);


    auto res = task == 1 ? SolveTask1(n, a, b) : SolveTask2(n, a, b, moves);
    fout << res << "\n";

    return 0;
}
