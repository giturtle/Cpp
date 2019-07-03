


class Solution {
public:
    /**
     *  奇数位上都是奇数或者偶数位上都是偶数
     *  输入：数组arr，长度大于2
     *  len：arr的长度
     *  将arr调整成奇数位上都是奇数或者偶数位上都是偶数
     */
    void oddInOddEvenInEven(vector<int>& arr, int len) {
        int i =  0;
        int j = 1;
        int temp;
        int end = len-1;
        while(end >= i && end >= j){
            if(arr[end] % 2 == 0){
                temp = arr[i];
                arr[i] = arr[end];
                arr[end] = temp;
                i += 2;
            }else{
                temp = arr[j];
                arr[j] = arr[end];
                arr[end] = temp;
                j += 2;
            }
        }
    }
};
