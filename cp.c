#include <stdio.h>
#include <string.h>

int move_file_to_directory(char *src_path, char *dest_path)
{
  if (src_path == dest_path)
    return 0;
  FILE *src_fp;
  FILE *dest_fp;
  char *split_path;
  char *file_name;
  char s;

  split_path = strtok(src_path, "/");
  while (split_path != NULL)
  {
    split_path = strtok(NULL, "/");
  }
  src_fp = fopen(src_path, "r");
  strcat(dest_path, "/");
  strcat(dest_path, file_name);
  dest_fp = fopen(dest_path, "w");
  if (src_fp == NULL)
  {
    printf("cat: %s: No such file or directory\n", src_path);
    return -1;
  }
  if (dest_fp == NULL)
  {
    printf("cat: %s: No such file or directory\n", dest_path);
    return -1;
  }
  while ((s = fgetc(src_fp)) != EOF)
  {
    fwrite(&s, sizeof(s), 1, dest_fp);
  }
  fclose(src_fp);
  fclose(dest_fp);
  return 0;
}

int main(int argc, char *argv[])
{
  switch (argc)
  {
  case 1:
    printf("cp: missing file operand");
  case 2:
    printf("cp: missing destination file operand after %s", argv[1]);
  case 3:
    move_file_to_directory(argv[1], argv[2]);
  }
  return 0;
}
