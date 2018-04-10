#include <stdio.h>
#include <conio.h>
#include <ctype.h>
int main()
{
    char c;
    //bt a
    printf("nhap vao 1 ky tu: ");
    scanf("%d",&c);
    if (isalpha(c)) printf ("day la ky tu chu \n");
    else printf ("day la ky tu so \n");
    //bt b
    printf("ky tu %c co ma ASCII la %d",c);
    getch();
}
