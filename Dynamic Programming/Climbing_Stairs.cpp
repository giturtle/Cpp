


状态：
	子状态：跳上1级，2级，3级，...，n级台阶的跳法数
		f(n)：还剩n个台阶的跳法数
	
状态递推：
	n级台阶，第一步有n种跳法：跳1级、跳2级、到跳n级
	跳1级，剩下n-1级，则剩下跳法是f(n-1)
	跳2级，剩下n-2级，则剩下跳法是f(n-2)
	f(n) = f(n-1)+f(n-2)+...+f(n-n)
	
	f(n) = f(n-1)+f(n-2)+...+f(0)
	f(n-1) = f(n-2)+...+f(0)
	错位相减得：
	f(n) = 2*f(n-1)

初始值：
	f(1) = 1
	f(2) = 2*f(1) = 2
	f(3) = 2*f(2) = 4
	f(4) = 2*f(3) = 8
	所以它是一个等比数列
	f(n) = 2^(n-1)

返回结果：	
	f(n)



int jumpFloorII(int number) {
    if(number <= 0)
        return 0;
        
    int total = 1;
    for(int i = 1;i < number;i++)
        total *= 2;
        
    return total;
}



int jumpFloorII(int number) {
    if(number <= 0)
        return 0;
        
    return 1 << (number-1);
}
