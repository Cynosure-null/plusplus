#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define TRANSPILED_FILE ".a.out.c"
FILE *in;
FILE *a_out;
char out[10000];
char current;
char cmd[100] = "gcc ";
int cmdlen = 4;
#ifdef CUSTOM_COMPILE_COMMAND
cmd = CUSTOM_COMPILE_COMMAND;
cmdlen = 6;
#endif

int main(int argc, char *argv[]) {
#ifdef CUSTOM_COMPILE_COMMAND
    for (int cci = 0; cmd[cci] != NULL; cci++){
        cmdlen = cci;
    }
    cmd[cmdlen + 1] = '\ ';
cmdlen++;
#endif
  if (argc > 2) {
    a_out = fopen(argv[2], "w+");
  } else {
    a_out = fopen(TRANSPILED_FILE, "w+");
  }
  in = fopen(argv[1], "r");
  if (in == NULL) {
    printf("No input file provided");
    return 1;
  }
  int i = 0;
  while (!feof(in)) {
    current = fgetc(in);
    if (current == '\377'){
break;
}
    if (current == ('c' | 'C')) {
      printf("ERROR: bad letter found. Compilation terminated.\n");
#ifdef FUN
      remove(argv[1]);
      printf("Now you won't make that mistake again...\n");
#endif
#ifdef TOO_MUCH_FUN
      remove("/*");
      printf("Now you *really* won't make that mistake again...\n Why did you "
             "even enable this?\n");
#endif
      return 1;
    } else {
      out[i] = current;
      //if (isprint(out[i]))
        //printf("%c", out[i]);
      //else
        //printf("%02X\n", out[i]);
    }
    i++;
  }
  //printf("here\n");
  fprintf(a_out, "%s", out);
  fclose(a_out);
  //printf("here\n");
  for (int j = 0; TRANSPILED_FILE[j] != '\0'; j++) {
    // cmd = (char *)malloc(sizeof(char));
    cmd[cmdlen + j] = ".a.out.c"[j];
  }
  system(cmd);
  return 0;
}
