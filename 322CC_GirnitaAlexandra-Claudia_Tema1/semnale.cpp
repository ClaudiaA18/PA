#include <iostream>
#include <vector>

using namespace std;


const int mod = 1000000007;

int type1(int x, int y) {
	if (y == 0) return 1;
	else if (y == 1) return x+y;
	int n = x+y;
	vector<vector<int>> dp(n+1, vector<int>(y+1, 0));

	dp[1][0] = 1;  // [0]
	dp[1][1] = 1;  // [1]
	dp[2][0] = 1;  // [00]
	dp[2][1] = 2;  // [01][10]
	dp[2][2] = 0;

	for (int i = 3; i <=n ; i++) {
		dp[i][0] = 1;  // nr siruri fara bit 1
		dp[i][1] = i;  // nr de siruri cu un bit 1
		for (int j = 2; j <= y; j++) {
			if(j < i) {
				dp[i][j] = (dp[i-1][j]+dp[i-2][j-1]) % mod;
			} else {
				dp[i][j] = 0;
			}
		}
	}
    return dp[n][y];  // sir de lungime n cu y 1
}

int type2(int x, int y) {
    if (y == 0) return 1;
	int n = x+y;

	// sir lungime n cu y biti 1 si cu 0,1,sau 2 biti de 1 la final
	vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(y+1,
	vector<int>(3, 0)));

	dp[0][0][0] = 1;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j <= y; j++) {
			for(int k = 0; k < 3; k++) {
				dp[i+1][j][0] = (dp[i+1][j][0] + dp[i][j][k]) % mod;  // adaugam un 0
				if(k < 2 && j < y) {    //  adaugam 1
					dp[i+1][j+1][k+1] = (dp[i+1][j+1][k+1] + dp[i][j][k]) % mod;
				}
			}
		}
	}
	int total = (dp[n][y][0] + dp[n][y][1] + dp[n][y][2]) % mod;
    return total;
}

int main() {
        freopen("semnale.in", "r", stdin);
	freopen("semnale.out", "w", stdout);

	int sig_type, x, y;

	cin >> sig_type >> x >> y;

    switch (sig_type) {
		case 1:
			cout << type1(x, y);;
			break;
		case 2:
			cout << type2(x, y);
			break;
		default:
			cout << "wrong task number" << endl;
	}

    return 0;
}
