#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <set>
#include "DijkstraBase.cpp"
using namespace std;

class DijkstraListHeap : public DijkstraBase {
private:
    vector< vector< pair<int, int> > > adjacencyList;
;

public:
    DijkstraListHeap(int vertices) {
        comparisons=0;
        numVertices= vertices;
        adjacencyList.resize(numVertices);
    }

    void addEdge(int u, int v, int weight) override {
        if (u<0 || v<0 || u>= numVertices || v>= numVertices) {
            cout << "Invalid edge." << endl;
            return;
        }
        adjacencyList[u].push_back(make_pair(v, weight));
        adjacencyList[v].push_back(make_pair(u, weight));
    }

    void dijkstra() override {
        comparisons=0;
        vector<int> dist(numVertices, INT_MAX);
        dist[0]=0;
        vector<bool> visited(numVertices, false);
        vector<int> parent(numVertices, -1);
        priority_queue<pair<int,int>,  vector<pair<int,int> >, greater<pair<int,int> > > minHeap;
        minHeap.push(make_pair(0,0));

        while (!minHeap.empty()) {
            pair<int,int> popped = minHeap.top();
            minHeap.pop();
            int currentDistance = popped.first;
            int u = popped.second;

            comparisons++;
            if (visited[u]) continue;

            visited[u]=true;

            for (const auto& edge : adjacencyList[u]) {
                int v = edge.first;
                int weight = edge.second;
                comparisons++;

                if (!visited[v]) {
                    int newDistance = dist[u] +weight;
                    if (newDistance < dist[v]) {
                        dist[v]= newDistance;
                        parent[v]= u;
                        popped.first=newDistance;
                        popped.second= v;
                        minHeap.push(popped);
                    }
                }
            } 
        }
        cout << "Comparisons: " << getComparisons() <<endl; 
        for (int x=0; x<numVertices; x++) {
                cout << "Shortest path to " << x << " [cost = " << dist[x] << "]: ";
                if (dist[x]==INT_MAX) { cout << "No path available." << endl; }
                else {
                    printPath(x, parent);
                    cout << endl;
                }
            }
    }

    void printAdjacencyList() {
        for (int u=0; u< adjacencyList.size(); u++) {
            cout << "Node " << u << ": ";
            for (auto it = adjacencyList[u].begin(); it != adjacencyList[u].end(); ++it) {
                cout << "(" << it->first << ", " << it->second << ") ";
            } cout << endl;
        }
    }

};