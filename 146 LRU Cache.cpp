class LRUCache{
public:
    LRUCache(int capacity):capacity_(capacity) {
         data.clear();
         iterators.clear();
    }
    
    int get(int key) { //update the get one to the most recently used. 
        auto it=iterators.find(key);
        if(it==iterators.end()) return -1;
        int result=it->second->second;
        // update.   1 2 [3] 4 5 6 
        data.splice(begin(data),data,it->second);
        it->second=begin(data);
        return result;
    }
    
    void set(int key, int value) { // not there, insert.   there then update. 
         // not find. 
         auto it=iterators.find(key);
         if(it==iterators.end())
         {
             if(iterators.size()<capacity_)
             {
                 data.insert(begin(data),make_pair(key,value));
                 iterators[key]=begin(data);
             }else
             {     
                 //1 2 3 4  [9]-- delete one
                 iterators.erase(data.back().first);
                 data.pop_back();
                 data.insert(begin(data),make_pair(key,value));
                 iterators[key]=begin(data);
             }
         }
         else // find, update. -->value; key not change. 
         {
            it->second->second=value;
            // update.   1 2 [3] 4 5 6 
            data.splice(begin(data),data,it->second);
            iterators[key]=begin(data);
         }
    }
    private:
    int capacity_;// look up something, must be a hashTable there to support lookup.            
                  //another things, which one to delete. a list's front, c
    list<pair<int,int>> data;//it's double linked, so it's easy to do things. need value--(and key)->go back to hashmap to delete.
    unordered_map<int, list<pair<int,int>>::iterator>  iterators;   //map should be easy to locate list node. so list pointer(iterator here)
};
