#include <iostream>
#include <vector>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <set>
#include "DijkstraBase.cpp"
using namespace std;


class DijkstraMatrixArray : public DijkstraBase {
private:
    vector< vector<int> > adjacencyMatrix;

public:
    //initialize variables
    DijkstraMatrixArray(int vertices) {
        comparisons=0;
        numVertices= vertices;
        adjacencyMatrix.resize(numVertices, vector<int>(numVertices, 0));
    }

    // add edge
    void addEdge(int u, int v, int weight) override {
        if (u<0 || v<0 || u>= numVertices || v>= numVertices) {
            cout << "Invalid edge." << endl;
            return;
        }
        adjacencyMatrix[u][v]= weight;
        adjacencyMatrix[v][u]= weight;
    }

    int minimumDistance(vector<int>& dist, vector<bool>& visited) {
        int minVal= INT_MAX;
        int minIndex= -1;
        //find the nearest unvisited vertex
        for (int i=0; i<numVertices; i++) {
            comparisons++;
            if (!visited[i] && dist[i]<minVal) {
                minVal= dist[i];
                minIndex=i;
            }
        } return minIndex;
    }

    void dijkstra() override {
        comparisons=0;
        // initialize distance and visited vertices 
        vector<int> dist(numVertices, INT_MAX);
        dist[0]=0;
        vector<bool> visited(numVertices, false);
        vector<int> parent(numVertices, -1);

        int u;
        for (int i=0; i<numVertices; i++) {
            //find next nearest vertex
            u = minimumDistance(dist, visited);
            if (u==-1) break;

            //visit that nearest vertex
            visited[u]=true;

            //update distance array
            for (int v=0; v<numVertices; v++) {
                comparisons++;
                if (!visited[v] && adjacencyMatrix[u][v]!=0 &&
                    dist[u] + adjacencyMatrix[u][v] < dist[v]) {
                        dist[v]= dist[u]+ adjacencyMatrix[u][v];
                        parent[v]= u;
                    }
            }
        } cout << "Comparisons: " << getComparisons() <<endl; 
        
        for (int x=0; x<numVertices; x++) {
            cout << "Shortest path to " << x << " [cost = " << dist[x] << "]: ";
            if (dist[x]==INT_MAX) { cout << "No path available." << endl; }
            else {
                printPath(x, parent);
                cout << endl;
            }
        }
    }

    void printAdjacencyMatrix() {
        for (int i=0; i<numVertices; i++) {
            for (int j=0; j<numVertices; j++) {
                cout << adjacencyMatrix[i][j] << " "; 
            } cout << endl;
        }
    }
};