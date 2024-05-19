/* 
 * ID:      53036281
 * Email:   sam.lazareanu@gmail.com
 * @author  Samuel Lazareanu
*/
#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"
#include <sstream>

using namespace std;

TEST_CASE("Test graph addition")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g1 + g2;

    CHECK(g3.printGraph() == "[0, 2, 1]\n[2, 0, 3]\n[1, 3, 0]");
}

TEST_CASE("Test graph multiplication")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g4 = g1 * g2;

    CHECK(g4.printGraph() == "[1, 0, 2]\n[1, 3, 1]\n[1, 0, 2]");
}

TEST_CASE("Invalid operations")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);

    ariel::Graph g2;
    vector<vector<int>> notSquared = {
        {0, 1, 1, 1},
        {1, 0, 2, 1},
        {1, 2, 0, 1}};
    CHECK_THROWS(g2.loadGraph(notSquared));
    ariel::Graph g5;

    // Multiplication of two graphs with unmatching sizes for rows and columns
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g5.loadGraph(graph2);
    CHECK_THROWS(g5 * g1);
    CHECK_THROWS(g1 * g2);

    // Addition of two graphs with different dimensions
    ariel::Graph g6;
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g6.loadGraph(graph3);
    CHECK_THROWS(g1 + g6);
    
    // Subtraction of two graphs with different dimensions
    ariel::Graph g7;
    vector<vector<int>> graph4 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g7.loadGraph(graph4);
    CHECK_THROWS(g1 - g7);
    CHECK_THROWS(g1 - g6);

    // Division of a graph by a graph with different dimensions
    ariel::Graph g8;
    vector<vector<int>> graph5 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g8.loadGraph(graph5);
    CHECK_THROWS(g1 / g8);
    CHECK_THROWS(g1 / g6);   
}

TEST_CASE("Test graph equality")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g1 + g2;
    ariel::Graph g4 = g1 + g2;
    CHECK(g3 == g4);
    CHECK_FALSE(g1 == g2);
}
TEST_CASE("Test graph addition (+)")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 2, 2},
        {2, 0, 3},
        {2, 3, 0}};
    g2.loadGraph(graph2);

    ariel::Graph g3 = g1 + g2;

    CHECK(g3.printGraph() == "[0, 3, 2]\n[3, 0, 4]\n[2, 4, 0]");

    // Test addition with different sizes
    ariel::Graph g4;
    vector<vector<int>> graph4 = {
        {0, 1},
        {1, 0}};
    g4.loadGraph(graph4);
    CHECK_THROWS(g1 + g4);
}

TEST_CASE("Test graph addition (+=)")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 2, 2},
        {2, 0, 3},
        {2, 3, 0}};
    g2.loadGraph(graph2);

    g1 += g2;

    CHECK(g1.printGraph() == "[0, 3, 2]\n[3, 0, 4]\n[2, 4, 0]");

    // Test addition with different sizes
    ariel::Graph g4;
    vector<vector<int>> graph4 = {
        {0, 1},
        {1, 0}};
    g4.loadGraph(graph4);
    CHECK_THROWS(g1 += g4);
}

TEST_CASE("Test unary plus (+)")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    ariel::Graph emptyGraph;
    vector<vector<int>> graph2 = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};
    emptyGraph.loadGraph(graph2);

    emptyGraph += g1;
    CHECK(g1.printGraph() == emptyGraph.printGraph());
}

TEST_CASE("Test graph subtraction (-)")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 3, 2},
        {3, 0, 4},
        {2, 4, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g2.loadGraph(graph2);

    ariel::Graph g3 = g1 - g2;

    CHECK(g3.printGraph() == "[0, 2, 2]\n[2, 0, 3]\n[2, 3, 0]");

    // Test subtraction with different sizes
    ariel::Graph g4;
    vector<vector<int>> graph4 = {
        {0, 1},
        {1, 0}};
    g4.loadGraph(graph4);
    CHECK_THROWS(g1 - g4);
}

TEST_CASE("Test graph subtraction (-=)")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 3, 2},
        {3, 0, 4},
        {2, 4, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g2.loadGraph(graph2);

    g1 -= g2;
    
    CHECK(g1.printGraph() == "[0, 2, 2]\n[2, 0, 3]\n[2, 3, 0]");

    // Test subtraction with different sizes
    ariel::Graph g4;
    vector<vector<int>> graph4 = {
        {0, 1},
        {1, 0}};
    g4.loadGraph(graph4);
    CHECK_THROWS(g1 -= g4);
}

