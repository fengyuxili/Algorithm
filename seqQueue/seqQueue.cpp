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

	if( (rear+1) % capacity == front) //�������� 
	{
		T* newQueue = new T[capacity * 2];
		int start = (front + 1) % capacity;//����λ�� �ж���û�з�������
		if(start < 2) // frontĬ��Ϊ0,����start<2ʱû�з������� no wrap
		{
			copy(queue+start, queue+start+capacity-1, newQueue);//���ж������ݲ��ֿ������¶��� 
			
		}else //�����˻��� wrap �����ο��� 
		{
			copy(queue+start, queue+capacity,newQueue);//�����׵Ŀ�ʼ���ݵ��������һ�����ݿ������¶��� 
			copy(queue, queue+rear+1,newQueue+capacity-start);//�����׵Ŀ�ʼ���ݵ��������һ�����ݿ������¶���
			                                                //rear+1��rear�������±꣬��������Ҫ�����ĳ��� 
		}
		
		front = 2 * capacity -1;//�µĶ���λ�µ����������±� 
		rear = capacity - 2;//capacity-1���������±����ֵ����-1��ȥ֮ǰ�յĶ�����ռ�ռ� 
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
	rear = (rear+1) % capacity;//������ע�͵Ĵ���һ�� �ж��Ƿ������� 
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
	return queue[(front+1) % capacity];//����ʱ��ָ��յ� ���׵�ֵ��Ҫ��1 
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
		
	queue[front].~T();//�ͷſռ�
	queue[front] = ' ';
	
	/*�����ǰ����Ԫ��Ϊ���г��ȵ�4��֮һ ��ʡһ��ռ�*/ 
	int count = (rear-front+1+capacity) % capacity;//ѭ������Ԫ�ظ���
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

