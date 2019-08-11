
// https://blog.csdn.net/qq_42351880/article/details/99225267
       一、密码长度:

       5 分: 小于等于4 个字符

       10 分: 5 到7 字符

       25 分: 大于等于8 个字符
       

       二、字母:

       0 分: 没有字母

       10 分: 全都是小（大）写字母

       20 分: 大小写混合字母


       三、数字:

       0 分: 没有数字

       10 分: 1 个数字

       20 分: 大于1 个数字


       四、符号:

       0 分: 没有符号

       10 分: 1 个符号

       25 分: 大于1 个符号


       五、奖励:

       2 分: 字母和数字

       3 分: 字母、数字和符号

       5 分: 大小写字母、数字和符号


       最后的评分标准:

       >= 90: 非常安全

       >= 80: 安全（Secure）

       >= 70: 非常强

       >= 60: 强（Strong）

       >= 50: 一般（Average）

       >= 25: 弱（Weak）

       >= 0:  非常弱

 

对应输出为：

  VERY_WEAK,

   WEAK,    

   AVERAGE,    

   STRONG,     

   VERY_STRONG,

   SECURE,     

   VERY_SECURE 


#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string str;
    while(getline(cin,str)){
        //长度
        int score = 0;
        if(str.size() <= 4)
            score += 5;
        else if(str.size() <= 7 && str.size() >= 5)
            score += 10;
        else 
            score += 25;
        
        //标记，可以使用bool值
        int islittle = 0,isBigger = 0;
        int hasNum = 0,count = 0;
        int hasSym = 0,countSym = 0;
        
        for(int i = 0;i < str.size() ;++i){
            //字母
            if(str[i] >= 'a' && str[i] <= 'z'){
                islittle = 1;
            }else if(str[i] >= 'A' && str[i] <= 'Z'){
                isBigger = 1;
            }
            
            //数字
            if(str[i] >= '0' && str[i] <= '9'){
                hasNum = 1;
                count++;
            }
            
            //符号
            if (!(str[i] >= 'a' && str[i] <= 'z')    \
                    && !(str[i] >= 'A' && str[i] <= 'Z')    \
                    && !(str[i] >= '0' && str[i] <= '9')
               ){
                hasSym = 1;
                countSym++;
            }
        }
        
        //字母汇总
        if(islittle && isBigger)
            score += 20;
        else if((!islittle && isBigger)||(islittle && !isBigger))
            score += 10;
        
        //数字汇总
        if(count == 1)
            score += 10;
        else if(count > 1)
            score += 20;
        
        //字符汇总
        if(countSym == 1)
            score += 10;
        else if(countSym > 1)
            score += 25;

        //奖励
        if(hasNum && (islittle || isBigger))
            score += 2;
        else if((islittle || isBigger) && hasNum && hasSym)
            score += 3;
        else if(hasSym && hasNum && islittle && isBigger)
            score += 5;
        
        //输出
        if(score >= 90)
            cout << "VERY_SECURE" << endl;
        else if(score >= 80)
            cout << "SECURE" << endl;
        else if(score >= 70)
            cout << "VERY_STRONG" << endl;
        else if(score >= 60)
            cout << "STRONG" << endl;
        else if(score >= 50)
            cout << "AVERAGE" << endl;
        else if(score >= 25)
            cout << "WEAK" << endl;
        else if(score >= 0)
            cout << "VERY_WEAK" << endl;
    }
    return 0;
}
