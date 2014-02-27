/*
贪心算法之最小生成树

伪代码：
MST-PRIM（G, w, r） 
	for each u in V[G]
		do key[u] <- INF
		   pi[u] <- NIL
	key[r] <- 0
	Q <- V[G]
	while Q != EMPTY
		do u <- EXTRACT-MIN(Q)
			for each v in Adj[u]
				do if v in Q and w(u, v) < key[v]
					then pi[v] <- u
						key[v] = w(u,v)

*/
#include <iostream>
#include <vector>
using namespace std;

#define INF 10000
#define NIL 0

//节点
struct Node {
	Node(int vertex, int key = INF) : vertex(vertex), key(key) {}
	int vertex;
	int key;
};

void swap(Node &a, Node &b) {
	Node tmp = a;
	a = b;
	b = a;
}

//对优先队列进行MIN_HEAPIFY操作，使队列保持最小堆的性质
void minHeapify(vector<Node> &Q, int i) {
	int left = 2 * i;
	int right = 2 * i + 1;
	int min = i;

	if (left <= Q.size() && Q[left-1].key < Q[i-1].key) {
		min = left;
	}
	if (right <= Q.size() && Q[right-1].key < Q[min-1].key) {
		min = right;
	}
	if (min != i) {
		swap(Q[min], Q[i]);
		minHeapify(Q, min);
	}
}

void prim(int adj[][4]) {
	vector<Node> Q;	//queue
	vector<int> P;  //parents
	for (int i=0; i != 4; i++) {
		Q.push_back(Node(i));
		P.push_back(NIL);
	}
	Q[0].key = 0;
	while (Q.size() > 0) {

	}
}

void main() {
	int adj[4][4] = {{0,9,6,4},{9,0,7,INF},{6,7,0,3},{4,INF,3,0}}; //adjacency matrix

	system("PAUSE");
}