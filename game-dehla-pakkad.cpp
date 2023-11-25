#include <dos.h>
#include <conio.h>
#include <iostream.h>
#include <stdlib.h>

class dp
{
int *p,play,partner,op1,op2,ostar,pstar;
int heads,dehla,dnikal,hnikal,score,opscore,key,trump,rpp1,rpp2,rop1,rop2;

public:
 dp();
~dp();
 void print(int);
 void fplay(int);
 void fp2();
 void fop1();
 void fop2();
 void view();
 void chal();
 void skey(int);
  int chal1(int,int);
  int chal2(int,int,int);
  int chal3(int,int,int,int);
  int chal4(int,int,int,int,int);
};


int dp::chal1(int t,int re)
{
int k,min,l=100;

 if(re==12)
 return *(p+t);

 for(k=0;k<13;k++)
  {
  if( (*(p+t+k)!=0) && (l>(*(p+t+k)%100)) )
   {
   min=*(p+t+k);
   l=min%100;
   }
  }

 if(min%100==10)
 for(k=0,l=15;k<13;k++)
  {
  if((*(p+t+k)!=0) && (l>(*(p+t+k)%100)) && (*(p+t+k)%100)>10)
   {
   min=*(p+t+k);
   l=min%100;
   }
  }

 if(min==trump)
 for(k=0;k<13;k++)
  {
  if((*(p+t+k)%100<10) && (*(p+t+k)%100>min%100))
   min=*(p+t+k);
  }


return min;
}

int dp::chal2(int t,int re,int a)
{
int i,j,k,l,m,min,max;
if(re==12)
return *(p+t);

i=a/100;
min=(i+1)*100;
max=i*100;

 for(k=0,l=0;k<13;k++)
  {
  if(*(p+t+k)/100==i)
   {
   l++;
   if(min>*(p+t+k))
    min=*(p+t+k);
   if(max<*(p+t+k))
    max=*(p+t+k);
   }
  }

 if(l!=0 && min%100==10)
 for(k=0,m=15;k<13;k++)
  {
  if((*(p+t+k)!=0)&& (*(p+t+k)/100==i) && (m>(*(p+t+k)%100)) && (*(p+t+k)%100)>10)
   {
   min=*(p+t+k);
   m=min%100;
   }
  }


 if(l==0)
  {
  l=100;

  if(trump!=0)
  max=trump*100;
  else
  max=0;

  for(k=0,m=0;k<13-re;k++)
   {
   if(l>*(p+t+k)%100)
    {
    min=*(p+t+k);
    l=min%100;
    }

   if(trump!=0)
    {
    if((max<*(p+t+k)) && ((max/100)==(*(p+t+k)/100)))
     {
     max=*(p+t+k);
     m++;
     }
    if(k==13-re-1 && m==0)
     max=min;
    }
   else
    {
    if(max<*(p+t+k))
    max=*(p+t+k);
    }
   }

  if(trump==0)
  trump=min/100;
  }

if(a%100==10)
 return max;
else
 return min;
}


int dp::chal3(int t,int re,int a,int b)
{
int d=0,i,j,k,l,m,o=0,min,max;
if(re==12)
return *(p+t);

i=a/100;
min=(i+1)*100;
max=i*100;

 for(k=l=m=0;k<13;k++)
  {
  if(*(p+t+k)/100==i)
   {
   if(*(p+t+k)==10 || (a/100!=trump && b/100==trump))
    o=1;
   l++;
   if(min>*(p+t+k) && (*(p+t+k)%100)>10 && (a%100)<10)
    {
    min=*(p+t+k);
    m++;
    }
   if(max<*(p+t+k))
    max=*(p+t+k);
   }


  if((m==0 && k==13-1)||(o==1))
   {
   for(m=0,min=((i+1)*100);m<13;m++)
    {
    if(*(p+t+m)/100==i)
     {
     if(min>*(p+t+m))
      min=*(p+t+m);
     }
    }
   if(max%100<10)
    {
    max=min;
    d=1;
    }
   }
  }

 if(l!=0 && min%100==10)
 for(k=0,m=15;k<13;k++)
  {
  if((*(p+t+k)!=0) &&(*(p+t+k)/100==i) &&(m>(*(p+t+k)%100)) &&(*(p+t+k)%100)>10)
   {
   min=*(p+t+k);
   m=min%100;
   if(d==1)
    max=min;

   }
  }

 if(l==0)
  {
  l=100;

  if(trump!=0)
  max=trump*100;
  else
  max=0;

  for(k=0,m=0;k<13-re;k++)
   {
   if(l>*(p+t+k)%100)
    {
    min=*(p+t+k);
    l=min%100;
    }

   if(trump!=0)
    {
    if((max<*(p+t+k)) && ((max/100)==(*(p+t+k)/100)))
     {
     m++;
     max=*(p+t+k);
     if(b>max && (b/100)==(max/100))
      m=0;
     }
    if(k==13-re-1 && m==0)
     max=min;
    }
   else
    {
    if(max<*(p+t+k))
    max=*(p+t+k);
    }
   }

  if(trump==0)
  trump=min/100;
  }


if(((b%100)==10) || ((a%100)==10))
 return max;
else
 return min;
}


