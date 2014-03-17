#include <iostream>
using namespace std;

template<class E, class K>
class HashTable {
public:
	HashTable(int divisor = 11);
	
	~HashTable() {
		delete []ht;
		delete []empty;
	}

	bool Search(const K &k, E &e) const;

	HashTable<E, K> &Insert(const E &e);

private:
	int hSearch(const K &k) const;
	int D;	//散列的除数
	E *ht;  //散列数组
	bool *empty; //一维数组
};

template<class E, class K>
HashTable<E, K>::HashTable(int divisor) {
	D = divisor;

	ht = new E[D];
	empty = new bool[D];
	
	for (int i=0; i < D; i++) {
		empty[i] = true;
	}
}


template<class E, class K>
int HashTable<E, K>::hSearch(const K &k) const {
	int i = k % D;
	int j = i;
	
	do{
		if (empty[j] || ht[j] == k) {
			return j;
		}
		j = (j + 1) % D;
	} while (j != i);
	
	return j;
}

template<class E, class K>
bool HashTable<E, K>::Search(const K &k, E &e) const {
	int b = hSearch(k);
	if (empty[b] || ht[b] != k) {
		return false;
	}
	e = ht[b];
	return true;
}

template<class E, class K>
HashTable<E, K> &HashTable<E, K>::Insert(const E &e) {
	K k = e;
	int b =  hSearch(k);

	if(empty[b]) {
		empty[b] = false;
		ht[b] = e;
		return *this;
	}

}  