#include <stdio.h>
int main(){
	int i,j,k,n,A[16],adr,min;
	printf("n?  ");
	scanf("%d",&n);
	printf("A[n] elemanlarini girin:\n");
	for(k=1;k<=n;k++)
	{
		printf("%d ",k);
	}
	printf("\n\n");
	for(k=1;k<=n;k++)
	{
		scanf("%d",&A[k]);
	}
	for(i=1;i<=n-1;i++)
	{
		for(k=1;k<=n;k++)
		{
			printf("%d ",A[k]);
		}
		printf("\n");
		min=A[i];
		adr=i;
		for(j=i+1;j<=n;j++)
		{
			if(A[j]<min)
			{
				min=A[j];
				adr=j;
			}
		}
		A[adr]=A[i];
		A[i]=min;	
	}
	printf("\n\nA[n] sirali dizisi:\n");
	for(k=1;k<=n;k++)
	{
		printf("%d ",A[k]);
	}
	return 0;
}
