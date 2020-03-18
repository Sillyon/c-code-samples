#include<stdio.h>
int main(){
	int j,N,K,X,J,Z,i,A[64],Po[64],secim;
	printf("N degerini giriniz.\n");
	scanf("%d",&N);
	printf("A[n] dizisini giriniz:\n");
	for(i=1;i<=N;i++)
    {
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
    printf("\nSON DURUMDA\n\n");
    printf("DIZI   PO DIZISI\n");
    printf("           %d\n",Po[0]);
    for(j=1;j<=N;j++)
    {
        printf("  %d        %d\n",A[j],Po[j]);
    }
    secim=-1;//0 olmamasi icin.
    while(secim!=0)
    {
    	printf("\n1. Arama \n");
    	printf("2. Ekleme \n");
   		printf("3. Silme \n");
   		printf("4. Medyan Bulma \n");
		printf("0. Cikis \n"); 
    	printf("\nSeciminizi giriniz:   ");
    	scanf("%d",&secim);
    	if(secim==1)
    	{	
			printf("Aranan X degerini giriniz:  ");
			scanf("%d",&X);
			j=Po[0];
			while(j!=-1 && A[j]!=X)
			{
				j=Po[j];
			}
			if(j!=-1) {
				printf("\n%d. gozde bulundu.\n",j);
			}else{
				printf("Bulunamadi.");		
			}
    	}
    	else if(secim==2){
			printf("Eklenecek X degerini giriniz:  ");
			scanf("%d",&X);
			K=0;
			J=Po[0]; // En kucukten baslanarak karsilastirma yapilir.
			while(j!=-1 && X>A[J])
			{
				K=j;
				j=Po[j];
			}
			N++;
			A[N]=X;
			Po[K]=N;
			Po[N]=j;
		    printf("\nSON DURUMDA\n\n");
		    printf("DIZI   PO DIZISI\n");
		    printf("           %d\n",Po[0]);
		    for(j=1;j<=N;j++)
		    {
		        printf("  %d        %d\n",A[j],Po[j]);
		    }
    	}
    	else if(secim==3)
    	{
			printf("Silinecek X degerini giriniz:  ");
			scanf("%d",&X);
			K=0;
			j=Po[0];
			while(j!=-1 && A[j]!=X)
			{
				K=j;
				j=Po[j];
			}
			Po[K]=Po[j];
			Po[j]=-9;
			printf("\nSON DURUMDA\n\n");
		    printf("DIZI   PO DIZISI\n");
		    printf("           %d\n",Po[0]);
		    for(j=1;j<=N;j++)
		    {
		        printf("  %d        %d\n",A[j],Po[j]);
		    }	
    	}
    	else if(secim==4)
    	{
    		int med=(N+1)/2;
			j=Po[0];
			for(i=1;i<=med;i++)
			{
				K=j;
				j=Po[j];
			}
			printf("\nA[%d]=%d medyandir.\n",K,A[K]);
    	}
    }
	return 0;
}

