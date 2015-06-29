class TwoSum {
public:
	void add(int number) {
	    data[number]++;
	}

	bool find(int value) {
	    for(auto dat:data)
	    {
	        auto num=dat.first;
	        int target=value-num;
	        auto it=data.find(target);
	        if(it!=data.end())
	        {
	            if(num==target&&it->second>1) return true;
	            if(num!=target) return true;
	        }
	    }
	    return false;
	}
private:
    unordered_map<int,int> data;
};
