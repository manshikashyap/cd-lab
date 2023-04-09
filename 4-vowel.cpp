/* To find whether given letter is a vowel or not */

%{
    int vowel=0;
    int cons=0;
%}

%%
[aeiouAEIOU] {printf("%s is a vowel", yytext); vowel++;}
[a-zA-z] {printf("%s is a consonant", yytext); cons++;}
[0] {return 0;}
%%

int yywrap(){}

int main() 
{
    printf("Enter '0' to quit anytime\n\n");
    printf("Enter the Character:\n");
    yylex();
    printf("Total no. of vowels = %d\n", vowel);
    printf("Total no. of consonants = %d\n", cons);
    return 0;
}

