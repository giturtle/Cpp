



//一只青蛙一次可以跳上1级台阶，也可以跳上2级，和多级
//求青蛙跳上一个n级台阶的总共有多少跳法

class Solution {
public:
    int jumpFloorII(int target) {
        int result = 0;
        if(target == 0)
            result = 0;
        else if(target == 1)
            result = 1;
        else
            result = 2 * jumpFloorII(target - 1);
            // 2^(n-1)
        return result;
    }
};
