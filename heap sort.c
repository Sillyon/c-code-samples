#include <stdio.h>

#define MAX_SIZE 80
int main()
{
	int i,j,N,M,tmp;
	int A[MAX_SIZE],B[MAX_SIZE];
	printf("Dizinin eleman sayisini giriniz:");
	scanf("%d",&N);
	printf("Dizi elemanlarini giriniz:\n");
	for(i=1;i<=N;i++)
	{
		scanf("%d",&A[i]);
	}
	for(i=1;i<=2*N;i++)
	{
		if(i<=N)
		{
			B[i]=A[i];
		}else
		{
			B[i]=0;
		}
	}
	M=N/2;	
	for(j=1;j<=3;j++)
	{
		for(i=M;i>=1;i--)
		{
			if(B[i]>B[2*i])
			{
				if(B[i]<B[2*i+1])
				{
					tmp=B[i];
					B[i]=B[2*i+1];
					B[2*i+1]=tmp;
				}
			}else
			{
				if(B[2*i]>B[2*i+1])
				{
					tmp=B[i];
					B[i]=B[2*i];
					B[2*i]=tmp;
				}else
				{
					tmp=B[i];
					B[i]=B[2*i+1];
					B[2*i+1]=tmp;
				}
			}
		}
	}
	for(i=1;i<=2*N;i++)
	{
		printf("%d ",B[i]);
	}
	getch();
	return 0;
}
