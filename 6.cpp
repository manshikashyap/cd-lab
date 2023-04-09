#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char str[100];
	printf("enter a string: ");
	scanf("%s",&str);
	if(strcmp(str,"abb")==0){
		printf("the string matches the regular expression abb\n");
	}
	int i=0;
	while(str[i]=='a')i++;
	if(str[i]=='\0'){
		printf("the string matches the regular expression a*\n");
		return 0;
	}
	if(str[i]=='b'){
		while(str[i]=='b')i++;
		
	}
	if(str[i]=='\0'){
		printf("the string matches the regular expression a*b+\n");
		return 0;
	}
	
	printf("the string doesn't 'matches any regular expression \n");
		return 0;
	
}
