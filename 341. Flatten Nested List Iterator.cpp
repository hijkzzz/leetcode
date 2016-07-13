class NestedIterator {
    public:
        NestedIterator(vector<NestedInteger> &nestedList) {
            for(int i = nestedList.size() - 1; i >= 0; i--){
                s.push(&nestedList[i]);
            }
        }

        int next() {
            NestedInteger *ni = s.top();
            s.pop();
            return ni->getInteger();
        }

        bool hasNext() {
            while(!s.empty()) {
                NestedInteger *ni = s.top();
                if(ni->isInteger())
                    return true;
                else {
                    //展开 List
                    vector<NestedInteger> &v = ni->getList();
                    s.pop();
                    for(int i = v.size() - 1; i >= 0; i--){
                        s.push(&v[i]);
                    }
                }
            }
            return false;
        }

    private:
        stack<NestedInteger*> s;
};
