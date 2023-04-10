#include<stdio.h>

int total_philo,philname[20],status[20],howhung,hungry[20],choice;
int main()
{
    int i;
    printf("Enter total number of philosophers :");
    scanf("%d",&total_philo);
    for(i=0;i<total_philo;i++){
        philname[i]=i+1;
        status[i]=1;
    }
    printf("how many are hungry: ");
    scanf("%d",&howhung);
    if(howhung==total_philo){
        printf("deadlock stage");
    }
    else{
        for(i=0;i<howhung;i++){
            printf("Enter philosopher%d position :",i+1);
            scanf("%d",&hungry[i]);
            status[hungry[i]]=2;
        }
        do {
            printf("1.One can eat at a time \n2.Two can eat a time\n 3.exit\nEnter your choice : ");
            scanf("%d",&choice);

            switch(choice){
                case 1:one();
                break;
                case 2:  two();
                break;
                case 3: exit(0);
            }
        }while(1);
    }
    }

  one()
        {
        int pos=0, x, i;
        printf("\nAllow one philosopher to eat at any time\n");
        for(i=0;i<howhung; i++, pos++)
        {
            printf("\nP %d is granted to eat", philname[hungry[pos]]);
            for(x=pos+1;x<howhung;x++){
                printf("\nP %d is waiting", philname[hungry[x]]);}
        }
        }

    two(){
        int i,j,s=0,t,r,x;
        printf("\nAllow two philosopher to eat");
        for(i=0;i<howhung;i++){
            for(j=i+1;j<howhung;j++){
                if(abs(hungry[i]-hungry[j])>=1 && abs(hungry[i]-hungry[j])!=4){
                    printf("\n Combination %d\n",s+1);
                    t=hungry[i];
                    r=hungry[j];
                    printf("\nP %d and P%d are granted to eat",philname[hungry[i]],philname[hungry[j]]);

                    for(x=0;x<howhung;x++){
                        if(hungry[x]!=t && hungry[x]!=r)
                        printf("\nP%d is waiting",philname[hungry[x]]);
                    }
                }
            }
        }
    }



