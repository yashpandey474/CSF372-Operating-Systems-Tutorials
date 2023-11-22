#include <unistd.h>
#include <stdio.h>

int main(void){
    //CHANGE DIRECTOR
    if (chdir("..") != 0){
        printf("COULD NOT CHANGE CWD");
        return 1;
    }
    char cwd[256];
    if (getcwd(cwd, sizeof(cwd)) == NULL){
        printf("COULD NOT GET CWD");
        return 1;
    }
    printf("CWD: %s\n", cwd);
    return 0;


}