#include <stdio.h>

#define MP 10
#define MR 10

int main() {

    int n, m;

    printf("Enter no. of proc: ");
    scanf("%d", &n);

    printf("Enter no. of res: ");
    scanf("%d", &m);

    int al[MP][MR], req[MP][MR];
    int av[MR], fin[MP] = {0};

    printf("\nEnter Alloc Mat:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&al[i][j]);

    printf("\nEnter Req Mat:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&req[i][j]);

    printf("\nEnter Avail Res:\n");
    for(int j=0;j<m;j++)
        scanf("%d",&av[j]);

    int fd;

    do {

        fd = 0;

        for(int i=0;i<n;i++) {

            if(fin[i] == 0) {

                int pos = 1;

                for(int j=0;j<m;j++) {

                    if(req[i][j] > av[j]) {
                        pos = 0;
                        break;
                    }
                }

                if(pos) {

                    for(int j=0;j<m;j++)
                        av[j] += al[i][j];

                    fin[i] = 1;
                    fd = 1;
                }
            }
        }

    } while(fd);

    int dl = 0;

    printf("\nDeadlocked Proc: ");

    for(int i=0;i<n;i++) {

        if(fin[i] == 0) {
            printf("P%d ", i);
            dl = 1;
        }
    }

    if(dl == 0)
        printf("None");

    return 0;
}
