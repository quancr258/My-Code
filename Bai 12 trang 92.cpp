#include <stdio.h>
#include <conio.h>
int main()
{
    int i,n=0;
	float s=0;
    printf("nhap vao: \n");
    scanf("%d",&i);
    while(i!=0)
    {
      s=s+i;
      scanf("%d",&i);
      n=n+1;
    }
    printf("Tong cac so vua nhap la: Tong = %f\n",s);
    printf("Trung binh cong cua %d so vua nhap la: Trung Binh Cong = %f\n",n,s/n);
    getch();
}
