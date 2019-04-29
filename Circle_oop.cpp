#include <iostream> 
using namespace std;

struct Circle{
  double m_s;
  double m_c;
};

class MyCircle{
  public:
    double m_s;
    double m_r;
  public:
    void setR(double r){
      m_r = r;
    }
    double getR(){
      return m_r;
    }
    double getS(){
      m_s = 3.14*m_r*m_r;
      return m_s;
    }
};

int main(){
  MyCircle c1;
  double r;
  cout <<"请输入c1圆的半径："<< endl;
  cin >> r;
  c1.setR(r);

  cout << "c1圆的面积为：" << c1.getS() << endl;
  return 0;
}
