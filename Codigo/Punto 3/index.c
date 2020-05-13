#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  FILE *file;
  if (argc != 3)
  {
    printf("Debe de ingresar los parametros del programa");
    exit(0);
  }
  int n = abs(atoi(argv[1]));
  char lines [n][1024];
  if (n == 0)
  {
    printf("El parametro -n debe de ser mayor a 0");
    exit(0);
  }
  file = fopen(argv[2], "r");
  if (file == NULL)
  {
    printf("Error al leer el archivo");
    exit(0);
  }
  fseek(file, 0, SEEK_END);
  int positionFile = ftell(file);
  int linesRead = 0;
  char p;
  char *newLine;
  while (linesRead < n)
  {
    fseek(file, --positionFile, SEEK_SET);
    p = fgetc(file);
    if (p == '\n' || p == EOF)
    {
      linesRead++;
      strcpy(lines[linesRead], "");
    }else{
      strncat(lines[linesRead], &p, 1);
    }
  }
  
  while (linesRead >= 0)
  {
    printf("%s\n", lines[linesRead]);
    linesRead--;
  }
  return 0;
}