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
#define NIL -1

//节点
struct Node {
	Node(int vertex = 0, int key = INF) : vertex(vertex), key(key) {}

	int vertex;
	int key;
};

void swap(Node &a, Node &b) {
	Node tmp = a;
	a = b;
	b = tmp;
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
		swap(Q[min - 1], Q[i - 1]);
		minHeapify(Q, min);
	}
}

//取出优先队列中最小的
Node extractMin(vector<Node> &Q) {
	Node min = NULL;

	if (Q.size() < 1) {
		return min;
	}
	min = Q[0];
	Q[0] = Q[Q.size() - 1];
	Q.pop_back();
	minHeapify(Q, 1);
	
	return min;
}

//DECERSE-KEY
void decreaseKey(vector<Node> &Q, int i, int key) {
	if (Q[i-1].key < key) {
		return;
	}

	Q[i-1].key = key;
	while (i > 1 && Q[i/2 - 1].key > key) {
		swap(Q[i- 1], Q[i/2 - 1]);
		i = i/2;
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
		Node u = extractMin(Q);
		for (vector<Node>::size_type j = 0; j != Q.size(); j++) {
			if (Q[j].key > adj[u.vertex][Q[j].vertex]) {
				P[Q[j].vertex] = u.vertex;
				decreaseKey(Q, j+1, adj[u.vertex][Q[j].vertex]);
			}
		}
	}

	for (vector<int>::size_type j = 0; j != P.size(); j++) {
		cout<<P[j]<<endl;
	}
}

void main() {
	int adj[4][4] = {{0,9,6,4},{9,0,7,INF},{6,7,0,3},{4,INF,3,0}}; //adjacency matrix
	prim(adj);
	vector<Node> node;
	node.push_back(Node(1));
	cout<<node[0].key;
	system("PAUSE");
}