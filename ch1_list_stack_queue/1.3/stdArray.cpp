#include <iostream>
#include <array>
using namespace std;

void print(array<int, 5> arr);
/*print�� �������� ����� �� -> template
template <size_t N> -> �Ű����� �迭�� ũ�⸦ ���׸����� ����
void print(const array<int, N>& arr) -> ũ�� N�� array Ÿ�� arr�� �����ض�.
*/
int main()
{
	array<int, 10> arr1;
	arr1[0] = 1;
	cout << "�迭�� ù ��° ����: " << arr1[0] << endl;

	array<int, 4> arr2 = { 1,2,3,4 };
	cout << "arr2�� ��� ����: ";

	for (int i = 0; i < arr2.size(); i++)
		cout << arr2[i] << " ";
	cout << endl;

	//out of range err catch
	array<int, 4> arr3 = { 1,2,3,4 };

	try
	{
		cout << arr3.at(3) << endl;
		cout << arr3.at(4) << endl;	//out_of_range
	}
	catch (const out_of_range& ex)
	{
		cerr << ex.what() << endl;	//cerr: ���� �α� ���
	}
	array<int, 5> arr = { 1,2,3,4,5 };
	//���� ���� �Լ� ����ϱ�
	cout << arr.front() << endl;		//1 ���
	cout << arr.back() << endl;			//5 ���
	cout << *(arr.data() + 1) << endl;	//2 ���
	print(arr);
}

/*array ��ü�� �Լ��� �����ϱ�
������, ����, ������ �ʿ� ����*/
void print(array<int, 5> arr)
{
	for (auto ele : arr)	//���� ��� for��(�ݺ��� ������ ����). auto�� Ÿ�� �˾Ƽ� ���
		cout << ele << ", ";
	cout << endl;
	//�ݺ��� Ȱ���ϱ�. �� for���� ���� �ڵ���. 
	for (auto it = arr.begin(); it != arr.end(); it++)
	{
		auto element = (*it);
		cout << element << ' ';
	}
	//const_iterator, reverse_iterator � ����
	//���� ����(<, > ��)�� ���� �Ҵ� �����ڵ� ����
}
