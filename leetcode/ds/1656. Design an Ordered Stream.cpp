class OrderedStream {
public:
    vector <string> v;
    int ptr;

    OrderedStream(int n) {
        v.resize(n + 1);
        ptr = 1;
    }
    
    vector<string> insert(int idKey, string value) {
        v[idKey] = value;
        vector <string> chunks;
        while(ptr < v.size() && v[ptr] != "") {
            chunks.push_back(v[ptr++]);
        }
        return chunks;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */