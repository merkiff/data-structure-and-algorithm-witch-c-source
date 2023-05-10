#include <vector>
using namespace std;

int main() {
	/*
	//크기가 0인 벡터 선언
	vector<int> vec;
	//지정한 초깃값으로 이루어진 크기 5 벡터
	vector<int> vec = { 1,2,3,4,5 };
	//크기가 10
	vector<int> vec(10);
	//크기가 10, 모든 원소 5로 초기화
	vector<int> vec(10, 5);
	*/
	vector<int> vec = { 1,2,3,4,5 };
	vec.insert(vec.begin(), 0);//맨 앞에 새 원소 추가
	vector<int> vec;	//빈 벡터
	vec.push_back(1);	//맨 뒤에 1 추가
	vec.push_back(2);	//2 추가
	vec.insert(vec.begin(), 0);	//맨 앞에 0 추가
	vec.insert(find(vec.begin(), vec.end(), 1), 4);	//1 앞에 4 추가 {0, 4, 1, 2}

	//push_back, insert는 원소 임시 생성 후 벡터로 복사. 
	//삽입 위치에 곧바로 벡터 생성하는 emplace_back(), emplace()가 유용하다

	vector<int> vec2 = { 0,1,2,3,4,5,6,7,8,9 };
	vec2.pop_back();	//마지막 원소 제거
	vec2.erase(vec.begin());	//처음 원소 제거
	vec2.erase(vec2.begin() + 1, vec2.begin() + 4);	//1번쨰부터 4번째 앞까지 제거

	//claer(): 모든 원소 제거
	//reverse(capacity): 사용할 용량 지정
	//shrink_to)fit(): 여분의 메모리 공간 해제 용도
	//vector는 할당자 전달 가능
}