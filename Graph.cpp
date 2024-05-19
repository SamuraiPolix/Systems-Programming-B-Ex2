/* 
 * ID:      53036281
 * Email:   sam.lazareanu@gmail.com
 * @author  Samuel Lazareanu
*/

#include "Graph.hpp"

#define ERROR_UNMATCHING_ROWS_COLS "The number of columns in the first matrix must be equal to the number of rows in the second matrix.\n"
#define ERROR_NOT_SQUARE "The graph should be a square matrix!\n"
#define GRAPHS_SIZES_NOT_MATCHED "Cannot operate on graphs of different sizes!\n"

using namespace std;
namespace ariel {
    // Constuctors:

    void Graph::loadGraph(vector<vector<int>> graph) {
        // Check if the graph is square
        for (size_t i = 0; i < graph.size(); ++i) {
            if (graph[i].size() != graph.size()) {
                throw invalid_argument(ERROR_NOT_SQUARE);
            }
        }
        // Graph is a square - load it
        adjMatrix = graph;
        this->negativeCycles = false;
        this->cycles = false;
    }

    void Graph::printGraph() const {
        size_t vertices = 0;
        size_t edges = 0;
        
        // for (size_t i = 0; i < this->adjMatrix.size(); ++i) {
        //     vertices++;     // each row represents a vertice
        //     for (size_t j = 0; j < this->adjMatrix[i].size(); ++j) {
        //         if (this->adjMatrix[i][j] != 0){        // 0 means there is no edge between vertices i and j
        //             edges++;
        //         }
        //         cout << this->adjMatrix[i][j] << " ";       // print element
        //     }
        //     cout << endl;       // line drop
        // }
        cout << this->printMatrix();

        // Print stats
        cout << "Graph with " << vertices << " vertices and " << edges << " edges." << endl;        
    }

    string Graph::printMatrix() const{
        string result = "";
        for (size_t i = 0; i < adjMatrix.size(); ++i) {
            result.append("[");
            for (size_t j = 0; j < adjMatrix[i].size(); ++j) {
                result.append(to_string(adjMatrix[i][j]));       // print element
                result.append(",");
                if (j < adjMatrix[i].size()-1){
                    result.append(" ");     // space if not last element in row
                }
            }
            result.append("]");
            if (i < adjMatrix.size()-1){
                    result.append(", ");     // space and comma if not last row
                }
        }
        result.append("\n");
        return result;
    }

    size_t Graph::getSize() const{
        if (adjMatrix.size() != adjMatrix[0].size()){
            throw invalid_argument(ERROR_NOT_SQUARE);
        }
        return adjMatrix.size();
    }

    size_t Graph::countEdges() const{
        size_t edges = 0;
        
        for (size_t i = 0; i < this->adjMatrix.size(); ++i) {
            for (size_t j = 0; j < this->adjMatrix[i].size(); ++j) {
                if (this->adjMatrix[i][j] != 0){        // 0 means there is no edge between vertices i and j
                    edges++;
                }
            }
        }

        return edges;
    }

    int Graph::getWeight(size_t ver1, size_t ver2) const{
        return this->adjMatrix[ver1][ver2];   
    }
    bool Graph::getCycles() const{
        return this->cycles;
    }
    bool Graph::getNegativeCycles() const{
        return this->negativeCycles;
    }
    void Graph::setCycles(bool status){
        this->cycles = status;
    }
    void Graph::setNegativeCycles(bool status){
        this->negativeCycles = status;
        // If a negative cycles exists - a normal cycles exists as well
        this->cycles = status;
    }


    // Helper functions to run operations on an adjMatrix
    vector<vector<int>> Graph::matrixAdd(const vector<vector<int>>& other) const{
        // matrix to store the result
        vector<vector<int>> result(adjMatrix.size(), vector<int>(adjMatrix.size(), 0));

        for(size_t row = 0; row < adjMatrix.size(); row++){
            for (size_t col = 0; col < adjMatrix[row].size(); col++){
                result[row][col] = this->adjMatrix[row][col] + other[row][col];
            }
        }
        return result;
    }

    vector<vector<int>> Graph::matrixAdd(int scalar) const{
        // matrix to store the result
        vector<vector<int>> result(adjMatrix.size(), vector<int>(adjMatrix.size(), 0));

        for(size_t row = 0; row < adjMatrix.size(); row++){
            for (size_t col = 0; col < adjMatrix[row].size(); col++){
                result[row][col] = this->adjMatrix[row][col] + scalar;
            }
        }
        return result;
    }
    vector<vector<int>> Graph::matrixSub(const vector<vector<int>>& other) const{
        // matrix to store the result
        vector<vector<int>> result(adjMatrix.size(), vector<int>(adjMatrix.size(), 0));

        for(size_t row = 0; row < adjMatrix.size(); row++){
            for (size_t col = 0; col < adjMatrix[row].size(); col++){
                result[row][col] = this->adjMatrix[row][col] - other[row][col];
            }
        }
        return result;
    }

