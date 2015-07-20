//valid rolling string
//my original idea is to generate all the strings belong to k(a), and the compare it,add to table
//to generate all strings. DFS(pow(a,k)); 

//well it's just a bool check, so just no need to do that. just get all unique strings
#include <iostream>
#include <unordered_set>
#include <math.h>
using namespace std;

// assme a is 1 to 10. if greater than 10. then. not single digit.!!
//if substring is not considered efficient then rolling hash could do. 
bool valid_rolling(const string& str, int a,int k)
{
	int n=str.size();
	int count=pow(a,k);
	if(n+1-k<count) return false;

	unordered_set<string> nums; 
	for(int i=0;i<=n-k;++i)
	{
		string num=str.substr(i,k);
		nums.insert(num);
	}

	// following is not necessary
	   long num=0;
	   long base=1;
	   for(int i=0;i<k;++i)
	   {
	   		num=num*a+str[i]-'0';
			base=base*a;
	   }

	   unordered_set<int> nums2;
	   nums2.insert(num);
	   for(int i=k;i<n;++i)
	   {
		   num=(num-base*(str[i-k]-'a'))*a+(str[i]-'a');
	   	   nums2.insert(num);
	   }

	return count==(int)nums.size()&&count==(int) nums2.size();
}

int main()
{
	string str="00110";
	cout<<valid_rolling(str,2,2)<<endl;
}
