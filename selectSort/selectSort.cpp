#include <iostream>
using namespace std;

/*select sort is better than bubble sort,but also not suit big data sort*/
void selectSort(int *list , const int n);

void selectSort(int *list , const int n)
{
	for(int i = 0; i < n-1 ; i++){
		int min_index = i;
		for(int j=i+1; j < n; j++){
			if(list[j] < list[min_index])
			    min_index = j;	/*get min number index very time san */			
		}
		std::swap(list[i],list[min_index]);/*put the min number in front*/
	}
	 
}

int main(void)
{
    int a[] = {2,4,6,8,1,3,5,7,9,10};
    selectSort(a,10);
	for(int i=0;i<10;i++)
	    cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
