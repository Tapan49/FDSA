#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

void dfsExplore(int currentBuilding, const vector<vector<int>>& cityMap, vector<bool>& visited, const vector<string>& buildingNames) {
    visited[currentBuilding] = true;
    cout << buildingNames[currentBuilding] << " -> ";

    for (int neighbor : cityMap[currentBuilding]) {
        if (!visited[neighbor]) {
            dfsExplore(neighbor, cityMap, visited, buildingNames);
        }
    }
}

void bfsExplore(int startBuilding, const vector<vector<int>>& cityMap, const vector<string>& buildingNames, int totalBuildings) {
    vector<bool> visited(totalBuildings, false);
    queue<int> q;

    visited[startBuilding] = true;
    q.push(startBuilding);

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << buildingNames[current] << " -> ";

        for (int neighbor : cityMap[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int totalBuildings = 6;

    vector<string> buildingNames = {
        "City Hospital",
        "Community Center",
        "School",
        "Town Hall",
        "Fire Station",
        "Police HQ"
    };

    vector<vector<int>> cityRoads(totalBuildings);

    cityRoads[0] = {1, 2};
    cityRoads[1] = {0, 3, 4};
    cityRoads[2] = {0, 4};
    cityRoads[3] = {1, 5};
    cityRoads[4] = {1, 2, 5};
    cityRoads[5] = {3, 4};

    int startBuilding = 0;

    cout << "========================================\n";
    cout << "    DISASTER RELIEF INSPECTION SYSTEM   \n";
    cout << "========================================\n\n";

    cout << "Starting Base: " << buildingNames[startBuilding] << "\n\n";

    cout << "1. Deep Path Team (DFS Traversal):\n";
    vector<bool> visitedDFS(totalBuildings, false);
    dfsExplore(startBuilding, cityRoads, visitedDFS, buildingNames);
    cout << "END\n\n";

    cout << "2. Radial Spread Team (BFS Traversal):\n";
    bfsExplore(startBuilding, cityRoads, buildingNames, totalBuildings);
    cout << "END\n\n";

    cout << "========================================\n";

    return 0;
}