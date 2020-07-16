#include <iostream>

// 최대 공약수 찾기
int GCD(int val1, int val2) {
	// 음수일 경우 예외
	if (val1 < 0) { return -1; }
	else if (val2 < 0) { return -2; }
	// 두 수 모두 0일 경우 예외
	else if (val1 == 0 && val2 == 0) { return -3; }

	// 큰 값을 a, 작은 값을 b
	int a = (val1 > val2) ? val1 : val2;
	int b = (val1 > val2) ? val2 : val1;

	while (b != 0) {
		int tmp = a % b;
		a = b;
		b = tmp;
	}

	return a;
}

// 문자열이 정수인지 확인하는 함수
int IsInteger(char* const str) {
	char* pt = str;
	char c = NULL;

	// 첫 번째 문자가 '-' or 숫자가 아닐 때 에러
	c = *pt;
	if (c != '-' && (c < '0' || c > '9')) {
		return 1;
	}
	pt++;

	// 그 뒤로 숫자가 아닌 값이 나올 때 에러
	while (*pt != '\0') {
		c = *pt;
		if ((c < '0' || c > '9') && c != ' ' && c != '\t') {
			return 1;
		}
		pt++;
	}

	return 0;
}

enum ExitCode
{
	ArgError = 1,
	VarError = 2
};

int main(int argc, char* argv[])
{
	if (argc != 3) {
		fprintf(stderr, "Enter two positive integers. [ e.g. 12 34 ]");
		return ExitCode::ArgError;
	}

	int a, b;

	char* arg = argv[1];
	if (IsInteger(arg) == 0) {
		a = atoi(arg);
	}
	else {
		fprintf(stderr, "The first value is not integer.\n");
		return ExitCode::ArgError;
	}
	arg = argv[2];
	if (IsInteger(arg) == 0) {
		b = atoi(arg);
	}
	else {
		fprintf(stderr, "The second value is not integer.\n");
		return ExitCode::ArgError;
	}

	int gcd = GCD(a, b);
	if (gcd > 0) {
		printf("%d\n", gcd);
	}
	else {
		switch (gcd)
		{
		case -1:
			fprintf(stderr, "The first value is less than 0.\n");
			return ExitCode::VarError;
		case -2:
			fprintf(stderr, "The second value is less than 0.\n");
			return ExitCode::VarError;
		case -3:
			fprintf(stderr, "Neither value can be 0.\n");
			return ExitCode::VarError;
		default:
			fprintf(stderr, "Unknown error.\n");
			return ExitCode::VarError;
		}
	}

	return 0;
}
