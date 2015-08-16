class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        for(auto row:vec2d)
        {
            for(auto num:row) data.push(num); 
        }
    }

    int next() {
        int num=data.front(); data.pop();
        return num;
    }

    bool hasNext() {
        return !data.empty();
    }
    private: 
    queue<int> data; 
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
