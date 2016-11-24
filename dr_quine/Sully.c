#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define A "Sully_%d.c"
#define B "./Sully_%d"
#define F "clang -Wall -Werror -Wextra -o Sully_%d Sully_%d.c"
#define S "#include <stdio.h>%c#include <stdlib.h>%c#include <string.h>%c#define A %cSully_%cd.c%c%c#define B %c./Sully_%cd%c%c#define F %cclang -Wall -Werror -Wextra -o Sully_%cd Sully_%cd.c%c%c#define S %c%s%c%cint main() {%c%cint i = %d;%c%ci = (strcmp(__FILE__, %cSully.c%c) == 0 ? 5 : (i > 0 ? i - 1 : 0));%c%cchar a[50];sprintf(a, A, i );FILE *f = fopen(a, %cw%c);%c%cfprintf(f, S, 10, 10, 10, 34, 37, 34, 10, 34, 37, 34, 10, 34, 37, 37, 34, 10, 34, S, 34, 10, 10, 9, i, 10, 9, 34, 34, 10, 9, 34, 34,10, 9, 10, 9, 10, 9, 10, 9, 10, 9, 10, 10);fclose(f);%c%cif (i >= 0)%c%c{char s[200];sprintf(s, F, i, i);system(s);}%c%cif (i > 0)%c%c{char s[200];sprintf(s, B, i);system(s);}%c}%c"
int main() {
	int i = 5;
	i = (strcmp(__FILE__, "Sully.c") == 0 ? 5 : (i > 0 ? i - 1 : 0));
	char a[50];sprintf(a, A, i );FILE *f = fopen(a, "w");
	fprintf(f, S, 10, 10, 10, 34, 37, 34, 10, 34, 37, 34, 10, 34, 37, 37, 34, 10, 34, S, 34, 10, 10, 9, i, 10, 9, 34, 34, 10, 9, 34, 34,10, 9, 10, 9, 10, 9, 10, 9, 10, 9, 10, 10);fclose(f);
	if (i >= 0)
	{char s[200];sprintf(s, F, i, i);system(s);}
	if (i > 0)
	{char s[200];sprintf(s, B, i);system(s);}
}
