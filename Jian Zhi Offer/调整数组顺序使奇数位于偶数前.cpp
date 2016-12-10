class Solution {
    public:
        void reOrderArray(vector<int> &array) {
            if (array.size() < 2) return;

            for (int i = 0; i < array.size();i++){
                for (int j = array.size() - 1; j > i;j--){
                    //前偶后奇交换
                    if (array[j] % 2 == 1 && array[j - 1]%2 == 0){
                        swap(array[j], array[j-1]);
                    }
                }
            }
        }
};
