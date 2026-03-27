#include<stdio.h>
int main(){
    int n,i;
    printf("N.of processes: ");
    scanf("%d",&n);
    int waiting[n],burst[n],turnaround[n],arrival[n],response[n],completion[n];
    float total_wt = 0,total_tat = 0,total_res = 0;
    for(int i=0;i<n;i++){
        printf("Enter arrival time: ");
        scanf("%d",&arrival[i]);
        printf("Enter burst time: ");
        scanf("%d",&burst[i]);
    }
    completion[0] = arrival[0] + burst[0];
    for(i = 1; i < n; i++) {
        if(completion[i-1] < arrival[i])
            completion[i] = arrival[i] + burst[i];
        else
            completion[i] = completion[i-1] + burst[i];
    }
    for(i = 0; i < n; i++) {
        turnaround[i] = completion[i] - arrival[i];
        waiting[i] = turnaround[i] - burst[i];
        response[i] = waiting[i];
        total_tat += turnaround[i];
        total_wt += waiting[i];
        total_res += response[i];
    }
    printf("\nProcess\tArrival Time\tBurst Time\tCompilation Time\tWaiting Time\tTurnaround Time\tResponse Time\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1,arrival[i], burst[i], completion[i],waiting[i], turnaround[i],response[i]);
    }
    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);
    printf("Average Response Time = %.2f\n",total_res/n);
    return 0;
}
