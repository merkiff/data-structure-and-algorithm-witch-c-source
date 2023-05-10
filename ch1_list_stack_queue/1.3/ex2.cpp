//다양한 타입 데이터 여러 개를 받아 공통 타입으로 변환하는 함수
#include <array>
#include <iostream>
#include <type_traits>
using namespace std;

template<typename ... Args>
//컨테이너를 생성하는 build_array()
/*
array< ? , ? > build_array(Args&&... args)	//반환된 컨테이너는 빠른 순회가 필요하므로, 배열, 벡터 가능

*/
//array에 저장할 원소의 타입을 결정하기 위해 common_type 템플릿 사용.
//함수 인자에 의존적이므로 반환형을 후행 리턴 타입(trailing return type)으로 지정 ->
/*
auto build_array(Args&&... args) -> array<typename common_type<Args...>::type, ? >
{
	using commonType = typename common_type<Args...>::type;
	//배열 생성
}
*/
//원소 개수를 알아내는 코드와 배열을 생성하는 코드 입력
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