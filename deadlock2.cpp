#include<bits/stdc++.h>
using namespace std;
class deadlock
{
	public:
		int max[100][100];
		int alloc[100][100];
		int need[100][100];
		int avail[100];
		int n;
		int r;
		void input();
		void show();
		void cal();
		
};
void deadlock::input()
{
	int i,j;
	cout<<"\nEnter the number of process=";
	cin>>n;
	cout<<"\nEnter the number of resources instances=";
	cin>>r;
	cout<<"\nEnter the Max Matrix\n";
	for(i=0;i<n;i++)
	{
		for(j=0;j<r;j++)
		{
			cout<<"Enter Max for process "<<i<<" at instance "<<j<<"=";
				cin>>max[i][j];
		}
		
	}
	cout<<"\nEnter the allocation matrix\n";
	for(i=0;i<n;i++)
	{
		for(j=0;j<r;j++)
		{
			cout<<"Enter allocation for process "<<i<<" at instance "<<j<<"=";
				cin>>alloc[i][j];
				
		}
		
	}
	cout<<"\nEnter the available resources\n";
	for(j=0;j<r;j++)
	{
		cout<<"Enter available resources at instance "<<j;
		cin>>avail[j];
	}
}
void deadlock::show()
{
	int i,j;
	cout<<"\nProcess\t\tAllocation\t\tMax\t\tAvailable\t";
	for(i=0;i<n;i++)
	{
		cout<<"\n"<<i+1<<"\t";
		for(j=0;j<r;j++)
		{
			cout<<alloc[i][j]<<"\t";
		}
		for(j=0;j<r;j++)
		{
			cout<<max[i][j]<<"\t";
		}
		if(i==0)
		{
			for(j=0;j<r;j++)
			{
				cout<<avail[j]<<"\t";
			}
		}
	}
}
void deadlock::cal()
{
	int finish[100],temp,need[100][100],flag=0,k,c1=0;
	int safe[100];
	int i,j;
	for(i=0;i<n;i++)
	{
		finish[i]=0;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<r;j++)
		{
			need[i][j]=max[i][j]-alloc[i][j];
		}
	}
	cout<<"\n";
	while(flag<n)
	{
		
		for(i=0;i<n;i++)
		{
			int c=0;
			for(j=0;j<r;j++)
			{
				if((finish[i]==0)&&(need[i][j]<=avail[j]))
				{
					c++;
					if(c==r)
					{
						flag=flag+1;
						for(k=0;k<r;k++)
						{
							avail[k]+=alloc[i][k];
							
							
						}
						finish[i]=1;
						cout<<"P"<<i<<"->";
//						if(finish[i]==1)
//						{
//							i=n;
//						}
					}
				}
			}
			
		}
		
		
	}
			for(i=0;i<n;i++)
			{
				if(finish[i]==1)
				{
					c1++;
				}
			}
			if(c1==n)
			{
				cout<<"\nThe system is in safe state";
			}
			else
			{
				cout<<"\nProcess are in deadlock";
				cout<<"\nSystem is in unsafe state";
			}
			
}
int main()
{
	int i,j;
	deadlock ob;
	cout<<"\t\tBankers algorithm\n";
	ob.input();
	ob.show();
	ob.cal();
	return 0;
}




/*
OUTPUT:



                Bankers algorithm

Enter the number of process=5

Enter the number of resources instances=4

Enter the Max Matrix
Enter Max for process 0 at instance 0=6
Enter Max for process 0 at instance 1=0
Enter Max for process 0 at instance 2=1
Enter Max for process 0 at instance 3=2
Enter Max for process 1 at instance 0=2
Enter Max for process 1 at instance 1=7
Enter Max for process 1 at instance 2=5
Enter Max for process 1 at instance 3=0
Enter Max for process 2 at instance 0=2
Enter Max for process 2 at instance 1=3
Enter Max for process 2 at instance 2=5
Enter Max for process 2 at instance 3=6
Enter Max for process 3 at instance 0=1
Enter Max for process 3 at instance 1=6
Enter Max for process 3 at instance 2=5
Enter Max for process 3 at instance 3=3
Enter Max for process 4 at instance 0=1
Enter Max for process 4 at instance 1=6
Enter Max for process 4 at instance 2=5
Enter Max for process 4 at instance 3=6

Enter the allocation matrix
Enter allocation for process 0 at instance 0=4
Enter allocation for process 0 at instance 1=0
Enter allocation for process 0 at instance 2=0
Enter allocation for process 0 at instance 3=1
Enter allocation for process 1 at instance 0=1
Enter allocation for process 1 at instance 1=1
Enter allocation for process 1 at instance 2=0
Enter allocation for process 1 at instance 3=0
Enter allocation for process 2 at instance 0=1
Enter allocation for process 2 at instance 1=2
Enter allocation for process 2 at instance 2=5
Enter allocation for process 2 at instance 3=4
Enter allocation for process 3 at instance 0=0
Enter allocation for process 3 at instance 1=6
Enter allocation for process 3 at instance 2=3
Enter allocation for process 3 at instance 3=3
Enter allocation for process 4 at instance 0=0
Enter allocation for process 4 at instance 1=2
Enter allocation for process 4 at instance 2=1
Enter allocation for process 4 at instance 3=2

Enter the available resources
Enter available resources at instance 0=3
Enter available resources at instance 1=2
Enter available resources at instance 2=1
Enter available resources at instance 3=1

Process        		Allocation             				Max             			Available
1       	4       0       0       1       6       0       1       2       3       2       1       1
2       	1       1       0       0       2       7       5       0
3       	1       2       5       4       2       3       5       6
4       	0       6       3       3       1       6       5       3
5       	0       2       1       2       1       6       5       6
P0->P2->P3->P4->P1->
The system is in safe state
--------------------------------*/
