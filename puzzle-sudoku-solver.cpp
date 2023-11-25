#include <iostream.h>
#include <conio.h>
#include <math.h>

class SUD
{
protected:
int *p,*r,*blck,n;
int bi,ri,stop,X;

public:
 void init();
 void showSUD();
 void green();
 void red(int);
 void put(int,int);
 void fill();
 SUD();
~SUD()
 {
  delete []p;
  delete []r;
  delete []blck;
 }
};


SUD::SUD()
 {
  bi=ri=stop=0;
  int i;
  cout<<"SUDOKU of nxn, then n= ";
  cin>>n;
  p=new int[n*n];
  for(i=0;i<n*n;i++)
  *(p+i)=0;
  r=new int[n*n*n];
  blck=new int[n*n];
 }

void SUD::init()
{
 int m;
 cout <<"How many numbers do u want to give frm your side?? ";
 cin>>m;
 cout<<"Example for value at s[2][1], give only '21'"<<endl;

 for(int l=0;l<m;l++)
 {
  int a,i,j,k=1;
  cout<<"To give value at [][]: ";
  cin>>a;
  cout<<"value?? ";
  cin>>i;
  red(i);

  for(j=0;(j<ri)&&(l!=0);j++)
  if(a==*(r+j))
  {
   k=0;
   cout<<"invalid LOCATION"<<endl<<"Try Again!!";
   m++;
   break;
  }

  if(k!=0)
  {
   *(blck+bi)=a;
   bi++;
   a=((a/10)-1)*n + ((a%10)-1);
   *(p+a)=i;
   stop++;
  }
 }
}

void SUD::green()
{
red(X);
int *row,*col,*mat;
int a,b,c,d,e,f,g,h,i,j,k,l,m,o,z;

row=new int[n];
col=new int[n];
mat=new int[n];

for(a=1;a<=n;a++)
{
 e=h=0;
 for(b=0;b<n;b++)
 {
  d=0;
  *(row+b)=a*10+b+1;

  for(c=o=0;c<bi;c++)
  {
   if(*(row+b)==*(blck+c))
   {
    o++;
    h++;
    break;
   }
  }
  if(o==0)
   m=*(row+b);

  for(c=0;c<ri;c++)
  {
  if(*(row+b)==*(r+c))
   {
    if(m==*(r+c))
     {h=0;
     z=1;}
    d++;
    break;
   }
  }

  if(d==0)
  {
   e++;
   f=*(row+b);
  }
 }

 if(h==n-1)
  f=m;

 if((e==1 && ri!=bi)||(h==n-1 && z!=1))
 {
 put(f,X);
 red(X);
 }
}


for(a=1;a<=n;a++)
{
 e=h=0;
 for(b=0;b<n;b++)
 {
  d=0;
  *(col+b)=a+(b+1)*10;

  for(c=o=0;c<bi;c++)
  {
   if(*(col+b)==*(blck+c))
   {
    o++;
    h++;
    break;
   }
  }
  if(o==0)
   m=*(col+b);

  for(c=0;c<ri;c++)
  {
   if(*(col+b)==*(r+c))
   {
    if(m==*(r+c));
     {h=0;
     z=1;}
    d++;
    break;
   }
  }

  if(d==0)
  {
   e++;
   f=*(col+b);
  }
 }

 if(h==n-1)
  f=m;

 if((e==1 && ri!=bi)||(h==n-1 && z!=1))
 {
 put(f,X);
 red(X);
 }
}

for(a=b=c=1;a<=n;a++)
{
 d=b*10+c;

 c+=(int)sqrt(n);
 if(a%(int)sqrt(n)==0)
 {
  b+=(int)sqrt(n);
  c=1;
 }

 f=d/10;
 g=d%10;

 k=j=0;
 for(e=1;e<=n;e++)
 {
  i=0;
  *(mat+e-1)=f*10+g;

  g+=1;
  if(e%(int)sqrt(n)==0)
  {
   f+=1;
   g=g-sqrt(n);
  }

  for(h=o=0;h<bi;h++)
  {
   if(*(mat+e-1)==*(blck+h))
   {
    o++;
    j++;
   }
  }
  if(o==0)
   m=*(mat+e-1);

  for(h=0;h<ri;h++)
  {
   if(*(mat+e-1)==*(r+h))
   {
    if(m==*(r+h))
     {j=0;
     z=1;}
    i++;
    break;
   }
  }

  if(i==0)
  {
   k++;
   l=*(mat+e-1);
  }
 }

 if(j==n-1)
  l=m;

 if((k==1&&ri!=bi)||(j==n-1 && z!=1))
  put(l,X);
}

delete []row;
delete []col;
delete []mat;
};

void SUD::put(int a,int c)
{
 *(blck+bi)=a;
 bi++;
 a=((a/10)-1)*n + ((a%10)-1);
 *(p+a)=c;
 stop++;
}

void SUD::red(int i)
{
 ri=0;
 for(int j=0;j<bi;j++)
 {
 *(r+ri)=*(blck+j);
 ri++;
 }

 for(j=0;j<n*n;j++)
 {
  if(*(p+j)==i)
  {
  int l=((j/n)+1)*10+1;
  for(;l<=( ((j/n)+1)*10 + n );l++)
   {
    *(r+ri)=l;
    ri++;
   }

  l=j%n+1;
  for(int m=1;m<=n;m++)
   {
    *(r+ri)=m*10+l;
    ri++;
   }

  l=(j/n)+1;
  if((l%(int)sqrt(n))!=0)
  l=(int)sqrt(n)-l%(int)sqrt(n)+l;

  m=j%n+1;
  if((m%(int)sqrt(n))!=0)
  m=(int)sqrt(n)-m%(int)sqrt(n)+m;

  int u=l-(int)sqrt(n),v=m-(int)sqrt(n);
  for(;l>u;l--)
   {
    m=v+sqrt(n);
    for(;m>v;m--)
    {
     *(r+ri)=l*10+m;
     ri++;
    }
   }
  }
 }
}

void SUD::fill()
{
 for(;;)
 {
 for(X=1;X<=n;X++)
  green();

 if(bi==n*n)
  break;
 }
}

void SUD::showSUD()
{
 clrscr();
 for(int m=0;m<n*n;m++)
 {
  if(m%(int)sqrt(n)==0)
  cout<<" ";

  if(m%((int)sqrt(n)*n)==0)
  cout<<endl;

  if(m%n==0)
  cout<<endl;

  cout<<" "<<*(p+m);
 }
}

void main()
{
SUD s;
char i;
cout<<"Wwanna initialize some values(y/n)??";
cin>>i;

if(i=='y')
{
 s.init();
 s.fill();
}
s.showSUD();
getch();
}