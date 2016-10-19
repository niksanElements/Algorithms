#include <stdio.h>
   #include <stdlib.h>
   #include <time.h>
   int main()
   {  int n = 90000, m=4000;
      srand((unsigned)time(NULL));
      printf("%d\n",n);
      for(int i=1;i<=n;i++)
         printf("%d\n",rand()%m+1);
   }