TEST_CASE("Test unary minus (-)")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 3, 2},
        {3, 0, 4},
        {2, 4, 0}};
    g1.loadGraph(graph1);

    ariel::Graph emptyGraph;
    vector<vector<int>> graph2 = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};
    emptyGraph.loadGraph(graph2);

    emptyGraph -= g1;

    CHECK(emptyGraph.printGraph() == "[0, -3, -2]\n[-3, 0, -4]\n[-2, -4, 0]");
}

TEST_CASE("Test graph equality (==)")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g2.loadGraph(graph2);

    ariel::Graph g3;
    vector<vector<int>> graph3 = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}};
    g3.loadGraph(graph3);

    CHECK(g1 == g2);
    CHECK_FALSE(g1 == g3);
}

TEST_CASE("Test graph inequality (!=)")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 2, 2},
        {2, 0, 3},
        {2, 3, 0}};
    g2.loadGraph(graph2);

    CHECK(g1 != g2);
    CHECK_FALSE(g1 != g1);
}

TEST_CASE("Test graph greater than (>)")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 2, 2},
        {2, 0, 3},
        {2, 3, 0}};
    g2.loadGraph(graph2);

    CHECK(g2 > g1);
    CHECK_FALSE(g1 > g2);
}

TEST_CASE("Test graph greater than or equal (>=)")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g2.loadGraph(graph2);

    ariel::Graph g3;
    vector<vector<int>> graph3 = {
        {0, 2, 2},
        {2, 0, 3},
        {2, 3, 0}};
    g3.loadGraph(graph3);

    CHECK(g1 >= g2);
    CHECK(g3 >= g1);
    CHECK_FALSE(g1 >= g3);
}

TEST_CASE("Test graph less than (<)")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 2, 2},
        {2, 0, 3},
        {2, 3, 0}};
    g2.loadGraph(graph2);

    CHECK(g1 < g2);
    CHECK_FALSE(g2 < g1);
}

TEST_CASE("Test graph less than or equal (<=)")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g2.loadGraph(graph2);

    ariel::Graph g3;
    vector<vector<int>> graph3 = {
        {0, 2, 2},
        {2, 0, 3},
        {2, 3, 0}};
    g3.loadGraph(graph3);

    CHECK(g1 <= g2);
    CHECK(g1 <= g3);
    CHECK_FALSE(g3 <= g1);
}

TEST_CASE("Test graph increment (++)")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    // increases only edges (weight > 0)
    ++g1;
    CHECK(g1.printGraph() == "[0, 2, 0]\n[2, 0, 2]\n[0, 2, 0]");

    // increases only edges (weight > 0)
    g1++;
    CHECK(g1.printGraph() == "[0, 3, 0]\n[3, 0, 3]\n[0, 3, 0]");
}

TEST_CASE("Test graph decrement (--)")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {1, 2, 1},
        {2, 1, 2},
        {1, 2, 1}};
    g1.loadGraph(graph1);
    // reduces only edges (weight > 0)
    --g1;
    CHECK(g1.printGraph() == "[0, 1, 0]\n[1, 0, 1]\n[0, 1, 0]");

    // reduces only edges (weight > 0)
    g1--;
    CHECK(g1.printGraph() == "[0, 0, 0]\n[0, 0, 0]\n[0, 0, 0]");
}

TEST_CASE("Test graph scalar multiplication (*)")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {1, 2, 1},
        {2, 1, 2},
        {1, 2, 1}};
    g1.loadGraph(graph1);

    ariel::Graph g2 = g1 * 2;

    CHECK(g2.printGraph() == "[2, 4, 2]\n[4, 2, 4]\n[2, 4, 2]");

    ariel::Graph g3 = 3 * g1;

    CHECK(g3.printGraph() == "[3, 6, 3]\n[6, 3, 6]\n[3, 6, 3]");
}

