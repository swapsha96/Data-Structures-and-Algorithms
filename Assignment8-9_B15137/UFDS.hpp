#ifndef UFDS_
#define UFDS_ 1

#include "seqLinearList.hpp"

namespace cs202 {

class UFDS {
  // Private attributes and functions for class
  // If you want to add any more variables, please add them
  // and give a valid reason for their use.
  // DO NOT DELETE ANY OF THE MEMBERS FROM BELOW
  // YOU NEED TO USE THEM ALL.

  // node in consideration for union find data structure
  // stores parent and rank for each vertex
  // You may add new members to the node, with explanation as to
  // why the members were necessary.
  class node {
    public:
      int parent;
      int rank;

      node(){}
    //creates an instance with given parent p and rank r
      node(int p, int r){
      	parent = p;
      	rank = r;
      }
  };

  LinearList<node> vertex;
  int nDisjoint;

  public:
    // Create an empty union find data structure with N isolated sets.
    UFDS(const unsigned int& N);

    // Default constructor
    ~UFDS(){}

    // Make a new set with N vertices with all sets being disjoint
    void make_set (const unsigned int& N);

    // Return the representative / parent of set consisting of object x.
    int find_set (const unsigned int& x);
    
    // Unite sets containing objects x and y.
    void union_set (const unsigned int& x, const unsigned int& y);
    
    // Are objects x and y in the same set?
    bool is_same_set (const unsigned int& x, const unsigned int& y);

    // Return the number of disjoint sets.
    int num_disjoint_sets();
    
    // Return the size of the set containing object x.
    int size_set (const unsigned int& x); 

 	//return parent of object x
 	int parent(const unsigned int& x);
  };    

	UFDS::UFDS(const unsigned int& N){

		vertex.resize(N);

		for(int i = 0; i < N; i++)
			vertex.push_back(node(i, 0));

		nDisjoint = N;
	}

	void UFDS::make_set(const unsigned int& N){

		for(int i = 0; i < vertex.size(); i++){
			vertex.erase_pos(i);
		}

		vertex.resize(N);

		for(int i = 0; i < N; i++)
			vertex.push_back(node(i, 0));	

		nDisjoint = N;
	}

	int UFDS::find_set (const unsigned int& x){

		if(x != vertex[x].parent)
			return find_set(vertex[x].parent);
		else
			return x;
	}

	void UFDS::union_set (const unsigned int& x, const unsigned int& y){

		int parent, Node;

		if(vertex[x].rank > vertex[y].rank){
			parent = find_set(x);	
			Node = find_set(y);
		}
		else{
			parent = find_set(y);
			Node = find_set(x);
		}

		vertex[Node].parent = parent;

		if(vertex[parent].rank == vertex[Node].rank)
			vertex[parent].rank += 1;

		nDisjoint--; 
	}

	bool UFDS::is_same_set (const unsigned int& x, const unsigned int& y){

		return (find_set(x) == find_set(y));
	}

	int UFDS::num_disjoint_sets(){

		return nDisjoint;
	}

	int UFDS::size_set (const unsigned int& x){

		return vertex[x].rank + 1;
	}

	int UFDS::parent(const unsigned int& x){
	 	return vertex[x].parent;
	 }

}

#endif  /* UFDS_ */
