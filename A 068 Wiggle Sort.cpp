#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

//gready algorithm and why it works!!
// 1 2 3  //3 greater than 2. then must be greater than 1. safe
// 1 3 2 

// 2 4 3 1 //swap to previous.. safe. if smaller than 3. then smaller than 4 of coures. 
// 2 4 1 3. 
void Sort(vector<int>& data){
	int n = data.size();
	for (int i = 1; i < n; ++i)
	{
		if ((i & 1) &&(data[i]<data[i-1]))
		{
			swap(data[i], data[i - 1]);
		}
		else if (!(i & 1) && (data[i]>data[i-1]))
		{
			swap(data[i], data[i - 1]);
		}
	}
}


int main()
{
	vector<int> data = {1,2,3,4,5,6,7,8,9};
	Sort(data);
	for (auto digit : data) cout << digit << " ";
	cout << endl;
} 
 
