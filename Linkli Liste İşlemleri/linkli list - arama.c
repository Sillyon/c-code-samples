#include<stdio.h>
int main()
{
	int i,j,LA[16],Po[16],N,X;
	printf("N degerini giriniz.\n");
	scanf("%d",&N);
	printf("LA dizisini sirasiyla giriniz.\n");
	for(i=1;i<=N;i++)
		scanf("%d",&LA[i]);
	}
	printf("Po dizisini sirasiyla giriniz.\n");
	for(i=0;i<=N;i++){
		scanf("%d",&Po[i]);
	}	
	printf("Aranan X degerini giriniz:\n");
	scanf("%d",&X);
	j=Po[0];
	while(j!=-1 && LA[j]!=X)
	{
		j=Po[j];
	}
	if(j!=-1) {
		printf("%d. gozde bulundu.\n",j);
	}else
		printf("Bulunamadi.");		
	}
	return 0;
}

