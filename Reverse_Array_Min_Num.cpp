


//旋转数组中最小的数字
//[ 折半查找思路 ]
int Min(int *num, int length) {
	if (num == nullptr || length <= 0)
		throw new std::exception("Invalid parameters");
	int index1 = 0;
	int index2 = length - 1;
	int mid = index1;
	while (num[index1] >= num[index2]) {
		if (index2 - index2 == 1) {
			mid = index2;
			break;
		}
		mid = (index2 - index1)/2 + index1;
		if (num[mid] >= num[index1])
			index1 = mid;
		if (num[mid] <= num[index2])
			index2 = mid;
	}
	return num[mid];
}




//处理 { 1,0,1,1,1 } 和 { 1,1,1,0,1 }

//代码更改为:

int MinInOrder(int* num, int index1, int index2) {
	int ret = num[index1];
	for (int i = index1 + 1; i <= index2; ++i) {
		if (ret > num[i])
			ret = num[i];
	}
	return ret;
}
int min(int *num, int size) {
	if (num == nullptr || size <= 0)
		throw new std::exception("Invild parameters");
	int index1 = 0;
	int index2 = size - 1;
	int mid = index1;
	while (num[index1] >= num[index2]) {
		if (index2 - index1 == 1) {
			mid = index2;
			break;
		}
		mid = (index2 - index1) / 2 + index1;
		//如果下标为index1、index2和mid指向的三个数字相等，则顺序查找
		if (num[index1] == num[index2]
			&& num[index1] == num[mid]
			&& num[mid] == num[index2]) {
			return MinInOrder(num, index1, index2);
		}
		if (num[mid] >= num[index1])
			index1 = mid;
		if (num[mid] <= num[index2])
			index2 = mid;
	}
	return num[mid];
}
