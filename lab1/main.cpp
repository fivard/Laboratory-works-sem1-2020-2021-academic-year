#include <iostream>
#include "graph.h"
#include "date.h"

namespace test {
    int main_test(int argc, char* argv[]);
}

void inform();

int main(int argc, char* argv[]) {

    test::main_test(argc,argv);

    Graph<Date> graph;
    Date edgeWeight{};
    bool flag = true;
    int action;


    while(flag){
        inform();
        cin >> action;
        switch(action){
            case 1:
                graph.addVertex();
                break;
            case 2:
                int firstVertex, secondVertex;
                cout << "Enter [firstVertex]/[secondVertex]\n";
                graph.chooseVertex();
                cin >> firstVertex >> secondVertex >> edgeWeight;
                graph.addEdge(firstVertex, secondVertex, edgeWeight);
                break;
            case 3:
                int indexVertex;
                cout << "Enter [indexVertex]\n";
                graph.chooseVertex();
                cin >> indexVertex;
                graph.deleteVertex(indexVertex);
                break;
            case 4:
                cout << "Enter [firstVertex]/[secondVertex]\n";
                graph.chooseVertex();
                cin >> firstVertex >> secondVertex;
                graph.deleteEdge(firstVertex, secondVertex);
                break;
            case 5:
                cout << graph;
                break;
            case 6:
                cout << "Enter [countOfVertexes]\n";
                int countOfVertexes;
                cin >> countOfVertexes;
                graph.generateRandomGraph(countOfVertexes);
                break;
            case 7:
                graph.MST_Kruskala();
                break;
            case 8:
                graph.clearGraph();
                break;
            case 0:
                flag = false;
                break;
            default:
                cout << "Wrong case\n";
        }
        cout << "Successfully!\n";
    }
    return 0;
}

void inform(){
    cout << "\nCommands:\n"
    << "[1] - addVertex\n"
    << "[2] - addEdge\n"
    << "[3] - deleteVertex\n"
    << "[4] - deleteEdge\n"
    << "[5] - outputGraph\n"
    << "[6] - randomGraph\n"
    << "[7] - MST_Kruskala\n"
    << "[8] - clearGraph\n"
    << "\n[0] - exit\n";

}