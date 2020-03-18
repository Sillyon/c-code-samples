#include <stdio.h>
#include <stdbool.h>
 
int main() {
    int curr[5][5];
    int max_claim[5][5];
    int avl[5];
    int alloc[5] = {0, 0, 0, 0, 0};
    int max_res[5];
    int running[5];
 
    int i, j, exec, r, p;
    int count = 0;
    bool guvenli = false;
 
    printf("\nKaynak sayisini girin: ");
    scanf("%d", &r);
 
    printf("\nProcess sayisini girin: ");
    scanf("%d", &p);
    for (i = 0; i < p; i++) {
        running[i] = 1;
        count++;
    }
 
    printf("\nIstek kaynaklarini girin: ");
    for (i = 0; i < r; i++)
        scanf("%d", &max_res[i]);
 
    printf("\nAyrilan kaynak tablosunu girin: ");
    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++)
            scanf("%d", &curr[i][j]);
    }
 
    printf("\nAzami istek tablosunu girin: ");
    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++)
            scanf("%d", &max_claim[i][j]);
    }
 
    printf("\nIstek kaynaklari: ");
    for (i = 0; i < r; i++)
        printf("%d ", max_res[i]);
 
    printf("\nAyrilmis kaynak tablosu:\n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++)
            printf("\t%d", curr[i][j]);
        printf("\n");
    }
 
    printf("\nAzami istek tablosu:\n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++)
            printf("\t%d", max_claim[i][j]);
        printf("\n");
    }
 
    for (i = 0; i < p; i++)
        for (j = 0; j < r; j++)
            alloc[j] += curr[i][j];
 
    printf("\nAyrilan kaynaklar: ");
    for (i = 0; i < r; i++)
        printf("%d ", alloc[i]);
    for (i = 0; i < r; i++)
        avl[i] = max_res[i] - alloc[i];
 
    printf("\nMusait kaynaklar: ");
    for (i = 0; i < r; i++)
        printf("%d ", avl[i]);
    printf("\n");
 
    while (count != 0) {
        guvenli = false;
        for (i = 0; i < p; i++) {
            if (running[i]) {
                exec = 1;
                for (j = 0; j < r; j++) {
                    if (max_claim[i][j] - curr[i][j] > avl[j]) {
                        exec = 0;
                        break;
                    }
                }
 
                if (exec) {
                    printf("\nProcess%d calistiriliyor.\n", i + 1);
                    running[i] = 0;
                    count--;
                    guvenli = true;
                    for (j = 0; j < r; j++)
                        avl[j] += curr[i][j];
                    break;
                }
            }
        }
 
        if (!guvenli) {
            printf("\nProcessler guvenli olmayan durumdadir..");
            break;
        }
 
        if (guvenli)
            printf("\nProcess guvenli durumdadir..");
 
        printf("\nMusait durumu: ");
        for (i = 0; i < r; i++)
            printf("%d ", avl[i]);
    }
 
    return 0;
}
