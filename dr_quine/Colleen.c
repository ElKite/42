#include <stdio.h>

/*
	This function is useless
*/
void im_useless(char * program)
{
	printf(program, 10, 10, 10, 9, 10, 10, 10, 10, 9, 10, 10, 10, 10, 10, 9, 10, 9, 9, 10, 9, 10, 9, 34, program, 34, 10, 9, 10, 10);
}

int main()
{
	/*
		I'm a comment
	*/
	char *program = "#include <stdio.h>%c%c/*%c%cThis function is useless%c*/%cvoid im_useless(char * program)%c{%c%cprintf(program, 10, 10, 10, 9, 10, 10, 10, 10, 9, 10, 10, 10, 10, 10, 9, 10, 9, 9, 10, 9, 10, 9, 34, program, 34, 10, 9, 10, 10);%c}%c%cint main()%c{%c%c/*%c%c%cI'm a comment%c%c*/%c%cchar *program = %c%s%c; im_useless(program);%c%creturn 0;%c}%c"; im_useless(program);
	return 0;
}
