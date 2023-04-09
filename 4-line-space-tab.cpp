/*Count the number of lines, tabs and spaces*/

%{
	int cnt_l=0, cnt_s=0, cnt_t=0;
%}

%%
[\n] {cnt_l++;} 
[ \t] {cnt_s++;}
[^\t] {cnt_t++;}
%%

int yywrap() {}

int main()
{
	printf("Enter the text: \n");
	yylex();
	printf("\nNo. of lines = %d", cnt_l);
	printf("\nNo. of tabs = %d", cnt_t);
	printf("\nNo. of spaces = %d", cnt_s);
	return 0;
}


