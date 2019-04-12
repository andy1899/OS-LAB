// Intially -1 represent no element 
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
main()
{
	cout<<"Enter input string";
	string inp;
	cin>>inp;
	ll m,miss=0,cnt=0,n,frame,len=inp.length();
	cout<<"Enter page frame size";
	cin>>frame;
    ll pos=-1,a[frame];
      for(n=0;n<frame;n++)
       a[n]=-1;
      
	bool flag;
	for(m=0;m<len;m++)
	{ cnt=0;
	  for(n=0;n<frame;n++)
	  {
	  	if(inp[m]-48!=a[n])
         {
         	
         	++cnt;
										} 	  		
		  else if(inp[m]-48==a[n])
    {
    
		   flag=false;
		   break;
		   }
	  }
	  if(cnt==frame)
	  flag=true;
	  else;
			if(flag==true)
	  {
	  	++miss;
	  	++pos;
				pos=pos%frame;
			
	  	a[pos]=inp[m]-48;

	  }
	  cout<<"Queue"<<endl;
	    for(n=frame-1;n>=0;n--)
	  cout<<a[n]<<" ";
	  cout<<endl;
	
	}
	    cout<<"No of Hits="<<len-miss;
	    cout<<"No of fault="<<miss;
}
