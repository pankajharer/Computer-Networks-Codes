#include <bits/stdc++.h> 
using namespace std;

int a[1000]; 
int noofbit=0;

void decToBinary(int n)
{
	int i;
	for(i=0; n>0; i++)
	{
		a[i]=n%2; 
		n= n/2;
	}
	cout<<"Binary of the given number= ";
	for(i=i-1 ;i>=0 ;i--)
	{
		cout<<a[i]; noofbit++;
	}
	cout<<endl;
}

int main()
{
	int ip[4];
	cout<<"input ip address: "; 
	for(int i=0;i<4;i++){
		cin>>ip[i];
	}
	cout<<"\nip address is: "; 
	for(int i=0;i<4;i++){
		cout<<ip[i]<<".";
	}
	int host;
	cout<<"\ninput no of host: "; 
	cin>>host;
	cout<<"\nClass of the IP address is: ";
 	if(0<=ip[0] && ip[0]<=127)
	{
	 	cout<<" A";
		cout<<"\n it is class A so subnet mask of class A is 255.0.0.0"<<endl; 
		decToBinary(host);
		int j=24-noofbit;
		cout<<endl<<"subnet in binary form :"<<endl; 
		int cal=0;
		for( int i=0;i<8;i++)
		{
			cout<<1;
		}
		cout<<".";
		for( int i=0;i<j;i++)
		{
			if(cal==8)
			{
				cout<<"."; 
				cal=0;
 			}
		}
		cout<<1; 
		cal++;
		for( int i=0;i<noofbit;i++)
		{ 
			if(cal==8)
			{
				cout<<"."; cal=0;
			}
			cout<<0;
		}
		cout<<"\n\n\nsubnetmask of the ip address for "<<host<<" host is: "; 
		cout<<255<<".";
		int k=0; 
		int i=1;
		int count=0; 
		for(i=1;i<=j;i++)
		{
			if(count==8){
				count=0; break;
			}
			k+=pow(2,8-i); count++;
		}
		cout<<k<<"."; k=0;
		i=i-1;
		for(int q=1;i<=j;q++ && i++)
		{
			if(count==8)
			{ 
				count=0;
				break;
			}
			k+=pow(2,8-q); 
			count++;
		}
		cout<<k<<"."; k=0;
		i=i-1;
		for(int q=1;i<=j;q++ && i++)
		{
			if(count==8)
			{ 
				count=0;
				break;
			}
			k+=pow(2,8-q); count++;
		}
		cout<<k<<".";
	}
	else if(128<=ip[0] && ip[0]<=191)
	{
		int cal=0;
		cout<<"B";
		cout<<"\n - it is class B so subnet mask of class B is 255.255.0.0"<<endl;
		decToBinary(host); 
		cout<<endl;
		int j=16-noofbit;
		
		cout<<endl<<"subnet in binary form :"<<endl; 
		for( int i=0;i<16;i++)
		{
			cout<<1;
			if(i==7)
			{
				cout<<".";
			}
	    }
	    cout<<".";
		for( int i=0;i<j;i++)
		{
			if(cal==8)
			{
				cout<<"."; 
				cal=0;
			}
			cout<<1; 
			cal++;
		}
		for( int i=0;i<noofbit;i++)
		{ 
			if(cal==8)
			{
				cout<<"."; 
				cal=0;
			}
			cout<<0; 
			cal++;
		}
		cout<<endl<<255<<"."<<255<<".";
		int k=0;
		int count=0; 
		int i=1;
		for(i=1;i<=j;i++)
		{ 
			if(count==8)
			{
				count=0; break;
			}
			k+=pow(2,8-i); count++;
		}
		cout<<k<<"."; 
		int l=0;
		i=i-1;
		for(int q=1;i<=j;q++ && i++)
		{
			l+=pow(2,8-q);
		}
		cout<<l;
	}
	
	else if(192<=ip[0] && ip[0]<=223)
	{
		int cal=0;
		cout<<"C";
		cout<<"\n - it is class C so subnet mask of class C is 255.255.0.0"; 
		decToBinary(host);
		int j=8-noofbit; 
		int ans[32];
		cout<<endl<<"subnet in binary form :"<<endl; 
		
		for( int i=0;i<24;i++)
		{
			cout<<1;
			if(i==7 || i==15)
			{
				cout<<".";
			}
		}
		
		cout<<".";
		for( int i=0;i<j;i++)
		{
			if(cal==8)
			{
				cout<<"."; cal=0;
 			}
 		}
		cout<<1; 
		cal++;
		for(int i=0;i<noofbit;i++)
		{ 
			if(cal==8)
			{
				cout<<"."; 
				cal=0;
 			}
			cout<<0;
		}
		int k=0; 
		for(int i=1;i<=j;i++)
		{
			k+=pow(2,8-i);
		} 
		cout<<endl<<endl<<255<<"."<<255<<"."<<255<<"."<<k;
	}
	return 0;
}
