/* 10989 - 수 정렬하기3
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	int n;
	int i;
	int count[10001] = { 0, }; // counting 배열 문제조건 10000보다 작다했음 들어오는 수
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		count[tmp]++; // 빈도 수 쌓기
	}

	for (i = 1; i <= 10000; i++) {
		if(count[i]) printf("%d\n", i); // 빈도 수가 체크 되어있다면 출력!
	}

	return 0;
}
*/

/* 2108 - 통계학

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <limits.h>
#include <cmath>

using namespace std;
double Rounding(double n, int digit);

int main() {
	int num;
	scanf("%d", &num);

	int* testcase = (int*)malloc(sizeof(int) * num);

	for (int i = 0; i < num; i++) {
		scanf("%d", &testcase[i]);
	}

	// 정렬
	sort(testcase, testcase + num);

	// 산술 평균
	double sum = 0;
	for (int i = 0; i < num; i++) {
		sum += testcase[i];
	}

	double avg = (double)sum / (double)num;

	// 중앙값
	int middle = testcase[num/2];


	// 최빈값 - 절댓값이 4000을 넘지 않음 - 문제조건 빈도수 배열 8000개짜리 필요
	int count[8001] = { 0, };
	int max = INT_MIN;
	int many = 0;
	for (int i = 0; i < num; i++) {
		count[testcase[i]+4000]++; // -4000 ~ 0 도 포함 -4000이 count[0]으로 가게끔

		if (max < count[testcase[i]+4000]) {
			many = testcase[i]; // 최빈값
			max = count[testcase[i]+4000];
		}
	}

	// 최빈값이 여러개인 경우 두번 째로 작은 값 출력

	int tick = 0;
	for (int i = 0; i < 8001; i++) {
		if (max == count[i]) {
			tick++;
			if (tick == 2) {
				many = i - 4000;
				break;
			}
		}
	}

	// 범위 - 정렬된 상태이므로
	int range = testcase[num - 1] - testcase[0];

	printf("%g\n%d\n%d\n%d\n",Rounding(avg,0),middle,many,range);

	return 0;
}

double Rounding(double x, int digit)
{
	return (floor((x)*pow(float(10), digit) + 0.5f) / pow(float(10), digit));
}
*/

/* 1181 - 단어 순 정렬
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <limits.h>
#include <cmath>


using namespace std;

bool compare(string a, string b) {
	if (a.size() != b.size()) {
		return a.size() < b.size();
	}

	return a < b;
}

int main() {
	string str[20000];
	string dupstr;
	int num;
	
	scanf("%d", &num);

	int i = 0;
	while ( i < num) {
		cin >> str[i];
		i++;
	}

	sort(str, str + num, compare);

	i = 0;
	while (i < num) {
		if (str[i] != dupstr) {
			cout << str[i] << "\n";
		}
		dupstr = str[i];
		i++;
	}

	return 0;
}
*/

/* 15649 - N과 M(1)
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <limits.h>
#include <cmath>
#include <stdbool.h>

bool promissing(int i, int* seq){
	
	int k = 1;
	bool flag = true;

	while ( k < i && flag ) {
		if (seq[k] == seq[i])
			flag = false;
		k++;
	}
	
	return flag;
}

void nAndm(int i,int m,int n,int *seq) {
	int j;
	if (promissing(i,seq)) {
		if (i == m) {
			for (int k = 1; k <= m; k++) {
				printf("%d ", seq[k]);
			}
			printf("\n");
		}
		else {
			for (j = 1; j <= n; j++) {
				seq[i+1] = j;
				nAndm(i + 1, m, n, seq);
			}
		}
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int* seq = (int*)malloc(sizeof(int) * (m+1));
	nAndm(0,m,n,seq);
	return 0;
}
*/

/* 15650 - N과 M(2)
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <limits.h>
#include <cmath>
#include <stdbool.h>

bool promissing(int i, int* seq) {

	int k = 1;
	bool flag = true;

	while (k < i && flag) {
		if (seq[k] >= seq[i])
			flag = false;
		k++;
	}

	return flag;
}

void nAndm(int i, int m, int n, int* seq) {
	int j;
	if (promissing(i, seq)) {
		if (i == m) {
			for (int k = 1; k <= m; k++) {
				printf("%d ", seq[k]);
			}
			printf("\n");
		}
		else {
			for (j = 1; j <= n; j++) {
				seq[i + 1] = j;
				nAndm(i + 1, m, n, seq);
			}
		}
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int* seq = (int*)malloc(sizeof(int) * (m + 1));
	nAndm(0, m, n, seq);
	return 0;
}
*/