int dp::chal4(int t,int re,int a,int b,int c)
{
int d=0,i,j,k,l,m,min,max;
if(re==12)
return *(p+t);

i=a/100;
min=(i+1)*100;
max=(i+1)*100;

 for(k=l=m=0;k<13;k++)
  {
  if(*(p+t+k)/100==i)
   {
   if((*(p+t+k)%100==10 && a/100==b/100 && b/100==c/100 && *(p+t+k)>a && *(p+t+k)>c)||(*(p+t+k)%100==10 && a/100==b/100 && b/100==c/100 && b>a && b>c) || (*(p+t+k)%100==10 && ( (a/100==c/100 && b/100==trump)||(c/100==trump && b/100==trump && b>c)) && a/100!=trump))
   return *(p+t+k);

   l++;
   if(min>*(p+t+k))
    min=*(p+t+k);
   if(max>*(p+t+k))
    if( (*(p+t+k)%100)>(a%100) && (*(p+t+k)%100)>(b%100) &&  (*(p+t+k)%100)>(c%100))
    {
    max=*(p+t+k);
    m++;
    }
   }

  if(m==0 && k==13-1)
   {
   max=min;
   d=1;
   }
  }

 if(l!=0 && min%100==10)
 for(k=0,m=15;k<13;k++)
  {
  if((*(p+t+k)!=0)&& (*(p+t+k)/100==i) && (m>(*(p+t+k)%100)) && (*(p+t+k)%100)>10)
   {
   min=*(p+t+k);
   m=min%100;
   if(d==1)
   max=min;
   }
  }

 if(l!=0 && a/100!=trump && (b/100==trump || c/100==trump))
  max=min;

 if(l==0)
  {
  l=100;

  if(trump!=0)
  max=trump*100;
  else
  max=0;

  for(k=0,m=0;k<13-re;k++)
   {
   if(l>*(p+t+k)%100)
    {
    min=*(p+t+k);
    l=min%100;
    }

   if(trump!=0)
    {
    if((max<*(p+t+k)) && ((max/100)==(*(p+t+k)/100)))
     {
     m++;
     max=*(p+39+k);
     if(( (c>max) && ((c/100)==(max/100)) ) || ( (b>max) && ((b/100)==(max/100)) ))
      m=0;
     }
    if(k==13-re-1 && m==0)
     max=min;
    }
   else
    {
    if(max<*(p+t+k))
    max=*(p+t+k);
    }
   }

  if(trump==0)
  trump=min/100;
  }

 if(a/100==b/100 && b/100==c/100 && b>a && b>c)
  return min;

 if(b/100==trump && c/100==trump && b>c)
  return min;

 if( ((c%100)==10) || ((b%100)==10) || ((a%100)==10) )
  return max;
 else
  return min;
}

void dp::fop1()
{
int i,j;
if(key==1)
 op1=chal2(13,rop1,play);

else if(key==2)
 {
 play=partner=op2=0;
 op1=chal1(13,rop1);
 }
else if(key==3)
 op1=chal4(13,rop1,partner,op2,play);

else
 op1=chal3(13,rop1,op2,play);

for(i=13;i<26;i++)
 {
 if(*(p+i)==op1)
  {
  for(j=i;j<25;j++)
   *(p+j)=*(p+j+1);
  *(p+j)=0;
  break;
  }
 }
rop1++;
}

