88 合并两个有序数组
非递减顺序：从小到大排列
输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
输出：[1,2,2,3,5,6]
解释：需要合并 [1,2,3] 和 [2,5,6] 。
合并结果是 [1,2,2,3,5,6] 
我的：先nums2中插入到nums1中0的位置 然后使用选择排序
class Solution { //排序
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=m;i<m+n;i++){
            nums1[i]=nums2[i-m];
        }
        int i,j;
        for(i=1; i<n+m; i++) {    //sort(nums1.begin(), nums1.end());
            if(nums1[i]<nums1[i-1]) {  
                int temp=nums1[i];  
                for(j=i-1; j>=0 && nums1[j]>temp; j--) {   
                   nums1[j+1]=nums1[j];
                }
                nums1[j+1]=temp;
            }
        }
    }
};

双指针
利用两个数组已经有序，创建一个新的数组，每次取两个数组中的最小放进去
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = 0, p2 = 0;
        int sorted[m + n];
        int cur;
        while (p1 < m || p2 < n) {
            if (p1 == m) {
                cur = nums2[p2++];
            } else if (p2 == n) {
                cur = nums1[p1++];
            } else if (nums1[p1] < nums2[p2]) {
                cur = nums1[p1++];
            } else {
                cur = nums2[p2++];
            }
            sorted[p1 + p2 - 1] = cur;
        }
        for (int i = 0; i != m + n; ++i) {
            nums1[i] = sorted[i];
        }
    }
};

逆向双指针 0ms
避免使用临时变量创建一个新的数组，不用担心覆盖nums1的问题
//我的
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l=m-1;
        int j=n-1;
        int i=m+n-1;
        while(j>=0){
            if(l>=0&&nums1[l]>nums2[j]){
                nums1[i]=nums1[l];
                l--;
            }else{
                nums1[i]=nums2[j];
                j--;
            }
            i--;
        }
    }
};   

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1, p2 = n - 1;
        int tail = m + n - 1;
        int cur;
        while (p1 >= 0 || p2 >= 0) {
            if (p1 == -1) {
                cur = nums2[p2--];
            } else if (p2 == -1) {
                cur = nums1[p1--];
            } else if (nums1[p1] > nums2[p2]) {
                cur = nums1[p1--];
            } else {
                cur = nums2[p2--];
            }
            nums1[tail--] = cur;
        }
    }
};

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left = m - 1, right = n - 1, cur = m + n - 1;
        while (left >= 0 && right >= 0) 
            nums1[cur--] = nums1[left] > nums2[right] ? nums1[left--] : nums2[right--]; //>优先级大于=
        // nums1剩下的已经排序，可以跳过
        while (right >= 0) 
            nums1[cur--] = nums2[right--];        
    }
};