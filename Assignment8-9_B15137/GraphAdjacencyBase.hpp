#ifndef GRAPH_ADJACENCY_BAG
#define GRAPH_ADJACENCY_BAG 1

#include "list.hpp"

//to store destination and weight of an edge
class edge{

public:

	int src;
	int dest;
	int weight;

	edge(){}

	edge(int s, int d, int w){
		src = s;
		dest = d;
		weight = w;
	}

	bool operator==(const edge& p){
		return (dest == p.dest && src == p.src);
	}

	void operator=(const edge& p){
		src = p.src;
		dest = p.dest;
		weight = p.weight;
	}

	bool operator!=(const edge& p){
		return (dest != p.dest || src != p.src);
	}

	bool operator>(const edge& p){
		return (weight > p.weight);
	}

	bool operator<(const edge& p){
		return (weight < p.weight);
	}

	bool operator>=(const edge& p){
		return (weight >= p.weight);
	}

	bool operator<=(const edge& p){
		return (weight <= p.weight);
	}
};

//to store destination and weight of an edge
class vertexHeap{

public:

	int v;
	int weight;

	vertexHeap(){
			
	}

	vertexHeap(int s, int w){
		
		v = s;
		weight = w;
	}

	bool operator==(const vertexHeap& p){
		return (v == p.v);
	}

	void operator=(const vertexHeap& p){
		v = p.v;
		weight = p.weight;
	}

	bool operator!=(const vertexHeap& p){
		return (v != p.v);
	}

	bool operator>(const vertexHeap& p){
		return (weight > p.weight);
	}

	bool operator<(const vertexHeap& p){
		return (weight < p.weight);
	}

	bool operator>=(const vertexHeap& p){
		return (weight >= p.weight);
	}

	bool operator<=(const vertexHeap& p){
		return (weight <= p.weight);
	}
};


using namespace cs202;
/*
/*
 * A base class which can denote any Graph Adjacency representation.
 * Subclasse by AdjacencyMatrix and AdjacencyList
 * Use this class in your graphs to be able to select any representation as desired by the user.
 */
class GraphAdjacencyBase {
public:

	GraphAdjacencyBase(){}
	/* Destructor:
	 * releases all resources acquired by the class
	 */
  virtual ~GraphAdjacencyBase(){}
	/*
	 * Function: edgeExists
	 * Returns true if an edge exists between vertices i and j, false otherwise.
	 */
  virtual bool edgeExists(int i, int j) = 0;
	/*`
	 * Function: vertices
	 * Returns the number of vertices in the adjacency structure.
	 */
  virtual int vertices() = 0;
	/*
	 * Function: edges
	 * Returns the number of edges in the adjacency structure.
	 */
  virtual int edges() = 0;
	/*
	 * Function add:
	 * Adds an edge between vertices i and j
	 */
  virtual void add(int i, int j, int w) = 0;
	/*
	 * Function: remove
	 * Deleted the edge between vertices i and j
	 */
  virtual void remove(int i, int j) = 0;
	/*
	 * Function: degree
	 * Returns the degree of the vertex i
	 */
  virtual int degree(int i) = 0;
  /*
   * Function: getAdjacent
   * Returns array of adjacent nodes of vertex i
   */ 
  virtual LinearList<LinearList<edge> > getAdjacent() = 0;
};
#endif /* ifndef GRAPH_ADJACENCY_BAG */