#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	fstream file;
	char mas[20];
	int N=3,i=0,j=0,K,x=0,y=0,flag=0;
	int cash=0,cash2=0,raz=1;
	struct AAA
	{
		int u;
		int d;
		int l;
		int r;
	};
	AAA*step = new AAA;
	/*step->d=0;
	step->l=0;
	step->r=0;
	step->u=0;*/
	file.open("1.txt",ios::in);
	int**map = new int*[N];
	for(int j=0;j<N;j++)
		map[j]=new int[N];
	i=0;j=0;
	while(!file.eof())
	{
		file>>mas;
		map[i][j]=atoi(mas);
		cout<<map[i][j]<<" ";
		if(i == 2)
		{
		   i=0;
		   j++;
		   cout<<"\n";
		}
		else
			i++;
	}
	//cout<<"***"<<map[0][0]+map[1][1]<<"\n";
	printf("Enter the number of steps\n");
	cin>>K;
	int *var = new int[K];
	for(int i=0;i<K;i++)
	{
		var[i]=1;
		raz*=4;
	}
	//printf("***%d\n",raz);
	x=0;
	y=0;
	for (int j=0;j<raz;j++)
	{
		x=0;
		y=0;
		flag=0;
		cash=map[0][0];
	 for (int z=0;z<K;z++)
	 {
		//flag=0;
		/*if(!x && !y)
		{
		cash+=map[x][y];
		}*/
		
		if (!x && !y )
		{
			//cout<<"&&";
			step->u=0;
			step->l=0;
			step->d=1;
			step->r=1;
		}
		else
		{
		 if (x==2 && y==2)
			{
				step->u=1;
				step->l=1;
				step->d=0;
				step->r=0;
			}
			
		 if (!x && y==1)
			{
				step->u=1;//0
				step->l=0;//1
				step->d=1;
				step->r=1;
			}	
		 if (x==1 && !y)
			{
				step->u=0;//1
				step->l=1;//0
				step->d=1;
				step->r=1;
			}
		 if (x==2 && !y)
			{
				step->u=0;//1
				step->l=1;//0
				step->d=1;//0
				step->r=0;//1
			}
		 if (!x && y==2)
			{
				step->u=1;//0
				step->l=0;//1
				step->d=0;//1
				step->r=1;//0
			}
		 if (x==2 && y==1)
			{
				step->u=1;
				step->l=1;
				step->d=1;//0
				step->r=0;//1
			}
		 if (x==1 && y==2)
			{
				step->u=1;
				step->l=1;
				step->d=0;//1
				step->r=1;//0
			}
		 if (x==1 && y==1)
			{
				step->u=1;
				step->l=1;
				step->d=1;
				step->r=1;
			}
		}
		if(!x && !y)
			{
				cout<<cash<<"**"<<map[x][y]<<"*"<<x<<"*"<<y<<"__start_"<<"_step:u"<<step->u<<";r"<<step->r<<";d"<<step->d<<";l"<<step->l<<"\n";
			}
		switch (var[z])
		{
		case 1: if(step->u == 1)
			   {
				   y--;
				   break;
			   }
			   else 
			   {
				   flag=1;
				   cash=0;
				   cout<<"%%1\n";
				   break;
			   };
		case 2: if(step->r == 1)
			   {
				   x++;
				   break;
			   }
			   else 
			   {
				   flag=1;
				   cash=0;
			       cout<<"%%2\n";
				   break;
			   };
		case 3: if(step->d == 1)
			   {
				   y++;
				   break;
			   }
			   else
			   {
				   flag=1;
				   cash=0;
				   cout<<"%%3\n";
				   break;
			   };
		case 4: if(step->l == 1)
			   {
				   x--;
				   break;
			   }
			   else 
			   {
				   flag=1;
				   cash=0;
				   cout<<"%%4\n";
				   break;
				};
		};
		if (!flag)
		{
			cash+=map[x][y];
			cout<<cash<<"**"<<map[x][y]<<"*"<<x<<"*"<<y<<"var["<<z<<"]="<<var[z]<<"_step:u"<<step->u<<";r"<<step->r<<";d"<<step->d<<";l"<<step->l<<"\n";
		}
		/*if(flag==1)
		{
			var[0]++;
			for(int l=0;l<K;l++)
				{
					if(var[l] > 4)
						{
							 var[l]=1;
							 var[l+1]++;
		      			}
				}	
			break;
		}*/
		if(flag)
		{
			break;
		}
		cout<<"\n";
	  }
	 var[0]++;
	 for(int l=0;l<K;l++)
	 {
		 if(var[l] > 4)
		 {
			 var[l]=1;
			 var[l+1]++;
		 }
	 }
	 if(cash>cash2)
	  {
		  cash2=cash;
	  }
	 cash=0;
	}
	printf("Cash = %d\n",cash2);
	return 0;
}