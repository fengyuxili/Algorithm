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
		int j = right+1;//+1����do j--��ʱ��ָ��list���һ�� 
		T pivot = list[left];//���� 
		
		//��һ�θ��ݻ�׼ ��ν��� 
		do{
			do i++; while(list[i] < pivot);//�ҵ�>=��׼���� ����ѭ�� 
			do j--; while(list[j] > pivot);//�ҵ�<=��׼���� ����ѭ��
			if(i < j) 
				swap(list[i], list[j]);					
		}while(i < j);
		
		swap(list[left], list[j]);//��ʱj<=i ������ŵ�j��λ�� �൱��mid�� 
		quickSort(list, left, j-1);
		quickSort(list, j+1, right);
			
	}
} 
