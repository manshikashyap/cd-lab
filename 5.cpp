// Simulate lexical analyzer for validating operators
// If an operator, then show its name
// Else, print not an operator

#include <stdio.h>

int is_rel(char ch) {
    if(ch == '<' || ch == '>' || ch == '!' || ch == '=')
        return 1;
    return 0;
}

int is_bit(char ch) {
    if(ch == '&' || ch == '^' || ch == '~' || ch == '|')
        return 1;
    return 0;
}

int is_ari(char ch) {
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%')
        return 1;
    return 0;
}

void fun(char ch[]) {
    if(is_rel(ch[0]) && (ch[1]=='=' || ch[1]=='\0'))
        printf("\nIt is relational operator");
    else if((is_bit(ch[0]) && ch[1]=='\0') || ((ch[0]=='<' || ch[0]=='>') && ch[0]==ch[1]))
        printf("\nIt is bitwise operator");
    else if(((ch[0]=='&' || ch[0]=='|') && ch[0]==ch[1]) || (ch[0]=='!' && ch[1]=='\0'))
        printf("\nIt is logical operator");
    else if(ch[0]=='?' && ch[1]==':')
        printf("\nIt is ternary operator");
    else if((ch[0]=='+' || ch[0]=='-') && ch[0]==ch[1])
        printf("\nIt is unary operator");
    else if((is_ari(ch[0]) && ch[1]=='=') || (ch[0]=='=' && ch[1]=='\0'))
        printf("\nIt is assignment operator");
    else if(is_ari(ch[0]) && ch[1]=='\0')
        printf("\nIt is arithmetic operator");
    else
        printf("\nIt is not an operator");
}

int main() {
    char ch[2];
    
    printf("Enter the string: ");
    scanf("%s",&ch);
    fun(ch);
    return 0;
}
