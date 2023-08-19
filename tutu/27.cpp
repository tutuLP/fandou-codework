### 27 移除元素
返回剩下的元素个数
~~~
输入：nums = [0,1,2,2,3,0,4,2], val = 2
输出：5, nums = [0,1,4,0,3]
~~~

0ms

~~~c++
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int>::iterator it=nums.begin();
        for(;it<nums.end();it++){
            if(*it==val){
                nums.erase(it);
                it--;
            }
        }
        return nums.size();
    }
};
~~~

或 使用双指针