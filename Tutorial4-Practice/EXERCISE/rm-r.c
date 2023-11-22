//TAKE A DIRECTORY PATH AND DELETE ALL ITS CONTENTS RECURSIVELY
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

void deleteDirectory(char* dirPath){
    //OPEN DIRECTORY STREAM
    DIR *dirStream = opendir(dirPath);

    // READ FROM THE DIRECTORY
    struct dirent *entry;

    //STORE PATH OF FILE
    char filePath[256];

    //GET EACH ENTRY
    while ((entry = readdir(dirStream)) != NULL)
    {
        // IF NOT PARENT DIRECTORY ENTRY OR CURRENT DIRECTORY ENTRY
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0)
        {
            //GET THE FILEPATH: %S/%S, DIRPATH, ENTRY->D_NAME
            snprintf(filePath, sizeof(filePath), "%s/%s", dirPath, entry->d_name);
            printf("PATH = %s\n", filePath);
            
            //TRY OPENING AS SUBDIRECTORY
            DIR *subDir = opendir(filePath);

            //IF DIRECTORY => RECURSE
            if (subDir != NULL)
            {
                deleteDirectory(filePath);
            }

            //ELSE UNLINK THE FILE
            else
            {
                unlink(filePath);
            }
        }
    }

    //CLOSE THE DIRECTORY STREAM
    closedir(dirStream);

    //REMOVE THE DIRECTORY [now empty]
    rmdir(dirPath);
}
int main(void){
    char* dirPath = "tmp";

    //OPEN THE DIRECTORY
    deleteDirectory(dirPath);
}