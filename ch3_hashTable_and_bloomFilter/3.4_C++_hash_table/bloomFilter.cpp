#include <iostream>
#include <vector>

class bloom_filter {
  std::vector<bool> data;
  int nBits;

  //해시 함수 추가
  int hash(int num, int key)
  // num은 어떤 해시 함수를 사용할지 결정 => 해시 함수 여러 개 사용하지 않아도
  // 된다
  {
    switch (num) {
    case 0:
      return key % nBits;
    case 1:
      return (key / 7) % nBits;
    case 2:
      return (key / 11) % nBits;
    }
    return 0;
  }

public:
  bloom_filter(int n)
      : nBits(n)
  //생성자
  {
    data = std::vector<bool>(nBits, false);
  }

  void lookup(int key)
  /*필요한 모든 비트가 1로 설정되어 있는지 검사
  가변의 해시 함수를 사용하면 각각의 해시와 연관된 비트가 모두 1로
  설정되어있는지 반복문으로 확인 "있을 수 있음" -> false-positive 발생 떄문 */
  {
    bool result = data[hash(0, key)] & data[hash(1, key)] & data[hash(2, key)];

    if (result)
      std::cout << key << ": 있을 수 있음" << std::endl;
    else
      std::cout << key << ": 절대 없음" << std::endl;
  }

  void insert(int key) {
    data[hash(0, key)] = true;
    data[hash(1, key)] = true;
    data[hash(2, key)] = true;
    std::cout << key << "을(를) 삽입: ";

    for (auto a : data)
      std::cout << a << " ";
    std::cout << std::endl;
  }
};

int main() {
  bloom_filter bf(7);
  bf.insert(100);
  bf.insert(54);
  bf.insert(82);

  bf.lookup(5);
  bf.lookup(50);
  bf.lookup(20);
  bf.lookup(54);
}