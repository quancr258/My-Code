//nhap vao 1000 so ngau nhien tu ban phim, tim 2 so lien tiep co tong bang 1 so X nhap tu ban phim
#include <stdio.h>
#include <conio.h>
int main()
{
    int a[1001],i,x,s=0;
    for(i=0;i<1000;i++)
        {
            printf("nhap vao phan tu thu %d: ",i+1);
            scanf("%d",&a[i]);
            if (a[i]>=100) return;
        }
    printf("\n nhap vao so X = ");
    scanf("%d",&x); 
    for (i=1;i<1000;i++)
        if((a[i-1]+a[i])==x) 
        {
            printf("2 so can tim la: %d ; %d \n",a[i-1],a[i]);
            s++;
        }
        if(s==0) printf("khong co cap so lien tiep can tim");
    getch();
}
