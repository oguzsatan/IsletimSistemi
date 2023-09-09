#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<string.h>
int main() 
{ 
    while(1){
    	printf("myshell>>");
    	//girilen satiri bu degiskene birakiyorum
    	char data[64];
    	char komut[20];
    	int status;
    	//bu degisenleri operandlar icin kullanacagim
    	char operand1[20];
    	char operand2[20];
    	char operand3[20];
    	
	    if (fgets(data, sizeof data, stdin)) {
	    	int ind1=0, ind2=0, ind3=0;
	        int i;
        	int j;
        	 if(data[0] == 'e' && data[1] == 'x' && data[2] == 'i' && data[3] == 't'){
		        	break;
		        }	
        	while(1){
        		//ilk bosluga kadar olan kismi komut olarak aliyorum
		        for(i = ind1, j = 0 ; i < strlen(data); i++, j++){
		        	if(data[i] == ' '){
		        		komut[j] = '\0';
		        		ind1 = i;
		        		break;
		        	}
		        	else{
		        		komut[j] = data[i];
		        	}
		        }

		       	
		        if(data[0] == 'c' && data[1] == 'l' && data[2] == 'e' && data[3] == 'a' && data[4] == 'r'){
		        	for(i = 0 ; i < 30 ; i++)
		        		printf("myshell>>\n");
		        	break;
		        }	
		        //eger komut 'tekrar' ise buradaki kod calisacak
		        else if(strcmp(komut, "tekrar")==0){
		        	//parametlerimi guncelliyorum
		        	char *args[]={"./tekrar",NULL,NULL,NULL,NULL}; 
		        	//burada ilk bosluga kadar olan kismi alip ilk kelimeyi aliyorum
		        	for(i = ind1+1, j = 0 ; i <strlen(data) ; i++, j++){
		        		if(data[i] == ' '){
			        		operand1[j] = '\0';
			        		ind2= i;
			        		break;
			        	}
			        	else{
			        		operand1[j] = data[i];
			        	}
		        	}
		        	//burada satir sonuna kadar gidip sayiyi aliyorum
		        	for(i = ind2+1 , j = 0; i <strlen(data) ; i++, j++){
			        		operand2[j] = data[i];
			        	}
			        operand2[strlen(data)] = '\0';
			        args[1] = operand1;
			        args[2] = operand2;
			       //burada yeni proses yaratip sonrasinda diger programi buradan cagiriyorum
		        	if(fork()==0){
		        		execvp(args[0], args);
		        		perror("Exec failed!");
		        	}
		        	//burada child islemin bitmesi bekleniyor
		        	wait(&status);
		        }

		        //eget komut 'islem' ise buradaki kod calisacak
		        else if(strcmp(komut, "islem")==0){
		        	char *args[]={"./islem",NULL,NULL,NULL,NULL}; 
		        	for(i = ind1+1, j = 0 ; i <strlen(data) ; i++, j++){
		        		if(data[i] == ' '){
			        		operand1[j] = '\0';
			        		ind2= i;
			        		break;
			        	}
			        	else{
			        		operand1[j] = data[i];
			        	}
		        	}

		        	for(i = ind2+1, j = 0 ; i <strlen(data) ; i++, j++){
		        		if(data[i] == ' '){
			        		operand2[j] = '\0';
			        		ind3= i;
			        		break;
			        	}
			        	else{
			        		operand2[j] = data[i];
			        	}
		        	}

		        	for(i = ind3+1 , j = 0; i <strlen(data) ; i++, j++){
		        			if(data[i] == ' '){
		        				break;
		        			}
			        		operand3[j] = data[i];
			        		operand3[j+1] = '\0';
			        	}
			       
			        //eger operand sayisi farklı ise hata veriyorum
			        if(ind3 == 0){
			        	printf("Hatali komut girdiniz!\n");
			        	continue;
			        }
			        args[1] = operand1;
			        args[2] = operand2;
			        args[3] = operand3;
		        	if(fork()==0){
		        		execvp(args[0], args);
		        		perror("Exec failed!");
		        	}
		        }
		        else{//eger farkli bir komut girildi ise hata veriyorum
		        	printf("Hatali komut girdiniz!\n");
		        }
		        if(ind3 != 0){
		        	if(strlen(data) > ind3 + strlen(operand3) + 2){
		        		if(data[ind3 + strlen(operand3) + 2] == '|'){
		        			ind1 = ind3 + strlen(operand3) + 4;
			        		ind2 = 0;
			        		ind3 = 0;
			        		continue;
		        		}
		        		else{
		        			printf("Hatali input giridiniz!\n");
		        		}
			        		
		        	}
		        	else{
		        		break;
		        	}
		        }
		        else{
		        	if(strlen(data) > ind2 + strlen(operand2) + 2){
		        		if(data[ind2 + strlen(operand2) + 2] == '|'){
		        			ind1 = ind2 + strlen(operand2) + 4;
			        		ind2 = 0;
			        		ind3 = 0;
			        		continue;
		        		}
		        		else{
		        			printf("Hatali input giridiniz!\n");
		        			break;
		        		}
			        		
		        	}
		        	else{
		        		break;
		        	}
		    
		        }

        	}
	    }
    }
      
    return 0; 
} 