/*
@file
Programming Language spring2013 assignment 2.
A program that designs a check-in/check-out system for a hotel.

@author
Name				: Fatih �omak
Student no			: 12011015
Date				: 22/10/2014
E-Mail				: fatihchomak@gmail.com
					  fatihchomak@hotmail.com
Compiler used		: TDM-GCC 4.7.1 64-bit
IDE					: Dev-C++ 5.4.1
Operating System 	: Windows 8.1 Single Language
					  64 bit ��letim Sistemi, x64 tabanl� i�lemci
CPU					: Intel(R) Core(TM) i7-3630QM CPU @ 2.40GHz 2.40 Ghz
RAM					: 16,0 GB (kullan�labilir miktar: 15,9 GB)
*/

#include "Header.h"
int main()
{
	
	int input,N=0;
	int total = 0;
	long long *array;
	array = (long long*)malloc(0);
	printf("Hello World!\nWelcome of check-in/check-out system for a hotel.\n\n");
	do
	{
		printf("Press 1 for CHECK-IN\nPress 2 for CHECK-OUT\nPress 3 for DISPLAY CUSTOMER LIST\nPress 4 for EXIT\n");
		scanf("%d",&input);
		switch(input)
		{
			case 1 :
				{
					printf("Enter the number of new customers:\n");
					scanf("%d",&N);
					array = check_in(N, &total, array);
					break;
				}
			case 2 :
				{
					if(N==0)//program�n ilk kullan�m�nda N degerimiz 0 atand��� i�in bu caseye gelinirse tekrar ba�a d�ner.
					{
						break;
					}
					printf("Enter the number of leaving customers:\n");
					scanf("%d",&N);
					
					if(N>=total)//silinecek ki�i say�s� oteldeki ki�i say�s�na e�it veya daha fazla olursa break komutu �al���r.
					{
						break;
					}
					
					array = check_out(N, &total, array);
					break;
				}
			case 3 :
				{
					display(total, array);
					break;
				}
			case 4 :
				{
					break;
				}
			default:
				{
					printf("Wrong Choice, Please Press a Number Again\n");
				}
		}
	}
	while(input!=4);//input olarak okudu�umuz de�ere 4 girilene kadar program �al���r.
	
	getchar();
}

long long* check_in(int add, int *total, long long *array)
{
	long long *newarray;
	int i;
	newarray =(long long*) realloc(array , (*total+add)*sizeof(long long));
	//newarray eklenen ki�ilerin sona eklenmesiyle bellekte realloc ile olu�turulur
	
	if(!newarray)//eklenecek ki�i say�s� bellek alan�ndan daha fazla girildi�inde program exit verir
		exit(1);
	
	for(i=0;i<add;i++)
	{
		printf("%d. customer's ID is :   ",i+1);
		scanf("%lld",&newarray[*total+i]);
	}
	printf("\n");
	*total += add;
	return newarray;
	
}

long long* check_out(int del, int *total, long long *array)
//del degiskeni silinecek ki�i say�s�d�r
{
	long long *donearray;
	long long entry;
	int i,j;
	int tmp=0;
	
	for(i=0;i<del;i++)
	{
		printf("%d. customer's ID is :   ",i+1);
		scanf("%lld",&entry); //entry silinecek ID girdisi
		j=0;
		while((entry!=(array[j])) && j<(*total))
		{
			j++;
		}
		
		if(j==(*total))
		//tamam�n� taray�p bulamam��sa b�yle bir numara yoktur
		{
			printf("ID not found!\n");
			tmp++; //tmp sayac� bulunamayan her silme IDsini sayar ve daha sonra yeni dizimizde d���lecek eleman say�s�ndan eksiltilir.(del-tmp) �eklinde
		}
		else
		{
			array[j]=-1;
			//bulunduysa da ID yerine -1 atanmaktad�r
		}
	}
	
	j=0;
	
	//donearray dizimiz, ID numaras�na -1 atanan g�zlerin olmad��� fakat di�er elemanlar�n ta��naca�� yeni dizimiz
	donearray =(long long*)malloc((*total - del + tmp)*sizeof(long long));//malloc ile bellekte yer ayr�l�r, yeni dizimiz i�in
	for(i=0;i<(*total);i++)
	{
		if(array[i]!=-1)
		//adres eleman� -1 olmayan g�zleri yeni olu�an dizimize aktar�yoruz
		{
			donearray[j]=array[i];
			j++;
		}
	}
	*total = *total-del+tmp;
	printf("\n");
	free(array); //eski dizimizin bellekteki yeri temizlendikten sonra yeni dizimizi ana fonksiyona d�nd�r�yoruz
	return donearray;
}

void display(int total, long long *array)
{
	int i=0;
	printf("   LIST OF CUSTOMERS\n\n");
	for(i=0;i<total;i++)
	{
		printf("Customer %d :   %lld\n",i+1,array[i]);
	}
	printf("\n");
}
