/*�л� ���� ���� ���α׷�
�� ���� std::array Ȱ��� �˾ƺ���*/
#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;

//Ŭ���� ���ø�
template <typename T>
class dynamic_array
{
	T* data;
	size_t n;
public:
	//�迭 ũ�⸦ ���ڷ� �޴� ������
	dynamic_array(int n)
	{
		this->n = n;
		data = new T[n];
	}
	//���� ������
	dynamic_array(const dynamic_array<T>& other)
	{
		n = other.n;
		data = new T[n];

		for (int i = 0; i < n; i++)
			data[i] = other[i];
	}
	//��� �����Ϳ� �����ϱ� ���� [] ������, at() �ۼ�
	T& operator[](int index)
	{
		return data[index];
	}

	const T& operator[](int index) const
	{
		return data[index];
	}

	T& at(int index)
	{
		if (index < n)
			return data[index];
		throw "Index out of range";
		//"throw�� ���� ������ '����' �����ʹ�, 
		//'����' �����͸� ���δ� try ��Ͽ� ���ؼ� ������ �Ǿ� �̾ �����ϴ� catch ��Ͽ� ���� ó���ȴ�."
	}

	//�迭�� ũ�⸦ ��ȯ�ϴ� size() �Լ�
	size_t size() const
	{
		return n;
	}
	//�Ҹ���
	~dynamic_array()
	{
		delete[] data;	//�޸� ���� ����
	}
	//�迭 ���Ҹ� ��ȸ�� �� ����� �ݺ��� ���� �Լ�
	T* begin() { return data; }
	const T* begin() const { return data; }
	T* end() { return data + n; }
	const T* end() const { return data + n; }

	//�� �迭�� �ϳ��� ��ġ�� + ������ �Լ� friend�� ����
	//friend�� ����� �ٸ� Ŭ������ private �� protected ����� ����
	friend dynamic_array<T> operator+(const dynamic_array<T>& arr1, dynamic_array<T>& arr2)
	{
		dynamic_array<T> result(arr1.size() + arr2.size());
		copy(arr1.begin(), arr1.end(), result.begin());
		copy(arr2.begin(), arr2.end(), result.begin() + arr1.size());

		return result;
	}
	//�迭�� ����� ��� �����͸� ���ڿ��� ��ȯ�ϴ� �Լ�
	string to_string(const string& sep = ", ")	//sep: ������ ������ ���� ���ڿ�
	{
		if (n == 0)
			return "";
		/*
		istringstream: string�� �Է¹޾� �ٸ� �������� �ٲ��ִ� ����� �Ѵ�.
		ostringstream: string�� �����ϰų�, Ư�� ��ġ�� ���ڿ��� ��ȯ�ϱ� ���� ����Ѵ�.
		stringstream: ������ �ִ� string���� ����� \n�� ������ ���ڿ��� ���ʴ�� ������ ������ �����Ѵ�.
		*/
		ostringstream os;
		//os�� �迭�� ù ���� ����
		os << data[0];

		for (int i = 1; i < n; i++)
			//"data0, data1, data2, ..."�� �������� �߰�
			os << sep << data[i];
		//������ ���ڿ� ��ȯ
		return os.str();
	}
};

//�л� ������ ������ ����ü
struct student
{
	string name;
	int standard;
};

//ostream: ����� �����ϴ� Ŭ����
//https://ansohxxn.github.io/cpp/chapter9-3/

ostream& operator<<(ostream& os, const student& s)
{
	return (os << "[" << s.name << ", " << s.standard << "]");
}

int main()
{
	int nStudents;
	cout << "1�� �л� ���� �Է��ϼ���: ";
	cin >> nStudents;

	dynamic_array<student> class1(nStudents);
	for (int i = 0; i < nStudents; i++)
	{
		string name;
		int standard;
		cout << i + 1 << "��° �л� �̸��� ���̸� �Է��ϼ���: ";
		cin >> name >> standard;
		class1[i] = student{ name, standard };
	}

	//out of range
	try
	{
		//class1[nStudents] = student {"John", 8};	//������ �� ���� ����. ������ ����
		class1.at(nStudents) = student{ "John" , 8 };	//���� �߻�
	}
	catch (...)	//try���� �߻��� ��� ���� catch
	{
		cout << "���� �߻�!" << endl;
	}

	//���� ����
	auto class2 = class1;
	cout << "1���� �����Ͽ� 2�� ����: " << class2.to_string() << endl;

	//�� �б��� ���ļ� �� �б� ����
	auto class3 = class1 + class2;
	cout << "1�ݰ� 2���� ���� 3�� ����: " << class3.to_string() << endl;
}