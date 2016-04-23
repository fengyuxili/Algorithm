#include<iostream>
using namespace std;
/*bubble sort is uesd to few data sort*/ 
void bubbleSort(int list[] , int n);

int main()
{   
    
    int a[] = {2,4,6,8,1,3,5,7,9,10};
	
	bubbleSort(a,10);
	for(int i=0;i<10;i++)
	    cout<<a[i]<<" ";
	cout<<endl;
    return 0;
}
void bubbleSort(int *list , const int n)
{
    for(int i=0;i<n-1;i++)
	    for(int j=0;j<n-i-1;j++){
	    	if(list[j] > list[j+1])
	    	    std::swap(list[j] ,list[j+1]);
		}
			
} 
