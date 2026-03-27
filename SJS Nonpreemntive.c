#include <stdio.h>
int main()
{
    int n,i,time=0,smallest;
    int at[n],bt[n],ct[n],tat[n],wt[n];
    int completed[20]={0},count=0;
    float avgwt=0,avgtat=0;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nProcess P%d\n",i+1);
        printf("Arrival Time: ");
        scanf("%d",&at[i]);
        printf("Burst Time: ");
        scanf("%d",&bt[i]);
    }
    while(count<n)
    {
        smallest=-1;
        int min=9999;
        for(i=0;i<n;i++)
        {
            if(at[i]<=time && completed[i]==0 && bt[i]<min)
            {
                min=bt[i];
                smallest=i;
            }
        }
        if(smallest==-1)
        {
            time++;
        }
        else
        {
            time=time+bt[smallest];
            ct[smallest]=time;
            tat[smallest]=ct[smallest]-at[smallest];
            wt[smallest]=tat[smallest]-bt[smallest];
            avgwt+=wt[smallest];
            avgtat+=tat[smallest];
            completed[smallest]=1;
            count++;
        }
    }
    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    printf("\nAverage Waiting Time = %.2f",avgwt/n);
    printf("\nAverage Turnaround Time = %.2f\n",avgtat/n);
    return 0;
}
