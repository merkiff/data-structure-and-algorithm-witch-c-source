#include <forward_list>
using namespace std;

int main()
{
	forward_list<int> fwd_list = { 1,2,3 };
	fwd_list.push_front(0);	//맨 앞에 0 추가
	auto it = fwd_list.begin();
	fwd_list.insert_after(it, 5);	//맨 처음 원소 뒤에 5 추가
	fwd_list.insert_after(it, 6);	//같은 위치에 6 추가
	fwd_list.pop_front();	//맨 앞 삭제
	auto it2 = fwd_list.begin();
	fwd_list.erase_after(it2);	//맨 앞 다음 원소 삭제
	fwd_list.erase_after(it2, fwd_list.end());	//맨 앞 다음부터 마지막까지 삭제
}