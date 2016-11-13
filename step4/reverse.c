#include <stdio.h>

int main(int argc, char* argv[])
{
  const char *filename = argv[1];
  FILE *fd_input = fopen(filename, "r");
  FILE *fd_output = fopen("out.dat", "w");
  char line[512];
  int hex;

  printf("Reading %s...\n", filename);

  while (fgets(line, sizeof(line), fd_input))
  {
    sscanf(line, "%x", &hex);
    fwrite(&hex, 1, 1, fd_output);
  }

  fclose(fd_input);
  fclose(fd_output);
  return 0;
}
