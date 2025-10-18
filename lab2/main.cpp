#include <iostream>
#include "DijkstraMatrixArray.cpp"
#include "DijkstraListHeap.cpp"

int main() {
    int V = 15;
    int E = 50;
    int maxWeight = 9;

    DijkstraMatrixArray g1(V);
    g1.addRandomEdges(E, maxWeight);
    cout << "Adjacency Matrix for Graph (V=" << V << ", E=" << E << ")" << endl;
    g1.printAdjacencyMatrix();
    cout << endl;
    cout << "Running Dijkstra's algorithm..." << endl;
    g1.dijkstra();

    cout << endl;
    
    DijkstraListHeap g2(V);
    g2.addRandomEdges(E, maxWeight);
    cout << "Adjacency Matrix for Graph (V=" << V << ", E=" << E << ")" << endl;
    g2.printAdjacencyList();
    cout << endl;
    cout << "Running Dijkstra's algorithm..." << endl;
    g2.dijkstra();

    return 0;
}