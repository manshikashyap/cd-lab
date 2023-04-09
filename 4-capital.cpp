/* To find capital letters */

%{
	int count = 0;
%}

%%
[A-Z] {printf("%s is a capital letter\n", yytext); count++;}
. {printf("%s is not a capital letter\n", yytext);}
\n {return 0;}
%%

int yywrap(){}

int main()
{
	printf("Enter a string: \n");
	yylex();
	printf("Number of capital letters = %d\n", count);
	return 0;
}


