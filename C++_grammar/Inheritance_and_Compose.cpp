



// Car和BMW Car和Benz构成is-a的关系
 class Car{
 protected:
 string _colour = "白色"; // 颜色
 string _num = "陕ABIT00"; // 车牌号
 };

 class BMW : public Car{
 public:
 void Drive() {cout << "好开-操控" << endl;}
 };

 class Benz : public Car{
 public:
 void Drive() {cout << "好坐-舒适" << endl;}
 };

 // Tire和Car构成has-a的关系

 class Tire{
 protected:
 string _brand = "Michelin"; // 品牌
 size_t _size = 17; // 尺寸

 };

 class Car{
 protected:
 string _colour = "白色"; // 颜色
 string _num = "陕ABIT00"; // 车牌号
 Tire _t; // 轮胎
 };





//A Test：

class Base1 {
public:
 int _b1;
};
class Base2 {
public:
 int _b2;
};
class Derive : public Base1, public Base2 {
public:
 int _d;
};
int main(){
 // A. p1 == p2 == p3
 // B. p1 < p2 < p3
 // C. p1 == p3 != p2  √
 // D. p1 != p2 != p3
 Derive d;
 Base1* p1 = &d;
 Base2* p2 = &d;
 Derive* p3 = &d;
 return 0;
}
