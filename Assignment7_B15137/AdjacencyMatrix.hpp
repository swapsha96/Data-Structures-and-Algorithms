#ifndef ADJACENCY_MATRIX
#define ADJACENCY_MATRIX 1
#include "GraphAdjacencyBase.hpp"
#include <iostream>
class AdjacencyMatrix : public GraphAdjacencyBase {
private:
	int V;
	int **matrix;
public:
	AdjacencyMatrix() {
		
	};

	AdjacencyMatrix(int v) {
		V = v;
		matrix = new int*[V];
		for(int i = 0; i < V; i++) {
			matrix[i] = new int[V];
			for(int j = 0; j < V; j++) {
				matrix[i][j] = 0;
			}
		}
	};

	bool edgeExits(int i, int j) {
		return (matrix[i][j] == 1) ? true : false;
	};

	int vertices() {
		return this->V;
	};

	int edges() {
		int count = 0;
		for(int i = 0; i < V; i++) {
			for(int j = 0; j < V; j++) {
				if(matrix[i][j] == 1)
					count++;
			}
		}
		return count;
	};

	void add(int i, int j) {
		matrix[i][j] = 1;
	};

	void remove(int i, int j) {
		matrix[i][j] = 0;
	};

	int degree(int i) {
		int count = 0;
		for(int j = 0; j < V; j++) {
			if(matrix[i][j] == 1) {
				count++;
			}
		}
		return count;
	};

	int indegree(int j) {
		int count = 0;
		for(int i = 0; i < V; i++) {
			if(matrix[i][j] == 1) {
				count++;
			}
		}
		return count;
	};

	void print() {
		for(int i = 0; i < V; i++) {
			for(int j = 0; j < V; j++) {
				std::cout << matrix[i][j] << " ";
			}
			std::cout << "\n";
		}
	};
};
#endif /* ifndef ADJACENCY_MATRIX */