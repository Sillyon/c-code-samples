#include<stdio.h>
#include<stdlib.h>
int main()
{
    int NA,A[10],linkA[10],headA,NB,B[10],linkB[10],headB,headC,adr,C[20],linkC[20],i,NC,j,k,tmp,baslangic;
    printf("1.dizinin eleman sayisini giriniz\n");
    scanf("%d",&NA);
    for(i=0;i<NA;i++)
    {
        printf(" %d . elemani giriniz :  ",i);
        scanf("%d",&A[i]);
    }
    printf("Head A yi giriniz \n");
    scanf("%d",&headA);
    printf("1.dizinin linkini giriniz\n");
    for(i=0;i<NA;i++)
    {
        printf(" %d . elemani giriniz :  ",i);
        scanf("%d",&linkA[i]);
    }
    printf("2.dizinin eleman sayisini giriniz\n");
    scanf("%d",&NB);
    for(i=0;i<NB;i++)
    {
        printf(" %d . elemani giriniz :  ",i);
        scanf("%d",&B[i]);
    }
    printf("Head B yi giriniz \n");
    scanf("%d",&headB);
    printf("2.dizinin linkini giriniz\n");
    for(i=0;i<NB;i++)
    {
        printf(" %d . elemani giriniz :  ",i);
        scanf("%d",&linkB[i]);
    }
    
    printf("\n\nHead A : %d\n",headA);
    printf("A dizisi : \n");
    for(i=0;i<NA;i++)
    {
        printf(" %d ",A[i]);
    }
    printf("\nLink A dizisi : \n");
    for(i=0;i<NA;i++)
    {
        printf(" %d ",linkA[i]);
    }

    printf("\n\nHead B : %d\n",headB);
    printf("B dizisi : \n");
    for(i=0;i<NB;i++)
    {
        printf(" %d ",B[i]);
    }
    printf("\nLink B dizisi : \n");
    for(i=0;i<NB;i++)
    {
        printf(" %d ",linkB[i]);
    }


    NC=NB+NA;
    for(i=0;i<NC;i++)
    {
        linkC[i]=-1;
    }
    i=0;
    j=0;
    k=0;
    while(i<NC)
    {
        while(j<NA)
        {
            C[j]=A[j];
            j++;
            i++;
        }
        C[i]=B[k];
        k++;
        i++;

    }

    if(C[headA]<=C[headB+NA])
    {
        headC=headA;
        tmp=headB+NA;
    }
    else
    {
        headC=headB+NA;
        tmp=headA;
    }
    baslangic=headC;
    adr=headC;

    while(adr!=-1)
    {
        if(adr>(NA-1))
        {
            adr=adr-NA;
            adr=linkB[adr];
            if(adr!=-1)
            {
                adr=adr+NA;
                if(C[adr]<=C[tmp])
                {
                    linkC[headC]=adr;
                    headC=adr;
                }
                else
                {
                    linkC[headC]=tmp;
                    headC=tmp;
                    tmp=adr;
                    adr=headC;
                }

            }
        }
        else
        {
            adr=linkA[adr];
            if(adr!=-1)
            {
                if(C[adr]<=C[tmp])
                {
                    linkC[headC]=adr;
                    headC=adr;
                }
                else
                {
                    linkC[headC]=tmp;
                    headC=tmp;
                    tmp=adr;
                    adr=headC;
                }

            }

        }
    }
    printf("\n\n\nHead C : %d\n",baslangic);
    linkC[headC]=tmp;
    printf("--------------\nC dizisi :\n");
    for(i=0;i<NC;i++)
    {
        printf(" %d ",C[i]);
    }
    printf("\n\nLink C dizisi :\n");
    for(i=0;i<NC;i++)
    {
        printf(" %d ",linkC[i]);
    }


    return 0;

}

