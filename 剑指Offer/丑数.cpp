class Solution {
public:
    int GetUglyNumber_Solution(int index) {
    	// 利用三个指针从小到大生成丑数
        vector<int> res{1};
        int p2 = 0, p3 = 0, p5 = 0;
        
        for (int i = 1; i < index; ++i) {
            int minn = min(res[p2] * 2, min(res[p3] * 3, res[p5] * 5));
            res.push_back(minn);
            if (minn == res[p2] * 2) ++p2;
            if (minn == res[p3] * 3) ++p3;
            if (minn == res[p5] * 5) ++p5;
        }
        
        return res[index - 1];
    }
};
