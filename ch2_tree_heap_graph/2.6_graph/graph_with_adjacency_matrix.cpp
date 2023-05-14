/*������ ���� ��Ʈ��ũ�� �׷����� �����ϰ� ���� ��ķ� �����ϱ�*/
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
		os << "����";
		return os;
	case city::MOSCOW:
		os << "��ũ��";
		return os;
	case city::SEOUL:
		os << "����";
	case city::SEATTLE:
		os << "�þ�Ʋ";
	case city::DUBAI:
		os << "�ι���";
		return os;
	case city::SYDNEY:
		os << "�õ��";
		return os;
	default:
		return os;
	}
}

/*�����͸� ������ graph ����ü*/
struct graph
{
	std::vector<std::vector<int>> data;

	/*n���� ���� ������ �׷����� �����ϴ� ������. �������*/
	graph(int n)
	{
		data.reserve(n);
		std::vector<int> row(n);
		std::fill(row.begin(), row.end(), -1);	//����ִ� ������ -1�� ǥ��

		for (int i = 0; i < n; i++)
		{
			data.push_back(row);
		}
	}

	/*������ �߰��ϴ� �Լ�. ���ڴ� ���� 2���� ������ ����ġ(�Ÿ�)*/
	void addEdge(const city c1, const city c2, int dis)
	{
		std::cout << "���� �߰�: " << c1 << "-" << c2 << "=" << dis << std::endl;

		auto n1 = static_cast<int>(c1);
		auto n2 = static_cast<int>(c2);
		//����� �����̹Ƿ� �� �� �߰�
		data[n1][n2] = dis;
		data[n2][n1] = dis;
	}
	/*������ �����ϴ� �Լ�*/
	void removeEdge(const city c1, const city c2)
	{
		std::cout << "���� ����: " << c1 << "-" << c2 << std::endl;
		auto n1 = static_cast<int>(c1);
		auto n2 = static_cast<int>(c2);
		//����� �����̹Ƿ� �� �� ����
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