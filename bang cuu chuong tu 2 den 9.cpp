#include <stdio.h>
#include <conio.h>
int main()
{
    int i,j;
    printf("bang cuu chuong 2:\n");
    for(i=2;i<=9;i++)
       for(j=1;j<=10;j++)
       {
          printf("%d x %d = %d \n",i,j,i*j);
          if(j==10 && i<9) printf("bang cuu chuong %d:\n",i+1);
       }
    getch();
}
