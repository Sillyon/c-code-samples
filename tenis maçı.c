#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
int main ()
{
	int N,a,i,k,b,c;
	char oyuncu1[10],oyuncu2[10];
	printf("oyuncu1 ismi = ");
	scanf("%s",&oyuncu1);
	printf("oyuncu2 ismi = ");
	scanf("%s",&oyuncu2);
	srand(time(NULL));
	while(a!=1)
	{
		printf("set sayisini giriniz.(3 veya 5)\n");
		scanf("%d",&N);
		if((N==3) || (N==5))
		a=1;
	}
	
	int set1=0,set2=0,oyun1,oyun2,sayi1,sayi2;
	
	for(i=1;i<=N;i++)
	{
		printf("%d. set basladi..\n",i);
		oyun1=0;
		oyun2=0;
		c=0;
		
		while(c!=1)
		{
			sayi1=0;
			sayi2=0;
			b=0;
			
			while(b!=1)
			{
				k=rand()%2;
				if(k==0)
				{
				
					sayi1=sayi1+1;
				}
				else
				{
					
					sayi2=sayi2+1;
				}
				if((sayi1==4) && (sayi2==4))
				{
					sayi1--;
					sayi2--;
				}
				if(sayi1==4)
				{
					if(sayi2<3)
					{
						sayi1=5;
					}
				}
				
				if(sayi2==4)
				{
				
					if(sayi1<3)
					{
						sayi2=5;
					}
					
				}
				
				if((sayi1==5) || (sayi2==5))
				{
					b=1;
				}
				switch(sayi1)
				{
				case 0: printf("%s  0 - ",oyuncu1);break;
				case 1: printf("%s 15 - ",oyuncu1);break;
			    case 2: printf("%s 30 - ",oyuncu1);break;
			    case 3: printf("%s 40 - ",oyuncu1);break;
			    case 4: printf("%s  A - ",oyuncu1);break;
			    case 5: printf("%s OYUN ",oyuncu1);break;
				}
			    switch(sayi2)
			    {
				case 0: printf("%s  0\n",oyuncu2);break;
				case 1: printf("%s 15\n",oyuncu2);break;
			    case 2: printf("%s 30\n",oyuncu2);break;
			    case 3: printf("%s 40\n",oyuncu2);break;
			    case 4: printf("%s  A\n",oyuncu2);break;
			    case 5: printf("%s OYUN\n",oyuncu2);break;
			    }
			}
			
			if(sayi1>sayi2)
			{
				
				oyun1=oyun1+1;
			}
			else
			{
			    
				oyun2=oyun2+1;
			}
			if(((oyun1>=6) && (oyun1-oyun2>=2)) || ((oyun2>=6) && (oyun2-oyun1>=2)))
			{
				c=1;
			}	
			
		}
		
		if((oyun1-oyun2>=2) || (oyun1==7))
		{
			printf(" %d. seti %s kazandi!\n",i,oyuncu1);
			set1++;
		}
		else
		{
			printf(" %d. seti %s kazandi!\n",i,oyuncu2);
			set2++;
		}
		printf("%d-%d\n",oyun1,oyun2);
	}
	
	if(set1>set2)
	{
		printf("  %s OYUNU KAZANDI!",oyuncu1);
	}
	else
	{
		printf("  %s OYUNU KAZANDI!", oyuncu2);
	}
	
	return 0;
}
