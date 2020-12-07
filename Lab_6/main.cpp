#include <iostream>
#include <fstream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#define PLIK_WSPOLDZIELONY "pamiec"
#define MODES 0666

using namespace std;

int main(int argc, char *argv[])
{
    int fd, i = 0;
    char nazwa_pliku[100], tmp;
    struct stat FileStat;
    char *pamiec;

    fd = open(PLIK_WSPOLDZIELONY,
              O_RDWR | O_CREAT, // odczyt/zapis, jesli nei ma to uworz
              S_IRWXU | S_IROTH | S_IWOTH | S_IXOTH); // utworzy z takimi prawami

    while (1)
    {
        cout << "Nazwa pliku: ";
        cin >> nazwa_pliku;
        if (nazwa_pliku[0] == 'q')
            break;

        stat(nazwa_pliku, &FileStat); // pobieranie informacji o pliku
        pamiec = (char *)mmap(NULL,
                              FileStat.st_size,
                              PROT_READ | PROT_WRITE,
                              MAP_SHARED,
                              fd, 0);    // mapowanie pamieci w programie
        ftruncate(fd, FileStat.st_size); // zmiana rozmaru pliku na dysku

        fstream file(nazwa_pliku, fstream::in); // otwarcie pliku do odczytu
        i = 0;
        while (file >> noskipws >> tmp) // czytanie z pliku znak po znaku
            pamiec[i++] = tmp;          // zapisywanie znaku do pliku i zwiekszanie wskaznika pamieci

        cout << "Pomyslnie zapisano do pliku!" << endl;
    }

    ftruncate(fd, 0);                         // czyszczenie pliku na dysku
    munmap((void *)pamiec, FileStat.st_size); // zwalnianie pamieci w programie
    close(fd);                                // zamykanie pliku pamieci wspoldzielonej
    return 0;
}