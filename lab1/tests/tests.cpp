//
// Created by Admin on 07.10.2020.
//

#include "../date.h"
#include "../graph.h"
#include "doctest.h"

TEST_CASE("DATE"){
    Date date1{1, 1, 1,0,0,0};
    Odds odd{};
    odd.sec = 25;

    SUBCASE("Convert date in sec, operator +=, -="){
        CHECK(date1.countSecForData() == 86400);
        date1+=odd;
        CHECK(date1.countSecForData() == 86425);
        date1-=odd;
        CHECK(date1.countSecForData() == 86400);
    }

    Date date2{};
    date2.createNewDataBySec(86400);

    SUBCASE("Create date by sec"){
        CHECK(date1 == date2);
    }

    SUBCASE("operator <, >"){
        CHECK((date1 > date2) == 0);
        CHECK((date1 < date2) == 0);
        date1 += odd;
        CHECK((date1 > date2) == 1);
        CHECK((date1 < date2) == 0);
    }

    date1 += odd;
    SUBCASE("operator -"){
        odd = date1 - date2;
        CHECK(odd.sec == 25);
    }

};

TEST_CASE("GRAPH"){
    Graph<int> graph;

    SUBCASE("Empty") {
        CHECK(graph.getEdges() == 0);
        CHECK(graph.getVertexes() == 0);
    }

    graph.addVertex();
    graph.addVertex();

    SUBCASE("Vertexes"){

        CHECK(graph.getVertexes() == 2);

        graph.addVertex();

        CHECK(graph.getVertexes() == 3);

        graph.deleteVertex(0);
        graph.deleteVertex(1);

        CHECK(graph.getVertexes() == 1);
    }

    SUBCASE("Edges"){
        graph.addEdge(0,1,10);
        CHECK(graph.getEdges() == 1);
        graph.deleteEdge(0,1);
        CHECK(graph.getEdges() == 0);

        graph.addVertex();
        graph.addVertex();
        graph.addEdge(0,1,10);
        graph.addEdge(0,2,10);
        graph.addEdge(0,3,10);
        graph.deleteVertex(0);
        CHECK(graph.getEdges() == 0);

        SUBCASE("Clear graph"){
            graph.clearGraph();
            CHECK(graph.getEdges() == 0);
            CHECK(graph.getVertexes() == 0);
        }
    }

    SUBCASE("Random graph"){
        graph.generateRandomGraph(100);
        Test test;
        CHECK(test.checkGeneratingGraph(graph));
    }

    graph.clearGraph();
    SUBCASE("MST"){
        graph.addVertex();
        graph.addVertex();
        graph.addVertex();
        graph.addVertex();
        graph.addVertex();

        graph.addEdge(0, 1, 13);
        graph.addEdge(0, 2, 2);
        graph.addEdge(1, 2, 33);
        graph.addEdge(1, 3, 7);
        graph.addEdge(2, 4, 1);
        graph.addEdge(2, 3, 100);
        graph.addEdge(3, 4, 25);

        CHECK(graph.MST_Kruskala() == 23);

    }

    SUBCASE("Sorted edges"){
        Test test;
        CHECK(test.checkSortedEdges(graph));
    }
};
