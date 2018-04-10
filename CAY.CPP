#include<stdio.h>
#include<conio.h>
struct nut
{ int Info;
  nut *left,*right;};
typedef nut Node;
Node *root;
void khoitao(Node *&root)
{ root=NULL;}
//---------------------------------------
void mocnut(Node *&root,int x)
{
   if(root==NULL)
    {
      root=new Node;
      root->Info=x;
      root->left=NULL;
      root->right=NULL;
    }
    else
      if(root->Info>=x)
	 mocnut(root->left,x);
      else
	 mocnut(root->right,x);
}
//----------------------------------------------
void taocay(Node *&root)
{
   int tam;
   do
   {
     printf("nhap mot so nguyen, 0: dung");
     scanf("%d",&tam);
     if(tam!=0)
       mocnut(root,tam);
   }
   while(tam!=0);
}
//---------------------------------------------
void duyetLNR(Node *root)
{
   if(root!=NULL)
   {
   duyetLNR(root->left);
   printf("%3d",root->Info);
   duyetLNR(root->right);
   }
}
//---------------------------------------------
int Tongnut(Node *root)
{
   if(root==NULL)
      return 0;
   else
      if((root->left==NULL) && (root->right==NULL))
	 return root->Info;
      else
	 return root->Info+ Tongnut(root->left)+Tongnut(root->right);
}
int main()
{
   khoitao(root);
   taocay(root);
   printf("\n Duyet cay \n");
   duyetLNR(root);
   printf("\n tong cac nut %d \n",Tongnut(root));
   getch();
   return 0;
}
