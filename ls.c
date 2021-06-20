#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <err.h>

// しゃきょー

int main(int argc, char **argv)
{
  char *target_path;
  if (argc > 2)
    target_path = argv[1];
  else
    target_path = ".";

  DIR *target = opendir(target_path);
  if (target == NULL)
    err(1, "opendir");

  struct dirent *d;

  while ((d = readdir(target)) != NULL)
  {
    printf("%s\n", d->d_name);
  }
}