#include<stdio.h>
#include<conio.h>
main(){
       int n,i,j,k;
       int *a,x,*tree;
       printf("Dizinizin boyutunu giriniz:\n");
       scanf("%d",&n);
/*Diziler için yer tutulur. Aðaç dizis, verilen dizinin en az 4 katý olmalýdýr. Calloc ile agaç dizisine ilk deðer olarak 0 atanýr. */
       a=(int *)malloc((n+1)*sizeof(int));
       tree=(int *)calloc((n+1)*4,sizeof(int)); 

       printf("Diziyi giriniz:\n");
       for(i=1;i<=n;i++) scanf("%d",&a[i]);

       tree[1]=a[1];
       for(i=2;i<=n;i++){
                j=1;
                while(tree[j]!=0){
                          if(a[i]>tree[j])
                                   j=2*j+1;
                                   else
                                   j=2*j;
                                   }
                tree[j]=a[i];
                }

       printf("\nAgac dizisi:\n");
       for(i=1;i<=(n*4);i++) printf("%d ",tree[i]);  
	   
	   printf("\nsilinecek elemani seciniz.\n");
	   scanf("%d",&x);
	   j=1;
	   while(tree[j]!=x && tree[j]!=0 )
	   {
	   	if(x>tree[j])
	   	{
	   		j=j*2+1;
	   	}else
	   	{
	   		j=2*j;
	   	}
	   }
	   if(tree[j]==x)
	   {
	   	
	   	tree[j]=0;

	   	while(tree[j*2]!=0 || tree[j*2+1]!=0)
	   	{
	   		printf("\n a");
	   		if(tree[j*2]!=0 && tree[j*2+1]==0)//sadece solda varsa
	   		{
	   			printf("\n b");
	   			k=j;
	   			j=j*2;
	   			if(tree[j*2+1]!=0)
	   			{
	   				j=j*2+1;
	   				tree[k]=tree[j];
	   				tree[j]=0;
	   			}
	   			else
	   			{
	   				tree[k]=tree[j];
					tree[j]=0;	
			 	}   	   			

	   		}
	   		else // saðda varsa
	   		{
	   			printf("\n d");
	   			k=j;
	   			j=j*2+1;
	   			if(tree[j*2]!=0)
	   			{
	   				j=j*2;
	   				tree[k]=tree[j];
	   				tree[j]=0;
	   			}
	   			else
	   		    {
	   		       	tree[k]=tree[j];
					tree[j]=0;	  	
	   		    }
	   			
	   			
	   		}
	   		
	   	}

	   	
	   	
	   }else//silinecek eleman yoksa
	   {
	   	printf("HATA!!!");
	   }
		printf("\nAgac dizisi:\n");
		for(i=1;i<=(n*4);i++) printf("%d ",tree[i]) ; 
	   
	   

       getch();
       
       }

