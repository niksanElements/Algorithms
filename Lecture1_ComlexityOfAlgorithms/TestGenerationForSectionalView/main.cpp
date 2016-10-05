#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 1000
#define STEP 5
int main()
{
    int n=MAX,m=MAX, i,v;
    srand((unsigned)time(NULL));
    printf("%d %d\n",m,n);
    v=rand()%STEP+1;
    for(i=1;i<m;i++){
        printf("%d ",v);
        v+=rand()%STEP+1;
    }
    printf("%d\n",v);
    v=rand()%STEP+1;
    for(i=1;i<n;i++){
            printf("%d ",v);
            v+=rand()%STEP+1;
    }
    printf("%d\n",v);
}
