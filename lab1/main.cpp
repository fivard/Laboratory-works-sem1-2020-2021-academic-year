#include <iostream>
#include "graph.h"
#include "date.h"

using namespace std;

void inform();

int main() {
/*
    int year, month, day, hour, minutes, sec;
    cout << "Enter a new date\n [day]/[month]/[year]/[hour]/[minutes]/[sec]\n";
    cin >> day >> month >> year >> hour >> minutes >> sec;
    Date newDate1(year, month, day, hour, minutes, sec);
    cout << newDate1;

    cout << "Enter a new date\n [day]/[month]/[year]/[hour]/[minutes]/[sec]\n";
    cin >> day >> month >> year >> hour >> minutes >> sec;
    Date newDate2(year, month, day, hour, minutes, sec);
    cout << newDate2;

    Odds odd = newDate1 - newDate2;
    cout << odd;
*/
    Graph<int> graph;
    bool flag = true;
    int action;

    while(flag){
        inform();
        cin >> action;
        switch(action){
            case 1:
                graph.addVertex();
                cout << "Successfully!\n";
                break;
            case 2:
                int firstVertex, secondVertex, edgeWeight;
                cout << "Enter [firstVertex]/[secondVertex]/[weight]\n";
                graph.chooseVertex();
                cin >> firstVertex >> secondVertex >> edgeWeight;
                graph.addEdge(firstVertex, secondVertex, edgeWeight);
                cout << "Successfully!\n";
                break;
            case 3:
                int indexVertex;
                cout << "Enter [indexVertex]\n";
                graph.chooseVertex();
                cin >> indexVertex;
                graph.deleteVertex(indexVertex);
                cout << "Successfully!\n";
                break;
            case 4:
                cout << "Enter [firstVertex]/[secondVertex]\n";
                graph.chooseVertex();
                cin >> firstVertex >> secondVertex;
                graph.deleteEdge(firstVertex, secondVertex);
                cout << "Successfully!\n";
                break;
            case 5:
                cout << graph;
                break;
            case 6:
                graph.clearGraph();
                cout << "Successfully!\n";
                break;
            case 0:
                flag = false;
                break;
            default:
                cout << "Wrong case\n";
        }
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
    << "[6] - clearGraph\n"
    << "\n[0] - exit\n";

}