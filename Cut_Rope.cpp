
//给你一根长度为n的绳子，请把绳子剪成m端（m、n都是整数，都>1）
//每段绳子的长度记为k[0],k[1]..k[m],请问k[0] * k[1] * k[m]可能的最大乘积是多少？
//例如，当绳子长度为8，剪成2,3,3，最大乘积为8



//【动态规划】（DP）问题

int maxProductAfterCutting_solution1(int length){
  if(length < 2)
    return 0;
  if(length == 2)
    return 1;
  if(length == 3)
    return 2;
  
  int *products = new int[length + 1];
  products[0] = 0;
  products[1] = 1;
  products[2] = 2;
  products[3] = 3;
  
  int max = 0;
  for(int i = 4;i <= length;++i){
    max = 0;
    for(int j = 1;j <= i / 2;++j){
      int product = products[j] * products[i - j];
      if(max < product)
        max = product;
        
      products[i] = max;
    }
  }
  max = products[length];
  delete[] products;
  
  return max;
}




//【贪婪算法】

int maxProductAfterCutting_solution2(int length){
  if(length < 2)
    return 0;
  if(length == 2)
    return 1;
  if(length == 3)
    return 2;
    
  //尽可能多的去剪去长度为3的绳子段
  int timesOf3 = length / 3;
  
  //当绳子剩下的长度为4的时候，不能再剪去长度为3的绳子段
  if(length - timesOf3 * 3 == 1)
    timeOf3 -= 1;
    
  int timesOf2 = (length - timeOf3 * 3)/2;
  
  return (int)(pow(3,timeOf3)) * (int)(pow(2,timeOf2));
}
