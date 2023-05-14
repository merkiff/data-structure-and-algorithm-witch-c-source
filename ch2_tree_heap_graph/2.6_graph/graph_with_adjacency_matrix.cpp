/*교재의 도시 네트워크를 그래프로 구성하고 인접 행렬로 저장하기*/
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
	std::vector<std::vector<int>> data;

	/*n개의 노드로 구성된 그래프를 구성하는 생성자. 비어있음*/
	graph(int n)
	{
		data.reserve(n);
		std::vector<int> row(n);
		std::fill(row.begin(), row.end(), -1);	//비어있는 엣지는 -1로 표현

		for (int i = 0; i < n; i++)
		{
			data.push_back(row);
		}
	}

	/*엣지를 추가하는 함수. 인자는 도시 2개와 에지의 가중치(거리)*/
	void addEdge(const city c1, const city c2, int dis)
	{
		std::cout << "에지 추가: " << c1 << "-" << c2 << "=" << dis << std::endl;

		auto n1 = static_cast<int>(c1);
		auto n2 = static_cast<int>(c2);
		//양방향 엣지이므로 둘 다 추가
		data[n1][n2] = dis;
		data[n2][n1] = dis;
	}
	/*에지를 제거하는 함수*/
	void removeEdge(const city c1, const city c2)
	{
		std::cout << "에지 삭제: " << c1 << "-" << c2 << std::endl;
		auto n1 = static_cast<int>(c1);
		auto n2 = static_cast<int>(c2);
		//양방향 엣지이므로 둘 다 삭제
		data[n1][n2] = -1;
		data[n2][n1] = -1;
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