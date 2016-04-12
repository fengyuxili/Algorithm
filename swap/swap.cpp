#include <iostream>
#include <stdio.h>
using namespace std;
/*
���þ��Ǳ��� 
*/
void swap(int &rx , int &ry);
/*
can not use swap function name,because iostream have been include swap function,
will cause function overloading,so use swapT
class is class mode type -��ģ��
typename is funtion mode type -����ģ��
*/
template<typename T> void swapT(T& rx , T& ry);
 
int main(void)
{
	int a = 10;
	int b = 1;

	cout<< "before swap \na = " << a << "\t b = " << b << endl;
	swap(a,b);
	cout<<"use  swap"<<endl;
	cout<< "a = " << a << "\t b = " << b << endl;
	
	swapT<int>(a,b);
	cout<<"use  swapT"<<endl;
	cout<< "a = " << a << "\t b = " << b << endl;
	std::swap(a,b);
	cout<<"use std::swap"<<endl;
	cout<< "a = " << a << "\t b = " << b << endl;
	return 0;
}

void swap(int &rx,int &ry){
	int tmp;
	tmp = rx;
	rx = ry;
	ry = tmp;
	return;
}

template<typename T> void swapT(T& rx , T& ry)
{
    T tmp;
	tmp = rx;
	rx  = ry;
	ry  = tmp;	
	return;		
}

