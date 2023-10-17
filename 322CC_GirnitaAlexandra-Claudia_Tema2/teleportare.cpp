#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <fstream>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int dest;
    int weight;
};

void addEdge(vector<vector<Edge>>& graph, int src, int dest, int weight) {
    Edge edge;
    edge.dest = dest;
    edge.weight = weight;
    graph[src].push_back(edge);
}

int shortestPath(int N, const vector<vector<Edge>>& graph) {
    vector<int> dist(N + 1, INF);
    priority_queue<pair<int, int>,
    vector<pair<int, int>>,
    greater<pair<int, int>>> pq;

    dist[1] = 0;
    pq.push(make_pair(0, 1));

    while (!pq.empty()) {
        int currNode = pq.top().second;
        int currDist = pq.top().first;
        pq.pop();

        if (currDist > dist[currNode])
            continue;

        for (const Edge& edge : graph[currNode]) {
            int neighbor = edge.dest;
            int weight = edge.weight;

            int newDist = currDist + weight;

            if (newDist < dist[neighbor]) {
                dist[neighbor] = newDist;
                pq.push(make_pair(newDist, neighbor));
            }
        }
    }

    return dist[N];
}

int main() {
    int N, M, K;
    ifstream cin("teleportare.in");
    ofstream cout("teleportare.out");

    cin >> N >> M >> K;

    vector<vector<Edge>> graph(N + 1);

    for (int i = 0; i < M; i++) {
        int X, Y, T;
        cin >> X >> Y >> T;
        addEdge(graph, X, Y, T);
        addEdge(graph, Y, X, T);
    }

    for (int i = 0; i < K; i++) {
        int X, Y, P;
        cin >> X >> Y >> P;

       for (Edge& edge : graph[X]) {
            if (edge.dest == Y) {
                edge.weight = 1;
                break;
            }
        }

        for (Edge& edge : graph[Y]) {
            if (edge.dest == X) {
                edge.weight = 1;
                break;
            }
        }

	// Add a new edge with weight 1 to represent the teleportation tunnel
        addEdge(graph, X, Y, 1);
        addEdge(graph, Y, X, 1);
    }

    int shortestTime = shortestPath(N, graph);
    cout << shortestTime << endl;

    return 0;
}
