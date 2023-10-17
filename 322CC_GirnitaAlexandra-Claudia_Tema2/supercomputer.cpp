#include <fstream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    // Deschidem fișierele de intrare și ieșire
    ifstream fin("supercomputer.in");
    ofstream fout("supercomputer.out");

    int N, M;
    fin >> N >> M;

    // Creăm vectori pentru seturile de date, dependențele și gradele de intrare
    vector<int> datasets(N + 1);
    vector<vector<int>> dependencies(N + 1);
    vector<int> indegree(N + 1, 0);

    // Citim seturile de date
    for (int i = 1; i <= N; i++) {
        fin >> datasets[i];
    }

    // Citim dependențele și calculăm gradele de intrare
    for (int i = 0; i < M; i++) {
        int u, v;
        fin >> u >> v;
        dependencies[u].push_back(v);
        indegree[v]++;
    }

    // Creăm cozi pentru sarcinile care nu au dependențe
    queue<int> q1, q2;
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            if (datasets[i] == 1) {
                q1.push(i);
            } else {
                q2.push(i);
            }
        }
    }
    // Inițializăm numărul minim de schimbări de context și setul de date curent
    int minSwitches = 0, currentDataset = 0;
    // Procesăm sarcinile până când ambele cozi sunt goale
    while (!q1.empty() || !q2.empty()) {
	// Alegem coada curentă în funcție de setul de date curent
        queue<int>& currentQueue = (!q1.empty() && currentDataset == 1) ||
	q2.empty() ? q1 : q2;
        // Actualizăm setul de date curent
        currentDataset = datasets[currentQueue.front()];

        // Procesăm toate sarcinile din coada curentă
        while (!currentQueue.empty()) {
            int task = currentQueue.front();
            currentQueue.pop();

            // Procesăm toate sarcinile dependente
            for (int dependentTask : dependencies[task]) {
                indegree[dependentTask]--;
		if (indegree[dependentTask] == 0) {
                // Dacă o sarcină dependentă nu mai are alte dependențe
                    if (datasets[dependentTask] == 1) {
                        q1.push(dependentTask);
                    } else {
                        q2.push(dependentTask);
                    }
                }
            }
     	}
        // Dacă mai avem sarcini în coada q1 și setul de date curent nu este 1
	// Incrementăm numărul de schimbări
        if (!q1.empty() && currentDataset != 1) {
            minSwitches++;
        }
        // Dacă mai avem sarcini în coada q2 și setul de date curent nu este 2
	// Incrementăm numărul de schimbări
	if (!q2.empty() && currentDataset != 2) {
            minSwitches++;
        }
    }

    	// Scriem numărul minim de schimbări de context în fișierul de ieșire
	fout<<minSwitches;

	return 0;
}
