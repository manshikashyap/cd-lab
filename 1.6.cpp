 #include <stdio.h>
  #include <string.h>
  #define MAX 256

  int main() {
        FILE *fp1, *fp2;
        char word[MAX], filename[MAX];
        char str[MAX], temp[] = "temp.txt", *ptr, *tmp;

        /* get the input file from the user */
        printf("Enter your input file name:");
        fgets(filename, MAX, stdin);
        filename[strlen(filename) - 1] = '\0';

        /* get the word to delete from the user */
        printf("Enter your input word:");
        scanf("%s", word);
        
        /* open input file in read mode */
        fp1 = fopen(filename, "r");

        /* error handling */
        if (!fp1) {
                printf("Unable to open the input file!!\n");
                return 0;
        }

        /* open temporary file in write mode */
        fp2 = fopen(temp, "w");

        /* error handling */
        if (!fp2) {
                printf("Unable to open temporary file!!\n");
                return 0;
        }
        
    
        /* delete the given word from the file */
        while (!feof(fp1)) {
                strcpy(str, "\0");
                /* read line by line from the input file */
                fgets(str, MAX, fp1);

                /*
                 * check whether the word to delete is
                 * present in the current scanned line
                 */
                if (strstr(str, word)) {
                        tmp = str;
                        while (ptr = strstr(tmp, word)) {
                                /*
                                 * letters present before
                                 * before the word to be deleted
                                 */
                                while (tmp != ptr) {
                                        fputc(*tmp, fp2);
                                        tmp++;
                                }
                                /* skip the word to be deleted */
                                
                                ptr = ptr + strlen(word);
                               
                                tmp = ptr;
                        }

                        /* characters present after the word to be deleted */
                        while (*tmp != '\0') {
                                fputc(*tmp, fp2);
                                tmp++;
                        }
                } else {
                        /*
                         * current scanned line doesn't 
                         * have the word that need to be deleted
                         */
                        fputs(str, fp2);
                }
        }

        /* close the opened files */
        fclose(fp1);
        fclose(fp2);
    
        /* remove the input file */
        remove(filename);
        /* rename temporary file name to input file name */
        rename(temp, filename);
        return 0;
  }

