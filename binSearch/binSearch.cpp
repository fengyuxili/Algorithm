#include <iostream>
using namespace std;
/*use the recursive algorithm and binary to search the number*/
int binSearch(int *list , const int x, const int left , const int right) ;

int main(void)
{
	int list[] = {1,2,3,4,5,6,7,8,9,10};
	int ret = -1;
	ret = binSearch(list , 2, 0 , 9);
	if( ret < 0)
	    cout<<"Not This Number!"<<endl;
	else
	    cout<<"This number is in "<<ret+1<<"th" << " and is "<<list[ret]<<endl ;
}
int binSearch(int *list , const int x, const int left , const int right) 
{	
	if(left <= right){
		int mid = (left + right)/2;
		if( x < list[mid] )
		    return binSearch(list , x, left , mid -1);
		else if( x >  list[mid] )
		    return binSearch(list , x, mid+1 , right);
		else
		    return mid;
	}
	return -1;
}
