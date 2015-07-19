// a random container which support add, delete, return random with O(1)
#include <iostream>
#include <time.h>
#include <random>
#include <vector>
#include <unordered_map>
using namespace std;

template<typename T>
class randomContainer
{
	public:
		void add(const T& dat)
		{
			index[dat]=size;
			if(size==data.size()) { data.push_back(dat);++size; }
			else { data[size++]=dat; }
		}

		void erase (const T& dat) //key of this container. swap end. 
		{
			int p=index[dat]; int end=size-1;
			swap(data[p],data[end]);
			index[data[p]]=p;
			index.erase(data[end]);
			--size;
		}

		T random()
		{
			return data[rand()%size];
		}

	private:
	int size=0;
	vector<T> data;
	unordered_map<T,int> index;
};

int main()
{
	srand(time(0));
	randomContainer<int> rdContainer;
	
	rdContainer.add(1);
	for(int i=0;i<10;++i)
	cout<<rdContainer.random()<<" ";
	cout<<endl;

	rdContainer.add(2);
	for(int i=0;i<10;++i)
	cout<<rdContainer.random()<<" ";
	cout<<endl;
	
	rdContainer.add(3);
	for(int i=0;i<10;++i)
	cout<<rdContainer.random()<<" ";
	cout<<endl;
	
	rdContainer.erase(1);
	for(int i=0;i<10;++i)
	cout<<rdContainer.random()<<" ";
	cout<<endl;
	
	return 0;
}
