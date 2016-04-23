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
	//out=0已经从序列出来 
	for( out=1; out<n; out++){
		
		T temp = list[out];
		in = out;
		while(in>0 && list[in-1]>temp){ //已经出来的序列第一个数比新出来的数比大 
			list[in] = list[in-1]; //已经出来的序列就移动到list[in-1] <= temp 的位置 
			--in;
		}
		list[in] = temp;//把新出来的数插入序列 
	}
}

template<class T>
void insertionSort2(T *list , const int n)
{
	/*该函数是为了简化insertionSort函数的while循环条件 去掉in>0的条件*/
	/*为此list2第一位是不进行排序的 所以下列从i=2开始 打印时从1～10*/
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

