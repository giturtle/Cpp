




#include <iostream>
#include <time.h>
#define MAX  10000000

void swap(int a, int b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

int partition(int A[], int low, int high)
{
	int mid = (low + high) >> 1;
	if (A[low] > A[mid])   swap(A[low], A[mid]);
	if (A[low] > A[high])  swap(A[low], A[high]);
	if (A[mid] > A[high])  swap(A[mid], A[high]);
	int pivot = A[mid]; //三者取中，最坏时间复杂度优化
	//int pivot = A[low];
	while (low < high)
	{
		while (low < high && A[high] >= pivot)	high--;	
			A[low] = A[high];
		   
		while (low < high && A[low] <= pivot)  low++;
			 A[high] = A[low];
		 		
	}
	A[low] = pivot;

	return low;
}


void quicksort(int A[], int low, int high)
{
	while (low < high)
	{
	
        int part = partition(A, low, high);
		if (part < (high + low)>>1) //两者取短 + 尾递归优化，最坏空间复杂度优化至logn，避免了栈溢出
		{
			quicksort(A, low, part - 1);//短的递归
			low = part + 1;//长的优化
		//	quicksort(A, part + 1, high);
		}
		else
		{		
			quicksort(A, part + 1, high);
			high = part - 1;		
		//	quicksort(A, low, part - 1);
		}

	}
}



int main()
{

	srand((unsigned int)time(NULL));
	int *A = new int[MAX];
	for (int loop = 0; loop < MAX; loop++)
	{
		//A[loop] = (rand() % MAX) + 1;   //随机数
	    A[loop] = MAX - loop;         //逆序数
		//A[loop] = loop;               //顺序数
	}

	quicksort(A, 0, MAX - 1);

	int i = 0;
	while ( i < MAX)
	{
		std::cout << "-" << A[i];
		i += 10000;
	}
}




