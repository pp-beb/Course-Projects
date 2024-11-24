#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
struct teams{
	string name;
	int points;
	int gd;
};
void entry(int n,teams t[])
	{
	int i;
	cout<<"Please enter all team names :"<<endl;
	for(i=0;i<n;i++)
		{
		cout<<"Team "<<i+1<<" : ";
		cin>>t[i].name;	
		}
	}
	
	void entryPoints(int n, teams t[])
	{
	int i;
	cout<<"Please enter starting points for teams :"<<endl;
	for(i=0;i<n;i++)
		{
		cout<<t[i].name<<":";
		cin>>t[i].points;
		}
	cout<<"Please enter starting goal difference for teams :"<<endl;
	for(i=0;i<n;i++)
		{
		cout<<t[i].name<<":";
		cin>>t[i].gd;
		}
	}
	void output(teams t[],int n)
	{
		int i;
		cout<<"Teams\t\t\tPoints\t\t\tGD"<<endl;
		for(i=0;i<n;i++)
		{
			cout<<t[i].name<<"\t\t\t"<<t[i].points<<"\t\t\t"<<t[i].gd<<endl;
		}
		}
	void sortTeams(teams t[],int n)
	{
		int i,j;
		teams temp;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(t[j].points < t[i].points)
				{
					temp=t[i];
					t[i]=t[j];
					t[j]=temp;
				}
				else if(t[j].points == t[i].points)
				{
					if(t[j].gd < t[i].gd)
				{
					temp=t[i];
					t[i]=t[j];
					t[j]=temp;
				}
				}
			}
		}
	}
 int menu(teams t[], int n)
 {
 	int menuN;
 	cout<<"\t  MENU"<<endl<<"Update(1)\tAdd team(2)\nView table(3)\tExit(4)"<<endl<<endl;
 	cin>>menuN;
 	switch (menuN){
 		case 1: 
 		cout<<"Currently working on this feature."<<endl<<endl;
 		break;
 		
 		case 2:
 		cout<<"Currently working on this feature."<<endl<<endl;
 		break;
 		
 		case 3:
 		output(t,n);
 		break;
 		
 		case 4:
 			cout<<"Thankyou!";
 		exit(1);
 		break;
	 }
 	
	 }	
int main(){
int number;
cout<<"How many teams do you want to enter? "<<endl;
cin>>number;
teams Teams[number];
entry(number,Teams);
entryPoints(number,Teams);
output(Teams,number);
sortTeams(Teams,number);
cout<<"The updated table is:"<<endl;
output(Teams,number);
while(1)
{
menu(Teams,number);
}
}
	

