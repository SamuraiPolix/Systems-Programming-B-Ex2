/* 
 * ID:      53036281
 * Email:   sam.lazareanu@gmail.com
 * @author  Samuel Lazareanu
*/

#pragma once
#include <vector>
#include <iostream>

using namespace std;
namespace ariel {
    class Graph{
        // private: by default

        vector<vector<int>> adjMatrix;
        bool negativeCycles;
        bool cycles;

        string printMatrix() const;

        // Helper functions for Graph operations - operations on adjMatrix
        vector<vector<int>> matrixAdd(const vector<vector<int>>&) const; 
        vector<vector<int>> matrixAdd(int) const;
        vector<vector<int>> matrixAddToEdges(int) const;
        vector<vector<int>> matrixSub(const vector<vector<int>>&) const; 
        vector<vector<int>> matrixSub(int) const;
        vector<vector<int>> matrixSubFromEdges(int) const;
        vector<vector<int>> matrixMul(const vector<vector<int>>&) const; 
        vector<vector<int>> matrixMul(int) const;
        vector<vector<int>> matrixDiv(const vector<vector<int>>&) const; 
        vector<vector<int>> matrixDiv(int) const;

        // Helper functions for comperison opertaions
        bool isSubgraphOf(const Graph&) const;

        public:
            // Inline Constructors
            Graph(){ negativeCycles = false; cycles = false; adjMatrix = {}; }

            Graph(vector<vector<int>> adjMatrix){ Graph(); loadGraph(adjMatrix); }
            
            // Declaring Functions:

            /*
             * Load the received adjacency matrix to the object.
             * Returns 1 if succeeds, 0 if fails.
            */ 
            void loadGraph(vector<vector<int>>);
            
            /*
             * Prints the adjMatrix and the number of verices and edges in the graph.
            */
            string printGraph() const;

            /*
             * Returns the size of the AdjMatrix of the graph.
             * Size represents the number vertices = number of rows and cols (square matrix).
            */ 
            size_t getSize() const;
            size_t countEdges() const;
            int getWeight(size_t, size_t) const;
            bool getCycles() const;
            bool getNegativeCycles() const;
            void setCycles(bool);
            void setNegativeCycles(bool);

            // Operators
            // prefix
            Graph& operator++();
            Graph& operator--();
            // postfix
            Graph operator++(int);
            Graph operator--(int);

            // -compound assignment-
            Graph& operator+=(const Graph&);
            Graph& operator+=(const int);
            Graph& operator-=(const Graph&);
            Graph& operator-=(const int);
            Graph& operator*=(const Graph&);
            Graph& operator*=(const int);
            Graph& operator/=(const Graph&);
            Graph& operator/=(const int);

            // -comparison operators-
            /* Graphs G1 and G2 will be called equal if they are of the same order of magnitude and contain the same edges
             * (and the weights of the edges are the same)
             * or if G1 is not greater than G2 and neither is G2 greater than G1.
             */
            bool operator==(const Graph& other) const;
            bool operator!=(const Graph& other) const;
            /* Graph G2 is larger than graph G1 if graph G1 is contained exactly in graph G2.
             * If neither graph is exactly contained in the other and the graphs are not equal,
             * then graph G2 is greater than graph G1 if the number of edges in G2 is greater than the number of edges in G1.
             * If the number of edges is the same,
             * then the graph G2 is larger than the graph G1 if the representative matrix of G2 has a higher order of magnitude than G1.
             */
            bool operator<(const Graph& other) const;
            bool operator<=(const Graph& other) const;
            bool operator>(const Graph& other) const;
            bool operator>=(const Graph& other) const;

            // -binary operators-
            // *All set as friend to allow access to private members and methods
            friend Graph operator+(const Graph&, const Graph&);
            friend Graph operator+(const Graph&, int);
            friend Graph operator+(double, const Graph&);

            friend Graph operator-(const Graph&, const Graph&);
            friend Graph operator-(const Graph&, int);
            friend Graph operator-(double, const Graph&);

            friend Graph operator*(const Graph&, const Graph&);
            friend Graph operator*(const Graph&, int);
            friend Graph operator*(double, const Graph&);

            friend Graph operator/(const Graph&, const Graph&);
            friend Graph operator/(const Graph&, int);
            friend Graph operator/(int, const Graph&);

            // -stream operators-
            friend ostream& operator<<(ostream&, const Graph&);
    };
}