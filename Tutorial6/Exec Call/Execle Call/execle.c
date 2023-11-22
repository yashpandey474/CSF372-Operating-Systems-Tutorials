#include <unistd.h>

//PARAMETERS PASSED IN CALL ALONG WITH ENVIORNMENT VARIABLE
int main(void){
    char* pathName = "/bin/bash";
    char *const env[] = {NULL};
    execle(pathName, pathName,"-c", NULL, env);
}