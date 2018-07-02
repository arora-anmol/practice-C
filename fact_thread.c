/*
    Creates 2 threads to calculate factorial
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int factorial=1;
int product=1;
void  *helper_method(void *arg);

int main(int argc, char *argv[]) {

    if (argc != 2){
        fprintf(stderr, "Wrong number of inputs \n");
        return -1;

    } 
    int start_val = atoi(argv[1]);
    void* return_val;
    pthread_t helper_thread;

    pthread_create(&helper_thread, NULL, helper_method, &start_val);

    printf("Created the thread \n");
    for(int i = start_val; i>start_val/2; i--){
        factorial*=i;
    }

    pthread_join(helper_thread, &return_val);

    printf("factorial : %d \n", factorial);

    factorial = factorial* (*(int*)return_val);
    printf("\n The factorial of the number is: %d \n", factorial);
    return 0;


}

void *helper_method(void *my_start_val){

    int *start_val = (int *)my_start_val;
   // printf("\n Reached here in new thread \n");
    for(int i = *start_val/2; i>0; i--){
        product*=i;
    }
    printf(" Product: %d \n", product);
    return ((void *)(&product));
}
