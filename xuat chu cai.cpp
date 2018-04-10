#include <stdio.h>
#include <conio.h>
#include <ctype.h>
int main()
{
    char i;
    printf("*In ra cac chu ca tu \"A den Z\" chu hoa va chu thuong: \n\n");
    for(i=65;i<=90;i++)
    {
       printf("%c \t",i);
    //for(i=97;i<=122;i++)
       printf("%c \t\n",tolower(i));
    }
    printf("*In ra cac chu ca tu \"Z den A\" chu hoa va chu thuong: \n\n");
    for(i=90;i>=65;i--)
    {
       printf("%c \t",i);
    //for(i=97;i<=122;i++)
       printf("%c \t\n",tolower(i));
    }
    getch();
}
