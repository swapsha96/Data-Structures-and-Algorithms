#ifndef ADJACENCY_LIST
#define ADJACENCY_LIST 1
#include "GraphAdjacencyBase.hpp"
#include <iostream>
class AdjacencyList : public GraphAdjacencyBase {
private:
	struct AdjListNode {
		int data;
		int color;
		AdjListNode *next;
	};

	struct AdjList {
		AdjListNode *head;
	};

	struct Graph {
		int V;
		AdjList *array;
	};

	Graph *graph;
public:
	AdjacencyList() {
		
	};

	AdjacencyList(int V) {
		graph = new Graph;
		graph->V = V;
		graph->array = new AdjList[V];
		for(int i = 0; i < V; i++)
			graph->array[i].head = NULL;
	};

	void add(int src, int dest) {
		//src -> dest
		AdjListNode *node1 = new AdjListNode;
		node1->data = dest;
		node1->color = 0;
		node1->next = graph->array[src].head;
		graph->array[src].head = node1;
	};

	void print() {
		for(int i = 0; i < graph->V; i++) {
			AdjListNode *root = graph->array[i].head;
			std::cout << i << ": ";
			while(root) {
				std::cout << root->data << " ";
				root = root->next;
			}
			std::cout << "\n";
		}
	};

	bool edgeExits(int i, int j) {
		AdjListNode *root = graph->array[i].head;
		while(root) {
			if(root->data == j)
				return true;
			else
				root = root->next;
		}
		return false;
	};

	int vertices() {
		return graph->V;
	};

	int edges() {
		int count = 0;
		for(int i = 0; i < graph->V; i++) {
			AdjListNode *root = graph->array[i].head;
			while(root) {
				count++;
				root = root->next;
			}
		}

		return count;
	};

	void remove(int i, int j) {
		AdjListNode *prev = NULL;
		AdjListNode *root = graph->array[i].head;
		while(root) {
			if(root->data == j) {
				if(prev == NULL)
					graph->array[i].head = root->next;
				else
					prev->next = root->next;
				break;
			}
			else {
				if(prev == NULL)
					prev = root;
				else
					prev = prev->next;
				root = root->next;
			}
		}
	};

	int degree(int i) {
		int count = 0;
		AdjListNode *root = graph->array[i].head;
		while(root) {
			count++;
			root = root->next;
		}
		return count;
	};

	int indegree(int j) {
		int count = 0;
		for(int i = 0; i < graph->V; i++) {
			AdjListNode *root = graph->array[i].head;
			while(root) {
				if(root->data == j)
					count++;
				root = root->next;
			}
		}
		return count;
	};
};
#endif /* ifndef ADJACENCY_LIST */