    vector<vector<int>> Graph::matrixSub(int scalar) const{
        // matrix to store the result
        vector<vector<int>> result(adjMatrix.size(), vector<int>(adjMatrix.size(), 0));

        for(size_t row = 0; row < adjMatrix.size(); row++){
            for (size_t col = 0; col < adjMatrix[row].size(); col++){
                result[row][col] = this->adjMatrix[row][col] - scalar;
            }
        }
        return result;
    }
    vector<vector<int>> Graph::matrixMul(const vector<vector<int>>& other) const{
        // matrix to store the result
        vector<vector<int>> result(adjMatrix.size(), vector<int>(adjMatrix.size(), 0));

        for(size_t row = 0; row < adjMatrix.size(); row++){
            for (size_t col = 0; col < adjMatrix[row].size(); col++){
                for (size_t ind = 0; ind < adjMatrix.size(); ind++) {
                    result[row][col] += adjMatrix[row][ind] * other[ind][col];
                }
            }
        }
        return result;
    }

    vector<vector<int>> Graph::matrixMul(int scalar) const{
        // matrix to store the result
        vector<vector<int>> result(adjMatrix.size(), vector<int>(adjMatrix.size(), 0));

        for(size_t row = 0; row < adjMatrix.size(); row++){
            for (size_t col = 0; col < adjMatrix[row].size(); col++){
                result[row][col] = this->adjMatrix[row][col] * scalar;
            }
        }
        return result;
    }

    vector<vector<int>> Graph::matrixDiv(const vector<vector<int>>& other) const{
        // matrix to store the result
        vector<vector<int>> result(adjMatrix.size(), vector<int>(adjMatrix.size(), 0));

        for(size_t row = 0; row < adjMatrix.size(); row++){
            for (size_t col = 0; col < adjMatrix[row].size(); col++){
                for (size_t ind = 0; ind < adjMatrix.size(); ind++) {
                    result[row][col] += adjMatrix[row][ind] / adjMatrix[ind][col];
                }
            }
        }
        return result;
    }

    vector<vector<int>> Graph::matrixDiv(int scalar) const{
        // matrix to store the result
        vector<vector<int>> result(adjMatrix.size(), vector<int>(adjMatrix.size(), 0));

        for(size_t row = 0; row < adjMatrix.size(); row++){
            for (size_t col = 0; col < adjMatrix[row].size(); col++){
                result[row][col] = this->adjMatrix[row][col] / scalar;
            }
        }
        return result;
    }

    // Helper functions for comparison operators
    bool Graph::isSubgraphOf(const Graph& graph) const{
        // If 'this' graph is bigger - there are more vertices in 'this' graph so its no a subgraph of 'graph'
        if (this->getSize() > graph.getSize()){
            return false;
        }

        // Iterate over this graph and check the adjMatrixes match
        size_t size = this->getSize();
        for (size_t row = 0; row < size; row++){
            for (size_t col = 0; col < size; col++){
                if (this->getWeight(row, col) != graph.getWeight(row, col)){
                    return false;
                }
            }
        }

        return true;        // vetices and edges match (if 'graph' is bigger than 'this' we don't care about the rest [outside of 'this' vetices])
    }

    // Operators
    // prefix
    Graph& Graph::operator++(){
        this->matrixAdd(1);
        return *this;
    }
    
    Graph& Graph::operator--(){
        this->matrixSub(1);
        return *this;
    }

    // // postfix
    Graph Graph::operator++(int scalar){
        Graph temp = *this;     // TODO understand why we do this
        this->matrixAdd(1);
        return temp;
    }
    Graph Graph::operator--(int){
        Graph temp = *this;     // TODO understand why we do this
        this->matrixSub(1);
        return temp;
    }

    Graph& Graph::operator+=(const Graph& right){
        if (this->adjMatrix.size() != right.adjMatrix.size() || this->adjMatrix[0].size() != right.adjMatrix[0].size()){
            throw invalid_argument(GRAPHS_SIZES_NOT_MATCHED);
        }
        this->loadGraph(this->matrixAdd(right.adjMatrix));
        return *this;
    }
    Graph& Graph::operator+=(const int right){
        this->loadGraph(this->matrixAdd(right));
        return *this;
    }
    Graph& Graph::operator-=(const Graph& right){
        if (this->adjMatrix.size() != right.adjMatrix.size() || this->adjMatrix[0].size() != right.adjMatrix[0].size()){
            throw invalid_argument(GRAPHS_SIZES_NOT_MATCHED);
        }
        this->loadGraph(this->matrixSub(right.adjMatrix));
        return *this;
    }
    Graph& Graph::operator-=(const int right){
        this->loadGraph(this->matrixSub(right));
        return *this;
    }
    Graph& Graph::operator*=(const Graph& right){
        if (this->adjMatrix[0].size() != right.adjMatrix.size()){
            throw invalid_argument(ERROR_UNMATCHING_ROWS_COLS);
        }
        this->loadGraph(this->matrixMul(right.adjMatrix));
        return *this;
    }
    Graph& Graph::operator*=(const int right){
        this->loadGraph(this->matrixMul(right));
        return *this;
    }
    Graph& Graph::operator/=(const int right){
        this->loadGraph(this->matrixDiv(right));
        return *this;
    }

