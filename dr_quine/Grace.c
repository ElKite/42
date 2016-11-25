#include <stdio.h>
/*
	Ceci est un commentaire
*/
#define kid "Grace_kid.c"
#define S "#include <stdio.h>%c/*%c%cCeci est un commentaire%c*/%c#define kid %cGrace_kid.c%c%c#define S %c%s%c%c#define start() int main() {FILE *f = fopen(kid, %cw%c);fprintf(f, S, 10, 10, 9, 10, 10, 34, 34, 10, 34, S, 34, 10, 34, 34, 10, 10);}%cstart();%c"
#define start() int main() {FILE *f = fopen(kid, "w");fprintf(f, S, 10, 10, 9, 10, 10, 34, 34, 10, 34, S, 34, 10, 34, 34, 10, 10);}
start();
