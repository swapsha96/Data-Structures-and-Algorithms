#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include "UndirectedGraph.hpp"

using namespace std;



int options(){

	cout<<"\n[1] Add an edge\n";
	cout<<"[2] Remove an edge\n";
	cout<<"[3] Check an edge\n";
	cout<<"[4] Degree of a vertex\n";
	cout<<"[5] No. of vertices\n";
	cout<<"[6] No. of edges\n";
	cout<<"[7] DFS\n";
	cout<<"[8] BFS\n";
	cout<<"[9] Kruskal\n";
	cout<<"[10] Prim\n";
	cout<<"[0] Exit\n";

	int choice;
	cout<<"Enter choice : ";
	cin>>choice;

	return choice;
}

void readFromFile(UndirectedGraph& graph){

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

void print(int& i){
	cout<<i<<"\n";
}

void print(int& u, int& v, int& w){
	cout<<u<<"->"<<v<<" : "<<w<<endl;
}

int main(){

	int nVertices;
	char mode;
	int src, dest, weight;

	cout<<"Enter mode of implementation(m: Adjacency matrix | l: Adjacency list) : ";
	cin>>mode;

	cout<<"Enter no. of vertices : ";
	cin>>nVertices;
	
	UndirectedGraph graph(nVertices, mode);

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

						graph.add(src, dest, weight);
					
						break;

			case 2 :	cout<<"Enter source : ";
						cin>>src;
						cout<<"Enter destination : ";
						cin>>dest;

						graph.remove(src, dest);
						
						break;

			case 3 :	cout<<"Enter source : ";
						cin>>src;
						cout<<"Enter destination : ";
						cin>>dest;

						if(graph.edgeExists(src, dest))
							cout<<"Edge exists.";
						else
							cout<<"Edge does not exists.";
					
						break;

			case 4 :	cout<<"Enter vertex : ";
						cin>>src;

						cout<<"Degree["<<src<<"] : "<<graph.degree(src);
						break;

			case 5 :	cout<<graph.vertices();
						break;

			case 6 :	cout<<graph.edges();
						break;

			case 7 :	graph.dfs(print);
						break;

			case 8 :	graph.bfs(print);
						break;

			case 9 :	try{
							graph.kruskal(print);
						}
						catch(const char* err){
							cout<<err<<endl;
						}
						break;
			case 10 :	try{
							graph.primMST();
						}
						catch(const char* err){
							cout<<err<<endl;
						}
						break;

			case 0 :	exit(EXIT_SUCCESS);

			default :	cout<<"Invalid Choice.";

		}
	}

	return 0;
}