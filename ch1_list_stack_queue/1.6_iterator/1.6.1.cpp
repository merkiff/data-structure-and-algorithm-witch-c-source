/*�̰����� F1 �׶����� ������ ��ܿ��� �ݺ��ڸ� �����
������ ������ �˻��ϴ� ���*/
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

	auto it = vec.begin();	//��� �ð�
	cout << "���� �ֱ� �����: " << *it << endl;

	it += 8;
	cout << "8�� �� �����: " << *it << endl;

	advance(it, -3);
	cout << "���� 3�� �� �����: " << *it << endl;

	forward_list<string> fwd(vec.begin(), vec.end());
	auto it1 = fwd.begin();	//���� �ð�
	cout << "���� �ֱ� �����: " << *it1 << endl;

	advance(it1, 5);
	cout << "8�� �� �����: " << *it1 << endl;
	//������ �̵��� �����ϹǷ� �Ʒ� �ڵ�� ����
	//advance(it, -3);
}