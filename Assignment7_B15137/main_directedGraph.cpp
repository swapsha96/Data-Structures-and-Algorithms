#include "DirectedGraph.hpp"
#include <fstream>

void printIt(int &i) {
	std::cout << i << " ";
}

int main(int argc, char *argv[]) {
	int n, m, x, y, option;
	char mode;
	DirectedGraph *graph;
	if(argc == 1) {
		std::cin >> n >> m >> mode;
		graph = new DirectedGraph(n, mode);
		for(int i = 0; i < m; i++) {
			std::cin >> x >> y;
			graph->add(x, y);
		}
	}
	else if(argc == 2) {
		ifstream file;
		file.open(argv[1]);
		if(file.is_open()) {
			file >> n;
			file >> m;
			file >> mode;
			graph = new DirectedGraph(n, mode);
			for(int i = 0; i < m; i++) {
				file >> x;
				file >> y;
				graph->add(x, y);
			}
		}
		
	}
	else {
		return 0;
	}
	
	graph->print();
	while(1) {
		std::cout << "Choose:\n";
		std::cout << "1. Check if edge exists.\n";
		std::cout << "2. Number of edges.\n";
		std::cout << "3. Number of vertices.\n";
		std::cout << "4. Add edge.\n";
		std::cout << "5. Remove edge.\n";
		std::cout << "6. Indegree of vertex.\n";
		std::cout << "7. Breadth first search.\n";
		std::cout << "8. Depth first search.\n";
		std::cout << "9. Print.\n";
		std::cin >> option;
		switch(option) {
			case 1: {
				std::cin >> x >> y;
				std::cout << "Check if " << x << " - " << y << " exists: " << graph->edgeExits(x, y) << "\n";
			};
			break;
			case 2: {
				graph->edges();
			};
			break;
			case 3: {
				graph->vertices();
			};
			break;
			case 4: {
				std::cin >> x >> y;
				graph->add(x, y);
				graph->print();
			};
			break;
			case 5: {
				std::cin >> x >> y;
				graph->remove(x, y);
				graph->print();
			};
			break;
			case 6: {
				std::cin >> x;
				std::cout << "Degree of " << x << ": " << graph->indegree(x) << "\n";
			};
			break;
			case 7: {
				std::cout << "Breadth first search: ";
				graph->bfs(&printIt);
			};
			break;
			case 8: {
				std::cout << "Depth first search: ";
				graph->dfs(&printIt);
			};
			break;
			case 9: {
				graph->print();
			};
			break;
		}
	}

	return 0;
	// DirectedGraph *graph = new DirectedGraph(5, 'l');
	// graph->add(0, 3);
	// graph->add(0, 2);
	// graph->add(4, 0);
	// graph->add(2, 1);
	// graph->add(3, 1);
	// graph->add(3, 4);
	// graph->print();
	// std::cout << "Check if 0 - 1 exists: " << graph->edgeExits(0, 1) << "\n";
	// std::cout << "Check if 2 -> 3 exists: " << graph->edgeExits(2, 3) << "\n";
	// std::cout << "Indegree of 1: " << graph->indegree(1) << "\n";
	// std::cout << "Outdegree of 0: " << graph->outdegree(0) << "\n";
	// graph->edges();
	// graph->vertices();
	// graph->remove(0, 1);
	// graph->bfs();
	// graph->dfs();

	return 0;
}