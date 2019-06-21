



//手套
class Gloves {
public:
    int findMinimum(int n, vector<int> left, vector<int> right) {
        int sum = 0;
        int leftSum = 0,rightSum = 0;
        int leftMin = 30,rightMin = 30;
        for(int i=0;i<n;i++) {
            if(left[i] * right[i] == 0)
                sum += (left[i] + right[i]);
            else{
                leftSum += left[i];
                rightSum += right[i];
                leftMin = min(leftMin,left[i]);
                rightMin = min(rightMin,right[i]);
            }
        }
        return sum + min(leftSum - leftMin + 1,rightSum - rightMin + 1) + 1;
    }
};
