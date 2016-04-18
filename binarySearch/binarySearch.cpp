#include <iostream>
using namespace std;

/*binary search need to sort first*/
/*this is a effient algorithm to search number*/
int binarySearch(int *list , const int n, const int searchNum);

int main(void)
{
	int list[] = {1,2,3,4,5,6,7,8,9,10};
	int ret = -1;
	
	ret = binarySearch(list , 10 , 8);
	if(ret < 0 )
	    cout<<"Not this number"<<endl;
	else
	    cout<<"This number is in "<<ret+1<<"th" << " and is "<<list[ret]<<endl ;   
	
	return 0;
}

int binarySearch(int *list , const int n, const int searchNum)
{
	int low;
	int mid;
	int high;
	low =0,high = n-1;
	
	while(low <= high){
		mid = (low + high)/2;
		if(list[mid] == searchNum)
			return mid;
		else if (list[mid] < searchNum)
		    low = mid +1;
		else if (list[mid] > searchNum)
		    high = mid -1;
	
	}
	return -1;	
}
