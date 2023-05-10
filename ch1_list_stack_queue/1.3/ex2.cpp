//�پ��� Ÿ�� ������ ���� ���� �޾� ���� Ÿ������ ��ȯ�ϴ� �Լ�
#include <array>
#include <iostream>
#include <type_traits>
using namespace std;

template<typename ... Args>
//�����̳ʸ� �����ϴ� build_array()
/*
array< ? , ? > build_array(Args&&... args)	//��ȯ�� �����̳ʴ� ���� ��ȸ�� �ʿ��ϹǷ�, �迭, ���� ����

*/
//array�� ������ ������ Ÿ���� �����ϱ� ���� common_type ���ø� ���.
//�Լ� ���ڿ� �������̹Ƿ� ��ȯ���� ���� ���� Ÿ��(trailing return type)���� ���� ->
/*
auto build_array(Args&&... args) -> array<typename common_type<Args...>::type, ? >
{
	using commonType = typename common_type<Args...>::type;
	//�迭 ����
}
*/
//���� ������ �˾Ƴ��� �ڵ�� �迭�� �����ϴ� �ڵ� �Է�
auto build_array(Args&&... args)->array<typename common_type<Args...>::type, sizeof...(args)>
{
	using commonType = typename common_type<Args...>::type;
	return { forward<commonType>((Args&&)args)... };
}

int main()
{
	auto data = build_array(1, 0u, 'a', 3.2f, false);

	for (auto i : data)
		cout << i << " ";
	cout << endl;
}