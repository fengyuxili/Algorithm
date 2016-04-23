#include <iostream>
#include <string.h>
using namespace std;
/*排列组合 使用递归算法*/
void permutations(char *list, const int start,const int end);
int count = 0;
int main()
{
	char  list[] = "abc";
	int end = strlen(list)-1; 	
	permutations(list, 0, end);
	cout<<"total="<<count<<endl;
	
	return 0;
}
 
void permutations(char *list, const int start,const int end)
{
      if( start == end ){
      	for(int i = 0; i <= end; i++)
      	    cout<<list[i];
      	cout<<endl;
      	count++;
	  }else{
	  	
	  	    for(int i = start; i <= end; i++){
	  	    
	  	    	if( start != i)
	  	    	    swap(list[start],list[i]);	  	    	    
	  	    	permutations(list,start+1,end);	  	    
	  	    	if( start != i)
	  	    	    swap(list[start],list[i]);	  	    	
			}
	  }
      
}
