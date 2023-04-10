#include<stdio.h>

struct priority
{
int pid; //process ID
int pr;	//priority
int wtime; //waiting time
int btime; //burst time
int tatime; //turnaround time
}p[10], temp;


int main() {
int i, j, n;
float total_wtime, total_tatime; //total waitime and turnaround time
printf("Priority sceduling.\n");
printf("Enter the number of process: ");
scanf("%d", &n);
for(i=0; i<n; ++i) {
	p[i].pid = i;
	printf("Enter burst time and priority of the process: ");
	scanf("%d%d", &p[i].btime, &p[i].pr);
}

for(i=0; i<n; ++i) {
	for(j=i; j<n; ++j) {
		if(p[i].pr > p[j].pr){
			temp = p[i];
			p[i] = p[j];
			p[j] = temp;
		}
	}
}
p[0].wtime = 0;
p[0].tatime = p[0].btime;
total_tatime = p[0].tatime;
total_wtime = 0;
for(i=1; i<n; ++i) {
	p[i].wtime = p[i-1].wtime + p[i-1].btime;
	p[i].tatime = p[i-1].tatime + p[i].btime;
	total_tatime += p[i].tatime;
	total_wtime += p[i] .wtime;
}
printf("\t PROCESS \tPRIORITY \tBURST TIME \t WAITING TIME\t TURNAROUND TIME\n");
for(i=0;i<n;i++){
	printf("\n\t P%d \t\t %d \t\t %d \t\t %d \t\t %d", p[i].pid, p[i].pr, p[i].btime, p[i].wtime,p[i].tatime);
	}
printf("\nAverage Waiting Time -- %f", total_wtime/n);
printf("\nAverage Turnaround Time -- %f", total_tatime/n);
return 0;
}
