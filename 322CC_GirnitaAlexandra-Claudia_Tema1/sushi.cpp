#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int task1(int n, int m, int x, vector <int>& p, vector <vector <int> >& g) {
	int buget = n*x;
	vector<int> scor(m+1);
	vector< vector<int> > dp(m + 1, vector<int>(buget + 1, 0));
	for(int i = 0; i < m; i++) {
		scor[i] = 0;
		for(int j = 0; j < n; j++) {
			scor[i] += g[j][i];
		}
	}

	int sol_aux;

	for(int i = 1; i <= m; i++) {
		for(int j = 0; j <= buget; j++) {
			dp[i][j] = dp[i-1][j];
			if(j-p[i-1] >= 0) {
				sol_aux = dp[i-1][j-p[i-1]] + scor[i-1];
				dp[i][j] = max(dp[i][j], sol_aux);
			}
		}
	}
	return dp[m][buget];
}

int task2(int n, int m, int x, vector <int> &p, vector <vector <int> > &g) {
	int buget = n*x;
	vector<int> scor(m+1);
	vector< vector<int> > dp(m + 1, vector<int>(buget + 1, 0));

	for(int i = 0; i < m; i++) {
		scor[i] = 0;
		for(int j = 0; j < n; j++) {
			scor[i] += g[j][i];
		}
	}

	int sol_aux;

	for(int i = 1; i <= m; i++) {
		for(int j = 0; j <= buget; j++) {
			dp[i][j] = dp[i-1][j];
			if(j-p[i-1] >= 0) {
				sol_aux = dp[i-1][j-p[i-1]] + scor[i-1];

				if(j-2*p[i-1] >= 0) {
					sol_aux = max(sol_aux, dp[i-1][j-2*p[i-1]] + 2*scor[i-1]);
				}
				dp[i][j] = max(dp[i][j], sol_aux);
			}
		}
	}
	return dp[m][buget];
}

int task3(int n, int m, int x, vector <int> &p, vector <vector <int> > &g) {
	int buget = n*x;
	vector<int> scor(m+1);
	vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(buget + 1,
	vector<int>(n + 1, 0)));

	for(int i = 0; i < m; i++) {
		scor[i] = 0;
		for(int j = 0; j < n; j++) {
			scor[i] += g[j][i];
		}
	}

	int sol_aux;

	for(int i = 1; i <= m; i++) {
		for(int j = 0; j <= buget; j++) {
			for(int k = 0; k <= n; k++) {
				dp[i][j][k] = dp[i-1][j][k];
				if(j-p[i-1] >= 0 && k > 0) {
					sol_aux = dp[i-1][j-p[i-1]][k-1] + scor[i-1];

					if(j-2*p[i-1] >= 0 && k >= 2) {
						sol_aux = max(sol_aux, dp[i-1][j-2*p[i-1]][k-2] + 2*scor[i-1]);
					}
					dp[i][j][k] = max(dp[i][j][k], sol_aux);
				}
			}
		}
	}
	return dp[m][buget][n];
}


int main() {
	freopen("sushi.in", "r", stdin);
	freopen("sushi.out", "w", stdout);

	int task;  // task number

	int n;  // number of friends
	int m;  // number of sushi types
	int x;  // how much each of you is willing to spend

	vector <int> prices;  // prices of each sushi type
	// the grades you and your friends gave to each sushi type
	vector <vector <int> > grades;

	cin >> task;
	cin >> n >> m >> x;

	prices.assign(m, 0);
	grades.assign(n, vector <int> (m, 0));

	// price of each sushi
	for(int i = 0; i < m; ++i) {
		cin >> prices[i];
	}

	// each friends rankings of sushi types
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			cin >> grades[i][j];
		}
	}

	int ans = -1;

	switch(task) {
		case 1:
			ans = task1(n, m, x, prices, grades);
			break;
		case 2:
			ans = task2(n, m, x, prices, grades);
			break;
		case 3:
			ans = task3(n, m, x, prices, grades);
			break;
		default:
			cout << "wrong task number" << endl;
	}

	cout << ans << endl;

	return 0;
}
