#include <stdio.h>
int main(){
	int i,n,x,orta,adim,A[32];
	printf("n?  ");
	scanf("%d",&n);
	printf("A[n] elemanlarini sirali girin:\n");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&A[i]);
	}
	printf("Aranacak sayiyi girin: ");
	scanf("%d",&x);
	i=1;
	orta=(i+n)/2;
	adim=1; //ilk olarak orta indis hesaplandigi icin adim sayisi 1'den baslar.
	while(i<n && A[orta]!=x)
	{
		adim=adim+1;
		if(x>A[orta])
		{
			i=orta+1;
		}else
		{
			n=orta-1;
		}
		orta=(i+n)/2;
	}
	if(A[orta]==x)
	{
		printf("\n%d adimda bulundu.",adim);
		printf("\nBulundugu indis: %d",orta);
	}
	else
	{
		printf("\nSayi bulunamadi.");
	}
	return 0;
}
