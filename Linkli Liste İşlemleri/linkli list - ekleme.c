#include<stdio.h>
#include<conio.h>
int main()
	{
		int N,K,J,X,i,LA[20],Po[20];
		printf("N degerini giriniz.\n");
		scanf("%d",&N);
		printf("Eklenecek X degerini giriniz.\n");
		scanf("%d",&X);
		printf("LA dizisini sirasiyla giriniz.\n");
		for(i=1;i<=N;i++)
			{ scanf("%d",&LA[i]); }
		printf("Po dizisini sirasiyla giriniz.\n");
		for(i=0;i<=N;i++)
			{ scanf("%d",&Po[i]); }
		K=0;
		J=Po[0]; // En kucukten baslanarak karsilastirma yapilir.
		while(J!=-1 && X>LA[J])
			{ K=J;
			J=Po[J];  }
		N=N+1;
		LA[N]=X;
		Po[K]=N;
		Po[N]=J;
		printf("SON DURUMDA:\n");
		printf("    %d\n",Po[0]);
		for(i=1;i<=N;i++)
			{ printf("%d  %d\n",LA[i],Po[i]); }	
		getch();
		return 0;
	}

