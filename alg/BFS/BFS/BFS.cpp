#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

#define NIL		-1
#define WHITE	0
#define GRAY	1
#define BLACK	2

void BFS(vector<vector<int>> G, int s) {
	vector<int> color(G.size(), WHITE);
	vector<int> dist(G.size(), INT_MAX);
	vector<int> parent(G.size(), NIL);
	queue<int> Q;

	color[s] = GRAY;
	dist[s] = 0;
	Q.push(s);
	while (!Q.empty()) {
		int u = Q.front();
		Q.pop();
		cout<<u<<endl;
		for (int i = 0; i < G.size(); i++) {
			if (G[u][i] != INT_MAX) {
				if (color[i] == WHITE) {
					color[i] = GRAY;
					dist[i] = dist[u] + 1;
					Q.push(i);
				}
			}
		}
		color[u] = BLACK;
	}
}

void main() {
	vector<vector<int>> G;
	vector<int> row;
	row.push_back(INT_MAX);
	row.push_back(1);
	row.push_back(1);
	row.push_back(INT_MAX);
	G.push_back(row);
	row.clear();

	row.push_back(1);
	row.push_back(INT_MAX);
	row.push_back(INT_MAX);
	row.push_back(1);
	G.push_back(row);
	row.clear();

	row.push_back(1);
	row.push_back(INT_MAX);
	row.push_back(INT_MAX);
	row.push_back(INT_MAX);
	G.push_back(row);
	row.clear();

	row.push_back(INT_MAX);
	row.push_back(1);
	row.push_back(INT_MAX);
	row.push_back(INT_MAX);
	G.push_back(row);
	row.clear();

	BFS(G,0);
}