void dp::fp2()
{
int i,j;
if(key==1)
 partner=chal3(26,rpp2,play,op1);

else if(key==2)
 partner=chal2(26,rpp2,op1);

else if(key==3)
 {
 play=op1=op2=0;
 partner=chal1(26,rpp2);
 }
else
 partner=chal4(26,rpp2,op2,play,op1);

for(i=26;i<39;i++)
 {
 if(*(p+i)==partner)
  {
  for(j=i;j<38;j++)
   *(p+j)=*(p+j+1);
  *(p+j)=0;
  break;
  }
 }
rpp2++;
}

void dp::fop2()
{
int i,j;
if(key==1)
 op2=chal4(39,rop2,play,op1,partner);

else if(key==2)
 op2=chal3(39,rop2,op1,partner);

else if(key==3)
 op2=chal2(39,rop2,partner);

else
 {
 play=partner=op1=0;
 op2=chal1(39,rop2);
 }

for(i=39;i<52;i++)
 {
 if(*(p+i)==op2)
  {
  for(j=i;j<51;j++)
   *(p+j)=*(p+j+1);
  *(p+j)=0;
  break;
  }
 }
rop2++;
}


void dp::chal()
{
int aaa=score,patta,i,x,y,z;
i=(rand()+getch())%100;
for(;(score+opscore-(3*(ostar+pstar)))<10;)
{
 for(int k=0;k<52;k++)
  *(p+k)=0;

 for(x=0;x<52;)
  {
  patta=(rand()%1000);

  if((patta>301-i && patta<315-i)||(patta>401-i && patta<415-i)||(patta>501-i && patta<515-i)||(patta>601-i && patta<615-i))
   {
   for(y=z=0;y<52;y++)
   if(*(p+y)!=patta+i || *(p+y)==0)
    z++;

   if(z==52)
    {
    *(p+x)=patta+i;
    x++;
    }
   }
  }

int l,m,max,temp;
for(l=0;l<13;l++)
 {
 max=*(p+l);
 for(m=l+1,k=l;m<13;m++)
  {
  if(max<*(p+m))
   {
   max=*(p+m);
   k=m;
   }
  }
 temp=*(p+l);
 *(p+l)=max;
 *(p+k)=temp;
 }

clrscr();
view();
gotoxy(1,1);
cout<<"\n ALLOW FIRST TO PLAY..\n  ";
if((score+opscore==0) || aaa!=score)
cout<<(char)30<<" oR "<<(char)31;
if((score+opscore==0) )
cout<<"   ";
if((score+opscore==0) || aaa==score)
cout<<(char)17<<" oR "<< (char)16;
for(int gk=0,arrow;gk==0;)
{
union REGS i,o;

while(!kbhit());
i.h.ah=0;
int86 (22,&i,&o);

arrow=o.h.ah;
if((score+opscore==0) && (arrow==72||arrow==75||arrow==77||arrow==80))
gk=1;
else if((aaa!=score) && (arrow==72 || arrow==80))
gk=1;
else if((aaa==score) && (arrow==75 || arrow==77))
gk=1;
}
if(rpp1!=0)
getch();
aaa=score;
gotoxy(1,1);
cout<<"\n                      \n              ";

if(arrow==75)
key=2;
else if(arrow==72)
key=3;
else if(arrow==77)
key=4;
else
key=1;


for(int g=0;g<13;g++)
 {
 switch (key)
  {
  case 1:
  clrscr();
  op1=partner=op2=play=0;
  view();
  fplay(0);
  fop1();
  fp2();
  fop2();
  clrscr();
  view();
  skey(play/100);
  break;

  case 2:
  clrscr();
  fop1();
  fp2();
  fop2();
  view();
  fplay(op1/100);
  clrscr();
  view();
  skey(op1/100);
  break;

  case 3:
  clrscr();
  fp2();
  fop2();
  view();
  fplay(partner/100);
  fop1();
  clrscr();
  view();
  skey(partner/100);
  break;

  case 4:
  clrscr();
  fop2();
  view();
  fplay(op2/100);
  fop1();
  fp2();
  clrscr();
  view();
  skey(op2/100);
  break;
  }
 delay(5000);
 }

int won=0;
if((dehla>2) || (dehla==2 && heads>6))
 {
 if(dehla==4)
  {
  score+=4;
  pstar++;
  }
 else
  score++;
 won=1;
 }
else
 {
 if(dehla==0)
  {
  opscore+=4;
  ostar++;
  }
 else
  opscore++;
 }
trump=rpp1=rpp2=rop1=rop2=0;
clrscr();
view();
heads=dehla=dnikal=hnikal=0;
char wanna;
gotoxy(31,10);
if(won==1)
 cout<<"YoU wON!!\n   ";
else
 cout<<"YoU LooSE!!\n   ";
if((score+opscore-(3*(ostar+pstar)))!=10)
{
cout<<"                           wAnna cOntinue??\n";
cout<<"                              (Y/N) ";
cin>>wanna;
if((wanna=='y')||(wanna=='Y'))
 i+=7;
}

if(wanna!='y' || wanna!='y' || (score+opscore-(3*(ostar+pstar))==10) )
 {
 clrscr();

 cout<<"              xxxx\n";
 cout<<"            xxxxxxxx\n";
 cout<<"            xxxxxxxx\n";
 cout<<"              xxxx               xxxx\n";
 cout<<"                               xxxxxxxx\n";
 cout<<"                               xxxxxxxx\n";
 cout<<"                                 xxxx\n\n\n\n\n\n";
 cout<<"       xxxx\n";
 cout<<"     xxxxxxxx\n";
 cout<<"     xxxxxxxx\n";
 cout<<"       xxxx\n";

 gotoxy(4,8);
 if(opscore>score)
  cout<<"HARD LUCK..\n   YOU LOOSE!!\n"<<"   YOU:"<<score<<"  OPPONENT:"<<opscore;
 else if(opscore<score)
  cout<<"CONGRATTS!!\n   YOU WON!!\n"<<"   YOU:"<<score<<"  OPPONENT:"<<opscore;
 else
  cout<<"WELL PLAYED..\n   SCORE LEVELLED!!\n"<<"   YOU:"<<score<<"  OPPONENT:"<<opscore;
 break;
 }
}
}

