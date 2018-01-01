



main: fonctionsUsuelles.o cuissine.o
	gcc cuissine.o fonctionsUsuelles.o -o main

main.o: fonctionsUsuelles.h article.h cuissine.c
	gcc -c cuissne.c -o main.o

fonctions.o: fonctionsUsuelles.c article.h
	gcc -c fonctionsUsuelles.c -Wall -o fonctionsUsuelles.o
