#include <stdio.h>
#define MP 10
#define MR 10
int main() {
    int n, m;
    int al[MP][MR], mx[MP][MR], nd[MP][MR];
    int av[MR], wk[MR];
    int fin[MP] = {0}, ss[MP];
    printf("Enter no. of proc: ");
    scanf("%d", &n);
    printf("Enter no. of res: ");
    scanf("%d", &m);
    printf("Enter Alloc Mat:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&al[i][j]);
    printf("Enter Max Mat:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&mx[i][j]);
    printf("Enter Avail Res:\n");
    for(int j=0;j<m;j++) {
        scanf("%d",&av[j]);
        wk[j] = av[j];
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            nd[i][j] = mx[i][j] - al[i][j];
    printf("\nNeed Mat:\n");
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++)
            printf("%d ", nd[i][j]);
        printf("\n");
    }
    int cnt = 0;
    while(cnt < n) {
        int fd = 0;
        for(int i=0;i<n;i++) {
            if(fin[i] == 0) {
                int pos = 1;
                for(int j=0;j<m;j++) {
                    if(nd[i][j] > wk[j]) {
                        pos = 0;
                        break;
                    }
                }
                if(pos) {
                    for(int j=0;j<m;j++)
                        wk[j] += al[i][j];

                    ss[cnt++] = i;
                    fin[i] = 1;
                    fd = 1;
                }
            }
        }
        if(fd == 0) {
            printf("\nUnsafe State\n");
            return 0;
        }
    }
    printf("\nSafe State\n");
    printf("Safe Seq: ");
    for(int i=0;i<n;i++) {
        printf("P%d", ss[i]);
        if(i != n-1)
            printf(" -> ");
    }
    return 0;
}
