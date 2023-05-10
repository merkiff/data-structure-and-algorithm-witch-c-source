/*학생 정보 관리 프로그램
을 통해 std::array 활용법 알아보기*/
#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;

//클래스 템플릿
template <typename T>
class dynamic_array
{
	T* data;
	size_t n;
public:
	//배열 크기를 인자로 받는 생성자
	dynamic_array(int n)
	{
		this->n = n;
		data = new T[n];
	}
	//복사 생성자
	dynamic_array(const dynamic_array<T>& other)
	{
		n = other.n;
		data = new T[n];

		for (int i = 0; i < n; i++)
			data[i] = other[i];
	}
	//멤버 데이터에 접근하기 위한 [] 연산자, at() 작성
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
		//"throw에 의해 던져진 '예외' 데이터는, 
		//'예외' 데이터를 감싸는 try 블록에 의해서 감지가 되어 이어서 등장하는 catch 블록에 의해 처리된다."
	}

	//배열의 크기를 반환하는 size() 함수
	size_t size() const
	{
		return n;
	}
	//소멸자
	~dynamic_array()
	{
		delete[] data;	//메모리 누수 방지
	}
	//배열 원소를 순회할 때 사용할 반복자 관련 함수
	T* begin() { return data; }
	const T* begin() const { return data; }
	T* end() { return data + n; }
	const T* end() const { return data + n; }

	//두 배열을 하나로 합치는 + 연산자 함수 friend로 정의
	//friend로 선언된 다른 클래스의 private 및 protected 멤버에 접근
	friend dynamic_array<T> operator+(const dynamic_array<T>& arr1, dynamic_array<T>& arr2)
	{
		dynamic_array<T> result(arr1.size() + arr2.size());
		copy(arr1.begin(), arr1.end(), result.begin());
		copy(arr2.begin(), arr2.end(), result.begin() + arr1.size());

		return result;
	}
	//배열에 저장된 모든 데이터를 문자열로 반환하는 함수
	string to_string(const string& sep = ", ")	//sep: 데이터 구분을 위한 문자열
	{
		if (n == 0)
			return "";
		/*
		istringstream: string을 입력받아 다른 형식으로 바꿔주는 기능을 한다.
		ostringstream: string을 조립하거나, 특정 수치를 문자열로 변환하기 위해 사용한다.
		stringstream: 가지고 있는 string에서 공백과 \n을 제외한 문자열을 차례대로 빼내는 역할을 수행한다.
		*/
		ostringstream os;
		//os에 배열의 첫 원소 삽입
		os << data[0];

		for (int i = 1; i < n; i++)
			//"data0, data1, data2, ..."의 형식으로 추가
			os << sep << data[i];
		//조립한 문자열 반환
		return os.str();
	}
};

//학생 정보를 저장할 구조체
struct student
{
	string name;
	int standard;
};

//ostream: 출력을 수행하는 클래스
//https://ansohxxn.github.io/cpp/chapter9-3/

ostream& operator<<(ostream& os, const student& s)
{
	return (os << "[" << s.name << ", " << s.standard << "]");
}

int main()
{
	int nStudents;
	cout << "1반 학생 수를 입력하세요: ";
	cin >> nStudents;

	dynamic_array<student> class1(nStudents);
	for (int i = 0; i < nStudents; i++)
	{
		string name;
		int standard;
		cout << i + 1 << "번째 학생 이름과 나이를 입력하세요: ";
		cin >> name >> standard;
		class1[i] = student{ name, standard };
	}

	//out of range
	try
	{
		//class1[nStudents] = student {"John", 8};	//예상할 수 없는 동작. 비정상 종료
		class1.at(nStudents) = student{ "John" , 8 };	//예외 발생
	}
	catch (...)	//try에서 발생한 모든 예외 catch
	{
		cout << "에외 발생!" << endl;
	}

	//깊은 복사
	auto class2 = class1;
	cout << "1반을 복사하여 2반 생성: " << class2.to_string() << endl;

	//두 학급을 합쳐서 새 학급 생성
	auto class3 = class1 + class2;
	cout << "1반과 2반을 합쳐 3반 생성: " << class3.to_string() << endl;
}