void dp::view()
{
int i;
/*
for(i=1;i<=52;i++)
 {
 print(*(p+i-1));
 cout<< "  ";
 if(i%13==0)
 cout<<"\n";
 }

 */
gotoxy(31,3);
cout<<"Your Partner";
gotoxy(31,4);
for(i=0+rpp2;i<16;i++)
 {
 if(rpp2==13)
  {
  i+=2;
  continue;
  }
 cout<<(char)177;
 }
/**/
gotoxy(31,5);
for(i=0+rpp2;i<16;i++)
 {
 if(rpp2==13)
  {
  i+=2;
  continue;
  }
 cout<<(char)178;
 }
gotoxy(31,6);
for(i=0+rpp2;i<16;i++)
 {
 if(rpp2==13)
  {
  i+=2;
  continue;
  }
 cout<<(char)177;
 }

gotoxy(7,7);
cout<<"Opponent 1";
gotoxy(7,8);
for(i=0+rop1;i<16;i++)
 {
 if(rop1==13)
  {
  i+=2;
  continue;
  }
 cout<<(char)177;
 }
gotoxy(7,9);
for(i=0+rop1;i<16;i++)
 {
 if(rop1==13)
  {
  i+=2;
  continue;
  }
 cout<<(char)178;
 }
gotoxy(7,10);
for(i=0+rop1;i<16;i++)
 {
 if(rop1==13)
  {
  i+=2;
  continue;
  }
 cout<<(char)177;
 }

gotoxy(54,7);
cout<<"Opponent 2";
gotoxy(54,8);
for(i=0+rop2;i<16;i++)
 {
 if(rop2==13)
  {
  i+=2;
  continue;
  }
 cout<<(char)177;
 }
gotoxy(54,9);
for(i=0+rop2;i<16;i++)
 {
 if(rop2==13)
  {
  i+=2;
  continue;
  }
 cout<<(char)178;
 }
gotoxy(54,10);
for(i=0+rop2;i<16;i++)
 {
 if(rop2==13)
  {
  i+=2;
  continue;
  }
 cout<<(char)177;
 }

gotoxy(18,19);
cout<<"You";
gotoxy(18,16);
for(i=0;i<13-rpp1;i++)
 {
  if(*(p+i)%100==10)
  cout<<(char)(*(p+i)/100)<<10<<(char)177;
  else if(*(p+i)%100==11)
  cout<<(char)(*(p+i)/100)<<(char)74<<(char)32<<(char)177;
  else if(*(p+i)%100==12)
  cout<<(char)(*(p+i)/100)<<(char)81<<(char)32<<(char)177;
  else if(*(p+i)%100==13)
  cout<<(char)(*(p+i)/100)<<(char)75<<(char)32<<(char)177;
  else if(*(p+i)%100==14)
  cout<<(char)(*(p+i)/100)<<(char)65<<(char)32<<(char)177;
  else
  cout<<(char)(*(p+i)/100)<<*(p+i)%100<<(char)32<<(char)177;
 }

gotoxy(18,17);
for(i=0+rpp1;i<13;i++)
cout<<(char)178<<(char)178<<(char)178<<(char)178;

gotoxy(18,18);
for(i=0+rpp1;i<13;i++)
cout<<(char)177<<(char)177<<(char)177<<(char)177;

gotoxy(4,15);
if(trump!=0)
 cout<<"Trump "<<(char)trump;

if( (rpp1!=0 && rpp1!=13)||(rop1!=0 && rop1!=13)||(rpp2!=0 && rpp2!=13)||(rop2!=0 && rop2!=13))
 {
 gotoxy(37,9);
 print(partner);
 }
if((rpp1!=0 && rpp1!=13)||(rop1!=0 && rop1!=13)||(rpp2!=0 && rpp2!=13)||(rop2!=0 && rop2!=13))
 {
 gotoxy(29,11);
 print(op1);
 }
if((rpp1!=0 && rpp1!=13)||(rop1!=0 && rop1!=13)||(rpp2!=0 && rpp2!=13)||(rop2!=0 && rop2!=13))
 {
 gotoxy(45,11);
 print(op2);
 }
if((rpp1!=0 && rpp1!=13)||(rop1!=0 && rop1!=13)||(rpp2!=0 && rpp2!=13)||(rop2!=0 && rop2!=13))
 {
 gotoxy(37,13);
 print(play);
 }

gotoxy(30,21);
cout<<"Dehla: "<<dehla<<"/"<<dnikal;
gotoxy(30,22);
cout<<"Heads: "<<heads<<"/"<<hnikal;
gotoxy(30,23);
cout<<"Your Score: "<<score;
cout<<"\b\b\b\b\b\b\b\b\b\b\b\b";
if(pstar!=0 || ostar!=0)
for(int ps=0;ps<pstar;ps++)
cout<<"\b\b*";

gotoxy(30,24);
cout<<"Opponent's: "<<opscore;
cout<<"\b\b\b\b\b\b\b\b\b\b\b\b";
if(pstar!=0 || ostar!=0)
for(int ps=0;ps<ostar;ps++)
cout<<"\b\b*";

gotoxy(50,21);
cout<<"Use for ";
cout<<(char)5<<"Club    'C'";
gotoxy(58,22);
cout<<(char)4<<"Diamond 'D'";
gotoxy(58,23);
cout<<(char)3<<"Heart   'H'";
gotoxy(58,24);
cout<<(char)6<<"Spades  'S'";
}

