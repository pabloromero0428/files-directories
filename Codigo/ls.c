#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <linux/limits.h>
#include <sys/stat.h>




void error(const char *s);



void getPermissions(struct stat myStat);


int main(int argc, char* argv[])
{

 
    DIR *dir;  
    struct dirent *ent;  
   
    struct stat myStat;
  


  if(argc > 3){
     printf("Error, cantidad de argumentos inválida.\n");
    return 1;
 }

 if(argc <= 1){

     dir = opendir (".");
      if (dir == NULL)
    error("Error al abrir el directorio");
  
  while ((ent = readdir (dir)) != NULL)
    {
      
      if ( (strcmp(ent->d_name, ".")!=0) && (strcmp(ent->d_name, "..")!=0) )
    {
     
     printf ("%s \n", ent->d_name);
    }
    }
   closedir (dir);

    return EXIT_SUCCESS;
 }

 if(argc == 2 &&   strcmp(argv[1],"-l") == 0){//mysl dir
   
    dir = opendir(".");
      if (dir == NULL)
    error("No puedo abrir el directorio");
  
  while ((ent = readdir (dir)) != NULL)
    {
     
      if ( (strcmp(ent->d_name, ".")!=0) && (strcmp(ent->d_name, "..")!=0) )
    {
    
      printf ("%s \n", ent->d_name);
      char mtime[100];
      stat(ent, &myStat);
      printf("---------------------------------------------\n");
      printf("st_gid = %o\n", myStat.st_mode);
      printf("User id = %o\n", myStat.st_uid);
      printf("Group id = %o\n", myStat.st_gid);
      printf("File Size: \t\t\t\t%ld bytes\n", (long)myStat.st_size);
      printf("Number of Links: \t\t\t%ld\n", (long)myStat.st_nlink);
      printf("File inode: \t\t\t\t%ld\n", (long)myStat.st_ino);
      printf("Blocksize for file system I/O: \t\t%ld\n", (long)myStat.st_blksize);   
      printf("File Permissions: \t");
      getPermissions(myStat);
      printf("Size = %ld bytes\n", myStat.st_size);
      strcpy(mtime, ctime(&myStat.st_mtime));
      printf("st_mtime = %s\n", mtime);
     
    }
    }
   closedir (dir);

    return EXIT_SUCCESS;
 }



 if(argc == 2 && strcmp(argv[1],"-l") != 0){

     dir = opendir (argv[1]);
      if (dir == NULL)
    error("No puedo abrir el directorio");
  
  while ((ent = readdir (dir)) != NULL)
    {     
      if ( (strcmp(ent->d_name, ".")!=0) && (strcmp(ent->d_name, "..")!=0) )
    {
     
      printf ("%s \n", ent->d_name);
    }
    }
   closedir (dir);

    return EXIT_SUCCESS;
 }


if(argc == 3 &&   strcmp(argv[1],"-l") == 0){
   
    dir = opendir(argv[2]);
      if (dir == NULL)
    error("No puedo abrir el directorio");
  
  while ((ent = readdir (dir)) != NULL)
    {
      
      if ( (strcmp(ent->d_name, ".")!=0) && (strcmp(ent->d_name, "..")!=0) )
    {
      
      printf ("%s \n", ent->d_name);
      char mtime[100];
      stat(ent, &myStat);
      printf("---------------------------------------------\n");
      printf("st_gid = %o\n", myStat.st_mode);
      printf("User id = %o\n", myStat.st_uid);
      printf("Group id = %o\n", myStat.st_gid);
      printf("File Size: \t\t\t\t%ld bytes\n", (long)myStat.st_size);
      printf("Number of Links: \t\t\t%ld\n", (long)myStat.st_nlink);
      printf("File inode: \t\t\t\t%ld\n", (long)myStat.st_ino);
      printf("Blocksize for file system I/O: \t\t%ld\n", (long)myStat.st_blksize);   
      printf("File Permissions: \t");
      getPermissions(myStat);
      printf("Size = %ld bytes\n", myStat.st_size);
      strcpy(mtime, ctime(&myStat.st_mtime));
      printf("st_mtime = %s\n", mtime);
     
    }
    }
   closedir (dir);

    return EXIT_SUCCESS;
 }
 
 
}

void error(const char *s)
{
  
  perror (s);
  exit(EXIT_FAILURE);
}


void getPermissions(struct stat myStat)
{
    printf((S_ISDIR(myStat.st_mode)) ? "d" : "-");
    printf((myStat.st_mode & S_IRUSR) ? "r" : "-");
    printf((myStat.st_mode & S_IWUSR) ? "w" : "-");
    printf((myStat.st_mode & S_IXUSR) ? "x" : "-");
    printf((myStat.st_mode & S_IRGRP) ? "r" : "-");
    printf((myStat.st_mode & S_IWGRP) ? "w" : "-");
    printf((myStat.st_mode & S_IXGRP) ? "x" : "-");
    printf((myStat.st_mode & S_IROTH) ? "r" : "-");
    printf((myStat.st_mode & S_IWOTH) ? "w" : "-");
    printf((myStat.st_mode & S_IXOTH) ? "x" : "-");
}