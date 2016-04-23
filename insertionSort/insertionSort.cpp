#include<iostream>
using namespace std;

template<class T>
void insertionSort(T *list , const int n);

template<class T>
void insertionSort2(T *list , const int n);

int main()
{
	double list[] = {1,3,5,7,9,2.3,2.3,6,8,0};
	double list2[] = {0,1,3,5,7,9,2.3,2.3,6,8,0};
	
	insertionSort(list,10);	
	for(int i=0;i<10;i++)
	    cout<<list[i]<<" ";
	cout<<endl;
	
	insertionSort2(list2 ,10);	
	for(int i=1;i<=10;i++)
	    cout<<list2[i]<<" ";
	cout<<endl;
	
	return 0;
}

template<class T> 
void insertionSort(T *list , const int n)
{
	int in;
	int out;
	//out=0�Ѿ������г��� 
	for( out=1; out<n; out++){
		
		T temp = list[out];
		in = out;
		while(in>0 && list[in-1]>temp){ //�Ѿ����������е�һ�������³��������ȴ� 
			list[in] = list[in-1]; //�Ѿ����������о��ƶ���list[in-1] <= temp ��λ�� 
			--in;
		}
		list[in] = temp;//���³��������������� 
	}
}

template<class T>
void insertionSort2(T *list , const int n)
{
	/*�ú�����Ϊ�˼�insertionSort������whileѭ������ ȥ��in>0������*/
	/*Ϊ��list2��һλ�ǲ���������� �������д�i=2��ʼ ��ӡʱ��1��10*/
	for(int i=2;i<=n;i++){
		T temp = list[i];
		int j=i-1;
		while(temp < list[j]){
			list[j+1]=list[j];
			j--;
		}
		list[j+1] = temp;
	}
	
} 