void dp::fplay(int w)
{
int i,j,k,x;
for(x=0;x==0;)
 {
 k=play;
 char a[3];
 gotoxy(4,16);
 cout<<"Play\n                \r   ";
 cin.getline(a,15);

 if((int)a[0]==99 || (int)a[0]==67)
 i=5;
 else if((int)a[0]==100 || (int)a[0]==68)
 i=4;
 else if((int)a[0]==104 || (int)a[0]==72)
 i=3;
 else if((int)a[0]==115 || (int)a[0]==83)
 i=6;

 if((int)a[1]==65 || (int)a[1]==97)
 j=14;
 else if((int)a[1]==74 || (int)a[1]==106)
 j=11;
 else if((int)a[1]==75 || (int)a[1]==107)
 j=13;
 else if((int)a[1]==81  || (int)a[1]==113 )
 j=12;
 else if((int)a[1]==49 )
 j=10;
 else
 j=(int)a[1]-48;

 play=100*i+j;

 j=0;
 if(w!=0 && play/100!=w)
  {
  for(i=0;i<13;i++)
   {
   if((*(p+i)/100)==w && *(p+i)!=0)
    {
    cout<<"   wRong chOice!";
    getch();
    cout<<"\r                ";
    j++;
    play=k;
    break;
    }
   }
  }

  if(j!=0)
  continue;

 for(i=0;i<13;i++)
  {
  if(*(p+i)==play)
   {
   for(j=i;j<12;j++)
    *(p+j)=*(p+j+1);

   *(p+j)=0;
   rpp1++;
   x++;
   break;
   }
  }

 if(i==13)
  {
  cout<<"   nO matCh!";
  getch();
  cout<<"\r             ";
  x=0;
  play=k;
  }

 if(trump==0 && play/100!=w && w!=0)
  trump=play/100;
 }
}

