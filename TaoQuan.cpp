#include <stdio.h>
#include <math.h>
int main()
{
	long long n,m,k,t;
	scanf("%lld%lld%lld",&n,&m,&k);
	t=m;
	if(m>n/2) t=n/2;
	while(k>(m+n)-3*t) t--;
	printf("%lld",t);
}
/*
n = ong, m = ba, k = so nguoi duoc chon
VD: TH1:(ba > ong/2) 5 ba 6 ong => co 3 nhom 2 ong 1 ba du 2 ba va t = 3 = so nhom duoc di => 3*t= 9 nguoi duoc di (voi 6 ong 3 ba)
	TH2:(ba <= ong/2) 5 ba 16 ong => co 5 nhom 2 ong 1 ba du 6 ong va t = 5 = so nhom duoc di => 3*t= 15 nguoi duoc di (voi 10 ong 5 ba)
Voi 3*t la 3 nguoi/nhom, sau moi luot neu So nguoi duoc chon k van lon hon tong so nguoi con sot lai sau khi lap nhom 3 nguoi
thi se lay nguoi cua nhung nhom do the vao, tuc la so luong nhom se bi giam di 1 sau moi luot cho den khi = hoac > so luong k,
sau khi chon xong k nguoi thi nhung nhom du? nguoi (thoa man 2 ong 1 ba moi nhom) con lai se la so nhom can tim.*/
