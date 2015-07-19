// given a text (a list a words), design a class which support return min distance between any two given word. 

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

//read data (n)
//one time call: then easy (n) again

//multiple times: use a map to store the index for word. 
//distance then get the min distance of two sorted vector (K1)+(K2) 
// if K1 and K2 are far away from each other. go over small one then BS other


class DistanceFinder
{
	public:
		DistanceFinder(const vector<string>& text)
		{
			for(int i=0;i<text.size();++i)
			{
				positions[text[i]].push_back(i);
			}
			for(auto pir:positions)
			{
				sort(begin(pir.second),end(pir.second));
			}
		}

		int Distance(const string& word1, const string& word2) 
		{
			//assume input is valid. 
			auto vec1=positions[word1];
			auto vec2=positions[word2];
			int left=0, right=0;
			int distance=INT_MAX;
			while(left<vec1.size()&&right<vec2.size())
			{
				distance=min(distance,abs(vec1[left]-vec2[right]));
				if(distance==1) return 1;
				if(vec1[left]>vec2[right]) ++right;
				else ++left;
			}

			return distance;
		}

	private:
		unordered_map<string, vector<int>> positions;
};

int main()
{
	DistanceFinder df( {"the","quick","brown","fox","quick"} );
	cout<<df.Distance("fox","the")<<endl;
	cout<<df.Distance("quick","fox")<<endl;
}
