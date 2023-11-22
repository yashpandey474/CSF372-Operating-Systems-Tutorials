#include <unistd.h>

//PARAMETERS PASSED IN LIST AND FILENAME INSTEAD OF PATHNAME
int main(void){
    char* programName = "ls";
    //FIRST ARGUMENT IS FILENAME
    execlp(programName, "-l", "/home", NULL);
}