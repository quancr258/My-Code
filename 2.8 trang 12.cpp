#include<stdio.h>
#include<math.h>
int main(int argc,char *argv[])
{
	float d;
	if(argc==4)
	{
		float a = atof(argv[1]);
		float b = atof(argv[2]);
		float c = atof(argv[3]);
		d=pow(b,2)-4*a*c;
		if(d>0) printf("x1 = %f \t x2 = %f",(-b-sqrt(d))/(2*a),(-b+sqrt(d))/(2*a));
		if(d==0) printf("x1 = x2 = %f",(-b+sqrt(d))/(2*a));
		if(d<0) printf("pt vo nghiem");
	}
	else printf("Sai! VD: GiaiPT_Bac2 1 2 -3");
}
