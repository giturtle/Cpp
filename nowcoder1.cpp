//链接：https://www.nowcoder.com/questionTerminal/6736cc3ffd1444a4a0057dee89be789b?orderByHotValue=1&page=1&onlyReference=false

//牛牛举办了一次编程比赛,参加比赛的有3*n个选手,每个选手都有一个水平值a_i.现在要将这些选手进行组队,一共组成n个队伍,即每个队伍3人.牛牛发现队伍的水平值等于该队伍队员中第二高水平值。
//例如:
//一个队伍三个队员的水平值分别是3,3,3.那么队伍的水平值是3
//一个队伍三个队员的水平值分别是3,2,3.那么队伍的水平值是3
//一个队伍三个队员的水平值分别是1,5,2.那么队伍的水平值是2
//为了让比赛更有看点,牛牛想安排队伍使所有队伍的水平值总和最大。
//如样例所示:
//如果牛牛把6个队员划分到两个队伍
//如果方案为:
//team1:{1,2,5}, team2:{5,5,8}, 这时候水平值总和为7.
//而如果方案为:
//team1:{2,5,8}, team2:{1,5,5}, 这时候水平值总和为10.
//没有比总和为10更大的方案,所以输出10.

//输入描述:
//输入的第一行为一个正整数n(1 ≤ n ≤ 10^5)
//第二行包括3*n个整数a_i(1 ≤ a_i ≤ 10^9),表示每个参赛选手的水平值.

//输出描述:
//输出一个整数表示所有队伍的水平值总和最大值.

//示例1
//输入
//2
//5 2 8 5 1 5
//输出
//10

/////////////////////////////////////////////////////////////////////////////////////////////////

【题目解析】：
队伍的水平值等于该队伍队员中第二高水平值，为了所有队伍的水平值总和最大的解法，也就是说每个队伍
的第二个值是尽可能大的值。所以实际值把最大值放到最右边，最小是放到最左边。
【解题思路】：
本题的主要思路是贪心算法，贪心算法其实很简单，就是每次选值时都选当前能看到的局部最优解，所
以这里的贪心就是保证每组的第二个值取到能选择的最大值就可以，我们每次尽量取最大，但是最大的
数不可能是中位数，所以退而求其次，取 每组中第二大的
排序，然后取下标为3n - 2，3n - 4 ，3n - 4... n+2，n位置的元素累加即可，相当下标为[0,n-1]的n个数
做每组的最左边的数，剩下的2个数据两个为一组，大的值做最右边的数，次大的做中间值，这里就是
把这个次大的值加起来。
例如 现在排序后 有 1 2 5 5 8 9 ，那么取 8 和 5相加等于 13


/////////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
  int n;
  while (cin >> n){
    long long sum = 0;
    vector<int> a;
    a.resize(3*n);
    for (int i = 0; i < (3 * n); i++){
      cin >> a[i];
    }
    /*
    排序，然后取下标为3n - 2，3n - 4 ，3n - 4... n+2，n位置的元素累加即可，
    相当下标为[0,n-1]的n个数做每组的最左边的数，剩下的2个数据两个为一组，
    大的值做最右边的数，次大的做中间值，这里就是把这个次大的值加起来
    */
    std::sort(a.begin(), a.end());
    for (int i = n; i <= 3 * n - 2; i += 2){
      sum += a[i];
    }
    cout << sum << endl;
  }
}


