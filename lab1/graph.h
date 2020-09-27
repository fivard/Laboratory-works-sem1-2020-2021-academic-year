//
// Created by Admin on 17.09.2020.
//

#ifndef LAB1_GRAPH_H
#define LAB1_GRAPH_H

#include <vector>
#include <map>
#include <iostream>

using namespace std;

template <class T>
class Graph{
    vector < vector < pair<T, pair<int,int> > > > graph;
    int countOfVertexes;
    int countOfEdges;

public:
    Graph(){
        countOfEdges = 0;
        countOfVertexes = 0;
    }
};



#endif //LAB1_GRAPH_H

