#include <stdio.h>

/*
	This function is useless
*/
void im_useless()
{

}

int main()
{
	/*
		I'm a comment
	*/
	char *program = "#include <stdio.h>%c%c/*%c%cThis function is useless%c*/%cvoid im_useless()%c{%c%c}%c%cint main()%c{%c%c/*%c%c%cI'm a comment%c%c*/%c%cchar *program = %c%s%c;%c%cprintf(program, 10, 10, 10, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 9, 10 , 9, 9, 10, 9, 10, 9, 34, program, 34, 10, 9, 10, 9, 10, 10);%c%creturn 0;%c}%c";
	printf(program, 10, 10, 10, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 9, 10 , 9, 9, 10, 9, 10, 9, 34, program, 34, 10, 9, 10, 9, 10, 10);
	return 0;
}
