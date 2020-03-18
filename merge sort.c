#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

void mergeSort(int arr[],int low,int mid,int high);
void partition(int arr[],int low,int high);

int main(){
   
    int merge[9]={1,2,3,4,5,6,7,8,9},i,n;
    
    srand(time(NULL));
    
    printf("dizi eleman sayisi?\n");
    scanf("%d",&n);

    /*for(i=0;i<n;i++){
         merge[i]=rand()%100;
    }*/
    printf("dizi ilk hali = \n");
    for(i=0; i<n; i++)
	{
    	printf("%d\t",merge[i]);
	}
	printf("\n");
    partition(merge,0,n-1);

    printf("merge sort uygulanmis dizi=\n");
    for(i=0;i<n;i++){
         printf("%d\t",merge[i]);
    }
	getch();
   return 0;
}

void partition(int arr[],int low,int high){

    int mid;

    if(low<high){
         mid=(low+high)/2;
         partition(arr,low,mid);
         partition(arr,mid+1,high);
         mergeSort(arr,low,mid,high);
    }
}

void mergeSort(int arr[],int low,int mid,int high){

    int i,m,k,l,temp[50];

    l=low;
    i=low;
    m=mid+1;

    while((l<=mid)&&(m<=high)){

         if(arr[l]<=arr[m]){
             temp[i]=arr[l];
             l++;
         }
         else{
             temp[i]=arr[m];
             m++;
         }
         i++;
    }

    if(l>mid){
         for(k=m;k<=high;k++){
             temp[i]=arr[k];
             i++;
         }
    }
    else{
         for(k=l;k<=mid;k++){
             temp[i]=arr[k];
             i++;
         }
    }
   
    for(k=low;k<=high;k++){
         arr[k]=temp[k];
    }
}
