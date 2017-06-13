#ifndef DIRECTED_GRAPH
#define DIRECTED_GRAPH 1
#include "AbstractGraph.hpp"
#include "AdjacencyMatrix.hpp"
#include "AdjacencyList.hpp"
#include "stack.hpp"
#include "queue.hpp"
/*
 * A class to represent a directed graph.
 */
class DirectedGraph : public AbstractGraph {
private:
    AdjacencyMatrix *m;
    AdjacencyList *l;
    char mode;
public:
    DirectedGraph() {

    };
  /*
   * Constructor: DirectedGraph
   *
   * Parameters: mode
   * Used to decide which representation to use
   * 'm' for AdjacencyMatrix
   * 'l' for AdjacencyList
   */
    DirectedGraph(int numVertices, char rep) {
        if(rep == 'l') {
            l = new AdjacencyList(numVertices);
        }
        else {
            m = new AdjacencyMatrix(numVertices);
        }
        this->mode = rep;
    };
  /*
   * Function: indegree
   * Returns the indegree of a vertex
   */
    int indegree(int i) {
        if(mode == 'l') {
            return l->indegree(i);
        }
        else {
            return m->indegree(i);
        }
    };
  /*
   * Function: outdegree
   * Returns the outdegree of a vertex.
   */
    int outdegree(int j) {
        if(mode == 'l') {
            return l->degree(j);
        }
        else {
            return m->degree(j);
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
            std::cout << "Number of edges: " << l->edges() << "\n";
        }
        else {
            std::cout << "Number of edges: " << m->edges() << "\n";
        }
    };

    void vertices()  {
        if(mode == 'l') {
            std::cout << "Number of vertices: " << l->vertices() << "\n";
        }
        else {
            std::cout << "Number of vertices: " << m->vertices() << "\n";
        }
    };

    void add(int i, int j) {
        if(mode == 'l') {
            l->add(i, j);
        }
        else {
            m->add(i, j);
        }
    };

    void remove(int i, int j) {
        if(mode == 'l') {
            l->remove(i, j);
            std::cout << "Deleted " << i << " -> " << j << "\n";
        }
        else {
            m->remove(i, j);
            std::cout << "Deleted " << i << " -> " << j << "\n";
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
                    work(s);
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
                work(s);
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
};
#endif /* ifndef DIRECTED_GRAPH */