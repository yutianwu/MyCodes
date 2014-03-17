#include <iostream>
using namespace std;

template <class T> 
class ChainNode {
	friend Chain<T>;
private:
	T data;
	ChainNode<T> *link;
};

template <class T>
class Chain {
public:
	Chain() { first = 0; }
	~Chain();
	bool IsEmpty() const { return first == 0;}
	int Length() const;
	bool Find(int k, T &x) const;
	int Search(const T &x) const;
	Chain<T>& Delete(int k, T &x);
	Chain<T>& Insert(int k, const T &x);
	void OutPut() const;
private:
	ChainNode<T> *first;
};

template <class T>
Chain<T>::~Chain() {
	ChainNode<T> *next;
	while (first) {
		next = first->link;
		delete first;
		first = next;
	}
}

template <class T>
int Chain<T>::Length() const {
	ChainNode<T> *current = first;
	int len = 0;
	while (current) {
		len++;
		current = current->link;
	}
	return len;
}

template <class T>
bool Chain<T>::Find(int k, T &x) const {
	if (k < 1) return false;
	ChainNode<T> *current = first;
	int index = 1;
	while (index < k && current) {
		current = current->link;
		index++;
	}
	if (current) {
		x = current->data;
		return true;
	} else {
		return false;
	}
}

template<class T> 
int Chain<T>::Search(const T &x) const {
	ChainNode<T> *current = first;
	int index = 1;
	while (current && current->data != x) {
		current = current->link;
		index++;
	}
	if (current) {
		return index;
	} else {
		return 0;
	}
}

template<class T>
void Chain<T>::OutPut() const {
	ChainNode<T> *current = first;
	while (current) {
		cout<<current->data<<" ";
		current = current->link;
	}
}

template<class T>
Chain<T> &Chain<T>::Delete(int k, T &x) {
	if (k < 1 || !first) {
		throw OutOfBounds();
	}
	ChainNode<T> *p = first;
	if ( k == 1) {
		first = first->link;
	} else {
		ChainNode<T> *q = first;
		for (int index = 1; index < k - 1 && q; index++) {
			q = q->link;
		}
		if (!q || !q->link) {
			throw OutOfBounds();
		} else {
			p = q->link;
			q->link = p->link;
			x = p->data;
			delete p;
			return *this; //this指针的解引用， 即Chain
		}
	}
}

template<class T>
Chain<T> &Chain<T>::Insert(int k, const T&x) {
	if (k < 0) throw OutOfBounds();
	ChainNode<T> *p = first;
	for (int index = 1; index < k && p; index ++) { //注意的是index < k
		p = p->link;
	}
	if (k >0 && !p) {
		throw OutOfBounds();
	}
	ChainNode<T> *y = new ChainNode<T>;
	y->data = x;
	if (k) {
		y->link = p->link;
		p->link = y;
	} else {
		y->link = first;
		first = y;
	}
	return *this;
}