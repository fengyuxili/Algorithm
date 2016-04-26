#include <iostream>
using namespace std;

template<class T>
void quickSort(T *a, const int left, const int right);

int main()
{
	int list[] = {5,7,4,2,6,1,0,9,3,8,11};
	
	quickSort(list, 0, sizeof(list) / sizeof(list[0]) - 1);
	
	for(int i = 0; i < sizeof(list) / sizeof(list[0]); i++)
		cout<<list[i]<<" ";	
	cout<<endl;
	
	return 0;
}

template<class T>
void quickSort(T *list, const int left, const int right)
{
	if(left < right){
		
		int i = left;
		int j = right+1;//+1是在do j--的时候指向list最后一个 
		T pivot = list[left];//枢轴 
		
		//第一次根据基准 多次交换 
		do{
			do i++; while(list[i] < pivot);//找到>=基准的数 跳出循环 
			do j--; while(list[j] > pivot);//找到<=基准的数 跳出循环
			if(i < j) 
				swap(list[i], list[j]);					
		}while(i < j);
		
		swap(list[left], list[j]);//此时j<=i 将枢轴放到j的位置 相当于mid数 
		quickSort(list, left, j-1);
		quickSort(list, j+1, right);
			
	}
} 
