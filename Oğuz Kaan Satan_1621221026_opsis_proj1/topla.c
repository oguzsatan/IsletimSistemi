#include<stdio.h> 
#include<unistd.h> 
#include <stdlib.h>
#include<string.h>  
  
int main(int argc, char * argv[]) 
{ 
	printf("%d + %d = %d\n",atoi(argv[1]), atoi(argv[2]), atoi(argv[1]) + atoi(argv[2]));
    return 0; 
} 		