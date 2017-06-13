#ifndef UNDIRECTED_GRAPH
#define UNDIRECTED_GRAPH 1
/*
 * A class to represent an UndirectedGraph
 * Subclasses AbstractGraph
 */
#include "AbstractGraph.hpp"
#include "AdjacencyMatrix.hpp"
#include "AdjacencyList.hpp"
#include "stack.hpp"
#include "queue.hpp"

class UndirectedGraph : public AbstractGraph {
private:
	AdjacencyMatrix *m;
	AdjacencyList *l;
	char mode;
public:
  /*
   * Constructor: UndirectedGraph
   *
   * Parameters: mode
   * Used to decide which representation to use
   * 'm' for AdjacencyMatrix
   * 'l' for AdjacencyList
   */
	UndirectedGraph() {

	};

	UndirectedGraph(int vertices, char mode) {
		if(mode == 'l') {
			l = new AdjacencyList(vertices);
		}
		else {
			m = new AdjacencyMatrix(vertices);
		}
		this->mode = mode;
	};

	void add(int i, int j) {
		if(mode == 'l') {
			l->add(i, j);
			l->add(j, i);
		}
		else {
			m->add(i, j);
			m->add(j, i);
		}
	};

	bool edgeExits(int i, int j) {
		if(mode == 'l') {
			return l->edgeExits(i, j);
		}
		else {
			return m->edgeExits(i, j);
		}
	};

	void edges() {
		if(mode == 'l') {
			std::cout << "Number of edges: " << l->edges()/2 << "\n";
		}
		else {
			std::cout << "Number of edges: " << m->edges()/2 << "\n";
		}
	};

	void vertices() {
		if(mode == 'l') {
			std::cout << "Number of vertices: " << l->vertices() << "\n";
		}
		else {
			std::cout << "Number of vertices: " << m->vertices() << "\n";
		}
	};

	void remove(int i, int j) {
		if(mode == 'l') {
			l->remove(i, j);
			l->remove(j, i);
			std::cout << "Deleted " << i << " - " << j << "\n";
		}
		else {
			m->remove(i, j);
			m->remove(j, i);
			std::cout << "Deleted " << i << " - " << j << "\n";
		}
	};

	void dfs(void (*work)(int&)) {
		if(mode == 'l') {
			int s = 0;
			bool *visited = new bool[l->vertices()];
			for(int i = 0; i < l->vertices(); i++) {
				visited[i] = false;
			}
			
			cs202::stack<int> *stack = new cs202::stack<int>();
			stack->push(s);

			while(!stack->empty()) {
				s = stack->top();
				stack->pop();
				if(!visited[s]) {
					std::cout << s << " ";
					visited[s] = true;
				}

				for(int i = 0; i < l->vertices(); i++) {
					if(l->edgeExits(s, i) && !visited[i])
						stack->push(i);
				}
			}

			std::cout << "\n";
		}
		else {
			int s = 0;
			bool *visited = new bool[m->vertices()];
			for(int i = 0; i < m->vertices(); i++) {
				visited[i] = false;
			}
			
			cs202::stack<int> *stack = new cs202::stack<int>();
			stack->push(s);

			while(!stack->empty()) {
				s = stack->top();
				stack->pop();
				if(!visited[s]) {
					work(s);
					visited[s] = true;
				}

				for(int i = 0; i < m->vertices(); i++) {
					if(m->edgeExits(s, i) && !visited[i])
						stack->push(i);
				}
			}
			std::cout << "\n";
		}
	};

	void bfs(void (*work)(int&)) {
		if(mode == 'l') {
			int s = 0;
			bool *visited = new bool[l->vertices()];
			for(int i = 0; i < l->vertices(); i++)
				visited[i] = false;

			cs202::queue<int> *queue = new cs202::queue<int>();
			visited[s] = true;
			queue->push(s);

			while(!queue->empty()) {
				s = queue->front();
				work(s);
				queue->pop();

				for(int i = 0; i < l->vertices(); i++) {
					if(s!= i && l->edgeExits(s, i) && !visited[i]) {
						visited[i] = true;
						queue->push(i);
					}
				}
			}
			std::cout << "\n";
		}
		else {
			int s = 0;
			bool *visited = new bool[m->vertices()];
			for(int i = 0; i < m->vertices(); i++)
				visited[i] = false;

			cs202::queue<int> *queue = new cs202::queue<int>();
			visited[s] = true;
			queue->push(s);

			while(!queue->empty()) {
				s = queue->front();
				std::cout << s << " ";
				queue->pop();

				for(int i = 0; i < m->vertices(); i++) {
					if(s!= i && m->edgeExits(s, i) && !visited[i]) {
						visited[i] = true;
						queue->push(i);
					}
				}
			}
			std::cout << "\n";
		}
	};

	void print() {
		if(mode == 'l') {
			l->print();
		}
		else {
			m->print();
		}
	};

	int degree(int i) {
		if(mode == 'l') {
			return l->degree(i);
		}
		else {
			return m->degree(i);
		}
	};
};
#endif /* ifndef UNDIRECTED_GRAPH */