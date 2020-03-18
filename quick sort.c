#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

void quicksort(int arr[], int fst, int last);

int main()
{
	int arr[9]={1,2,3,4,5,6,7,8,9};
 	int i,size;
 	srand(time(NULL));
 	printf("dizi eleman sayisi?\n");
 	scanf("%d",&size);
/*    for(i=0; i<size; i++)
 	{
 		arr[i]=rand()%100;
 	}*/
    printf("dizi ilk hali = \n");
 	for(i=0; i<size; i++)
 	{
 		printf("%d\t",arr[i]);
 	}
 	printf("\n");
 	quicksort(arr,0,size-1);
 	printf("quick sort uygulanmis dizi = \n");
 	for(i=0; i<size; i++)
 	{
	 	printf("%d\t",arr[i]);
	}
	getch();
 	return 0;
}

void quicksort(int arr[], int fst, int last)
{
 	int i,j,pivot,tmp;
 	if(fst<last)
 	{
   		pivot=fst;
   		i=fst;
   		j=last;
   		while(i<j)
   		{
     		while(arr[i]<=arr[pivot] && i<last)
        		i++;
     		while(arr[j]>arr[pivot])
        		j--;
     		if(i<j)
     		{
        		tmp=arr[i];
        		arr[i]=arr[j];
        		arr[j]=tmp;
     		}
   		}
   		tmp=arr[pivot];
   		arr[pivot]=arr[j];
   		arr[j]=tmp;
   		quicksort(arr,fst,j-1);
   		quicksort(arr,j+1,last);
 	}
}
