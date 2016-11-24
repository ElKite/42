#include <stdio.h>
/*
	Ceci est un commentaire
*/
#define kid "Grace_kid.c"
#define S "#include <stdio.h>%c/*%c%cCeci est un commentaire%c*/%c#define kid %cGrace_kid.c%c%c#define S %c%s%c%c#define start main%c%cint start() {%c%cFILE *f = fopen(kid, %cw%c);%c%cfprintf(f, S, 10, 10, 9, 10, 10, 34, 34, 10, 34, S, 34, 10, 10, 10, 10, 9, 34, 34, 10, 9, 10, 10);%c}%c"
#define start main

int start() {
	FILE *f = fopen(kid, "w");
	fprintf(f, S, 10, 10, 9, 10, 10, 34, 34, 10, 34, S, 34, 10, 10, 10, 10, 9, 34, 34, 10, 9, 10, 10);
}
