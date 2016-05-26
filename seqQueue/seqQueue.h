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
	T *queue;    //保存队列顺序数组 
	int front;   //记录队首 
	int rear;    //记录队尾
	int capacity;//队列大小 
};

 
#endif
