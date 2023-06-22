#include <iostream>
#include <vector>

using uint = unsigned int;	//타입 이름 짧게 바꾸기

class hash_map
{
	std::vector<int> data;	
public:
	//데이터 크기를 인자로 받는 생성자
	hash_map(size_t n)
	{
		data = std::vector<int>(n, 1);
	}

	//삽입 함수
	//해시 충돌 해결 x
	void insert(uint value)
	{
		int n = data.size();
		data[value % n] = value;	//해싱
		std::cout << value << "을(를) 삽입했습니다." << std::endl;
	}

	//룩업 함수
	bool find(uint value)
	{
		int n = data.size();
		return (data[value % n] == value);
	}

	//삭제 함수
	void erase(uint value)
	{
		int n = data.size();
		if (data[value % n] == value)
		{
			data[value % n] = -1;
			std::cout << value << "을(를) 삭제했습니다." << std::endl;
		}
	}
};

int main()
{
	hash_map map(7);

	//룩업 결과 출력하는 람다 함수
	auto print = [&](int value) {
		if (map.find(value))
			std::cout << "해시 맵에서 " << value << "을(를) 찾았습니다.";
		else
			std::cout << "해시 맵에서 " << value << "을(를) 찾지 못했습니다.";
		std::cout << std::endl;
	};

	map.insert(2);
	map.insert(25);
	map.insert(10);
	print(25);

	map.insert(100);
	print(100);
	print(2);

	map.erase(25);
}