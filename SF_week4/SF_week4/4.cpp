#include <iostream>

using namespace std;


//µİ¹éÊµÏÖ
void jump(int step,int* count) {
	if (step == 1)(*count)++;
	else if (step == 2) {
		(*count)++;
		jump(1, count);
	}
	else if (step == 3) {
		(*count)++;
		jump(2, count);
		jump(1, count);
	}
	else {
		jump(step - 1, count);
		jump(step - 2, count);
		jump(step - 3, count);
	}
}

int main() {
	int n;
	cin >> n;
	int count = 0;
	jump(n, &count);
	cout << count;
}