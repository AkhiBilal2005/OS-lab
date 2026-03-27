#include <stdio.h>
struct Process {
    int id, at, bt, rt, ct, wt, tat;
};
int main() {
    int n, tq, time = 0, completed = 0;
    struct Process p[20];
    int queue[100], front = 0, rear = 0, visited[20] = {0};
    printf("Enter number of processes: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Enter Arrival Time for P%d: ", p[i].id);
        scanf("%d", &p[i].at);
        printf("Enter Burst Time for P%d: ", p[i].id);
        scanf("%d", &p[i].bt);
        p[i].rt = p[i].bt;
    }
    printf("Enter Time Quantum: ");
    scanf("%d", &tq);
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(p[j].at > p[j+1].at) {
                struct Process temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
    time = p[0].at;
    queue[rear++] = 0;
    visited[0] = 1;
    while(completed < n) {
        if(front == rear) {
            time++;
            for(int i = 0; i < n; i++) {
                if(p[i].at <= time && !visited[i]) {
                    queue[rear++] = i;
                    visited[i] = 1;
                }
            }
            continue;
        }
        int i = queue[front++];
        int exec = (p[i].rt > tq) ? tq : p[i].rt;
        p[i].rt -= exec;
        time += exec;
        for(int j = 0; j < n; j++) {
            if(p[j].at <= time && !visited[j] && p[j].rt > 0) {
                queue[rear++] = j;
                visited[j] = 1;
            }
        }
        if(p[i].rt == 0) {
            p[i].ct = time;
            p[i].tat = p[i].ct - p[i].at;
            p[i].wt = p[i].tat - p[i].bt;
            completed++;
        } else {
            queue[rear++] = i;
        }
    }
    float avg_wt = 0, avg_tat = 0;
    printf("\nProcess\tAT\tBT\tCT\tWT\tTAT\n");
    for(int i = 0; i < n; i++) {
        avg_wt += p[i].wt;
        avg_tat += p[i].tat;
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].wt, p[i].tat);
    }
    printf("\nAverage Waiting Time = %.2f", avg_wt/n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat/n);
    return 0;
}
