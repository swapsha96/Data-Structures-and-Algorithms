
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "DirectedGraph.hpp"

using namespace std;

void readFromFile(DirectedGraph& graph){

	ifstream read;

	string filePath;

	cout<<"Enter address of input file : ";
	cin>>filePath;

	read.open(filePath.c_str(), ios::in);

	if(!read.is_open()){
		cout<<"Invalid file.\n";
		return;
	}

	int data, counter = 0;
	while(!read.eof()){

		read >> data;

		if(data == 1)
			graph.add(counter/graph.vertices(), counter%graph.vertices(), data);
		
		counter++;
	}
}

int options(){

	cout<<"\n[1] Add an edge\n";
	cout<<"[2] Remove an edge\n";
	cout<<"[3] Check an edge\n";
	cout<<"[4] In Degree of a vertex\n";
	cout<<"[5] Out Degree of a vertex\n";
	cout<<"[6] No. of vertices\n";
	cout<<"[7] No. of edges\n";
	cout<<"[8] DFS\n";
	cout<<"[9] BFS\n";
	cout<<"[0] Exit\n";

	int choice;
	cout<<"Enter choice : ";
	cin>>choice;

	return choice;
}

void print(int& i){
	cout<<i<<endl;
}

void print(int& u, int& v, int& w){
	cout<<u<<"->"<<v<<" : "<<w<<endl;
}

int main(){

	int nVertices;
	char mode;
	int src, dest, weight;

	cout<<"Mode of implementation(m: Adjacency matrix | l: Adjacency list) : ";
	cin>>mode;

	cout<<"Enter no. of vertices : ";
	cin>>nVertices;
	
	DirectedGraph graph(nVertices, mode);

	char choice;
	cout<<"Do you want to give input from file (y/n) : ";
	cin>>choice;

	if(choice == 'y' || choice == 'Y')
		readFromFile(graph);

	while(1){
		switch(options()){

			case 1 :	cout<<"Enter source : ";
						cin>>src;
						cout<<"Enter destination : ";
						cin>>dest;
						cout<<"Enter weight : ";
						cin>>weight;

						try{
							graph.add(src, dest, weight);
						}
						catch(const char* err){
							cout<<err<<endl;
						}
						break;

			case 2 :	cout<<"Enter source : ";
						cin>>src;
						cout<<"Enter destination : ";
						cin>>dest;

						try{
							graph.remove(src, dest);
						}
						catch(const char* err){
							cout<<err<<endl;
						}
						break;

			case 3 :	cout<<"Enter source : ";
						cin>>src;
						cout<<"Enter destination : ";
						cin>>dest;

						if(graph.edgeExists(src, dest))
							cout<<"Edge exists.\n";
						else
							cout<<"Edge does not exists.\n";

						break;

			case 4 :	cout<<"Enter vertex : ";
						cin>>src;

						cout<<"In Degree["<<src<<"] : "<<graph.indegree(src)<<endl;
	
						break;

			case 5 :	cout<<"Enter vertex : ";
						cin>>src;

						cout<<"Out Degree["<<src<<"] : "<<graph.outdegree(src)<<endl;
						
						break;

			case 6 :	cout<<graph.vertices()<<endl;
						break;

			case 7 :	cout<<graph.edges()<<endl;
						break;

			case 8 :	graph.dfs(print);
						break;

			case 9 :	graph.bfs(print);
						break;

			case 0 :	exit(EXIT_SUCCESS);

			default :	cout<<"Invalid Choice.\n";

		}
	}

	return 0;
}