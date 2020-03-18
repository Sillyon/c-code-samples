#include <stdio.h>
#include <stdlib.h>
int main()
{
int N,i,a,numtree=1;
int ilk_dizi[10],btree[1030];
printf("Eleman sayisini giriniz : ");
scanf("%d",&N);
for ( i=1;i<=N;i++)
{
printf("Dizinin %d . elemanini giriniz : ",i);
scanf("%d",&ilk_dizi[i]);
}
for (i=1;i<=N;i++)
{
numtree=numtree*2;
}
numtree=numtree-1;
for(i=1;i<=numtree;i++)
{
btree[i]=-1;
}
btree[1]=ilk_dizi[1];
for(i=2;i<=N;i++)
{
a=1;
while(btree[a]!=-1)
{
if(btree[a]>ilk_dizi[i])
{
a=2*a;
}
else
{
a=2*a+1;
}
}
btree[a]=ilk_dizi[i];
}
for (i=1;i<=numtree;i++)
{
printf("%d ",btree[i]);
}
return 0;
}
