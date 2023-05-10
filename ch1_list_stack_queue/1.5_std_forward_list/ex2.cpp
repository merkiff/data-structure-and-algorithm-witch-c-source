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
	//�ù� ���� �ʱ�ȭ
	forward_list<citizen> citizens = {
		{"Kim", 22}, {"Lee", 25}, {"Park", 18}, {"Jin", 16}
	};

	auto citizens_copy = citizens;	//�ٽ� �ʱ�ȭ���� �ʵ��� ���纻 ����. ���� ����

	cout << "��ü �ùε�: ";
	for (const auto& c : citizens)
		cout << c << " ";
	cout << endl;

	//���� ǥ���� ���
	citizens.remove_if([](const citizen& c) {
		return (c.age < 19);	//���̰� 19�� ���ϸ� ����
	});

	cout << "��ǥ���� �ִ� �ùε�: ";
	for (const auto& c : citizens)
		cout << c << " ";
	cout << endl;

	citizens_copy.remove_if([](const citizen& c) {
		return (c.age != 18);	//���̰� 19�� ���ϸ� ����
		});

	cout << "���⿡ ��ǥ���� ����� �ùε�: ";
	for (const auto& c : citizens_copy)
		cout << c << " ";
	cout << endl;

	//list1.sort();
	//list1.sort(greater<int>());
}