#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// 338 letter, str m=487, r = 479
void hashleme(int *, char *);
int arama(int *, char *);
void onerme(int *, char *);
int h(int, int);
int h1(int);
int offset(int);
int m=487,R=479;
int main(){
	int i,j,*hTable, flag=0;
	FILE *f,*f2;
	char kelime[32],str[32];
	hTable=(int *)malloc(m*sizeof(int));
	if(hTable==NULL){
		printf("can NOT allocate memory.\n");
		return 0;
	}
	for(i=0;i<m;i++){
		hTable[i]=9999;
	}
	f = fopen("smallDictionary.txt","r");
	
	if(f==NULL){
		printf("File cannot be opened.\n");
		return 0;
	}
	i = 1;
	while(fscanf(f,"%s",str) == 1 ){
		if(i!=1){
			j = 0;
			while(str[j]) {
      			str[j]=toupper(str[j]);
      			j++;
   			}
			hashleme(hTable, str);
			 
		}
		i++;
	}
	/*f2 = fopen("hTable.txt","w");
	i=0;
	while(i<m){
		fprintf(f2,"%d ",hTable[i]);	
		i++;	
	}*/
	printf("aranacak kelimeyi giriniz =");
	gets(kelime);
	flag = arama(hTable, kelime);
	if(flag==1){
		printf("buldunuz.\n");
	}
	else {
		printf("bulamadiniz.\n");
		onerme(hTable,kelime);
	}
	
	fclose(f);
	//fclose(f2);
	getch();
	return 0;
}
void hashleme(int * hTable, char * str){
	int i, key,k;
	//puts(str);
	for(i=key=0;i < strlen(str); i++) {
		key += (str[i]-'a' + 1)*26*(i+1);
	}
	i=0;
	do{
		k = h(key,i);
		i++;
	}
	while(hTable[k]!=9999);
	hTable[k]=key;
}
int arama(int * hTable, char * str){
	int i, key, k;
	for(i=key=0;i<strlen(str);i++) {
		key += (str[i]-'a' + 1)*26*i;
	}
	i=0;
	do{
		k = h(key,i);
		i++;
	}
	while(hTable[k]!=key && hTable[k]!=9999);
	if(hTable[k]==9999){
		return 0;
	}
	else {
		//printf("\nk: %d, hTable[k]: %d, key: %d\n",k,hTable[k],key);
		return 1;
	}
}
int h(int key, int i) {
	return (h1(key) + i*offset(key)) % m;
}
int h1(int key) {
	return key % m;
}
int offset(int key){
	return R-(key%R);
}

void onerme(int *hTable, char *str){
	int i, j, flag, n=strlen(str);
	char k;
	//puts(str);
	for(i=0;i<n;i++){
		k=str[i];
		for(j=0;j<26;j++){
			str[i]='A'+j;
			flag = arama(hTable, str);
			if(flag==1) {
				printf("bunu mu aramak istediniz = %s\n", str);
			}
		}
		str[i]=k;
	}
}
