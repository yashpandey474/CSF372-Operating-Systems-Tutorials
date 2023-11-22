//Write a program to make a directory, 
//create two text files inside it,
//open the directory and file.
//Write to one of the files and then
// copy content of one file to another.
//Close the files and the directory

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
    //MAKE A NEW DIRECTORY
   int md;
   int fd1, fd2, ret;
   md = mkdir("./temp", 0777);
   
   if (md != 0){
        printf("ERROR: COULD NOT MAKE NEW DIRECTORY");
        return 1;
   }

   //CHANGE CWD
   if (chdir("./temp") != 0){
        printf("ERROR: COULD NOT CHANGE CWD");
        return 1;
   }

   //CREATE TWO TEXT FILES
   fd1 = creat("txt1.txt", 0777);
   fd2 = creat("txt2.txt", 0777);

   //OPEN TEXT FILE
   fd1 = open("txt1.txt", O_WRONLY);

   //WRITE TO THE FILE
   char buffer[16] = "CONTENT OF FILE";
   ret = write(fd1, buffer, sizeof(buffer));

   //CLOSE THE OPEN FILE
   ret = close(fd1);

   //OPEN BOTH FILES
   fd1 = open("txt1.txt", O_RDONLY);
   fd2 = open("txt2.txt", O_WRONLY);

   //READ FROM FIRST FILE
   ret = read(fd1, buffer, sizeof(buffer));

   //WRITE TO SECOND FILE
   ret = write(fd2, buffer, sizeof(buffer));

   //CLOSE FILES AND DIRECTORY
   close(fd1);
   close(fd2);
   

}