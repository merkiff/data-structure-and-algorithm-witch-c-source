#include <iostream>
#include <vector>

using uint = unsigned int;	//Ÿ�� �̸� ª�� �ٲٱ�

class hash_map
{
	std::vector<int> data;	
public:
	//������ ũ�⸦ ���ڷ� �޴� ������
	hash_map(size_t n)
	{
		data = std::vector<int>(n, 1);
	}

	//���� �Լ�
	//�ؽ� �浹 �ذ� x
	void insert(uint value)
	{
		int n = data.size();
		data[value % n] = value;	//�ؽ�
		std::cout << value << "��(��) �����߽��ϴ�." << std::endl;
	}

	//��� �Լ�
	bool find(uint value)
	{
		int n = data.size();
		return (data[value % n] == value);
	}

	//���� �Լ�
	void erase(uint value)
	{
		int n = data.size();
		if (data[value % n] == value)
		{
			data[value % n] = -1;
			std::cout << value << "��(��) �����߽��ϴ�." << std::endl;
		}
	}
};

int main()
{
	hash_map map(7);

	//��� ��� ����ϴ� ���� �Լ�
	auto print = [&](int value) {
		if (map.find(value))
			std::cout << "�ؽ� �ʿ��� " << value << "��(��) ã�ҽ��ϴ�.";
		else
			std::cout << "�ؽ� �ʿ��� " << value << "��(��) ã�� ���߽��ϴ�.";
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