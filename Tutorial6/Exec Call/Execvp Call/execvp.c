#include <unistd.h>

//ARDUMENTS IN A VECTOR ALONG WITH FILENAME

int main(void){
    char* fileName = "ls";
    char* argv[] = {fileName, "-l", "/bin", NULL};
    execvp(fileName, argv);
}