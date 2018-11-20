#include<stdio.h>
#include<string.h>
#define linesize 255
int main(){
	FILE *fp;
	int k,a,b,sayac,j;
	
	char okunan[linesize];
	char aranan[32];
	char dosya[32];
	scanf("%s",dosya);
	
	fp=fopen(dosya,"r");
	if(fp==NULL)
	{
		printf("olmadi");
	}

	printf("kelimeyi girin:\n");
	scanf("%s",aranan);
	
	k=0;
	
	while(!feof(fp)){
		
		fgets(okunan,linesize-1,fp);
		k++;		
		a=strlen(aranan);
		b=strlen(okunan);
		sayac=0;
		j=0;

		while(j<b && sayac<a-1){
			
			if(aranan[sayac]==okunan[j]){
				sayac++;
				j++;
			}
			else{
				j++;
				sayac=0;
			}	
		}
		if(sayac==a-1)
		{
			printf("%d bulundu: %s\n",k,okunan);	
		}
	}
	fclose(fp);
	return 0;	
}

