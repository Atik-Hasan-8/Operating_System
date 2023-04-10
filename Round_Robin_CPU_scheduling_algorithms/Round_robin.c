
#include<stdio.h>
#define max 30
int main()
{
int i,j,n,count=0, ex=0, wt[max], bt[max], tat[max], rem_bt[max], qt, temp, at[max],p[max];
float awt=0,atat=0;
printf("--------ROUND ROBIN \n");
printf("Enter the no of processes : ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
    printf("\nEnter Burst Time for process %d -- ", i+1);
    scanf("%d",&bt[i]);
    rem_bt[i]=bt[i];
}
printf("\nEnter the time quntum : ");
scanf("%d",&qt);
/*
for(i=0;i<n;i++)
{
printf("\nEnter Arrival Time for process %d -- ", i+1);
scanf("%d",&at[i]);
}
//--------- sorting-------
for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{
if(at[i]>at[j])
{ temp=bt[i];
bt[i]=bt[j];
bt[j]=temp;
temp=rem_bt[i];
rem_bt[i]=rem_bt[j];
rem_bt[j]=temp;
/*temp=p[i];
p[i]=p[j];
p[j]=temp;
temp=at[i];
at[i]=at[j];
at[j]=temp;
}
}
} */
while(1)
{
    for(i=0,count=0;i<n;i++)
    {
        temp=qt;
        if(rem_bt[i]==0)
        {
        count++;
        continue;
        }
        if(rem_bt[i]>qt)
        {
        rem_bt[i]=rem_bt[i]-qt;
        }
        else
        if(rem_bt[i]>=0)
        {
        temp=rem_bt[i];
        rem_bt[i]=0;
        }
        ex=ex+temp;
        tat[i]=ex;
    }
if(n==count)
break;
}
printf("\n\tPROCESS\t BURST TIME \t WAITING TIME\tTURNAROUND TIME\n");
for(i=0;i<n;i++)
{
    wt[i]=tat[i]-bt[i];
    awt=awt+wt[i];
    atat=atat+tat[i];
    printf("\t%d \t %d \t\t %d \t\t %d \n",i+1,bt[i],wt[i],tat[i]);
}
printf("\nThe Average Turnaround time is -- %f",atat/n);
printf("\nThe Average Waiting time is -- %f ",awt/n);

}
