
题目ID：36939-合法括号序列判断
链接：https://www.nowcoder.com/practice/d8acfa0619814b2d98f12c071aef20d4?tpId=8&&tqId=11039&rp=1&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking




class Parenthesis {
public:
  bool chkParenthesis(string A, int n) {
  stack<char> sc;
  for (auto ele : A) {
    switch (ele) {
    case '(':
      sc.push(ele);
      break;
    case ')':{
        if (sc.empty() || sc.top() != '(')
           return false;
        else
          sc.pop();
      }
      break;
      default:
        return false;
      }
    }
  return true;
  }
};
