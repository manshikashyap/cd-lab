#include <iostream>
#include <stdlib.h>
using namespace std;
int main() {
   char ch;// source_file[20], target_file[20];
   FILE *source, *target;
   char source_file[]="C:/Users/DELL/OneDrive/Desktop/helper.txt";
   char target_file[]="C:/Users/DELL/OneDrive/Desktop/ans.txt";
   source = fopen(source_file, "r");
   if (source == NULL) {
      printf("Press any key to exit...");
      exit(EXIT_FAILURE);
   }
   target = fopen(target_file, "w");
   if (target == NULL) {
      fclose(source);
      printf("Press any key to exit...");
      exit(EXIT_FAILURE);
   }
   while ((ch = fgetc(source)) != EOF)
      fputc(ch, target);
   printf("File copied successfully.");
   fclose(source);
   fclose(target);
   return 0;
}
