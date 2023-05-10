#include <iostream>
#include <array>
using namespace std;

void print(array<int, 5> arr);
/*print를 범용으로 만드는 법 -> template
template <size_t N> -> 매개변수 배열의 크기를 제네릭으로 선언
void print(const array<int, N>& arr) -> 크기 N인 array 타입 arr을 참조해라.
*/
int main()
{
	array<int, 10> arr1;
	arr1[0] = 1;
	cout << "배열의 첫 번째 원소: " << arr1[0] << endl;

	array<int, 4> arr2 = { 1,2,3,4 };
	cout << "arr2의 모든 원소: ";

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
		cerr << ex.what() << endl;	//cerr: 에러 로그 출력
	}
	array<int, 5> arr = { 1,2,3,4,5 };
	//원소 접근 함수 사용하기
	cout << arr.front() << endl;		//1 출력
	cout << arr.back() << endl;			//5 출력
	cout << *(arr.data() + 1) << endl;	//2 출력
	print(arr);
}

/*array 객체를 함수에 전달하기
포인터, 참조, 역참조 필요 없음*/
void print(array<int, 5> arr)
{
	for (auto ele : arr)	//범위 기반 for문(반복자 때문에 가능). auto는 타입 알아서 계산
		cout << ele << ", ";
	cout << endl;
	//반복자 활용하기. 위 for문과 같은 코드임. 
	for (auto it = arr.begin(); it != arr.end(); it++)
	{
		auto element = (*it);
		cout << element << ' ';
	}
	//const_iterator, reverse_iterator 등도 존재
	//관계 연산(<, > 등)과 복사 할당 연산자도 지원
}
