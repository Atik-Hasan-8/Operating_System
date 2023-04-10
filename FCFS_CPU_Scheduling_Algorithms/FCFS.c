
#include<stdio.h>
struct fcfs
{
    int pid;
    int wtime;
    int btime;
    int tatime;
} p[10];
int main()
{
    int i , n;
    printf("Enter number of Process: ");
    scanf("%d",&n);
    float total_wtime=0;
    float total_tatime=0;
    for(i=0;i<n;i++){
        p[i].pid=i;
        printf("Enter burst time: ");
        scanf("%d",&p[i].btime);
    }
    p[0].wtime=0;
    p[0].tatime=p[0].btime;

    for(i=1;i<n;i++){
        p[i].wtime=p[i-1].wtime + p[i-1].btime;
        p[i].tatime=p[i-1].tatime + p[i].btime;
        total_wtime+=p[i].wtime;
        total_tatime+=p[i].tatime;
    }

    printf("\t PROCESS \tBURST TIME \t WAITING TIME\t TURNAROUND TIME\n");
    for(i=0;i<n;i++)
    printf("\n\t P%d \t\t %d \t\t %d \t\t %d", i, p[i].btime, p[i].wtime, p[i].tatime);
    printf("\nAverage Waiting Time -- %f", total_wtime/n);
    printf("\nAverage Turnaround Time -- %f", total_tatime/n);
}
