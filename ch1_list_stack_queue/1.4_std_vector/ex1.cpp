#include <vector>
using namespace std;

int main() {
	/*
	//ũ�Ⱑ 0�� ���� ����
	vector<int> vec;
	//������ �ʱ갪���� �̷���� ũ�� 5 ����
	vector<int> vec = { 1,2,3,4,5 };
	//ũ�Ⱑ 10
	vector<int> vec(10);
	//ũ�Ⱑ 10, ��� ���� 5�� �ʱ�ȭ
	vector<int> vec(10, 5);
	*/
	vector<int> vec = { 1,2,3,4,5 };
	vec.insert(vec.begin(), 0);//�� �տ� �� ���� �߰�
	vector<int> vec;	//�� ����
	vec.push_back(1);	//�� �ڿ� 1 �߰�
	vec.push_back(2);	//2 �߰�
	vec.insert(vec.begin(), 0);	//�� �տ� 0 �߰�
	vec.insert(find(vec.begin(), vec.end(), 1), 4);	//1 �տ� 4 �߰� {0, 4, 1, 2}

	//push_back, insert�� ���� �ӽ� ���� �� ���ͷ� ����. 
	//���� ��ġ�� ��ٷ� ���� �����ϴ� emplace_back(), emplace()�� �����ϴ�

	vector<int> vec2 = { 0,1,2,3,4,5,6,7,8,9 };
	vec2.pop_back();	//������ ���� ����
	vec2.erase(vec.begin());	//ó�� ���� ����
	vec2.erase(vec2.begin() + 1, vec2.begin() + 4);	//1�������� 4��° �ձ��� ����

	//claer(): ��� ���� ����
	//reverse(capacity): ����� �뷮 ����
	//shrink_to)fit(): ������ �޸� ���� ���� �뵵
	//vector�� �Ҵ��� ���� ����
}