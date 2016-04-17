#include <iostream>
using namespace std;

/*sequential search is useed to not sort list */
int sequentialSearch(int *list,const int n, const int searchNum);

int main(void)
{
	int list[] = {1,4,3,2,5,8,9,10,7,6};
	int ret;
	
	ret = sequentialSearch(list , 10 , 5);
	
	if(ret < 0)
	    cout<<"Not this number in  list" <<endl;
	else
	    cout<<"This number index is "<<ret+1<<"th in this list" <<endl;
	
	
}
int sequentialSearch(int *list , const int n, const int searchNum)
{
	for(int i = 0; i < n ; i++){
		if(list[i] == searchNum)
		    return i;
	}
	return -1;
}
