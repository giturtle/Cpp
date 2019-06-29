

//数组中重复的数字
//数组中所有数字都在0~n-1之内，请找出任一重复的数字

/*
 *方法一：先排序，之后遍历即可。
 */
//时间复杂度O(N*logN)，空间复杂度O(1)


/*
 *方法二
 */
//时间复杂度O(N)，空间复杂度O(N)
bool num(int num[], int size, int *dup) {
	int hashtable[size] = { 0 };
	for (int i = 0; i < size; ++i) {
		hashtable[i]++;
	}
	for (int i = 0; i < size; ++i) {
		if (hashtable[i] == 2) {
			*dup = hashtable[i];
			return true;
		}
	}
	return false;
}

/*
 *方法三：
 */
//时间复杂度O(N),空间复杂度O(1)
bool Num(int num[], int size, int *dup) {
	if ((num == nullptr) || (size <= 0)) {
		return false;
	}
	for (int i = 0; i < size; ++i) {
		if ((num[i] < 0) || (num[i] > size - 1)) {
			return false;
		}
	}
	for (int i = 0; i < size; ++i) {
		while (num[i] != i) {
			if (num[i] == num[num[i]]) {
				*dup = num[i];
				return true;
			}

			int temp = num[i];
			num[i] = num[num[i]];
			num[num[i]] = temp;
		}
	}
	return false;
}
