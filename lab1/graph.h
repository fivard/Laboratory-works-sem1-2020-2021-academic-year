//
// Created by Admin on 17.09.2020.
//

#ifndef LAB1_GRAPH_H
#define LAB1_GRAPH_H

#include <vector>
#include <map>
#include <iostream>

#define weight first
#define destination second

using namespace std;


template <class T>
class Graph{
    vector<vector<pair<T,int>>> graph;
    vector<bool> isExistVertex;
    int countOfVertexes;
    int countOfEdges;

public:
    Graph(){
        graph.clear();
        countOfEdges = 0;
        countOfVertexes = 0;
    }
    void addVertex(){
        vector<pair<T,int>> temp;
        graph.push_back(temp);
        graph[countOfVertexes].clear();

        isExistVertex.push_back(true);
        countOfVertexes++;
    }
    void deleteVertex(int index){
        if (index >= countOfVertexes || index < 0 || isExistVertex[index] == false){
            cout << "Wrong vertex\n";
            return;
        }

        int countOfDeletedEdges = graph[index].size();
        int adjacentVertex;
        bool flag;

        for (int i = 0; i < countOfDeletedEdges; i++){
            adjacentVertex = graph[index][i].destination;
            flag = true;
            for (int j = 0; j < graph[adjacentVertex].size() && flag; j++){
                if (graph[adjacentVertex][j].destination == index) {
                    graph[adjacentVertex].erase(graph[adjacentVertex].begin() + j);
                    flag = false;
                }
            }
        }

        isExistVertex[index] = false;
        countOfVertexes--;
        countOfEdges -= countOfDeletedEdges;
    }
    void addEdge(int firstVertex, int secondVertex, T weight){
        if (!isExistVertex[firstVertex] || !isExistVertex[secondVertex]){
            cout << "Wrong vertex\n";
            return;
        }

        bool isExist = false;
        for (int i = 0; i < graph[firstVertex].size() && !isExist; i++)
            if (graph[firstVertex][i].destination == secondVertex)
                isExist = true;
        if (isExist){
            cout << "This edge is already exist\n";
            return;
        }
        graph[firstVertex].push_back({weight, secondVertex});
        graph[secondVertex].push_back({weight, firstVertex});
        countOfEdges++;
    }
    void deleteEdge(int firstVertex, int secondVertex){
        if (!isExistVertex[firstVertex] || !isExistVertex[secondVertex]){
            cout << "Wrong vertex\n";
            return;
        }
        bool check = false;
        for (int i = 0; i < graph[firstVertex].size() && !check; i++)
            if (graph[firstVertex][i].destination == secondVertex) {
                graph[firstVertex].erase(graph[firstVertex].begin() + i);
                check = true;
            }
        if (!check){
            cout << "This edge isn't exist\n";
            return;
        }

        for (int i = 0; i < graph[secondVertex].size(); i++)
            if (graph[secondVertex][i].destination == firstVertex)
                graph[secondVertex].erase(graph[secondVertex].begin() + i);
        countOfEdges--;
    }
    void clearGraph(){
        graph.clear();
        isExistVertex.clear();
        countOfVertexes = 0;
        countOfEdges = 0;
    }
    void chooseVertex(){
        for (int i = 0; i < graph.size(); i++)
            if (isExistVertex[i])
                cout << "[" << i << "] ";
        cout << endl;
    }
    friend ostream& operator<<(std::ostream& os, const Graph<T>& tempGraph){
        for (int i = 0; i < tempGraph.graph.size(); i++){
            if (tempGraph.isExistVertex[i]) {
                cout << "Vertex " << i << ":\n";
                for (int j = 0; j < tempGraph.graph[i].size(); j++) {
                    cout << "\t -> " << tempGraph.graph[i][j].destination << ", weight = "
                         << tempGraph.graph[i][j].weight << endl;
                }
            }
        }
        return os;
    }
};



#endif //LAB1_GRAPH_H

