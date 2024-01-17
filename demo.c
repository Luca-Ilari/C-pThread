#include <stdio.h>
#include <pthread.h>

#define N_THREAD 5
#define MAX_TEMPS 10
#define K 2

void *somma(void *void_arr){
    double sum = 0;
    double *arr = (double*)(void_arr);         //convert from void pointer to double pointer

    for(int i = 0; i < K; ++i){
        sum = sum + *arr;
        ++arr;
    }
    printf("%f\n", sum);
    return NULL;
}

int main(int argc, char** argv){
    double temperature[MAX_TEMPS]= {24,32,12,32,21,12,12.9,42,23.7,25.2};
    int i;
    double* start_idx;
    pthread_t threadsArr[N_THREAD];

    for(i = 0; i < N_THREAD; ++i){
        start_idx = temperature + (i * (MAX_TEMPS / N_THREAD));
        pthread_create(&threadsArr[i], NULL, somma, (void*)start_idx);
    }

        //join all started threads
    for (i = 0; i < N_THREAD; ++i) {
        pthread_join(threadsArr[i],NULL);
        printf("Finished a thread\n");
    }
    return 0;
}
