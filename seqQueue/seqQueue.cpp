#include <iostream>
#include "seqQueue.h"
using namespace std;

template<class T>
Queue<T>::Queue(int queueCapacity):capacity(queueCapacity)
{
	if(capacity < 1)
	{
		cout<<"Queue capacity must be > 1"<<endl;
		exit(1);
	} 
	queue = new T[capacity];
	front = rear = 0;
}

template<class T>
inline bool Queue<T>::isEmpty() const
{
	return front == rear;
} 

template<class T>
void Queue<T>::Push(const T& item)
{

	if( (rear+1) % capacity == front) //队列满了 
	{
		T* newQueue = new T[capacity * 2];
		int start = (front + 1) % capacity;//队首位置 判断有没有发生回绕
		if(start < 2) // front默认为0,所以start<2时没有发生回绕 no wrap
		{
			copy(queue+start, queue+start+capacity-1, newQueue);//将有队列数据部分拷贝到新队列 
			
		}else //发生了回绕 wrap 分两次拷贝 
		{
			copy(queue+start, queue+capacity,newQueue);//将队首的开始数据到数组最后一个数据拷贝到新队列 
			copy(queue, queue+rear+1,newQueue+capacity-start);//将队首的开始数据到数组最后一个数据拷贝到新队列
			                                                //rear+1是rear是数组下标，而我们需要拷贝的长度 
		}
		
		front = 2 * capacity -1;//新的队首位新的数组的最大下标 
		rear = capacity - 2;//capacity-1等于数组下标最大值，再-1减去之前空的队首所占空间 
		capacity *= 2;
		delete [] queue;
		queue = newQueue;
	}
	/*
	if( rear = capacity-1)
		rear = 0;
	else
	    rear++;
	*/
	rear = (rear+1) % capacity;//与上面注释的代码一样 判断是否发生回绕 
	queue[rear] = item;  

}

template<class T>
inline T& Queue<T>::Front() const
{
	if(isEmpty())
	{
		cout<<"Queue is Empty"<<endl;
		exit(1);
	}
	return queue[(front+1) % capacity];//队首时刻指向空的 队首的值需要加1 
}
 
template<class T>
inline T& Queue<T>::Rear() const
{
	if(isEmpty())
	{
		cout<<"Queue is Empty"<<endl;
		exit(1);
	}
	return queue[rear];
}
 
template<class T>
void Queue<T>::Pop()
{
 	if( isEmpty() )
	{
		cout<<"Queue is Empty"<<endl;
		exit(1);
	}
	
	front = (front + 1) % capacity;
		
	queue[front].~T();//释放空间
	queue[front] = ' ';
	
	/*如果当前队列元素为队列长度的4分之一 节省一半空间*/ 
	int count = (rear-front+1+capacity) % capacity;//循环队列元素个数
	if( count*2*2 == capacity)  
	{
		T* newQueue = new T[capacity / 2];
		copy(queue+front, queue+front+count, newQueue);			
		capacity /= 2;
		front = 0;
		rear = count -1;
		delete []queue;
		queue = newQueue;		
	} 

} 


int main()
{
	Queue<char> q;
	q.Push('A');
	q.Push('B');
	q.Push('C');
	q.Push('D');
	q.Push('E');
	q.Push('F');
	q.Push('G');
	q.Push('H');
	q.Push('I');
	
	q.Pop();
	q.Pop();
	q.Pop();
	q.Pop();
	q.Pop();
	q.Pop();
	
	cout<<"Front: "<<q.Front()<<" , Rear: "<<q.Rear()<<endl;
		
} 

