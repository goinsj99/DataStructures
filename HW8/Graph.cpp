#include "Graph.hpp"
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

void Graph::addVertex(string name){
    bool findIt = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i]->name == name){
            findIt = true;
        }
    }
    if(findIt == false){
        vertex * lilVert = new vertex;
        lilVert->name = name;
        vertices.push_back(lilVert);
    }
}

void Graph::addEdge(string v1, string v2){

    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i]->name == v1)
        {
            for(int j = 0; j < vertices.size(); j++)
            {
                if(vertices[j]->name == v2 && i != j)
                {
                    adjVertex lilVert;
                    lilVert.v = vertices[j];
                    vertices[i]->adj.push_back(lilVert);
                    adjVertex bigVert;
                    bigVert.v = vertices[i];
                    vertices[j]->adj.push_back(bigVert);
                }
            }
        }
    }
}
void Graph::displayEdges(){
    int vSize = vertices.size();
    for(int i = 0; i < vSize; i++)
    {
        cout << vertices[i]->name << " --> ";
        int adjSize = vertices[i]->adj.size();
        for(int j = 0; j < adjSize; j++)
        {
            cout << " " << vertices[i]->adj[j].v->name;
        }
        cout << endl;
    }
}
void Graph::breadthFirstTraverse(string sourceVertex){
    vertex *vStart;
    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i]->name == sourceVertex)
        {
            vStart = vertices[i];
        }
    }
    cout << "Starting vertex (root): " << vStart->name << "->";
    vStart->visited = true;
    vertex *n;
    queue<vertex*> qBall;
    qBall.push(vStart);
    while(!qBall.empty())
    {
        n = qBall.front();
        cout << n->name;
        qBall.pop();
        for(int x = 0; x < n->adj.size(); x++)
        {
            if(!n->adj[x].v->visited)
            {
                n->adj[x].v->visited = true;
                n->adj[x].v->distance = n->distance + 1;
                qBall.push(n->adj[x].v);
                cout << n->adj[x].v->name << "(" << n->adj[x].v->distance << ")" << " ";
            }
        }
    }
    cout << endl;
}
void BFTHelp(vertex* vStart){
    vertex *n;
    vStart->visited = true;
    queue<vertex*> qBall;
    qBall.push(vStart);
    
    while(!qBall.empty())
    {
        n = qBall.front();
        qBall.pop();
        for(int i = 0; i < n->adj.size(); i++)
        {
            if(!n->adj[i].v->visited)
            {
                n->adj[i].v->visited = true;
                n->adj[i].v->distance = n->distance+1;
                qBall.push(n->adj[i].v);
            }
        }
    }
}
int Graph::getConnectedBuildings(){
    int connectingBuilds = 0;
    for(int i = 0; i < vertices.size(); i++)
    {
        if(!vertices[i]->visited){
            BFTHelp(vertices[i]);
            connectingBuilds++;
        }
    }
    return connectingBuilds;
}