#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
    printf("PID of first.c= %d\n",getpid() );
    char *args[]={"Welcome","ICT",NULL};
    execv("./second",args);
    printf("Back to first.c\n");
    return 0;
}
