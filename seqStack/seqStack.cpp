#include <iostream>
#include "seqStack.h"
using namespace std;
 
template<class T>
seqStack<T>::seqStack(int stackCapacity):capacity(stackCapacity)
{
	if(capacity < 1)
	{
	    cout<<"stack initialize size should be >0"<<endl;	
		exit(1);
	} 
	stack = new T[capacity];
	top = -1;
}

template<class T> 
seqStack<T>::~seqStack()
{
	delete [] stack;
}

template<class T> 
inline bool seqStack<T>::isEmpty() const
{
	return top == -1;
}

template<class T> 
inline T& seqStack<T>::Top() const
{
	if( isEmpty() )
	{
		cout<<"stack is empty!"<<endl;
		exit(1);
	}
	
	return stack[top];
}

template<class T> 
void seqStack<T>::Push(const T& item)
{
	if( top == capacity-1 ) // stack is full
	{
		changeListSize(stack, capacity, capacity*2);
		capacity=capacity*2;
	}
	stack[++top] = item;	
}

template<class T> 
void seqStack<T>::Pop()
{
	if( isEmpty() )
	{
		cout<<"stack is empty! Cannot delete"<<endl;
		exit(1);
	}	
	stack[top--].~T();//调用类型析构 释放空间
	
	if(top*2*2 == capacity){ //出栈时释放过多的剩余空间 
		changeListSize(stack, capacity, capacity/2);
		capacity=capacity/2;
	}
	 
}

template<class T>
void seqStack<T>::printStack() const
{
	cout<<"Print the stack element:"<<endl;
	for(int i=top; i>=0; i--)
	{
		cout<<stack[i]<<endl;
	}
}

template<class T>
void changeListSize(T* &stack, const int oldSize, const int newSize)
{
	if( newSize < 0 )
	{
		cout<<"New length must be >=0"<<endl;
		exit(1);
	}
	T* temp = new T[newSize];
	if( temp == NULL )
	{
	    cout<<"malloc new size heap is error"<<endl;
		exit(1);	
	} 
	
	int number = min(oldSize, newSize);
	//将数组list中的number个元素复制到temp容器中
	std::copy(stack, stack+number, temp);
	
	if(stack != NULL)
	    delete[] stack;
	stack = temp; 
}

int main()
{
	seqStack<int> st;
	st.Push(99);
	st.Push(88);
	st.Push(77);
	st.Push(65);
	st.Push(55);
	st.Push(44);
	st.Push(33);
	st.Push(22);
	st.Push(11);
	st.Pop();
	st.Pop();
	st.Pop();
	st.Pop();
	st.Pop();
	st.Pop();

	cout<<"Top element is: "<<st.Top()<<endl;	
    st.printStack();
	
	
}
