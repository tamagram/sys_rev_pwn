#include <stdio.h>

int output_internal_text_of_file(char *target_path)
{
  FILE *fp;
  char s;
  fp = fopen(target_path, "r");
  if (fp == NULL)
  {
    printf("cat: %s: No such file or directory\n", target_path);
    return -1;
  }
  while ((s = fgetc(fp)) != EOF)
  {
    printf("%c", s);
  }
  fclose(fp);
  return 0;
}

int main(int argc, char **argv)
{
  char *target_path;
  char str[256];
  if (argc > 1)
  {
    target_path = argv[1];
    output_internal_text_of_file(target_path);
  }
  else
    while (1)
    {
      fgets(str, sizeof(str), stdin);
      puts(str);
    }
  return 0;
}
