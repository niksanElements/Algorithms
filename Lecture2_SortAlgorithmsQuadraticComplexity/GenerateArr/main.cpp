#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{ int n = 100, m=1000; //до 215-1
  srand((unsigned)time(NULL));
  printf("%d\n",n);
  for(int i=1;i<=n;i++)
    printf("%d\n",rand()%m+1);
}