TEST_CASE("Test graph multiplication (graph * graph)")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(graph2);

    ariel::Graph g4 = g1 * g2;

    CHECK(g4.printGraph() == "[1, 0, 2]\n[1, 3, 1]\n[1, 0, 2]");

    // Test multiplication with different sizes
    ariel::Graph g5;
    vector<vector<int>> graph5 = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}};
    g5.loadGraph(graph5);
    CHECK_THROWS(g1 * g5);
}

TEST_CASE("Test graph output operator (<<)")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    ostringstream oss;
    oss << g1;
    CHECK(oss.str() == "[0, 1, 0]\n[1, 0, 1]\n[0, 1, 0]\n");

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 2, 2},
        {2, 0, 3},
        {2, 3, 0}};
    g2.loadGraph(graph2);

    ostringstream oss2;
    oss2 << g2;
    CHECK(oss2.str() == "[0, 2, 2]\n[2, 0, 3]\n[2, 3, 0]\n");

    ariel::Graph g3;
    vector<vector<int>> graph3 = {
        {1, 2},
        {2, 1}};
    g3.loadGraph(graph3);

    ostringstream oss3;
    oss3 << g3;
    CHECK(oss3.str() == "[1, 2]\n[2, 1]\n");

    // Test an empty graph
    ariel::Graph g4;
    vector<vector<int>> graph4 = {};
    g4.loadGraph(graph4);

    ostringstream oss4;
    oss4 << g4;
    CHECK(oss4.str() == "\n");
}

// TESTS FOR ALGORITHMS - WHILE USING THE OPERATORS FROM ABOVE
TEST_CASE("Test isConnected")
{
    ariel::Graph graph;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    graph.loadGraph(graph1);
    CHECK(ariel::Algorithms::isConnected(graph) == true);

    // graph with 0 edges - not connected
    graph -= graph;
    CHECK(ariel::Algorithms::isConnected(graph) == false);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    graph.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(graph) == false);

    ariel::Graph graph3;
    vector<vector<int>> graph4 = {
        {0, 1, 1, 1, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {0, 0, 0, 1, 0}};
    graph3.loadGraph(graph4);
    // making vertice 4 connected to the rest of the graph -> the graph is connected
    graph += graph3;
    CHECK(ariel::Algorithms::isConnected(graph) == true);
}

