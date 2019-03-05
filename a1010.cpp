#include<iostream>
#include<cctype>
#include<string>
using namespace std;

string s1,s2,s3,s;//s3给定的数（字符串形式），s待确定进制的数 
long long radix,tag,a,b;//a给定进制的数，b待求进制的数 

int judge(long long r)//用于比较a和b的大小，以及判断b是否会溢出
{
	b=0;
	for(int i=0;i<s.size();i++)
	{
		if(isdigit(s[i]))
		{
			b=b*r+(s[i]-'0');
		}
		else 
		b=b*r+(s[i]-'a'+10);
		if(b>a||b<0)
		{
			return 1;//表示发生了溢出，或者进制太大； 
		 } 
	}
	
	if(b==a)return 0;//表示找到了当前进制；
	else if(b<a)return -1;//表示当前的进制较小； 
	
 } 
 
int main()
{
	cin>>s1>>s2>>tag>>radix;
	if(tag==1){
		s3=s1;s=s2;
	}else {
		s3=s2;
		s=s1; 
	}
	
	
	long long left,right;
	
	
	char _max='0';
	//寻找最小进制left 
	for(int i=0;i<s.size();i++)
	{
		_max=max(_max,s[i]);
	}
	if(isdigit(_max))left=_max-'0'+1;
	else left=_max-'a'+11;
	
	
	//求出给定的数字 
	for(int i=0;i<s3.size();i++)
	{
		if(isdigit(s3[i]))
			a=a*radix+(s3[i]-'0');
		else 
			a=a*radix+(s3[i]-'a'+10);
	}
	
	//此处是对进制不唯一情况的处理 ,当待求数字只有一位时。 
	if(s.size()==1)
	{
		if(isdigit(s[0]))
		{
			if((s[0]-'0'==a))
			cout<<left<<endl;
		}
		else
		{
			if(s[0]-'a'+10==a)
			cout<<left<<endl;
		}
		return 0;
	}
	

	//最大进制： 
	right=a+1;
	
//	right=100 0000 0000; 这个也能过 
	while(left<=right)
	{
		long long mid =(left+right)/2;
			
		int flag=judge(mid);
		
		if(flag==1)right=mid-1; 
		else if(flag==0)
		{
			cout<<mid<<endl;
			return 0;
		}
		else left=mid+1;
	}
	
	cout<<"Impossible"<<endl;	
	
	return 0;
}
