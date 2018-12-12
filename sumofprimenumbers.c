#include <stdio.h>

int main() {
	int N, M,i,j,toplam;
	printf("Hosgeldiniz.. Girdilerde ( 2 <= N < M ) sarti saglanmali.\n\n");
	do {
		printf("2'den buyuk olacak sekilde N degerini girin: ");
		scanf("%d",&N);
	} while(N<2);
	do {
		printf("N'den buyuk olacak sekilde M degerini girin: ");
		scanf("%d",&M);
	} while (M<=N);
	toplam=0;
	for(i=N;i<=M;i++) {
		j=2;
		while(i%j!=0 && j<i) {
			
			j++;
		}
		if(i==j) {
			toplam+= i;
		}
	}
	printf("Toplam = %d",toplam);
	return 0;
}
