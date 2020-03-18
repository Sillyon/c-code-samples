#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define THREAD_SAYISI 10
pthread_mutex_t lock;
int sayac;

void * giris_fonksiyonu(void * threadno)
{	
	pthread_mutex_lock(&lock);

	sleep(rand()%5);
	int i;
	sayac += 1;
	printf("%d. islem basladi...\n",sayac);
	for(i=0; i<(0xFFFFF);i++);
	printf("%d. islem bitti...\n",sayac);
	
	pthread_mutex_unlock(&lock);
    pthread_exit(NULL);
}

int main() {
	pthread_t threadler[THREAD_SAYISI];

	if(pthread_mutex_init(&lock,NULL) != 0) {
		printf("mutex baslatilamadi\n");
		return 1;
	}

	long i,donus_degeri;
	srand(time(NULL));

    for(i=0; i<THREAD_SAYISI; i++){
        //printf("__________ %ld. thread olusturuluyor...\n", i);
        donus_degeri = pthread_create(&threadler[i], NULL, giris_fonksiyonu, (void *)i);
        if (donus_degeri){
            printf("HATA : %ld\n", donus_degeri);
            exit(-1);
       }
    }

    // tum threadler bitene kadar bekle
    for(i=0; i<THREAD_SAYISI;i++) {
        donus_degeri = pthread_join(threadler[i], NULL);
        if (donus_degeri){
            printf("HATA : %ld. threadde bir sorun oldu\n", donus_degeri);
            exit(-1);
        }
    }

	return 0;
}