#include <stdio.h>

int main()
{
    int n, i;

    int sys_bt[20], user_bt[20];
    int sys_wt[20], user_wt[20];
    int sys_tat[20], user_tat[20];
    int sys_n, user_n;
    printf("Enter number of system processes: ");
    scanf("%d", &sys_n);
    for(i = 0; i < sys_n; i++)
    {
        printf("Enter burst time of system process %d: ", i+1);
        scanf("%d", &sys_bt[i]);
    }
    printf("\nEnter number of user processes: ");
    scanf("%d", &user_n);
    for(i = 0; i < user_n; i++)
    {
        printf("Enter burst time of user process %d: ", i+1);
        scanf("%d", &user_bt[i]);
    }
    sys_wt[0] = 0;
    for(i = 1; i < sys_n; i++)
        sys_wt[i] = sys_wt[i-1] + sys_bt[i-1];

    for(i = 0; i < sys_n; i++)
        sys_tat[i] = sys_wt[i] + sys_bt[i];


    user_wt[0] = sys_wt[sys_n-1] + sys_bt[sys_n-1];

    for(i = 1; i < user_n; i++)
        user_wt[i] = user_wt[i-1] + user_bt[i-1];

    for(i = 0; i < user_n; i++)
        user_tat[i] = user_wt[i] + user_bt[i];

    printf("\nSystem Processes:\n");
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for(i = 0; i < sys_n; i++)
        printf("S%d\t%d\t\t%d\t\t%d\n", i+1, sys_bt[i], sys_wt[i], sys_tat[i]);

    printf("\nUser Processes:\n");
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for(i = 0; i < user_n; i++)
        printf("U%d\t%d\t\t%d\t\t%d\n", i+1, user_bt[i], user_wt[i], user_tat[i]);

    return 0;
}
