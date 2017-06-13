#include <iostream>
#include "UFDS.hpp"
#include "AdjacencyList.hpp"
#include "UndirectedGraph.hpp"

using namespace std;

int minSpanningTree(AdjacencyList* graph,int src,int dest,int& ans);

int main(int argc,char* argv[]){

	int stations,patrol;
	int src,dest,cost;
	int ques,ans;

	cout<<"Enter the number of stations and patrol routes"<<endl;
	cin>>stations>>patrol;

	AdjacencyList kingdom(stations);

	for(int i=0 ; i<patrol ; i++){

		cin>>src>>dest>>cost;
		kingdom.add(src,dest,cost);

	}

	cin>>ques;
	ans = 0;

	for(int i=0 ; i<ques ; i++){

		cin>>src>>dest;
		minSpanningTree(&kingdom,src,dest,ans);
	}

	cout<<ans<<endl;

	return 0;
}

int minSpanningTree(AdjacencyList* graph,int src,int dest,int& ans){

  	LinearList<LinearList<edge> > edges = graph->getAdjacent();  
  	LinearList<edge> allEdges(graph->edges());

  	for(int i = 0; i < graph -> vertices(); i++){
  		for(int j = 0; j < edges[i].size(); j++){
      		allEdges.push_back(edges[i][j]);
    	}
  	}
    	
  	qsort(&allEdges[0], allEdges.size(), sizeof(edge), edgeCompare);

  	UFDS sets(graph -> vertices());

  	int u = 0, v;
  	int weight;

  	while(sets.num_disjoint_sets() != 1){
  
    	if(allEdges.size() == 0)
      		throw "Graph is incomplete.";
    
    	u = allEdges[0].src;
    	v = allEdges[0].dest;

    	weight = allEdges[0].weight;
    	allEdges.erase_pos(0);


    	if(!sets.is_same_set(u, v)){

      		if((u == src and v == dest) or (u == dest and v == src)){
      			ans++;
      		}
      		sets.union_set(u, v);
    	}
  	}

  	return ans;
}