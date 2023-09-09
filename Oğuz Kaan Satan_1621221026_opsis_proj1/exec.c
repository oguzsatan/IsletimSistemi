//EXEC.c 
  
#include<stdio.h> 
#include<unistd.h> 
#include <stdlib.h>
#include<string.h>  
  
int main(int argc, char * argv[]) 
{ 
    int tekrar_sayisi = atoi(argv[2]);
    int i = 0; 
    for(i = 0 ; i < tekrar_sayisi ; i++)
    	printf("%s\n", argv[1]);
      
    return 0; 
} 		