#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
	int pipe_fds[2], size;
	char inbuf[100];

	// Tworze potok
	if (pipe(pipe_fds) < 0)
	{
		cout << "Nie udalo sie otworzyc potoku" << endl;
		return 1;
	}
	int i = 0;
	int jakis_fork = fork();
	
	switch (jakis_fork)
	{
	case -1:
		cout << "Error" << endl; // nie udalo sie utworzyc potomka
		exit(1);
	case 0:
		// potomek
		cout << "potomek";
		close(pipe_fds[1]); // zamykanie potoku do zapisu

		while ((size = read(pipe_fds[0], inbuf,
							BUFSIZ)) > 0) // czytanie z potoku do bufora
		{
			write(1, "#", sizeof "#"); // wypisywanie na
			write(1, inbuf, size);
			write(1, "#\n", sizeof "#\n");
		}
		break;
	default:
		//rodzic
		cout << "rodzic";
		close(pipe_fds[0]); // zamykanie potoku do odczytu
		char tmp;

		// otwieram plik do odczytu
		fstream file(argv[1], fstream::in); // otwarcie pliku do odczytu
		while (file >> noskipws >> tmp)		// czytanie z pliku znak po znaku
		{
			write(pipe_fds[1], &tmp, sizeof tmp);
		}
		break;
	}
	// zamykanie pozostaych strumieni
	close(pipe_fds[0]);
	close(pipe_fds[1]);
	return 0;
}