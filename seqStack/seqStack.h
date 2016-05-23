#ifndef _SEQSTACK_H
#define _SEQSTACK_H
template<class T>
class seqStack
{
public:
	seqStack(int stackCapacity = 2);
	~seqStack();
	
	bool isEmpty() const;
	T& Top() const;
	void Push(const T& item);
	void Pop();
	void printStack() const;
private:
	T *stack;
	int top;
	int capacity;
	
};

template<class T>
void changeListSize(T* &stack, const int oldSize, const int newSize);
#endif