/* 15651 - N과 M(3)
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <limits.h>
#include <cmath>
#include <stdbool.h>

bool promissing(int i, int* seq) {
	return true;
}

void nAndm(int i, int m, int n, int* seq) {
	int j;
	if (promissing(i, seq)) {
		if (i == m) {
			for (int k = 1; k <= m; k++) {
				printf("%d ", seq[k]);
			}
			printf("\n");
		}
		else {
			for (j = 1; j <= n; j++) {
				seq[i + 1] = j;
				nAndm(i + 1, m, n, seq);
			}
		}
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int* seq = (int*)malloc(sizeof(int) * (m + 1));
	nAndm(0, m, n, seq);
	return 0;
}
*/

/* 15652 - N과 M(4)
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <limits.h>
#include <cmath>
#include <stdbool.h>

bool promissing(int i, int* seq) {
	int k = 1;
	bool flag = true;

	while (k < i && flag) {
		if (seq[k] > seq[i])
			flag = false;
		k++;
	}

	return flag;
}

void nAndm(int i, int m, int n, int* seq) {
	int j;
	if (promissing(i, seq)) {
		if (i == m) {
			for (int k = 1; k <= m; k++) {
				printf("%d ", seq[k]);
			}
			printf("\n");
		}
		else {
			for (j = 1; j <= n; j++) {
				seq[i + 1] = j;
				nAndm(i + 1, m, n, seq);
			}
		}
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int* seq = (int*)malloc(sizeof(int) * (m + 1));
	nAndm(0, m, n, seq);
	return 0;
}
*/

/* 9663 - N-Queen

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <limits.h>
#include <cmath>
#include <stdbool.h>

int solution = 0;

bool promissing(int i,int* col) {
	int k = 1;
	bool flag = true;

	while (k < i && flag) {
		if (col[i] == col[k] || abs(col[i] - col[k]) == i - k) 
			flag = false;
		k++;
	}
	return flag;
}

void N_Queen(int i,int* col,int n) {
	int j;
	if (promissing(i, col)){
		if (i == n) {
			solution++;
		}
		else {
			for (j = 1; j <= n; j++) {
				col[i + 1] = j;
				N_Queen(i+1,col,n);
			}
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	int* board = (int*)malloc(sizeof(int) * (n + 1));
	N_Queen(0, board, n);
	printf("%d\n", solution);
	return 0;
}
*/

// 스도쿠 공식 - sector (i / 3) * 3 + (j / 3)

/*
 Row[a][b] = true 의 의미는 " a번째 가로줄에 b라는 숫자는 이미 존재합니다. "

 Col[a][b] = true 의 의미는 " a번째 세로줄에 b라는 숫자는 이미 존재합니다."

 Square[a][b] = true 의 의미는 "a번째 사각형에 b라는 숫자는 이미 존재합니다."
*/

/* 2580 - 스도쿠
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <limits.h>
#include <cmath>
#include <stdbool.h>

int board[11][11];

class Sector {
public:
	int lx;
	int uy;
	int rx;
	int ly;
	int number;
public:
	void set_Sector(int i, int j);

};

void Sector::set_Sector(int i, int j) {
	if (i >= 1 && i <= 3 && j >= 1 && j <= 3) {
		// 1;
		lx = 1;
		uy = 1;
		rx = 3;
		ly = 3;
		number = 1;
	}
	else if (i >= 1 && i <= 3 && j >= 4 && j <= 6) {
		// 2;
		lx = 1;
		uy = 4;
		rx = 3;
		ly = 6;
		number = 2;
	}
	else if (i >= 1 && i <= 3 && j >= 7 && j <= 9) {
		// 3;
		lx = 1;
		uy = 7;
		rx = 3;
		ly = 9;
		number = 3;
	}
	else if (i >= 4 && i <= 6 && j >= 1 && j <= 3) {
		// 4;
		lx = 4;
		uy = 1;
		rx = 6;
		ly = 3;
		number = 4;
	}
	else if (i >= 4 && i <= 6 && j >= 4 && j <= 6) {
		// 5;
		lx = 4;
		uy = 4;
		rx = 6;
		ly = 6;
		number = 5;
	}
	else if (i >= 4 && i <= 6 && j >= 7 && j <= 9) {
		// 6;
		lx = 4;
		uy = 7;
		rx = 6;
		ly = 9;
		number = 6;
	}
	else if (i >= 7 && i <= 9 && j >= 1 && j <= 3) {
		// 7;
		lx = 7;
		uy = 1;
		rx = 9;
		ly = 3;
		number = 7;
	}
	else if (i >= 7 && i <= 9 && j >= 4 && j <= 6) {
		// 8;
		lx = 7;
		uy = 4;
		rx = 9;
		ly = 6;
		number = 8;
	}
	else if (i >= 7 && i <= 9 && j >= 7 && j <= 9) {
		// 9;
		lx = 7;
		uy = 7;
		rx = 9;
		ly = 9;
		number = 9;
	}
}


bool promissing(int i, int j) {
	bool flag = true;
	// 열검사 1 ~ 9
	for (int k = 1; k <= 9; k++) {
		if (j != k) {
			if (board[i][k] == board[i][j])
				flag = false;
		}
	}
	// 행검사 1 ~ 9
	for (int k = 1; k <= 9; k++) {
		if (i != k) {
			if (board[k][j] == board[i][j])
				flag = false;
		}
	}
	// 3 x 3 검사
	// sector 1 ~ 9
	Sector area = Sector();
	area.set_Sector(i, j);
	//printf("(%d, %d) : secotr %d\n", i, j, area.number);
	for (int x = area.lx; x <= area.rx; x++) {
		for (int y = area.uy; y <= area.ly; y++) {
			if (i != x && j != y) {
				if (board[x][y] == board[i][j])
					flag = false;
			}
		}
	}

	return flag;
}

void sudoku() {

	int i, j;

	for (int x = 1; x <= 9; x++) {
		for (int y = 1; y <= 9; y++) {
			if (!board[x][y]) {

				i = x;
				j = y;

				goto jump;
			}
		}
	}

	printf("\n");

	for (int x = 1; x <= 9; x++) {
		for (int y = 1; y <= 9; y++) {

			printf("%d ", board[x][y]);
		}
		printf("\n");
	}
	exit(0);

jump:
	for (int solution = 1; solution <= 9; solution++) {
		
		board[i][j] = solution;
		if (promissing(i, j))
			sudoku();
		board[i][j] = 0; // 이거 빼먹어서 개고생했었다..
	}


}

int main() {

	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			scanf("%d", &board[i][j]);
		}
	}

	sudoku();

	return 0;
}
*/

