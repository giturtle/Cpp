

const int a;
int const b;
//二者等效


1. const int *c;	//const修饰的是指针所指向的内存空间不能被修改
	//c->xx = 10;//正在通过常量对象访问xx，因此无法对其进行修改
2. int* const d;	//内容d可以被修改，但是指针变量的指向是不可以修改的
	//d->xx = 10;//无误
	//d = NULL;	//错误
3. const int * const e; 	//指针变量指向与内容都不可修改，但是可以printf读



//C中的const是冒牌货，【const变量是只读变量，有自己的存储空间】
int main(){
  const int a = 10;
  int *p = NULL;
  p = &a;
  *p = 20;	//间接修改
  printf("%d\n",a);	//打印结果：20。通过指针对其进行了修改，所以说C中const修饰的变量并非一个真正意义上的常量
}



//C++中的const： 【可能分配、也可能不分配内存空间】【符号表】机制：key|value -> a|10二维表
//分配场景：
//1. 当const常量为全局，并且需要在其他文件中使用时（const int b = 10;）
//2. 当使用&操作符取const常量的地址

//1. 编译器扫描到const关键字，将初始化的变量名与值建立符号表映射机制。
//2. 更改指针指向的内容或者取地址时，从给其创建内存，但只是更改了分配内存p指针所指空间的值
//3. 输出此const值时【用符号表进行覆盖】，所以C++才真正实现了const修饰的变量为一个常量的功能。
