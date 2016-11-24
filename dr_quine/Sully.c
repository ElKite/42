#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define S "#include <stdio.h>%c#include <stdlib.h>%c#include <string.h>%c#define S %c%s%c%cint main() {%c%cint i = %d;%c%cFILE *f = fopen(%cSully_%d.c%c, %cw%c);%c%ci = (strcmp(__FILE__, %cSully.c%c) == 0 ? 5 : i - 1);%c%cfprintf(f, S, 10, 10, 10, 34, S, 34, 10, 10, 9, i, 10, 9, 34, i, 34, 34, 34, 10, 9, 34, 34, 10, 9, 10, 9, 10, 9, 34, i, i, i, 34, 10, 10);fclose(f);%c%cif (i >= 0)%c%csystem(%cclang -Werror -Wextra -Wall -o Sully_%d Sully_%d.c; ./Sully_%d%c);%c}%c"
int main() {
	int i = 5;
	FILE *f = fopen("Sully_5.c", "w");
	i = (strcmp(__FILE__, "Sully.c") == 0 ? 5 : i - 1);
	fprintf(f, S, 10, 10, 10, 34, S, 34, 10, 10, 9, i, 10, 9, 34, i, 34, 34, 34, 10, 9, 34, 34, 10, 9, 10, 9, 10, 9, 34, i, i, i,34, 10, 10);fclose(f);
	if (i >= 0)
	system("clang -Werror -Wextra -Wall -o Sully_5 Sully_5.c; ./Sully_5");
}
