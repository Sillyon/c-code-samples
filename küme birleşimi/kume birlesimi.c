#include <stdio.h>
int main(){
	int n,m,i,j,k,A[16],B[16],C[32];
	printf("Sirasiyla n ve m degerlerini girin.\n");
	scanf("%d",&n);
	scanf("%d",&m);
	printf("A[n] elemanlarini sirali girin:\n");
	for(i=1;i<=n;i++){
		scanf("%d",&A[i]);
	}
	printf("B[m] elemanlarini sirali girin:\n");
	for(j=1;j<=m;j++)
	{
		scanf("%d",&B[j]);
	}
	
	printf("A[n] dizisi:\n");
	for(i=1;i<=n;i++)
	{
		printf("%d ",A[i]);
	}
	printf("\nB[M] dizisi:\n");
	for(j=1;j<=m;j++)
	{
		printf("%d ",B[j]);
	}	
	
	i=1;
	j=1;
	k=1;
	while(i<=n && j<=m)
	{
		if(A[i]<B[j])
		{
			C[k]=A[i];
			i=i+1;
		}else
		{
			if(A[i]==B[j])
			{
				C[k]=A[i];
				i=i+1;
				j=j+1;
			}else
			{
				C[k]=B[j];
				j=j+1;
			}
		}
		k=k+1;
	}
	if(i>n){ //burada j>m kontrolu da yapilabilir.
		while(j<=m)
		{
			C[k]=B[j];
			j=j+1;
			k=k+1;
		}
	}else
	{
		while(i<=n)
		{
			C[k]=A[i];
			i=i+1;
			k=k+1;	
		}
	}
	
	printf("\n C[k] dizisi:\n");
	for(i=1;i<k;i++){
		printf("%d  ",C[i]);
	}
	
	return 0;
}
