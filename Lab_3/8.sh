#!/bin/bash
#sprzatac chcialem komenda:
# kill -9 $(pgrep -u user -n "8\.*")
#
# jednak dostawalem taki komunikat gdy chcialem posprzatac
#bash: fork: retry: Resource temporarily unavailable
# wiec nie udalo sie posprzatac

echo $$;
echo
echo "Program zbyt niebezpieczny. Nie uruchamiac dalej jesli nie wiesz co robisz";
while [ true ]; do
	./8.sh
	echo hej;
	sleep 3;
done