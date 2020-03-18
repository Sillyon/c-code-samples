#include <stdio.h>
#include <stdlib.h>
int main()
{
int btree[1030];
int n,find,i,a=1,sayac=0;
printf("Agac yapisindaki son dolu elemana kadar kac eleman var ? ");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
printf("Agac yapisindaki %d . elemani veriniz (bos yerler icin -1)",i);
scanf("%d",&btree[i]);
}
printf("Aranan elemani giriniz : ");
scanf("%d",&find);
for (i=1;i<=n;i++)
{
if (btree[a]==find){
sayac=sayac+1;break;
}
else
{
if(find>btree[a])
a=2*a+1;
else
a=2*a;
}
}
if(sayac>=1)
printf("Aradiginiz sayi %d. elemandir." ,a);
else
printf("Aradiginiz sayi bulunamadi . ");
return 0;
}
