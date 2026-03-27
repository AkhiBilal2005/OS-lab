#include<stdio.h>
int main(){
    int n,i,time=0,completed=0,min,idx;
    int at[20],bt[20],pr[20],rt_bt[20];
    int ct[20],tat[20],wt[20],rt[20];
    int start[20];
    printf("Enter number of processes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("P%d AT BT Priority: ",i+1);
        scanf("%d%d%d",&at[i],&bt[i],&pr[i]);
        rt_bt[i]=bt[i];
        start[i]=-1;
    }
    while(completed<n){
        min=999;
        idx=-1;

        for(i=0;i<n;i++){
            if(at[i]<=time && rt_bt[i]>0 && pr[i]<min){
                min=pr[i];
                idx=i;
            }
        }
        if(idx==-1){
            time++;
            continue;
        }
        if(start[idx]==-1)
            start[idx]=time;

        rt_bt[idx]--;
        time++;
        if(rt_bt[idx]==0){
            ct[idx]=time;
            tat[idx]=ct[idx]-at[idx];
            wt[idx]=tat[idx]-bt[idx];
            rt[idx]=start[idx]-at[idx];
            completed++;
        }
    }
    printf("\nP AT BT PR CT TAT WT RT\n");
    for(i=0;i<n;i++){
        printf("P%d  %d  %d  %d %d %d %d %d\n",
        i+1,at[i],bt[i],pr[i],ct[i],tat[i],wt[i],rt[i]);
    }
    return 0;
}