/* 14888 - 연산자 끼워넣기
#include <iostream>
#include <algorithm>

using namespace std;

int N;
int num[13];
// + - * /
int op[4];
// 가장 작은 값을 설정
int maxN = -1000000005;
// 가장 큰 값을 설정
int minN = 1000000005;

int dfs(int idx, int amount) {

	if (idx == N) {
		maxN = max(maxN, amount);
		minN = min(minN, amount);
		return 0;
	}

	if (op[0] > 0) {
		op[0] --;
		dfs(idx + 1, amount + num[idx]);
		op[0] ++;
	}
	if (op[1] > 0) {
		op[1] --;
		dfs(idx + 1, amount - num[idx]);
		op[1] ++;
	}
	if (op[2] > 0) {
		op[2] --;
		dfs(idx + 1, amount * num[idx]);
		op[2] ++;
	}
	if (op[3] > 0) {
		op[3] --;
		dfs(idx + 1, amount / num[idx]);
		op[3] ++;
	}
	return 0;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}

	dfs(1, num[0]);
	cout << maxN << "\n";
	cout << minN << "\n";
	return 0;
}
*/

/* 14889 - 스타트와 링크
#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

#define max_int 21

using namespace std;

int player[max_int][max_int],
n,
start_sum = 0, 
link_sum = 0, 
start_first, 
start_second, 
link_first, 
link_second, 
result = INT_MAX;

// 스타트, 링크 팀에 속한 사람들의 번호를 저장할 리스트
vector<int> start, link;

// 각 케이스에 대해 1) start에 넣거나, 2) link에 넣거나

void start_link(int i) {
	// 1 ~ n번째 선수에 대해 케이스를 구분했을때
	if (i == n + 1) {
		// start, link팀 각각의 크기가 n/2로 딱 절반일때
		if (start.size() == n / 2 && link.size() == n / 2) {
			start_sum = 0;
			link_sum = 0;
			for (int i = 0; i < n / 2; i++) {
				for (int j = i + 1; j < n / 2; j++) {
					if (i == j)continue;
					// 스타트팀 점수 계산
					start_sum += player[start[i]][start[j]] + player[start[j]][start[i]];	
					// 링크팀 점수 계산
					link_sum += player[link[i]][link[j]] + player[link[j]][link[i]];
				}
			}
			// 절대값을 취해주고, 최소값을 갱신해줍니다.
			result = min(result,(int)abs(start_sum - link_sum));
		}
		return;
	}

	// i번째 선수에 대해 두가지 케이스가 존재

	// 1) 스타트 팀에 넣는다.
	start.push_back(i);
	start_link(i + 1);
	start.pop_back();

	// 2) 링크 팀에 넣는다.
	link.push_back(i);
	start_link(i + 1);
	link.pop_back();
}

int main() {
	
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &player[i][j]);
		}
	}

	start_link(1);

	printf("%d\n", result);
}
*/

