#include<iostream>
#include<conio.h>
int or(int a[],int n)
{

if(n==2)
{

if(a[0]+a[1]==0)
{
return 0;
}
else
{
return 1;
}

}
else
{
if(a[0]+a[1]+a[2]==0)
{
return 0;
}
else
{
return 1;
}

}


}



int nor(int a[],int n)
{

if(n==2)
{
if(a[0]+a[1]==0)
{
return 1;
}
else
{
return 0;
}

}
else
{
if(a[0]+a[1]+a[2]==0)
{
return 1;
}
else
{
return 0;
}
}

}




int and(int a[],int n)
{
if(n==2)
{
if(a[0]+a[1]==2)
{
return 1;
}
else
{
return 0;
}
}
else
{
if(a[0]+a[1]+a[2]==3)
{
return 1;
}
else
{
return 0;
}

}


}

int nand(int a[],int n)
{

if(n==2)
{
if(a[0]+a[1]==2)
{
return 1;
}
else
{
return 0;
}

}
else
{
if(a[0]+a[1]+a[2]==3)
{
return 0;
}
else
{
return 1;
}

}

}

int xor(int a[3],int n)
{
if(n==2)
{
if(a[0]!=a[1])
{
return 1;
}
else
{
return 0;
}

}
else
{
if((a[0]+a[1]+a[2])%2!=0)
{
return 1;
}
else
{
return 0;
}
}

}


int or(int a[3],char c[],int n)
{
int l[3],m=0;

for(int i=0;i<n-1;i++)
{
if(c[i]=='a')
{
l[m]=and(a,n);
m++;
}
if(c[i]=='o')
{
l[m]=or(a,n);
m++;
}

if(c[i]=='n')
{
l[m]=nor(a,n);
m++;
}
if(c[i]=='N')
{
l[m]=nand(a,n);
m++;
}
if(c[i]=='x')
{
l[m]=xor(a,n);
m++;
}
}


return or(l,m);

}

int and(int a[3],char c[],int n)
{
int l[3],m=0;
for(int i=0;i<n-1;i++)
{
if(c[i]=='a')
{
l[m]=and(a,n);
m++;
}
if(c[i]=='o')
{
l[m]=or(a,n);
m++;
}

if(c[i]=='n')
{
l[m]=nor(a,n);
m++;
}
if(c[i]=='N')
{
l[m]=nand(a,n);
m++;
}
if(c[i]=='x')
{
l[m]=xor(a,n);
m++;
}
}


return  and(l,m);

}

int nor(int a[3],char c[],int n)
{
int l[3],m=0;

for(int i=0;i<n-1;i++)
{
if(c[i]=='a')
{
l[m]=and(a,n);
m++;
}
if(c[i]=='o')
{
l[m]=or(a,n);
m++;
}

if(c[i]=='n')
{
l[m]=nor(a,n);
m++;
}
if(c[i]=='N')
{
l[m]=nand(a,n);
m++;
}
if(c[i]=='x')
{
l[m]=xor(a,n);
m++;
}

}

return nor(l,m);


}

int nand(int a[3],char c[],int n)
{
int l[3],m=0;
for(int i=0;i<n-1;i++)
{
if(c[i]=='a')
{
l[m]=and(a,n);
m++;
}
if(c[i]=='o')
{
l[m]=or(a,n);
m++;
}

if(c[i]=='n')
{
l[m]=nor(a,n);
m++;
}
if(c[i]=='N')
{
l[m]=nand(a,n);
m++;
}
if(c[i]=='x')
{
l[m]=xor(a,n);
m++;
}
}
return  nand(l,m);


}

int xor(int a[3],char c[],int n)
{
int l[3],m=0;
for(int i=0;i<n-1;i++)
{
if(c[i]=='a')
{
l[m]=and(a,n);
m++;
}
if(c[i]=='o')
{
l[m]=or(a,n);
m++;
}

if(c[i]=='n')
{
l[m]=nor(a,n);
m++;
}
if(c[i]=='N')
{
l[m]=nand(a,n);
m++;
}
if(c[i]=='x')
{
l[m]=xor(a,n);
m++;
}
}
return xor(l,m);

}

int circuit(int a[3],char g[],int n)
{
if(g[0]=='a')
{
return and(a,&g[1],n);

}
if(g[0]=='n')
{
return nor(a,&g[1],n);
}
if(g[0]=='o')
{
return or(a,&g[1],n);
}
if(g[0]=='N')
{
return nand(a,&g[1],n);
}
if(g[0]=='x')
{
return xor(a,&g[1],n);
}


}

int* tobinary(int x)
{
int i=2,*a={0};
if(x==0)
{
*(a+2)=0;
}
while(x>0)
{
a[i]=x%2 ;
x=x/2;
i--;
}

return a;
}

void main()
{
clrscr();
int a,res[8],m=0,n,four[8],check=0;
float s=0;
char gates[4],t,c;
int i,j,k;
cout<<"enter the no of gates \n\n";
cin>>n ;
a=n;

cout<<"enter the gates \n o for or \n x for xor \nN for NAND \n m for nor \n a for and \n n for not\n";

for(i=0;i<a;i++)
{
cin>>gates[i];
if(gates[i]=='n')
{
check=1;
i--;
a--;
}

}
if(check==1)
{
gates[a]=='n';
}


do
{

for(int j=0;j<n;j++)
{
if(j==0&&n==3)
{
cout<<"    "<<gates[j]<<"\n";
cout<<"  /   \\   \n";
}
else if(j==0&&n==4)
{
cout<<"     "<<gates[j]<<"\n";
cout<<"  /   !  \\  \n";
}
else
{
cout<<" "<<gates[j]<<"   ";
}

}
cout<<"\n";
s=0;
for(int m=0;m<4;m++)
{
if(gates[i]=='n')
{
c=gates[3];
gates[3]=gates[i];
gates[i]=c;
check=1;
break;
}

}

for(i=0;i<8;i++)
{

a=tobinary(i);
res[i]=circuit(a,gates,n);


}




for(i=0;i<8;i++)
{
s=s+res[i];
}
cout<<"optimal\t"<<s<<"\t"<<s/8*100<<" %\n";
m++;
t=gates[0];
gates[0]=gates[m];
gates[m]=t;

a[0]=a[1]=a[2]=0;

}while(m<=n-1);

getch();
}
