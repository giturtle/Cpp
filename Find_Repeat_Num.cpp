

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


/*
	 *方法四：二分查找
	 */
	 //时间复杂度O(N),空间复杂度O(N)，但不修改原数组
	int CountRange(const int* num, int size, int start, int end) {
		if (num == nullptr) {
			return 0;
		}
		int count = 0;
		for (int i = 0; i < size; ++i) {
			if ((num[i] >= start) && (num[i] <= end))
				++count;
		}
		return count;
	}
	int GetDup(const int * num, int size) {
		if ((num == nullptr) || (size <= 0)) {
			return -1;
		}
		int start = 1;
		int end = size - 1;
		while (end >= start) {
			int mid = ((end - start) / 2) + start;
			int count = CountRange(num, size, start, mid);
			if (end == start) {
				if (count > 1)
					return start;
				else
					break;
			}
			if (count > (mid - start + 1))
				end = mid;
			else
				start = mid + 1;
		}
		return -1;
	}
	
