#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool possible(int n, vector<long long int >& G, int K, long long int mid) {
    long long int total = 0;
    int count = 1;
    for (int i = 0; i < n; i++) {
        if (G[i] > mid) {
            return false;
        }
        if (total + G[i] > mid) {
            count++;
            total = G[i];
        } else {
            total += G[i];
        }
    }
    if (count <= K)
        return true;
    else
        return false;
}


long long int feribot(int n, int k, vector <long long int>& cars) {
    long long int left = 0;
    long long int right = 0;
    for (int i = 0; i < n; i++) {
        right += cars[i];
    }
    while (left < right) {
        long long int mid = (left + right) / 2;
        if (possible(n, cars, k, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}


int main() {
	freopen("feribot.in", "r", stdin);
	freopen("feribot.out", "w", stdout);

	int n;
	int k;

	vector <long long int> cars;

	cin >> n;
	cin >> k;

	cars.assign(n, 0);

	for(int i = 0; i < n; i++) {
		cin >> cars[i];
	}

	long long int ans = feribot(n, k, cars);
	cout << ans << endl;

	return 0;
}
