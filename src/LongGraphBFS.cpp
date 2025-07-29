#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <omp.h>

using namespace std;

// serial bfs
void bfs_serial(const vector<vector<int>>& graph, int start) {
    vector<bool> visited(graph.size(), false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front(); q.pop();
         cout << "[Serial] Visited: " << node << endl;

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

// parallel bfs
void bfs_parallel(const vector<vector<int>>& graph, int start) {
    vector<bool> visited(graph.size(), false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int size = q.size();
        vector<int> currentLevel;

        while (size--) {
            int node = q.front(); q.pop();
             cout << "[Parallel] Visited: " << node << endl;
            currentLevel.push_back(node);
        }

#pragma omp parallel for schedule(dynamic)
        for (int i = 0; i < currentLevel.size(); ++i) {
            int node = currentLevel[i];
            for (int neighbor : graph[node]) {
#pragma omp critical
                {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }
        }
    }
}

// generating a large random graph
vector<vector<int>> generate_random_graph(int nodes, int edges_per_node) {
    vector<vector<int>> graph(nodes);
    srand(time(nullptr));

    for (int i = 0; i < nodes; ++i) {
        for (int j = 0; j < edges_per_node; ++j) {
            int neighbor = rand() % nodes;
            if (neighbor != i) {
                graph[i].push_back(neighbor);
            }
        }
    }

    return graph;
}

int main() {
    int num_nodes = 10000;
    int edges_per_node = 10;
    vector<vector<int>> graph = generate_random_graph(num_nodes, edges_per_node);

    // serial
    cout << "===== Serial BFS (Large Graph) =====" << endl;
    double t1 = omp_get_wtime();
    bfs_serial(graph, 0);
    double t2 = omp_get_wtime();
    cout << "Serial BFS Time: " << (t2 - t1) << " seconds" << endl;

    // parallel
    cout << "\n===== Parallel BFS (Large Graph) =====" << endl;
    double t3 = omp_get_wtime();
    bfs_parallel(graph, 0);
    double t4 = omp_get_wtime();
    cout << "Parallel BFS Time: " << (t4 - t3) << " seconds" << endl;

    return 0;
}
