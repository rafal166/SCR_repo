// W pierwszym eksperymencie zwykle byl pierwszy.
// teraz ju w ogle nie jest na poczatku listy
// do topa dodalem opcje -d [sekundy] zeby zmniejsyzc czas odswierzania
#include <stdio.h>
#include <iostream>
#include <time.h>
using namespace std;

void slepInNano(int milisec = 100)
{
    struct timespec req = {0};
    req.tv_sec = 0;
    req.tv_nsec = milisec * 1000000L;
    nanosleep(&req, (struct timespec *)NULL);
}

int main()
{
    int iterator = 0;

    while (1)
    {
        cout << iterator << endl;
        iterator++;
        slepInNano(100);
    }
    return 0;
}