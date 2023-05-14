/*교재의 도시 네트워크를 그래프로 구성하고 인접 리스트로 저장하기*/
#include <iostream>
#include <vector>

enum class city :int
{
	MOSCOW, LONDON, SEOUL, SEATTLE, DUBAI, SYDNEY
};

std::ostream& operator<<(std::ostream& os, const city c)
{
	switch (c)
	{
	case city::LONDON:
		os << "런던";
		return os;
	case city::MOSCOW:
		os << "모스크바";
		return os;
	case city::SEOUL:
		os << "서울";
	case city::SEATTLE:
		os << "시애틀";
	case city::DUBAI:
		os << "두바이";
		return os;
	case city::SYDNEY:
		os << "시드니";
		return os;
	default:
		return os;
	}
}

/*데이터를 저장할 graph 구조체*/
struct graph
{
	//pair 클래스: 두 개의 연관된 데이터를 한 쌍으로 묶어서 표현 가능
	//<utility>에 있지만, <vector>, <algorithm>이 <utility> 포함하고 있음
	std::vector<std::vector<std::pair<int, int>>> data;

	graph(int n)
	{
		data = std::vector<std::vector<std::pair<int, int>>>(n, std::vector<std::pair<int, int>>());
	}

	/*엣지를 추가하는 함수. 인자는 도시 2개와 에지의 가중치(거리)*/
	void addEdge(const city c1, const city c2, int dis)
	{
		std::cout << "에지 추가: " << c1 << "-" << c2 << "=" << dis << std::endl;

		auto n1 = static_cast<int>(c1);
		auto n2 = static_cast<int>(c2);
		//양방향 엣지이므로 둘 다 추가
		data[n1].push_back({ n2, dis });
		data[n2].push_back({ n1, dis });
	}

	/*에지를 제거하는 함수*/
	void removeEdge(const city c1, const city c2)
	{
		std::cout << "에지 삭제: " << c1 << "-" << c2 << std::endl;
		auto n1 = static_cast<int>(c1);
		auto n2 = static_cast<int>(c2);
		//양방향 엣지이므로 둘 다 삭제
		std::remove_if(data[n1].begin(), data[n1].end(), [n2](const auto& pair) {
			return pair.first == n2;
			});
		std::remove_if(data[n2].begin(), data[n2].end(), [n1](const auto& pair) {
			return pair.first == n1;
			});
	}
};

int main()
{
	graph g(6);
	g.addEdge(city::LONDON, city::MOSCOW, 2500);
	g.addEdge(city::LONDON, city::SEOUL, 9000);
	g.addEdge(city::LONDON, city::DUBAI, 5500);
	g.addEdge(city::SEOUL, city::MOSCOW, 6600);
	g.addEdge(city::SEOUL, city::SEATTLE, 8000);
	g.addEdge(city::SEOUL, city::DUBAI, 7000);
	g.addEdge(city::SEOUL, city::SYDNEY, 8000);
	g.addEdge(city::SEOUL, city::MOSCOW, 8400);
	g.addEdge(city::SEATTLE, city::SYDNEY, 12000);
	g.addEdge(city::DUBAI, city::SYDNEY, 1200);

	g.addEdge(city::SEATTLE, city::LONDON, 8000);
	g.removeEdge(city::SEATTLE, city::LONDON);

	return 0;
}