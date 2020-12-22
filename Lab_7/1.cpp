#include <iostream>
#include <fstream>
#include <pthread.h>
#include <unistd.h>
#define NUM_THREADS 8

using namespace std;

void *hello_function(void *threadid)
{
    cout << "Hello SCR. Written by thread " << (long *)threadid << endl;
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];
    cout << "Hello SCR. Written by MAIN" << endl;

    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_create(&(threads[i]), NULL, hello_function, (void *)i);
    }
    pthread_exit(NULL);
}

// bylem swiadomy, ze nie zostana wypisane w uporzadkowanej kolejnosci