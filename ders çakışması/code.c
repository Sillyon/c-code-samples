#include <stdio.h>

int main()
{
	int n = 3;
	int A[3][3] = {
	{0, 10, 3},
	{1, 12, 3},
	{2, 9, 2}
	};
	
	int adj[n][n];
	
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if((A[i][1]>=A[j][1] && A[i][1]<=A[j][1]+A[j][2] ) || (A[i][1]+A[i][2]>=A[j][1] && A[i][1]+A[i][2]<=A[j][1]+A[j][2]))
			{
				adj[i][j]=1;
				adj[j][i]=1;
			}
			else
			{
				adj[i][j]=0;
				adj[j][i]=0;
			}
		}
	}
	
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ", adj[i][j]);
		}
		printf("\n");
	}
	
	int index; //ders indisi
	scanf("%d",&index);
	
	for(i=index+1;i<n;i++)
	{
		if(adj[index][i]==1)
		{
			printf("%d ",i);
		}
	}
	return 0;
}
