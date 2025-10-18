#pragma once
#include <iostream>
#include <vector>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <set>
//#include "DijkstraBase.h"
using namespace std;


class DijkstraBase { 
protected: 
    int numVertices; 
    int comparisons;

public: 
    virtual void addEdge(int u, int v, int weight) = 0;
    virtual void dijkstra() = 0;

    int getComparisons() { return comparisons; };

    void addRandomEdges(int numEdges, int maxWeight) {
        int maxEdges = numVertices * (numVertices-1)/2;
        if (numEdges > maxEdges) numEdges = maxEdges;

        // store edges to avoid duplicates
        set< pair<int, int> > addedEdges;

        srand(time(0));

        int edgesAdded = 0;
        while (edgesAdded < numEdges) {
            int u= rand() % numVertices;
            int v= rand() % numVertices;
            if (u==v) continue; // no self-loop

            //undirected graph, store both ways u,v and v,u
            pair<int,int> edge = make_pair(min(u,v), max(u,v));

            // check first if edge already exists
            if (addedEdges.count(edge)==0) {
                // weight between 1 and maxWeight
                int weight = rand() % maxWeight +1;
                addEdge(u, v, weight);
                addedEdges.insert(edge);
                edgesAdded++;
            }
        }
    }

    void printPath(int vertex, const vector<int>& parent) {
        if (vertex == -1) return;
        printPath(parent[vertex], parent);
        cout << vertex << " ";
    }
};