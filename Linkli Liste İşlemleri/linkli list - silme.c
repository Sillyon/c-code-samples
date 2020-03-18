#include<stdio.h>
#include<conio.h>
int main()
	{
		int N,X,LA[20],Po[20],J,K,i;
		printf("N degerini giriniz.\n");
		scanf("%d",&N);
		printf("Silinecek X degerini giriniz.\n");
		scanf("%d",&X);
		printf("LA dizisini sirasiyla giriniz.\n");
		for(i=1;i<=N;i++)
			{
				scanf("%d",&LA[i]);
			}
		printf("Po dizisini sirasiyla giriniz.\n");
		for(i=0;i<=N;i++)
			{
				scanf("%d",&Po[i]);
			}
		K=0;
		J=Po[0];
		while(J!=-1 && LA[J]!=X)
			{
				K=J;
				J=Po[J];
			}
		Po[K]=Po[J];
		Po[J]=-9;
		
		printf("SON DURUMDA:\n");
		printf("    %d\n",Po[0]);
		for(i=1;i<=N;i++){
				printf("%d  %d\n",LA[i],Po[i]);
			}		
		getch();
		return 0;
	}

