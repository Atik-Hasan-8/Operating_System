#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
    printf("we are in second.c\n");
    printf("PID of second.c= %d\n",getpid() );
    return 0;
}

