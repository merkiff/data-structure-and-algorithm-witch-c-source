/*싱가포르 F1 그랑프리 수상자 명단에서 반복자를 사용해
유용한 정보를 검색하는 방법*/
#include <iostream>
#include <forward_list>
#include <vector>
using namespace std;
int main()
{
	vector<string> vec = {
		"Lewis Hamilton", "Lewis Hamilton", "Nico Roseberg", "Sebastian vettel", "Lewis Hamilton", "Sebastian Vettel",
		"Sebastian vettel", "Sebastian Vettel", "Fernando Alonso"
	};

	auto it = vec.begin();	//상수 시간
	cout << "가장 최근 우승자: " << *it << endl;

	it += 8;
	cout << "8년 전 우승자: " << *it << endl;

	advance(it, -3);
	cout << "그후 3년 뒤 우승자: " << *it << endl;

	forward_list<string> fwd(vec.begin(), vec.end());
	auto it1 = fwd.begin();	//선형 시간
	cout << "가장 최근 우승자: " << *it1 << endl;

	advance(it1, 5);
	cout << "8년 전 우승자: " << *it1 << endl;
	//순방향 이동만 가능하므로 아래 코드는 에러
	//advance(it, -3);
}