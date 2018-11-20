#include<stdio.h>
#include<stdlib.h>
struct TEST{
	int ID;
	char Hash[32];
};
struct TEST * dondur(struct TEST *ar,int n){
	int i,j;
	int m=0;
	struct TEST *dizi2;
	
	for (i=0;i<n;i++){
		if(ar[i].ID==0){
			m++;
		}
	}
	
	dizi2=(struct TEST*)malloc (m*sizeof(struct TEST));
	
	if(dizi2==NULL){
		printf("can not allocate\n");
		return NULL;
	}
	j=0;
	for (i=0;i<n;i++){
		if(ar[i].ID==0){
			dizi2[j]=ar[i];
			j++;
		}
	}
/*	for(i=0;i<m;i++){
		printf("%d", dizi2[i].ID);
		printf("%s", dizi2[i].Hash);
	}*/
	return dizi2;
	}

int main(){
	
	struct TEST dizi[10];
	struct TEST *array;
	int i,n;
	
	printf("n=?\n");
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		printf("%d gir:\n",i);
		scanf("%d", &dizi[i].ID);
		scanf("%s", dizi[i].Hash);
	}
	
	array=dondur(dizi,n);
	
	for(i=0;i<2;i++){
		printf("%d", array[i].ID);
		printf("%s", array[i].Hash);
	}

	return 0;
}



	

