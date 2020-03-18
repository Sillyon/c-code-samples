#include<stdio.h>
int main(){

int j,N,K,J,Z,i,A[20],Po[20];
	printf("N degerini giriniz.\n");
	scanf("%d",&N);
	for(i=1;i<=N;i++)
    {   
		printf("A Dizisi %d. eleman \n ",i);
        scanf("%d",&A[i]);
    }
	Po[0]=1;
	Po[1]=-1;

	for(i=2;i<=N;i++)
    {
        Z=A[i];
        K=0;
        J=Po[0];
        while(J>0&&Z>A[J])
        {
            K=J;
            J=Po[J];
        }

        A[i]=Z;
        Po[K]=i;
        Po[i]=J;
    }
      printf("SON DURUM\n\n");
      printf("DIZI   PO DIZISI\n");
      printf("           %d\n",Po[0]);
    for(j=1;j<=N;j++)
    {
        printf("  %d        %d\n",A[j],Po[j]);
    }

return 0;
}

