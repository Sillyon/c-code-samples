#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *frequency(int, char**);

int main() {
	FILE *fp=fopen("products.txt","r");
	int i,products_count;
	char ch;
	char *word = (char*)malloc(10000*sizeof(char));
	fscanf(fp,"%d\n", &products_count);
	char **products = (char**)malloc(products_count*sizeof(char*));
	i=0;
	while(!feof(fp)) {
		fgets(word, 9999, fp);
		products[i]=(char*)malloc(10000*sizeof(char));
		strcpy(products[i], word);
		i++;
	}
	fclose(fp);
	strcpy(word, frequency(products_count, products));
	printf("%s",word);
	for(i=0;i<products_count;i++) {
		free(products[i]);
	}
	free(products);
	return 0;
}

char *frequency(int products_count, char **products) {
	char *temp_word = (char*)malloc(10000*sizeof(char));
	int i,j,length,min_idx,temp;
	int *arrInt = (int*)calloc(products_count,sizeof(int));//burayý malloc dene en son.
	char **arrCh = (char**)calloc(products_count,sizeof(char*));
	for(i=0;i<products_count;i++) {
		arrCh[i]=(char*)calloc(10000,sizeof(char));
	}
	
	//frequency detection
	length=0;
	for(i=0;i<products_count;i++) {
		j=0;
		while(j<length && strcmp(arrCh[j], products[i])!=0) {
			j++;
		}
		if(j==length) {
			strcpy(arrCh[length], products[i]);
			arrInt[length]++;
			length++;
		}
		else {
			arrInt[j]++;;
		}
	}
	
	//sorting
	for(i=0;i<length-1;i++) {
		min_idx=i;
		for(j=i+1;j<length;j++) {
			if(arrInt[min_idx]>arrInt[j]) {
				min_idx=j;
			}
		}
		//swap
		temp=arrInt[i];
		strcpy(temp_word,arrCh[i]);
		arrInt[i]=arrInt[min_idx];
		strcpy(arrCh[i],arrCh[min_idx]);
		arrInt[min_idx]=temp;
		strcpy(arrCh[min_idx],temp_word);
	}
	
	//finding most frequent, last word in alphabetical order.
	i=length-1;
	while(arrInt[i]==arrInt[length-1]) {
		i--;
	}
	min_idx=i+1;	//max_idx is length-1
	temp=min_idx;	//mark index of word for finding last here
	for(i=min_idx;i<length;i++) {
		if(strcmp(arrCh[temp],arrCh[i])<0) {
			temp=i;
		}
	}
	
	//detect word in products array
	i=0;
	while(strcmp(arrCh[temp],products[i])!=0 && i<products_count) {
		i++;
	}
	if(strcmp(arrCh[temp],products[i])==0) {
		temp=i;
	}
	
	for(i=0;i<products_count;i++) {
		free(arrCh[i]);
	};
	free(temp_word);
	free(arrCh);
	free(arrInt);
	return products[temp];
}

