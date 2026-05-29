#include <stdio.h>
#define MAX 10
void firstFit(int block[], int b, int proc[], int p)
{
    int alloc[MAX];
    for(int i=0;i<p;i++)
        alloc[i] = -1;
    for(int i=0;i<p;i++) {
        for(int j=0;j<b;j++) {
            if(block[j] >= proc[i]) {

                alloc[i] = j;
                block[j] -= proc[i];
                break;
            }
        }
    }
    printf("\nFirst Fit:\n");
    for(int i=0;i<p;i++) {
        if(alloc[i] != -1)
            printf("P%d (%d) -> B%d\n",
                   i+1, proc[i], alloc[i]+1);
        else
            printf("P%d (%d) -> Not Allocated\n",
                   i+1, proc[i]);
    }
}
void bestFit(int block[], int b, int proc[], int p)
{
    int alloc[MAX];
    for(int i=0;i<p;i++)
        alloc[i] = -1;
    for(int i=0;i<p;i++) {
        int best = -1;
        for(int j=0;j<b;j++) {
            if(block[j] >= proc[i]) {
                if(best == -1 ||
                   block[j] < block[best])
                    best = j;
            }
        }
        if(best != -1) {
            alloc[i] = best;
            block[best] -= proc[i];
        }
    }
    printf("\nBest Fit:\n");
    for(int i=0;i<p;i++) {
        if(alloc[i] != -1)
            printf("P%d (%d) -> B%d\n",
                   i+1, proc[i], alloc[i]+1);
        else
            printf("P%d (%d) -> Not Allocated\n",
                   i+1, proc[i]);
    }
}
void worstFit(int block[], int b, int proc[], int p)
{
    int alloc[MAX];
    for(int i=0;i<p;i++)
        alloc[i] = -1;
    for(int i=0;i<p;i++) {
        int worst = -1;
        for(int j=0;j<b;j++) {
            if(block[j] >= proc[i]) {
                if(worst == -1 ||
                   block[j] > block[worst])
                    worst = j;
            }
        }
        if(worst != -1) {
            alloc[i] = worst;
            block[worst] -= proc[i];
        }
    }
    printf("\nWorst Fit:\n");
    for(int i=0;i<p;i++) {
        if(alloc[i] != -1)
            printf("P%d (%d) -> B%d\n",
                   i+1, proc[i], alloc[i]+1);
        else
            printf("P%d (%d) -> Not Allocated\n",
                   i+1, proc[i]);
    }
}
int main()
{
    int block[MAX], proc[MAX];
    int orgBlock[MAX];
    int b, p, ch;
    printf("Enter no. of blocks: ");
    scanf("%d",&b);
    printf("Enter block sizes:\n");
    for(int i=0;i<b;i++) {
        printf("Block %d: ",i+1);
        scanf("%d",&block[i]);
        orgBlock[i] = block[i];
    }
    printf("Enter no. of processes: ");
    scanf("%d",&p);
    printf("Enter process sizes:\n");
    for(int i=0;i<p;i++) {
        printf("Process %d: ",i+1);
        scanf("%d",&proc[i]);
    }
    printf("\n1. First Fit");
    printf("\n2. Best Fit");
    printf("\n3. Worst Fit");
    printf("\nEnter choice: ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            firstFit(orgBlock, b, proc, p);
            break;
        case 2:
            for(int i=0;i<b;i++)
                block[i] = orgBlock[i];
            bestFit(block, b, proc, p);
            break;
        case 3:
            for(int i=0;i<b;i++)
                block[i] = orgBlock[i];

            worstFit(block, b, proc, p);
            break;
        default:
            printf("Invalid Choice");
    }
    return 0;
}
