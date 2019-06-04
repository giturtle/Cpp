

//链接：https://www.nowcoder.com/practice/30c1674ad5694b3f8f0bc2de6f005490?tpId=8&&tqId=11019&rp=1&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking



class BinInsert {
public:
  int binInsert(int n, int m, int j, int i) {
    m <<= j;
    return n | m;
  }
};