    // -binary operators-
    Graph operator+(const Graph& left, const Graph& right){
        if (left.adjMatrix.size() != right.adjMatrix.size() || left.adjMatrix[0].size() != right.adjMatrix[0].size()){
            throw invalid_argument(GRAPHS_SIZES_NOT_MATCHED);
        }
        return Graph(left.matrixAdd(right.adjMatrix));
    }
    Graph operator+(const Graph& left, int value){
        return Graph(left.matrixAdd(value));
    }
    Graph operator+(double value, const Graph& right){
        return Graph(right.matrixAdd(value));
    }

    Graph operator-(const Graph& left, const Graph& right){
        if (left.adjMatrix.size() != right.adjMatrix.size() || left.adjMatrix[0].size() != right.adjMatrix[0].size()){
            throw invalid_argument(GRAPHS_SIZES_NOT_MATCHED);
        }
        return Graph(right.matrixSub(right.adjMatrix));
    }
    Graph operator-(const Graph& left, int value){
        return Graph(left.matrixSub(value));
    }
    Graph operator-(double value, const Graph& right){
        return Graph(right.matrixSub(value));
    }

    Graph operator*(const Graph& left, const Graph& right){
        if (left.adjMatrix[0].size() != right.adjMatrix.size()){
            throw invalid_argument(ERROR_UNMATCHING_ROWS_COLS);
        }
        return Graph(left.matrixMul(right.adjMatrix));
    }
    Graph operator*(const Graph& left, int value){
        return Graph(left.matrixMul(value));
    }
    Graph operator*(double value, const Graph& right){
        return Graph(right.matrixMul(value));
    }

    // Graph operator/(const Graph& left, const Graph& right){
    //     if (left.adjMatrix[0].size() != right.adjMatrix.size()){
    //         throw invalid_argument("Cannot operate on graphs with unmatching cols and rows!\n");
    //     }
    //     return Graph(left.matrixMul(right.adjMatrix));
    // }
    Graph operator/(const Graph& left, int value){
        return Graph(left.matrixDiv(value));
    }
    Graph operator/(double value, const Graph& right){
        return Graph(right.matrixDiv(value));
    }

    // -comparison operators-
    bool Graph::operator==(const Graph& other) const{
        return this->adjMatrix == other.adjMatrix || (!(*this > other) && !(other > *this));
    }
    bool Graph::operator!=(const Graph& other) const{
        return !(*this == other);       // using the == operator we implemented
    }

    bool Graph::operator<(const Graph& other) const{
        // Graph G2 is larger than graph G1 if graph G1 is contained exactly in graph G2.
        if (this->isSubgraphOf(other)){
            return true;
        }
        // If neither graph is exactly contained in the other and the graphs are not equal
        if (!other.isSubgraphOf(*this) && other!=(*this)){       // using our implemented !=
            size_t this_edges = this->countEdges();
            size_t other_edges = other.countEdges();
            // then graph G2 is greater than graph G1 if the number of edges in G2 is greater than the number of edges in G1.
            if(other_edges > this_edges){   
                return true;
            }
            // If the number of edges is the same,
            // then the graph G2 is larger than the graph G1 if the representative matrix of G2 has a higher order of magnitude than G1.
            else if(other_edges == this_edges || other.getSize() > this->getSize()){        // using our implemented ==
                return true;
            }
        }
        return false;
    }
    bool Graph::operator<=(const Graph& other) const{
        return (*this) < other || (*this) == other;     // using our implemented < , ==
    }
    bool Graph::operator>(const Graph& other) const{
        // Graph G2 is larger than graph G1 if graph G1 is contained exactly in graph G2.
        if (other.isSubgraphOf(*this)){
            return true;
        }
        // If neither graph is exactly contained in the other and the graphs are not equal
        if (!other.isSubgraphOf(*this) && other!=(*this)){       // using our implemented !=
            size_t this_edges = this->countEdges();
            size_t other_edges = other.countEdges();
            // then graph G2 is greater than graph G1 if the number of edges in G2 is greater than the number of edges in G1.
            if(this_edges > other_edges){   
                return true;
            }
            // If the number of edges is the same,
            // then the graph G2 is larger than the graph G1 if the representative matrix of G2 has a higher order of magnitude than G1.
            else if(this_edges == other_edges || other.getSize() < this->getSize()){        // using our implemented ==
                return true;
            }
        }
        return false;
    }
    bool Graph::operator>=(const Graph& other) const{
        return (*this) > other || (*this) == other;     // using our implemented > , ==
    }

    // -stream operators-
    ostream& operator<<(ostream& out, const Graph& graph){
        return (out << graph.printMatrix());
    }
    // istream& Graph::operator>>(istream& in, Graph& graph){
    //     return (out << graph.printMatrix());
    // }
}
