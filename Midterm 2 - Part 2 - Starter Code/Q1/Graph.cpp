#include "Graph.hpp"
#include <vector>
#include <queue>
using namespace std;

/*
 * adds a vertex to the graph
 */
void Graph::addVertex(int n){
    bool found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i]->key == n){
            found = true;
        }
    }
    if(found == false){
        vertex * v = new vertex;
        v->key = n;
        vertices.push_back(v);
    }
}

/*
 * adds an edge between two vertices (directed graph)
 */
void Graph::addEdge(int src, int dest){
    for(int i = 0; i < vertices.size(); i++) {
        if(vertices[i]->key == src) {
            for(int j = 0; j < vertices.size(); j++) {
                if(vertices[j]->key == dest && i != j) {
                    adjVertex av;
                    av.v = vertices[j];
                    vertices[i]->adj.push_back(av);
                }
            }
        }
    }
}

/*
 * Complete the following function which checks if vert is a boss vertex
 */
int bft(vertex* vert){
 
    vert->visited = true;
    queue<vertex*> q;
    q.push(vStart);
    vertex *n;    
    int count = 1;
    while(!q.empty()){
        n = q.front();
        q.pop();

        for( int j = 0; j < n->adj.size(); j++){
            if(!n->adj[j].v->visited){
                n->adj[j].v->visited = true;
                n->adj[j].v->distance = n->distance+1;
                q.push(n->adj[j].v);
                count++;
            }
        }
        // for(int i = 0; i)
    }
    return count;
}
bool Graph::isVertexABoss(vertex *vert) {
    int counter = bft(vert);
    if(counter == vert->adj.size()){
        return true;
    }
    return false;
}

/*
 * Complete the following function which checks if the graph is a Boss
 */
bool Graph::isGraphABoss() {
    // bool ty=
    // if(is)
    return true;
}
