#!/bin/bash

function on_quit(){
	echo Bajo!;
	exit;
}

function on_fpe(){
	echo "Przekroczylem limit, sorry musze sie wylaczyc";
	exit;
}
function on_int(){
	echo "Jakis int, nie rusza mnie to";
	exit;
}

function on_kill(){
	echo "To nie zadziala";
	exit;
}

#trap on_quit EXIT;
trap on_fpe SIGFPE;
trap on_int SIGINT; #przerwanie z klawiatury Crl+C
trap on_quit SIGQUIT; #przerwanie z klawiatury Crl+\
trap on_kill SIGKILL; # tego nie mozna przechwycic
trap "echo SIGILL" SIGILL; # nielegalna instrukcja
trap "echo SIGTRAP" SIGTRAP; # breakpoint
trap "echo SIGHUP" SIGHUP; # przerwanie terminala
trap "echo SIGABRT" SIGABRT; # sygnal abort
trap "echo SIGBUS" SIGBUS; # blad dostepu do pamieci
trap "echo SIGSEGV" SIGSEGV; # bledne odwolanie do pamieci
trap "echo SIGSYS" SIGSYS; # blad wywolania funkcji systemowej
trap "echo SIGPIPE" SIGPIPE; # blad otoku
trap "echo SIGALRM" SIGALRM; # blad timera
trap "echo SIGTERM" SIGTERM; # zatrzymanie procesu

echo $$ > /tmp/skrypt.sh.pid;

while [ true ]; do
	echo `date +%R`;
	sleep 2;
done