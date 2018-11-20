#include <stdio.h>

int main() {
    
    char kelime[16];
    char aranan[10];
    int basla,k,n;
    int  cikis=4;
    printf("1. kelimeyi giriniz:");
    scanf("%s",kelime);
    printf("\nAranacak kelimeyi giriniz:");
    scanf("%s",aranan);
    
    int i=0;
    while(kelime[i]){
        i++;
    }
    n=i;
    int  j=0;
    
    while(aranan[j]){
        j++;
    }
    k=j;
  
    i=0;
    j=0;
    
    while(cikis==4){
        basla=i;
        
        while(kelime[i] == aranan[j] && cikis == 4){
            i++;
            j++;
            if(j==k){
                printf("bulundu %d. goz",i-j);
                cikis=3;
            }
        }
        i=basla+1;
        
        
    }
  
}


