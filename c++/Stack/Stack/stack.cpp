#include <iostream>
using namespace std;

template<class T>
class Stack {
public:
	Stack(int MaxStackSize = 100);
	
	~Stack() { delete []stack}
	
	bool IsEmpty() {
		return top == -1;
	}

	bool isFull() {
		return top == MaxTop;
	}
	
	T Top() const;

	Stack<T> &Add(const T &x);

	Stack<T> &Delete(T &x);
private:
	int top;
	int MaxTop;
	T *stack;
};

template<class T>
Stack<T>::Stack(int MaxStackSize) {
	MaxTop = MaxStackSize - 1;
	stack = new T[MaxStackSize];
	top = -1;  //×¢Òâ topÎª-1
}

template<class T>
T Stack<T>::Top() const {
	if (IsEmpty()) { 
		throw OutOfBounds();
	} else {
		return stack[top];
	}
}

template<class T>
Stack<T> &Stack<T>::Add(const T &x) {
	if (IsFull()) {
		throw NoMem();
	} else {
		stack[++top] = x;
		return *this;
	}
}

template<class T>
Stack<T> &Stack<T>::Delete(T &x) {
	if( IsEmpty() ) {
		throw OutOfBounds();
	} else {
		x = stack[top--];
		return *this;
	}
}