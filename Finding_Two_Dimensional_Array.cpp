


bool Find(int *arr, int row, int col, int num) {
	bool found = false;

	if (arr != nullptr && row > 0 && col > 0) {
		int i = 0;
		int j = col - 1;
		while (i < row && j >= 0) {
			if (arr[i * col + j] == num) {
				found = true;
				break;
			}
			else if (arr[i * col + j] > num) {
				--j;
			}
			else
				++i;
		}
	}
	return found;
}
 
