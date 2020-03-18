#include<stdio.h>
#include<conio.h>
int main()
	{
		int N,J,K,i,LA[20],Po[20], med;
		printf("N degerini giriniz.\n");
		scanf("%d",&N);
		printf("LA dizisini sirasiyla giriniz.\n");
		for(i=1;i<=N;i++)
			{ scanf("%d",&LA[i]); }
		printf("Po dizisini sirasiyla giriniz.\n");
		for(i=0;i<=N;i++)
			{ scanf("%d",&Po[i]); }
		med=(N+1)/2;
		J=Po[0];
		for(i=1;i<=med;i++)
		{
			K=J;
			J=Po[J];
		}

		printf("SON DURUMDA:\n");
		printf("    %d\n",Po[0]);
		for(i=1;i<=N;i++)
			{ printf("%d  %d\n",LA[i],Po[i]); }
			
		printf("LA[%d]=%d medyandir.\n",K,LA[K]);
		getch();
		return 0;
	}

