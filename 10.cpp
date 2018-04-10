#include<conio.h>
#include<stdio.h>
#include<iostream>
//tim 3 canh cua tam giac
   
   int main()
   {  
       int a,b,c;
       //nhap du lieu
       //nhap a
       printf("nhap a=");
       scanf("%d",&a);
       //nhap b
       printf("nhap b=");
       scanf("%d",&b);
       //nhap c
       printf("nhap c=");
       scanf("%d",&c);
       // dieu kien de a,b,c la 3 canh cua tam giac
       if((a+b)>c && (b+c)>c && (c+a)>b)
       {  // a,b ,c la 3 canh cuan tam giac
           printf("a,b,c la 3 canh cua tam giac\t");
           system("pause");
           //a,b,c la 3 canh cua tam giac deu
           if( a==b && b==c && c==a)
           {
               printf("a,b,c la 3 canh cua tam giac deu\t");
               system("pause");
               return 0;
            }
               //a,b,c la 3 canh cua tam giac can
               else if(a==b || b==c || c==a)
               {  
                    printf("a,b,c la 3 canh cua tam giac can\t");
                    system("pause");
                    return 0;
                }
                    // a,b,c la 3 canh cua tam giac vuong
                    else if(a*a==(b*b+c*c) || b*b==(c*c+a*a) || c*c==(a*a+b*b))
                    {  
                         printf("a,b,c la 3 canh cua tam giac vuong\t");
                         system("pause");
                         return 0;
                    }
                         // a,b,c la 3 canh cua tam giac vuong can
                         else if((a*a==(b*b+c*c) || b*b==(c*c+a*a) || c*c==(b*b+a*a)) && ( a==b || b==c || c==a))
                        {  
                              printf("a,b,c la 3 canh cua tam giac vuong can\t");
                              system("pause");
                              return 0;
                        }
                              else {   printf("a,b,c la 3 canh cua tam giac thuong\t");
                                         system("pause");
                                         return 0;
                                    }
            }
                                         else 
										 	{  printf ("a,b,c ko phai la 3 canh cua tam giac\n");
                                                  system("pause");
                                                  return 0;
                                            }  getch();
	}
