

void ReplaceBlank(char string[], int size) {
	if (string == nullptr || size <= 0) {
		return;
	}
	int origin = 0;
	int Blank = 0;
	int i = 0;
	while (string[i++] != '\0') {
		++origin;
		if (string[i] == ' ')
			++Blank;
	}
	int NewSize = origin + 2 * Blank;	//包含原空格，共3*，' ' 成为了'%20'

	int IndexOfOrigin = origin;
	int IndexOfNew = NewSize;
	while (IndexOfOrigin >= 0 && IndexOfNew > IndexOfOrigin) {
		if (string[IndexOfOrigin] == ' ') {
			string[IndexOfNew--] = '0';
			string[IndexOfNew--] = '2';
			string[IndexOfNew--] = '%';
		}
		else
			string[IndexOfNew--] = string[IndexOfOrigin];
		--IndexOfOrigin;
	}
}
int main() {
	char str[30] = "i am a pig";
	int size = strlen(str);
	ReplaceBlank(str, size);
	cout << str << endl;
	system("pause");
	return 0;
}
