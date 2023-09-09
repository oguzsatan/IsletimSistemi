#include<stdio.h> 
#include<unistd.h> 
#include <stdlib.h>
#include<string.h>  
  
int main(int argc, char * argv[]) 
{ 
	int status;
	//buradan girilen isleme gore uygun programi calistiriyorum
    if(strcmp(argv[1], "topla") == 0){
    	char *args[]={"./topla",NULL,NULL,NULL,NULL}; 
    	args[1] = argv[2];
    	args[2] = argv[3];
    	//programi calistirmadan cocuk proses yaratiyorum
    	if(fork() == 0)
    		execvp(args[0], args);
    	//burada ebebeyn i bekliyorum.
    	wait(&status);
    }
    else if(strcmp(argv[1], "cikar") == 0){
    	char *args[]={"./cikar",NULL,NULL,NULL,NULL}; 
    	args[1] = argv[2];
    	args[2] = argv[3];
    	//programi calistirmadan cocuk proses yaratiyorum
    	if(fork() == 0)
    		execvp(args[0], args);
    	//burada ebebeyn i bekliyorum.
    	wait(&status);
    }
    else{//eger topla veya cikar degilse hata basiyorum
    	printf("Hatali komut girdiniz!\n");
    }
    return 0; 
} 		