#include <iostream>
#include <vector>
#include <queue>
#include <omp.h>  // openmp timer

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

int main() {
    // small graph
    vector<vector<int>> graph = {
        {1, 2},   // Node 0
        {0, 3},   // Node 1
        {0, 3},   // Node 2
        {1, 2}    // Node 3
    };

    // serial
    cout << "===== Serial BFS (Small Graph) =====" << endl;
    double t1 = omp_get_wtime();
    bfs_serial(graph, 0);
    double t2 = omp_get_wtime();
    cout << "Serial BFS Time: " << (t2 - t1) << " seconds" << endl;

    // parallel
    cout << "\n===== Parallel BFS (Small Graph) =====" << endl;
    double t3 = omp_get_wtime();
    bfs_parallel(graph, 0);
    double t4 = omp_get_wtime();
    cout << "Parallel BFS Time: " << (t4 - t3) << " seconds" << endl;

    return 0;
}
