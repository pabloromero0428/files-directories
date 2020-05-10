#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

char *convertTime(time_t time);
void getPermissions(struct stat myStat);


int main(int argc, char **argv)
{
    

    if(argc != 2)    
        return 1;
 
    struct stat file;
    if(stat(argv[1],&file) < 0)    
        return 1;
 

    printf("Information for: %s\n", argv[1]);
    printf("---------------------------\n");
    printf("st_gid = %o\n", file.st_mode);
    printf("User id = %o\n", file.st_uid);
    printf("Group id = %o\n", file.st_gid);
    printf("Size = %ld bytes\n", file.st_size);
    printf("File Size: \t\t\t\t%ld bytes\n", (long)file.st_size);
    printf("Number of Links: \t\t\t%ld\n", (long)file.st_nlink);
    printf("File inode: \t\t\t\t%ld\n", (long)file.st_ino);
    printf("Blocksize for file system I/O: \t\t%ld\n", (long)file.st_blksize);   
    printf("File Permissions: \t");
    getPermissions(file);
    printf("\n\n");
    printf("Last access: \t\t\t\t%s", convertTime(file.st_atime));
    printf("Last modification: \t\t\t%s", convertTime(file.st_atime));
    printf("The file %s a symbolic link\n", (S_ISLNK(file.st_mode)) ? "is" : "is not");

 

   
 
    printf("The file %s a symbolic link\n", (S_ISLNK(file.st_mode)) ? "is" : "is not");
 
    return 0;
}

char *convertTime(time_t time)
{
    char *c_time_string;
    c_time_string = ctime(&time);
    return c_time_string;
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

