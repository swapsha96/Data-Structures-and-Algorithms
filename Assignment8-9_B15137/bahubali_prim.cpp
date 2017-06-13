#include <iostream>
#include "UFDS.hpp"
#include "AdjacencyList.hpp"
#include "UndirectedGraph.hpp"

using namespace std;

int* minSpanningTree(AdjacencyList* graph);

int main(int argc,char* argv[]){

	int stations,patrol;
	int src,dest,cost;
	int ques,ans;

	cout<<"Enter the number of stations and patrol routes"<<endl;
	cin>>stations>>patrol;

	AdjacencyList mahishmati(stations);

	for(int i=0 ; i<patrol ; i++){

		cin>>src>>dest>>cost;
		mahishmati.add(src,dest,cost);

	}

	cin>>ques;
	ans = 0;
    int* mst = minSpanningTree(&mahishmati);

	for(int i=0 ; i<ques ; i++){

		cin>>src>>dest;
        if(mst[dest] == src or mst[src] == dest){
            ans++;
        }

	}

	cout<<ans<<endl;

	return 0;
}

int* minSpanningTree(AdjacencyList* graph){

  	LinearList<LinearList<edge>> edges = graph -> getAdjacent();

    const int no_of_vertices = graph -> vertices();

    int* parent = new int[no_of_vertices];
    int* visited = new int[no_of_vertices];
    int* key = new int[no_of_vertices];
    
    MinPriorityQueue<vertexHeap> heap;

    for(int i=0 ; i < no_of_vertices ; i++){
        parent[i] = -1;
        visited[i] = 0;
    }

    for(int i=0 ; i < no_of_vertices ; i++){
        heap.insert(vertexHeap(i,INT_MAX));
        key[i] = INT_MAX;
    }

    heap.heap_decrease_key(0);

    while(!heap.empty()){

        vertexHeap u = heap.extract_min();
        visited[u.v] = 1;

        for(int i=0 ; i< edges[u.v].size() ; i++){

            edge v = edges[u.v][i];

            if(visited[v.dest] == 0){

                if(v.weight < key[v.dest]){
                 
                    key[v.dest] = v.weight;
                    heap.heap_decrease_key(v.dest,vertexHeap(v.dest,v.weight));
                    parent[v.dest] = v.src; 
                
                }

            }
        }
    }

    return parent;
}