TEST_CASE("Test shortestPath")
{
    ariel::Graph graph;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    graph.loadGraph(graph1);
    CHECK(ariel::Algorithms::shortestPath(graph, 0, 2) == "0->1->2");

    // adding the same values keeps the same shortest path
    graph += graph;
    CHECK(ariel::Algorithms::shortestPath(graph, 0, 2) == "0->1->2");

    // graph with 0 edges - no path
    graph -= graph;
    CHECK(ariel::Algorithms::shortestPath(graph, 0, 2) == "-1");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    graph.loadGraph(graph2);
    CHECK(ariel::Algorithms::shortestPath(graph, 0, 4) == "-1");
}
TEST_CASE("Test isContainsCycle")
{
    ariel::Graph graph;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    graph.loadGraph(graph1);
    CHECK(ariel::Algorithms::isContainsCycle(graph) == "0");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    graph.loadGraph(graph2);
    CHECK((ariel::Algorithms::isContainsCycle(graph) == "The cycle is: 0->1->2->0" ||
          ariel::Algorithms::isContainsCycle(graph) == "The cycle is: 2->1->0->2" ||
          ariel::Algorithms::isContainsCycle(graph) == "The cycle is: 1->0->2->1" ||
          ariel::Algorithms::isContainsCycle(graph) == "The cycle is: 0->2->1->0" ||
          ariel::Algorithms::isContainsCycle(graph) == "The cycle is: 1->2->0->1" ||
          ariel::Algorithms::isContainsCycle(graph) == "The cycle is: 2->0->1->2") == true);

    // multiply the graph by -1 -> negative cycle
    graph = graph * -1;
    CHECK(ariel::Algorithms::negativeCycle(graph) == "Graph does have negativeCycles");
    CHECK((ariel::Algorithms::isContainsCycle(graph) == "The cycle is: 0->1->2->0" ||
          ariel::Algorithms::isContainsCycle(graph) == "The cycle is: 2->1->0->2" ||
          ariel::Algorithms::isContainsCycle(graph) == "The cycle is: 1->0->2->1" ||
          ariel::Algorithms::isContainsCycle(graph) == "The cycle is: 0->2->1->0" ||
          ariel::Algorithms::isContainsCycle(graph) == "The cycle is: 1->2->0->1" ||
          ariel::Algorithms::isContainsCycle(graph) == "The cycle is: 2->0->1->2") == true);
    
    
    // graph with 0 edges - no cycle
    graph++;
    CHECK(ariel::Algorithms::isContainsCycle(graph) == "0");
}
TEST_CASE("Test isBipartite")
{
    ariel::Graph graph;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    graph.loadGraph(graph1);
    CHECK(ariel::Algorithms::isBipartite(graph) == "The graph is bipartite: A={0, 2}, B={1}");

    // graph with 0 edges - bipartite
    graph -= graph;
    CHECK(ariel::Algorithms::isBipartite(graph) == "The graph is bipartite: A={0, 1, 2}, B={}");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    graph.loadGraph(graph2);
    CHECK(ariel::Algorithms::isBipartite(graph) == "0");    

    vector<vector<int>> graph3 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    graph.loadGraph(graph3);
    CHECK(ariel::Algorithms::isBipartite(graph) == "0");
}
TEST_CASE("Test invalid graph")
{
    ariel::Graph graph;
    vector<vector<int>> graph1 = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(graph.loadGraph(graph1));
    
    // load a valid graph
    vector<vector<int>> graph2 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    graph.loadGraph(graph2);

    // add a graph with different dimensions
    ariel::Graph graph3;
    vector<vector<int>> graph4 = {
        {0, 1},
        {1, 0}};
    graph3.loadGraph(graph4);
    // multiply the graphs - unmatching rows and cols
    CHECK_THROWS(graph * graph3);
}
TEST_CASE("Test negativeCycle")
{
    // Unweighted graphs without a negative cycle
    ariel::Graph graph;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 0, 0}};
    graph.loadGraph(graph1);
    CHECK(ariel::Algorithms::negativeCycle(graph) == "Graph doesn't have negativeCycles");

    // multiply the graph by -1 -> negative cycle
    graph = graph * -1;
    CHECK(ariel::Algorithms::negativeCycle(graph) == "Graph does have negativeCycles");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    graph.loadGraph(graph2);
    CHECK(ariel::Algorithms::negativeCycle(graph) == "Graph doesn't have negativeCycles");

    // Weighted graph without a negative cycle
    vector<vector<int>> graph3 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    graph.loadGraph(graph3);
    CHECK(ariel::Algorithms::negativeCycle(graph) == "Graph doesn't have negativeCycles");

    // Unweigthted graphs with a negative cycle
    vector<vector<int>> graph4 = {
        {0, -1, 0},
        {0, 0, -1},
        {-1, 0, 0}};
    graph.loadGraph(graph4);
    CHECK(ariel::Algorithms::negativeCycle(graph) == "Graph does have negativeCycles");

    // multiply the graph by -1 -> no negative cycle - only positive
    graph = graph * -1;
    CHECK(ariel::Algorithms::negativeCycle(graph) == "Graph doesn't have negativeCycles");
    CHECK(ariel::Algorithms::isContainsCycle(graph) == "The cycle is: 2->1->0->2");

    vector<vector<int>> graph5 = {
        {0, -1, 0, 0, 0},
        {0, 0, -1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}};
    graph.loadGraph(graph5);
    CHECK(ariel::Algorithms::negativeCycle(graph) == "Graph doesn't have negativeCycles");

    // Weighted graph with a negative cycle
    vector<vector<int>> graph6 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, -5},
        {0, 0, 0, -5, 0}};
    graph.loadGraph(graph6);
    CHECK(ariel::Algorithms::negativeCycle(graph) == "Graph does have negativeCycles");
}
TEST_CASE("Test normal cycles")
{
    ariel::Graph graph;
    // Unweighted graph without a cycle
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    graph.loadGraph(graph1);
    CHECK(ariel::Algorithms::isContainsCycle(graph) == "0");

    // Unweighted graph with a cycle
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    graph.loadGraph(graph2);
    CHECK((ariel::Algorithms::isContainsCycle(graph) == "The cycle is: 0->1->2->0" ||
          ariel::Algorithms::isContainsCycle(graph) == "The cycle is: 2->1->0->2" ||
          ariel::Algorithms::isContainsCycle(graph) == "The cycle is: 1->0->2->1" ||
          ariel::Algorithms::isContainsCycle(graph) == "The cycle is: 0->2->1->0" ||
          ariel::Algorithms::isContainsCycle(graph) == "The cycle is: 1->2->0->1" ||
          ariel::Algorithms::isContainsCycle(graph) == "The cycle is: 2->0->1->2") == true);

    // Weighted graph with a cycle
    vector<vector<int>> graph3 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    graph.loadGraph(graph3);
    CHECK(ariel::Algorithms::isContainsCycle(graph) != "0");        // all the cycles are valid
}
TEST_CASE("Test Bipartite")
{
    ariel::Graph graph;
    // Unweighted graph that is bipartite
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    graph.loadGraph(graph1);
    CHECK(ariel::Algorithms::isBipartite(graph) == "The graph is bipartite: A={0, 2}, B={1}");

    // Unweighted graph that is not bipartite
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    graph.loadGraph(graph2);
    CHECK(ariel::Algorithms::isBipartite(graph) == "0");

    // Weighted graph that is not bipartite
    vector<vector<int>> graph3 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    graph.loadGraph(graph3);
    CHECK(ariel::Algorithms::isBipartite(graph) == "0");
}

