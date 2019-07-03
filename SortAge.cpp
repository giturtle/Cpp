
//默认允许的年龄范围为0~99岁
//timeOfAge统计每个年龄出现的次数
//某个年龄出现了多少次，就在数组age里设置几次该年龄，相当与给数组age排序了

//该方法用长度为100的辅助空间换来了 O(N) 的时间效率


#define oldestAge 99
void SortAge(int age[], int length) {
	if (age == nullptr || length <= 0) {
		return;
	}
	int timeOfAge[oldestAge + 1];	//辅助空间

	for (int i = 0; i <= oldestAge; ++i)
		timeOfAge[i] = 0;

	for (int i = 0; i < length; ++i) {
		int Age = age[i];
		if (Age < 0 || Age > oldestAge)
			throw new std::exception("age out of range");
		++timeOfAge[Age];
	}
	int index = 0;
	for (int i = 0; i <= oldestAge; ++i) {
		for (int j = 0; j < timeOfAge[i]; ++j) {
			age[index] = i;
			++index;
		}
	}
}
int main() {
	int age[] = { 3,5,1,8 };
	SortAge(age, 4);
	for (int i = 0; i < 4; ++i) {
		cout << age[i] << " ";
	}
	system("pause");
	return 0;
}
