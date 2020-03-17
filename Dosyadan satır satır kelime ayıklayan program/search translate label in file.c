#include <stdio.h>
#include <string.h>
#define linesize 255

int main() {
	int i,j,satirUz,kelimeUz,sayac,k;
	FILE *fp1,*fp2;
	char *kelime="' | translate}}";
	char satir[linesize];
	fp1=fopen("find.txt","r");
	fp2=fopen("bulunanlar.txt","w");
	if(fp1==NULL || fp2==NULL) {
		printf("file can not be opened.");
	}
	while(!feof(fp1)) {
		fgets(satir, linesize-1, fp1);
		satirUz = strlen(satir);
		kelimeUz = strlen(kelime);
		i=0;
		j=0;
		while(j<kelimeUz-1 && i<satirUz) {
			if(satir[i]==kelime[j]) {
			i++;
			j++;
			}
			else {
				i++;
				j=0;
			}
		}
		if(j==kelimeUz-1) {
			sayac=0;
			while(satir[i-15-sayac]!='\'') {
				sayac++;
			}
			for(k=0;k<sayac;k++) {
				putc(satir[i-14-sayac+k],fp2);
			}
			fputs("\n",fp2);
		}
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}
