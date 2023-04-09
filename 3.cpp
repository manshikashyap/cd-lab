#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void help(FILE *fp) {
    FILE *fp1, *fp2;

    fp1 = fopen("C:/Users/DELL/OneDrive/Desktop/type1.txt", "w");
    if(!fp1) {
        printf("\nCould not open type1 file");
        exit(1);
    }

    fp2 = fopen("C:/Users/DELL/OneDrive/Desktop/type2.txt", "w");
    if(!fp2) {
        printf("\nCould not open type2 file");
        exit(1);
    }

    char ch;

    int f=0;
    while((ch = fgetc(fp)) != EOF) {

        if(f==0) {
            if(ch == '/') 
                f=1;
        }
        else if(f==1) {
            if(ch == '/') 
                f = 2;
            else if(ch == '*') 
                f = 3;
        }
        else if(f==2) {
            fputc(ch, fp1);
            if(ch == '\n')
                f = 0;
        }
        else if(f==3) {
            if(ch == '*') 
                f = 4;
            else
                fputc(ch, fp2);
        }
        else if(f==4) {
            if(ch == '/') {
                f = 0;
                fputc('\n', fp2);
            }
            else {
                fputc('*', fp2);
                fputc(ch, fp2);
                f = 3;
            }
        }
    } 

    fclose(fp1);
    fclose(fp2);
}

int main() {
    FILE *fp;
    char fname[50];

    printf("\nEnter the source file path: ");
    scanf("%s", fname);

    fp = fopen(fname,"r");
    if(!fp) {
        printf("\nCould not open read file");
        return 1;
    }

    help(fp);

    fclose(fp);

    return 0;
}