TEST_CASE("Directed graph"){
    ariel::Graph graph;
    vector<vector<int>> graph1 ={
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0}};
    graph.loadGraph(graph1);
    CHECK(ariel::Algorithms::isConnected(graph) == true);
    CHECK(ariel::Algorithms::shortestPath(graph, 0, 4) == "0->1->2->3->4");
    CHECK(ariel::Algorithms::isContainsCycle(graph) == "0");
    CHECK(ariel::Algorithms::negativeCycle(graph) == "Graph doesn't have negativeCycles");
    CHECK(ariel::Algorithms::isBipartite(graph) == "The graph is bipartite: A={0, 2, 4}, B={1, 3}");
}

TEST_CASE("Undirected graph"){
    ariel::Graph graph;
    vector<vector<int>> graph1 ={
        {0, 1, 0, 0, 0},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {0, 0, 0, 1, 0}};
    graph.loadGraph(graph1);
    CHECK(ariel::Algorithms::isConnected(graph) == true);
    CHECK(ariel::Algorithms::shortestPath(graph, 0, 4) == "0->1->2->3->4");
    CHECK(ariel::Algorithms::isContainsCycle(graph) == "0");
    CHECK(ariel::Algorithms::negativeCycle(graph) == "Graph doesn't have negativeCycles");
    CHECK(ariel::Algorithms::isBipartite(graph) == "The graph is bipartite: A={0, 2, 4}, B={1, 3}");
}

TEST_CASE("Graph with isolated vertices"){
    ariel::Graph graph;
    vector<vector<int>> graph0 ={
        {0, 1, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}};
    graph.loadGraph(graph0);
    CHECK(ariel::Algorithms::isConnected(graph) == false);
    CHECK(ariel::Algorithms::shortestPath(graph, 0, 4) == "-1");
    CHECK(ariel::Algorithms::isContainsCycle(graph) == "0");
    CHECK(ariel::Algorithms::negativeCycle(graph) == "Graph doesn't have negativeCycles");
    CHECK((ariel::Algorithms::isBipartite(graph) == "The graph is bipartite: A={0, 2, 3, 4}, B={1}" ||
    ariel::Algorithms::isBipartite(graph) == "The graph is bipartite: A={1}, B={0, 2, 3, 4})") == true);
}

TEST_CASE("Graph with a single vertex and no edges"){
    ariel::Graph graph;
    vector<vector<int>> graph0 ={
        {0}};
    graph.loadGraph(graph0);
    CHECK(ariel::Algorithms::isConnected(graph) == true);       // one vertice only is connected
    CHECK(ariel::Algorithms::shortestPath(graph, 0, 4) == "-1");
    CHECK(ariel::Algorithms::isContainsCycle(graph) == "0");
    CHECK(ariel::Algorithms::negativeCycle(graph) == "Graph doesn't have negativeCycles");
    CHECK(ariel::Algorithms::isBipartite(graph) == "The graph is bipartite: A={0}, B={}");
}

