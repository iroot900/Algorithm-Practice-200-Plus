#include <iostream>
#include <random>
#include <time.h>
using namespace std;

//not exactly, but just assume it's uniform
int rand7()
{
	return rand()%7+1;
}

int rand10()
{
	//main logic:
	//(1 2 3 4 5 6 7 -1 )* 7 + rand7();
	// 0: 1 2 3 4 5 6 7
	// 7: 8 9 .... 
	// 14: 
	int a=-1;
	do { a=(rand7()-1)*7+rand7();}
	 while(a>40);
	 return a%10+1; 
}

int main()
{
	srand(time(0));
	for(int i=0;i<20;++i)
		cout<<rand7()<<" ";
	cout<<endl;
	
	for(int i=0;i<20;++i)
		cout<<rand10()<<" ";
	cout<<endl;
}
