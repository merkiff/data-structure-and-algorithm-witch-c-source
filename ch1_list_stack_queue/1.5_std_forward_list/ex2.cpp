#include <string>
#include <iostream>
#include <forward_list>
using namespace std;

struct citizen
{
	string name;
	int age;
};

ostream& operator<<(ostream& os, const citizen& c)
{
	return (os << "[" << c.name << ", " << c.age << "]");
}

int main()
{
	//시민 정보 초기화
	forward_list<citizen> citizens = {
		{"Kim", 22}, {"Lee", 25}, {"Park", 18}, {"Jin", 16}
	};

	auto citizens_copy = citizens;	//다시 초기화하지 않도록 복사본 생성. 깊은 복사

	cout << "전체 시민들: ";
	for (const auto& c : citizens)
		cout << c << " ";
	cout << endl;

	//람다 표현식 사용
	citizens.remove_if([](const citizen& c) {
		return (c.age < 19);	//나이가 19세 이하면 제거
	});

	cout << "투표권이 있는 시민들: ";
	for (const auto& c : citizens)
		cout << c << " ";
	cout << endl;

	citizens_copy.remove_if([](const citizen& c) {
		return (c.age != 18);	//나이가 19세 이하면 제거
		});

	cout << "내년에 투표권이 생기는 시민들: ";
	for (const auto& c : citizens_copy)
		cout << c << " ";
	cout << endl;

	//list1.sort();
	//list1.sort(greater<int>());
}