void dp::print(int i)
{
  switch(i%100)
  {
  case 10:
  cout<<(char)(i/100)<<" "<<10;
  break;
  case 11:
  cout<<(char)(i/100)<<" "<<(char)74;
  break;
  case 12:
  cout<<(char)(i/100)<<" "<<(char)81;
  break;
  case 13:
  cout<<(char)(i/100)<<" "<<(char)75;
  break;
  case 14:
  cout<<(char)(i/100)<<" "<<(char)65;
  break;
  default:
  if(i!=0)
   cout<<(char)(i/100)<<" "<<i%100;
  else
   cout<<"   ";
  }
}

void dp::skey(int i)
{
 int m=0,max=0;

 if(play%100==10)
  {
  m++;
  dnikal++;
  }
 if(op1%100==10)
  {
  m++;
  dnikal++;
  }
 if(partner%100==10)
  {
  m++;
  dnikal++;
  }
 if(op2%100==10)
  {
  m++;
  dnikal++;
  }

 if((play/100==op1/100)&&(op1/100==partner/100)&&(partner/100==op2/100))
 {
 if(max<play)
  {
  max=play;
  key=1;
  }
 if(max<op1)
  {
  max=op1;
  key=2;
  }
 if(max<partner)
  {
  max=partner;
  key=3;
  }
 if(max<op2)
  {
  max=op2;
  key=4;
  }
 }

 else if((play/100==trump)||(op1/100==trump)||(partner/100==trump)||(op2/100==trump))
 {
  if(max<play && (play/100==trump))
   {
   max=play;
   key=1;
   }
 if(max<op1 && (op1/100==trump))
   {
   max=op1;
   key=2;
   }
 if(max<partner && (partner/100==trump))
   {
   max=partner;
   key=3;
   }
 if(max<op2 && (op2/100==trump))
   {
   max=op2;
   key=4;
   }
 }

 else if((play/100==i)||(op1/100==i)||(partner/100==i)||(op2/100==i))
 {
 if(max<play && (play/100==i))
  {
  max=play;
  key=1;
  }
 if(max<op1 && (op1/100==i))
  {
  max=op1;
  key=2;
  }
 if(max<partner && (partner/100==i))
  {
  max=partner;
  key=3;
  }
 if(max<op2 && (op2/100==i))
  {
  max=op2;
  key=4;
  }
 }

 if(key==1 || key==3)
  {
  heads++;
  dehla+=m;
  }

hnikal++;
}


dp::dp()
{
play=partner=op1=op2=rpp1=rpp2=rop1=rop2=ostar=pstar=0;
trump=heads=dehla=dnikal=hnikal=score=opscore=0;
key=1;
p=new int[52];
for(int i=0;i<52;i++)
 *(p+i)=0;
}


void main()
{
clrscr();
cout<<"\n \"DEHLA PAKAD\"\n press any key to start..";
dp start;
start.chal();
getch();
}


dp::~dp()
{
delete [] p;
}
