#include<stdio.h>

struct SJF
{
    int pid;
    int btime;
    int wtime;
    int tatime;
}p[20],temp;

int main(){

    int i,j,n;
    float total_wtime,total_tatime;
    printf("Enter number of process: ");
    scanf("%d",&n);
    for(i=0;i<n;++i){
        p[i].pid=i;
        printf("Enter Process%d Burst time :",i);
        scanf("%d",&p[i].btime);
    }
    for(i=0;i<n;++i){
    for(j=i;j<n;++j){
        if(p[i].btime>p[j].btime){
            temp=p[i];
            p[i]=p[j];
            p[j]=temp;
        }
    }
    }
     p[0].wtime=total_wtime=0;
    p[0].tatime=total_tatime=p[0].btime;
    for(i=1;i<n;++i){
        p[i].wtime=p[i-1].wtime +p[i-1].btime;
        p[i].tatime=p[i-1].tatime+p[i].btime;
        total_wtime+=p[i].wtime;
        total_tatime+=p[i].tatime;
    }
    printf("\t PROCESS \tBURST TIME \t WAITING TIME\t TURNAROUND TIME\n");
    for(i=0;i<n;i++){
        printf("\n\t P%d \t\t %d \t\t %d \t\t %d", p[i].pid,p[i].btime, p[i].wtime, p[i].tatime);
    }
    printf("\nAverage Waiting Time -- %f", total_wtime/n);
    printf("\nAverage Turnaround Time -- %f", total_tatime/n);

}


