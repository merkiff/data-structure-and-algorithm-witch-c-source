#include <forward_list>
using namespace std;

int main()
{
	forward_list<int> fwd_list = { 1,2,3 };
	fwd_list.push_front(0);	//�� �տ� 0 �߰�
	auto it = fwd_list.begin();
	fwd_list.insert_after(it, 5);	//�� ó�� ���� �ڿ� 5 �߰�
	fwd_list.insert_after(it, 6);	//���� ��ġ�� 6 �߰�
	fwd_list.pop_front();	//�� �� ����
	auto it2 = fwd_list.begin();
	fwd_list.erase_after(it2);	//�� �� ���� ���� ����
	fwd_list.erase_after(it2, fwd_list.end());	//�� �� �������� ���������� ����
}