// miara czasu ogolna -> -c
// miara czasu kazdej linijki -ttt
// drugie brk powinno zwrocic 0, a zzwrocilo obecny adres, czyli adres podany do

#include <stdio.h>
char *napis = "Witajcie moi mili ...";
int main()
{
  unsigned int index = 0;
  for (index;; index++)
  {
    // if (index > 22)
    //   break;
    printf("%c", napis[index]);
  }
  return 0;
}