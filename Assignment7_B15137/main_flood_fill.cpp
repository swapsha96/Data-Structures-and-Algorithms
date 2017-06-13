#include <iostream>
#include <fstream>
#include <stack>
#include <random>
#include <stdlib.h>
#include <time.h>
using namespace std;

stack<int> *q_x = new stack<int>();
stack<int> *q_y = new stack<int>();
int r = 0;

bool DFS(int x, int y, bool **visited, int m, int n, int **matrix, int dest_x, int dest_y) {
	if(x >= m || y >= n)
		return false;
	if(x < 0 || y < 0)
		return false;
	if(visited[x][y] == true)
		return false;
	if(matrix[x][y] == 1)
		return false;
	if(x == dest_x && y == dest_y) {
		q_x->push(x);
		q_y->push(y);
		return true;
	}
	visited[x][y] = true;
	bool *check = new bool[8];
	for(int i = 0; i < 8; i++) {
		check[i] = false;
	}
	while(1) {
		bool flag = true;
		for(int i = 0; i < 8; i++)
			if(check[i] == false) {
				flag = false;
				break;
			}

		if(flag == true)
			break;

		r = rand()%8;
		switch(r) {
			case 0: {
				if(DFS(x-1, y-1, visited, m, n, matrix, dest_x, dest_y) == true) {
					q_x->push(x);
					q_y->push(y);
					check[0] = true;
					return true;
				}
			}
			break;
			case 1: {
				if(DFS(x-1, y, visited, m, n, matrix, dest_x, dest_y) == true) {
					q_x->push(x);
					q_y->push(y);
					check[1] = true;
					return true;
				}
			}
			break;
			case 2: {
				if(DFS(x-1, y+1, visited, m, n, matrix, dest_x, dest_y) == true) {
					q_x->push(x);
					q_y->push(y);
					check[2] = true;
					return true;
				}
			}
			break;
			case 3: {
				if(DFS(x, y-1, visited, m, n, matrix, dest_x, dest_y) == true) {
					q_x->push(x);
					q_y->push(y);
					check[3] = true;
					return true;
				}
			}
			break;
			case 4: {
				if(DFS(x, y+1, visited, m, n, matrix, dest_x, dest_y) == true) {
					q_x->push(x);
					q_y->push(y);
					check[4] = true;
					return true;
				}
			}
			break;
			case 5: {
				if(DFS(x+1, y-1, visited, m, n, matrix, dest_x, dest_y) == true) {
					q_x->push(x);
					q_y->push(y);
					check[5] = true;
					return true;
				}
			}
			break;
			case 6: {
				if(DFS(x+1, y, visited, m, n, matrix, dest_x, dest_y) == true) {
					q_x->push(x);
					q_y->push(y);
					check[6] = true;
					return true;
				}
			}
			break;
			case 7: {
				if(DFS(x+1, y+1, visited, m, n, matrix, dest_x, dest_y) == true) {
					q_x->push(x);
					q_y->push(y);
					check[7] = true;
					return true;
				}
			}
			break;
		}
	}

	return false;
}

int main(int argc, char*argv[]) {
	int m, n;
	ifstream file;
	file.open(argv[1]);
	file >> m >> n;
	int **matrix;
	bool **visited;
	matrix = new int*[m];
	visited = new bool*[m];

	for(int i = 0; i < m; i++) {
		matrix[i] = new int[n];
		visited[i] = new bool[n];
		for(int j = 0; j < n; j++) {
			file >> matrix[i][j];
			visited[i][j] = false;
		}
	}
	int x, y, dest_x, dest_y;
	file >> x >> y >> dest_x >> dest_y;

	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}
	srand((unsigned)time(NULL));
	DFS(x, y, visited, m, n, matrix, dest_x, dest_y);
	// q_x->push(dest_x);
	// q_y->push(dest_y);
	while(q_x->size() != 0) {
		cout << "(" << q_x->top() << "," << q_y->top() << ") ";
		q_x->pop();
		q_y->pop();
	}
	cout << "\n";

	// for(int i = 0; i < m; i++) {
	// 	for(int j = 0; j < n; j++) {
	// 		cout << matrix[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }
}