TEST_CASE("Graph with self-loop"){
    ariel::Graph graph;
    vector<vector<int>> graph0 ={
        {1, 1, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    graph.loadGraph(graph0);
    CHECK(ariel::Algorithms::isConnected(graph) == false);
    CHECK(ariel::Algorithms::shortestPath(graph, 0, 4) == "-1");
    CHECK((ariel::Algorithms::isContainsCycle(graph) == "The cycle is: 0->1->0" ||
          ariel::Algorithms::isContainsCycle(graph) == "The cycle is: 1->0->1" ||
          ariel::Algorithms::isContainsCycle(graph) == "The cycle is: 1->1" ||
          ariel::Algorithms::isContainsCycle(graph) == "The cycle is: 0->0") == true);
    CHECK(ariel::Algorithms::negativeCycle(graph) == "Graph doesn't have negativeCycles");
    CHECK(ariel::Algorithms::isBipartite(graph) == "0");
}

TEST_CASE("Connected graph"){
    ariel::Graph graph;
    vector<vector<int>> graph0 ={
        {0, 1, 0, 0, 0},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {0, 0, 0, 1, 0}};
    graph.loadGraph(graph0);
    CHECK(ariel::Algorithms::isConnected(graph) == true);
    CHECK(ariel::Algorithms::shortestPath(graph, 0, 4) == "0->1->2->3->4");
    CHECK(ariel::Algorithms::isContainsCycle(graph) == "0");
    CHECK(ariel::Algorithms::negativeCycle(graph) == "Graph doesn't have negativeCycles");
    CHECK(ariel::Algorithms::isBipartite(graph) == "The graph is bipartite: A={0, 2, 4}, B={1, 3}");

    vector<vector<int>> graph2 = {
    {0, 1, 0},
    {1, 0, 1},
    {0, 1, 0}
    };
    graph.loadGraph(graph2); // Load the graph to the object.

    CHECK(ariel::Algorithms::isConnected(graph) == true);      
    CHECK(ariel::Algorithms::shortestPath(graph, 0, 2) == "0->1->2");
    CHECK(ariel::Algorithms::isContainsCycle(graph) == "0");    
    CHECK(ariel::Algorithms::isBipartite(graph) == "The graph is bipartite: A={0, 2}, B={1}");

        vector<vector<int>> graph3 = {
    {0, 1, 2, 0, 0},
    {1, 0, 3, 0, 0},
    {2, 3, 0, 4, 0},
    {0, 0, 4, 0, 5},
    {0, 0, 0, 5, 0}
    };
    graph.loadGraph(graph3); // Load the graph to the object.

    CHECK(ariel::Algorithms::isConnected(graph) == true);        
    CHECK(ariel::Algorithms::shortestPath(graph, 0, 4) == "0->2->3->4");
    CHECK(ariel::Algorithms::isContainsCycle(graph) == "The cycle is: 2->1->0->2");
    CHECK(ariel::Algorithms::isBipartite(graph) == "0");
}

TEST_CASE("Unconnected graph"){
    ariel::Graph graph;
    vector<vector<int>> graph2 = {
    {0, 1, 1, 0, 0},
    {1, 0, 1, 0, 0},
    {1, 1, 0, 1, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0}
    };
    graph.loadGraph(graph2); // Load the graph to the object.

    CHECK(ariel::Algorithms::isConnected(graph) == false);        
    CHECK(ariel::Algorithms::shortestPath(graph, 0, 4) == "-1"); 
    CHECK(ariel::Algorithms::isContainsCycle(graph) == "The cycle is: 2->1->0->2");    
    CHECK(ariel::Algorithms::isBipartite(graph) == "0");        
}    

TEST_CASE("Connected graph with a negative cycle"){
    ariel::Graph graph;
    vector<vector<int>> graph1 ={
        {0, -1, 0},
        {0, 0, -1},
        {-1, 0, 0}
    };
    graph.loadGraph(graph1);
    CHECK(ariel::Algorithms::isConnected(graph) == true);
    CHECK(ariel::Algorithms::shortestPath(graph, 0, 2) == "-1");
    CHECK(ariel::Algorithms::isContainsCycle(graph) == "The cycle is: 2->1->0->2");
    CHECK(ariel::Algorithms::negativeCycle(graph) == "Graph does have negativeCycles");
    CHECK(ariel::Algorithms::isBipartite(graph) == "0");
}

