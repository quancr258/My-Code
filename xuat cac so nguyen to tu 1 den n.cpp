#include <stdio.h>
#include <conio.h>
int main()
{
    int m,tp,n,i,j=1;
    printf("nhap vao so n = ");
    scanf("%d",&n);
    if (n>=2)
    {
    printf ("cac so nguyen to tu 1 den %d la:\n",n);
    for (i=1;i<=n;i++)
        for(m=2;m<=i;m++)
        { 
          if (i==2) printf ("%d. %d\n",j,i);
          if (i%m==0) break;
          else if(m==i-1) 
		  {
		  	j++;
		  	printf("%d. %d\n",j,i);
		  }
        }
                       
    }
    else printf("\n so %d khong hop le",n);
    getch();
}                              
