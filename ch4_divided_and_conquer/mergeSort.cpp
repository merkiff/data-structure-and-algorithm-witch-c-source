#include <iostream>
#include <vector>

template <typename T>
std::vector<T> merge(std::vector<T> &arr1, std::vector<T> &arr2)
/*두 개의 벡터를 병합하는 함수
T 타입의 벡터 두 개를 참조로 받고, 두 벡터의 원소를 하나로 병합한 새로운 벡터
반환 반한되는 벡터는 오름차순으로 정렬*/
{
  std::vector<T> merged;

  auto iter1 = arr1.begin();
  auto iter2 = arr2.begin();

  while (iter1 != arr1.end() && iter2 != arr2.end()) {
    // 반복자가 종료되기 전까지
    if (*iter1 < *iter2) {
      // iter1의 원소가 더 작으면
      merged.emplace_back(*iter1); // 결과값에 iter1의 원소 저장
      iter1++;
    } else {
      // iter2가 더 크면
      merged.emplace_back(*iter2); // 결과값에 iter2의 원소 저장
      iter2++;
    }
  }
  if (iter1 != arr1.end()) {
    // 아직 배열이 끝나지 않았다면 나머지 추가
    for (; iter1 != arr1.end(); iter1++)
      merged.emplace_back(*iter1);
  } else {
    for (; iter2 != arr2.end(); iter2++)
      merged.emplace_back(*iter2);
  }

  return merged;
}

template <typename T>
std::vector<T> merge_sort(std::vector<T> arr)
/*재귀적으로 병합 정렬 구현*/
{
  if (arr.size() > 1) {                // 사이즈가 1보다 큰 배열은
    auto mid = size_t(arr.size() / 2); // 반으로 쪼개기
    auto left_half =
        merge_sort<T>(std::vector<T>(arr.begin(), arr.begin() + mid));
    auto right_half =
        merge_sort<T>(std::vector<T>(arr.begin() + mid, arr.end()));

    return merge<T>(left_half, right_half); // 좌우 배열 합쳐서 반환
  }

  return arr;
}

template <typename T>
void print_vector(std::vector<T> arr)
/*벡터에 포함된 모든 데이터 출력*/
{
  for (auto i : arr)
    std::cout << i << " ";
  std::cout << std::endl;
}

void run_merge_sort_test()
/*병합 정렬 테스트 함수*/
{
  std::vector<int> S1{45, 1, 3, 1, 2, 3, 45, 5, 1, 2, 44, 5, 7};
  std::vector<float> S2{45.6f, 1.0f, 3.8f, 1.01f, 2.2f, 3.9f, 45.3f,
                        5.5f,  1.0f, 2.0f, 44.0f, 5.0f, 7.0f};
  std::vector<double> S3{45.6, 1.0, 3.8, 1.01, 2.2, 3.9, 45.3,
                         5.5,  1.0, 2.0, 44.0, 5.0, 7.0};
  std::vector<char> C{'b', 'z', 'a', 'e', 'f', 't', 'q', 'u', 'y'};

  std::cout << "정렬되지 않은 벡터: " << std::endl;
  print_vector<int>(S1);
  print_vector<float>(S2);
  print_vector<double>(S3);
  print_vector<char>(C);
  std::cout << std::endl;

  auto sorted_S1 = merge_sort<int>(S1);
  auto sorted_S2 = merge_sort<float>(S2);
  auto sorted_S3 = merge_sort<double>(S3);
  auto sorted_C = merge_sort<char>(C);

  std::cout << "병합 정렬에 의해 정렬된 벡터: " << std::endl;
  print_vector<int>(sorted_S1);
  print_vector<float>(sorted_S2);
  print_vector<double>(sorted_S3);
  print_vector<char>(sorted_C);
  std::cout << std::endl;
}

int main() {
  run_merge_sort_test();
  return 0;
}