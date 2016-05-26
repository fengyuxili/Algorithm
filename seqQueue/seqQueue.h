#ifndef _SEQQUEUE_H
#define _SEQQUEUE_H

template<class T>
class Queue
{
public:
	Queue(int queueCapacity = 4);
	bool isEmpty() const;
	T& Front() const;
	T& Rear() const;
	void Push(const T& item);
	void Pop();

private:
	T *queue;    //�������˳������ 
	int front;   //��¼���� 
	int rear;    //��¼��β
	int capacity;//���д�С 
};

 
#endif
