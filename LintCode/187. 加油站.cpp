class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        if(gas.empty()||cost.empty())
            return 0;
        int n=cost.size();
        int begin=0;        //假设从第零个加油站开始走
        int cur=0;          //当前储油量
        int Gas=0,Cost=0;  //Gas记录汽油总量，Cost记录着走完环路的消耗总量
        for(int i=0;i<n;++i){
            cur+=gas[i];   //加满油
            cur-=cost[i];  //走到下一站的花费
            Gas +=gas[i];
            Cost+=cost[i];
            if(cur<0){     //从当前加油站走不到下一站
                begin=i+1; //替换出发点，其实就是一个一个试！！！从1到n
                cur=0;     //重新计算
            }
        }
        return Gas>=Cost?begin:-1;   //如果花费总量大于汽油总量肯定走不完了，否则就返回起始点
    }
};
