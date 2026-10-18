#include <iostream>
using namespace std;

// Fix: Use a standard huge value that safely fits in an integer 
// without risk of edge collisions
#define INF 999999

int main() {
    int n = 4;
    int cost[5][5] = {
        {0, 0, 0, 0, 0},
        {0, 0, 10, 6, 5},
        {0, 10, 0, INF, 15},
        {0, 6, INF, 0, 4},
        {0, 5, 15, 4, 0}
    };

    int visited[5] = {0};
    int edges = 0, minCost = 0;

    visited[1] = 1;

    cout << "Edges in Minimum Spanning Tree:\n";

    while (edges < n - 1) {
        int min = INF, u = -1, v = -1;

        for (int i = 1; i <= n; i++) {
            if (visited[i]) {
                for (int j = 1; j <= n; j++) {
                    // Fix: Ensure we never pick a path that equals INF
                    if (!visited[j] && cost[i][j] < min && cost[i][j] != INF) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        // Safety verification if the graph breaks down or is disconnected
        if (u == -1 || min == INF) {
            cout << "Graph is disconnected! Cannot complete MST.\n";
            return 0;
        }

        cout << u << " - " << v << " : " << min << "\n";

        minCost += min;
        visited[v] = 1;
        edges++;
    }

    cout << "Minimum Cost = " << minCost << "\n";

    return 0;
}
