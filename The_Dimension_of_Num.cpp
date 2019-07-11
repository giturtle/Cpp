

本题相当于实现一个库函数中的`pow`函数：

# 一般解法
```javascript
//一般解法：无法完成底数为 0 ，或 负数 的情况
double Power1(double d,int n){
	double ret = 1;
	for (int i = 1; i <= n; ++i) {
		ret *= d;
	}
	return ret;
}
```
# 优化解法
```javascript
//优化解法，但效率不高
double PowerFunc(double d, unsigned int n) {
	double ret = 1.0;
	for (int i = 1; i <= n; ++i)
		ret *= d;
	return ret;
}

bool flag = false;

double Power2(double d, int n) {
	flag = false;
	if ((d == 0.0) && (n < 0)) {
		flag = true;
		return 0.0;
	}
	unsigned int absN = (unsigned int)n;
	if (n < 0)
		absN = (unsigned)(-n);

	double ret = PowerFunc(n, absN);
	if (n < 0)
		ret = 1.0 / ret;

	return ret;
}
```
# 高效解法
```javascript
double PowerFunc(double d,unsigned int n){
	if (n == 0)
		return 1;
	if (n == 1)
		return d;

	//公式:a ^ n = {
	//  n为偶数：a^(n/2) * a^(n/2)
	//  n为奇数：a^( (n-1) / 2) * a^( (n-1) / 2) * a	
	// }
	double ret = PowerFunc(d, n >> 1);	//（奇数-1）/2与不-1除二结果相同

	ret *= ret;

	if (n & 0x1)
		ret *= d;
	return ret;
}
```
