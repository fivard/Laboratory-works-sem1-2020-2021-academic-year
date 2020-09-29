//
// Created by Admin on 17.09.2020.
//

#ifndef LAB1_GRAPH_H
#define LAB1_GRAPH_H

#include <random>
#include <vector>
#include <map>
#include <iostream>
#include <ctime>
#include <algorithm>

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
    void generateRandomGraph(int vertexes){
        clearGraph();
        srand(time(nullptr));

        for (int i = 0; i < vertexes; i++)
            addVertex();

        int matrixEdges[vertexes][vertexes];
        for (int i = 0; i < vertexes; i++)
            for (int j = 0; j < vertexes; j++)
                matrixEdges[i][j] = 0;

        vector<int> startVertexes;
        for (int i = 0; i < vertexes; i++)
            startVertexes.push_back(i);
        shuffle(startVertexes.begin(), startVertexes.end(), std::mt19937(std::random_device()()));
        int firstVertex, secondVertex;
        T newWeight;
        for (int i = 1; i < vertexes; i++){
            newWeight = rand();
            firstVertex = startVertexes[i-1];
            secondVertex = startVertexes[i];
            graph[firstVertex].push_back({newWeight, secondVertex});
            graph[secondVertex].push_back({newWeight, firstVertex});
            matrixEdges[firstVertex][secondVertex] = matrixEdges[secondVertex][firstVertex] = 1;
            countOfEdges++;
        }

        int edges = (vertexes*(rand()%vertexes))/2;

        while (countOfEdges < edges){
            firstVertex = rand()%vertexes;
            secondVertex = rand()%vertexes;
            newWeight = rand();

            if (matrixEdges[firstVertex][secondVertex] != 0 || firstVertex == secondVertex)
                continue;

            graph[firstVertex].push_back({newWeight, secondVertex});
            graph[secondVertex].push_back({newWeight, firstVertex});
            matrixEdges[firstVertex][secondVertex] = matrixEdges[secondVertex][firstVertex] = 1;
            countOfEdges++;

        }
    }
    void MST_Kruskala(){
        Graph mst;
        for (int i = 0; i < countOfVertexes; i++)
            mst.addVertex();

        vector<pair<T, pair<int,int>>> allEdges = sortedEdges();
        long long allWeight = 0;

        vector<int> tree_id (countOfVertexes);
        for (int i =0 ; i < countOfVertexes; ++i)
            tree_id[i] = i;

        for (int i = 0; i < countOfEdges; ++i)
        {
            int firstVertex = allEdges[i].destination.first,  secondVertex = allEdges[i].destination.second;
            if (tree_id[firstVertex] != tree_id[secondVertex])
            {
                T newWeight = allEdges[i].weight;
                mst.addEdge(firstVertex, secondVertex, newWeight);
                int old_id = tree_id[secondVertex],  new_id = tree_id[firstVertex];
                for (int j=0; j<countOfVertexes; ++j)
                    if (tree_id[j] == old_id)
                        tree_id[j] = new_id;
            }
        }
        cout << mst;
    }
    vector<pair<T, pair<int,int>>> sortedEdges(){
        vector<pair<T, pair<int,int>>> edges;
        int matrix[countOfVertexes][countOfVertexes];
        for (int i = 0; i < countOfVertexes; i++)
            for (int j = 0; j < countOfVertexes; j++)
                matrix[i][j] = 0;

        for (int i = 0; i < graph.size(); i++){
            for (int j = 0; j < graph[i].size(); j++){
                if (matrix[i][graph[i][j].destination])
                    continue;
                else {
                    matrix[i][graph[i][j].destination] = matrix[graph[i][j].destination][i] =1;
                    edges.push_back({graph[i][j].weight,{i,graph[i][j].destination}});
                }
            }
        }
        sort(edges.begin(), edges.end());
        return edges;
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
        cout << "\ncountOfEdges = " << tempGraph.countOfEdges << endl;
        cout << "countOfVertexes = " << tempGraph.countOfVertexes << endl;
        return os;
    }
};

#endif //LAB1_GRAPH_H