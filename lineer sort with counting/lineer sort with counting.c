#include <stdio.h>
int main(){
	int i,j,n,A[16],S[16];
	printf("n degerini girin.\n");
	scanf("%d",&n);
	printf("A[n] elemanlarini girin:\n");
	for(i=1;i<=n;i++){
		scanf("%d",&A[i]);
	}
	for(j=1;j<=n;j++)
	{
		S[j]=1;
	}
	for(i=1;i<=n-1;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(A[i]>A[j])
			{
				S[i]=S[i]+1;
			}
			else
			{
				S[j]=S[j]+1;
			}
		}
	}
	printf("A[n]  S[n]\n");
	for(i=1;i<=n;i++)
	{
		printf("%d   %d\n",A[i],S[i]);
	}
	return 0;
}
