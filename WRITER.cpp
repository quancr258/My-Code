#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
	char t,a[1000],b[1000];
	int i,l=0,j,d,k[1000];
	//nhap so luong tin nhan
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		//nhap tin nhan
		scanf("%s",&a);
		d=strlen(a);
		l=d;
		for(j=0;j<d;j++)
		{
			if(a[j]=='.' || a[j]==',' || a[j]=='?' || a[j]=='!' || a[j]=='1') b[j]=1;
			if(a[j]=='a' || a[j]=='b' || a[j]=='c' || a[j]=='2') b[j]=2;
			if(a[j]=='d' || a[j]=='e' || a[j]=='f' || a[j]=='3') b[j]=3;
			if(a[j]=='g' || a[j]=='h' || a[j]=='i' || a[j]=='4') b[j]=4;
			if(a[j]=='j' || a[j]=='k' || a[j]=='l' || a[j]=='5') b[j]=5;
			if(a[j]=='m' || a[j]=='n' || a[j]=='o' || a[j]=='6') b[j]=6;
			if(a[j]=='t' || a[j]=='u' || a[j]=='v' || a[j]=='8') b[j]=8;
			if(a[j]=='p' || a[j]=='q' || a[j]=='r' || a[j]=='s' || a[j]=='7') b[j]=7;
			if(a[j]=='w' || a[j]=='x' || a[j]=='y' || a[j]=='z' || a[j]=='9') b[j]=9;
			if(a[j]=='_' || a[j]=='0') b[j]=10;
		}
		if(a[0]=='.' ||  a[0]==',' || a[0]=='?' || a[0]=='!' || a[0]=='1') l--;
		for(j=0;j<d;j++)
		{
			if(a[j]=='.' || a[j]=='a' || a[j]=='d' || a[j]=='g' || a[j]=='j' || a[j]=='m' || a[j]=='p' || a[j]=='t' || a[j]=='w' || a[j]=='_') l++;
			if(a[j]==',' || a[j]=='b' || a[j]=='e' || a[j]=='h' || a[j]=='k' || a[j]=='n' || a[j]=='q' || a[j]=='u' || a[j]=='x' || a[j]=='0') l+=2;
			if(a[j]=='?' || a[j]=='c' || a[j]=='f' || a[j]=='i' || a[j]=='l' || a[j]=='o' || a[j]=='r' || a[j]=='v' || a[j]=='y') l+=3;
			if(a[j]=='!' || a[j]=='2' || a[j]=='3' || a[j]=='4' || a[j]=='5' || a[j]=='6' || a[j]=='8' || a[j]=='s' || a[j]=='z') l+=4;
			if(a[j]=='1' || a[j]=='7' || a[j]=='9') l+=5;
		}
		for(j=0;j<d;j++)
		if(b[j]==b[j-1]) l--;
		k[i]=l;
	}
	//xuat so giay tuong ung voi moi tin nhan
	for(i=0;i<t;i++) printf("%d\n",k[i]);
}
