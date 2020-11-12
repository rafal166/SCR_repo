// do topa dodalem opcje -d [sekundy] zeby zmniejsyzc czas odswierzania
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <csignal>
using namespace std;

void slepInNano(int milisec = 100)
{
    struct timespec req = {0};
    req.tv_sec = 0;
    req.tv_nsec = milisec * 1000000L;
    nanosleep(&req, (struct timespec *)NULL);
}

void ALRM_func(int signal)
{
    cout << "SIGALRM: " << signal << endl;
}

void TERM_func(int signal)
{
    cout << "SIGTERM: " << signal << endl;
    exit(signal);
}

void USR1_func(int signal)
{
    cout << "SIGUSR1: " << signal << endl;
    exit(signal);
}

void USR2_func(int signal)
{
    cout << "SIGUSR2: " << signal << endl;
    exit(signal);
}

int main()
{
    int iterator = 0;

    signal(SIGALRM, ALRM_func); //b
    signal(SIGTERM, TERM_func); // a
    signal(SIGUSR1, USR1_func);
    signal(SIGUSR2, USR2_func);

    while (1)
    {
        cout << iterator << endl;
        iterator++;
        slepInNano(100);
        raise(SIGALRM);
        if (iterator == 30)
        {
            signal(SIGALRM, SIG_IGN);
            raise(SIGALRM);
        }
        else if (iterator == 50)
            signal(SIGALRM, ALRM_func);
    }
    return 0;
}