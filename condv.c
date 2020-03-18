#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  c = PTHREAD_COND_INITIALIZER;
int sayac = 0, aralik1 = 3, aralik2 = 6;

void * f1() {
  while(1) {
    pthread_mutex_lock(&m); // mutexi kilitle
    pthread_cond_wait(&c,&m); // f2 calisirken bekle, sinyal gönderecek
    sayac++; printf("f1 : %d\n", sayac);
    pthread_mutex_unlock(&m); // mutexi kilidini aç
    if(sayac >= 10) return(NULL);
  }
}

void * f2() {
  while(1) {
    pthread_mutex_lock(&m);
    if (sayac < aralik1 || sayac > aralik2) { pthread_cond_signal(&c); }
    else { sayac++; printf("**f2 : %d\n", sayac); }
    pthread_mutex_unlock(&m);
    if(sayac >= 10) return(NULL);
  }
}


int main() {
  pthread_t t1, t2;
  pthread_create(&t1, NULL, &f1, NULL);
  pthread_create(&t2, NULL, &f2, NULL);
  pthread_join(t1, NULL); pthread_join(t2, NULL);
  printf("Sayacin son durumu : %d\n", sayac);
  return 0;
}
