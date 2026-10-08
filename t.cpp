#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
#include<map>
#include<ctime>
#include<stdio.h>
#include<random>
#include<bits/stdc++.h>
using namespace std;
int n=1;

int a[10010][10010];
int t=0;
int timenumber(int a)
{
//	tt1=1;
	while(1)
	{
		t+=1;
	}
	return 0;
}
int set1(int x,int y)
{
	
	a[x][y]=0;
	int d=0;
	int e=1+rand();
	e+=t;
	if(e<=0)
	{
		e=0-e;
	}
	d=e%9+t;
	d%=9;
	d+=1;
	if(d<=0)
	{
		d=0-d;
	}
	int t3=1;
	b:
	bool t2=true;
	for(int i=x;i>=1;i--)
	{
		if(a[i][y]==d)
		{
			t2=false;
			goto a;
		}
	}
	for(int i=y;i>=1;i--)
	{
		if(a[x][i]==d)
		{
			t2=false;
			goto a;
		}
	}
	goto c;
	a:
	d+=1;
	if(d==10)
	{
		d=1;
	}
	t3++;
	if(t3==11)
	{
		return -1;
	}
	goto b;
	
	c:
	a[x][y]=d;
	
	
	//下一项部分 
	if(x<9)
	{
		set1(x+1,y); 
	}
	else
	{
		if(y!=9)
		{
			set1(1,y+1);
		}
		else
		{
			return 0;
		}
	}
	

}

int main()
{
	thread t2(timenumber,1); // 创建线程，传递函数指针和参数
	//	t1.join(); // 等待线程完成
	t2.detach();//独立线程
	set1(1,1);
	for(int i=1; i<=9; i++)
	{
		for(int j=1; j<=9; j++)
		{
			cout<<a[i][j]<<"  ";
		}
		cout<<endl;
	}
	return 0;
}