/* 1003 - 피보나치 함수
#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

vector<vector<long long>> fibo(43, vector<long long>(2, 0)); // 41행 2열짜리
vector<vector<long long>> solution(100, vector<long long>(2, 0)); // solution

int main() {
	int testcase;
	int n;

	scanf("%d", &testcase);

	fibo[0][0] = 1;
	fibo[1][1] = 1;

	for (int i = 0; i < 41; i++) {
		fibo[i + 2][0] = fibo[i][0] + fibo[i + 1][0]; // 0의 갯수
		fibo[i + 2][1] = fibo[i][1] + fibo[i + 1][1]; // 1의 갯수
	}

	for (int i = 0; i < testcase; i++) {
		scanf("%d", &n);
		solution[i][0] = fibo[n][0];
		solution[i][1] = fibo[n][1];
	}

	for (int i = 0; i < testcase; i++) {
		printf("%lld %lld\n", solution[i][0], solution[i][1]);
	}

	return 0;
}
*/

/* 1904 - 01타일
#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

long long tile[1000001];

int main() {
	int n;

	scanf("%d",&n);
	
	tile[1] = 1;
	tile[2] = 2;

	for (int i = 3; i <= n; i++) {
		tile[i] = (tile[i-1] + tile[i-2]) % 15746;
	}

	printf("%lld\n",tile[n]);

	return 0;
}
*/

/* 9461 - 파도반 수열

#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdio>

using namespace std;

vector<long long> oddTriangle(105);
vector<long long> evenTriangle(105);
vector<long long>solution_seq(1000);
vector<long long>for_print(1000);

int main() {
	
	int testcase;
	int n;
	scanf("%d", &testcase);
	
	oddTriangle[0] = 1;
	evenTriangle[0] = 1;

	oddTriangle[1] = 1;
	evenTriangle[1] = 2;

	oddTriangle[2] = 2;
	evenTriangle[2] = 3;

	for (int i = 0; i < 100; i++) {
		// 짝수 번째 삼각형 생성
		evenTriangle[i + 2] = oddTriangle[i + 2] + oddTriangle[i];
		// 홀수 번째 삼각형 생성
		oddTriangle[i+3] = evenTriangle[i] + evenTriangle[i+2];
		
	}
	// 파도반수열 index : 1 3 5 ... 에는 홀수번째 삼각형 0번째 인덱스는 안쓸거임
	int t = 0;
	for (int i = 1; i < 1000; i+=2) {
		solution_seq[i] = oddTriangle[t];
		t++;
	}
	t = 0;
	// 파도반수열 index 2 4 6 .. 에는 홀수 번째 삼각형
	for (int i = 2; i < 1000; i+=2) {
		solution_seq[i] = evenTriangle[t];
		t++;
	}
	
	for (int i = 1; i <= testcase; i++) {
		scanf("%d", &n);

		for_print[i] = solution_seq[n];

	}
	
	for (int i = 1; i <= testcase; i++) {
		printf("%lld\n", for_print[i]);
	}
	
	return 0;
}
*/

/* RGB 거리
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

vector<vector<long long>> rgb(1001, vector<long long>(3, 0));
vector<vector<long long>> mincost(1001, vector<long long>(3, 0));

int main() {

	int n;
	scanf("%d", &n);

	// 0 행은 비워놓는다.
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> rgb[i][j];
		}
	}
	
	for (int i = 1; i <= n; i++) {
		mincost[i][0] = min(mincost[i - 1][1], mincost[i - 1][2]) + rgb[i][0];
		mincost[i][1] = min(mincost[i - 1][0], mincost[i - 1][2]) + rgb[i][1];
		mincost[i][2] = min(mincost[i - 1][0], mincost[i - 1][1]) + rgb[i][2];
	}

	long long solution = min(min(mincost[n][0], mincost[n][1]), mincost[n][2]);

	printf("%lld\n", solution);

	return 0;
}
*/

/* 1932 - 계단 오르기
#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<vector<long long>>triangle(501, vector<long long>(501));

int main() {
	int n;

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			scanf("%lld", &triangle[i][j]);
		}
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
		// /
			if(j==1) triangle[i][j] += triangle[i - 1][j];
			else if(j==i) triangle[i][j] += triangle[i - 1][j - 1];
			else triangle[i][j] += (long long)max(triangle[i - 1][j - 1], triangle[i - 1][j]);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			printf("%lld ", triangle[i][j]);
		}
		printf("\n");
	}
	
	long long solution=LONG_MIN;
	
	for (int j = 1; j <= n; j++) {
		solution = (long long)max(triangle[n][j], solution);
	}
	
	printf("\n%lld\n", solution);
	
	return 0;
}
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

