#include<stdio.h>
int main() {
    int n,i,j,time=0,min,idx;
    int at[20],bt[20],pr[20];
    int ct[20],tat[20],wt[20],rt[20];
    int done[20]={0};
    printf("Enter number of processes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("P%d AT BT Priority: ",i+1);
        scanf("%d%d%d",&at[i],&bt[i],&pr[i]);
    }
    int completed=0;
    while(completed<n){
        min=999;
        for(i=0;i<n;i++){
            if(at[i]<=time && done[i]==0 && pr[i]<min){
                min=pr[i];
                idx=i;
            }
        }
        if(min==999){
            time++;
            continue;
        }
        rt[idx]=time-at[idx];
        time+=bt[idx];
        ct[idx]=time;
        tat[idx]=ct[idx]-at[idx];
        wt[idx]=tat[idx]-bt[idx];
        done[idx]=1;
        completed++;
    }
    printf("\nP AT BT PR CT TAT WT RT\n");
    for(i=0;i<n;i++){
        printf("P%d %d %d %d %d %d %d %d\n",
        i+1,at[i],bt[i],pr[i],ct[i],tat[i],wt[i],rt[i]);
    }
    return 0;
}
