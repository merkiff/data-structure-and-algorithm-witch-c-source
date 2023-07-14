#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>

bool linear_search(int N, std::vector<int> &S)
/*선형 검색 함수*/
{
    for (auto i : S)
    {
        if (i == N)
            return true;
    }

    return false;
}

/*부동소수점 숫자로 구성된 벡터를 검색하려면 함수 원형 다음과 같이 변경
bool linear_search(float N, std::vector<float>&S)
bool binary_search(float N, std::vector<float>&S)*/

bool binary_search(int N, std::vector<int> &S)
{
    auto first = S.begin();
    auto last = S.end();

    while (true)
    {
        //현재 검색 범위의 중간 원소를 mid_element에 저장
        auto range_length = std::distance(first, last);
        auto mid_element_index = static_cast<size_t>(std::floor(range_length / 2.0));
        auto mid_element_iter = first + mid_element_index;
        auto mid_element = *mid_element_iter;
        // mid_element와 N을 비교
        if (mid_element == N)
            return true;
        else if (mid_element > N)
            last = mid_element_iter;
        if (mid_element < N)
            first = mid_element_iter + 1;
        //현재 검색 범위에 하나의 원소만 남아 있다면 false를 반환
        if (range_length == 1)
            return false;
    }
}

void run_small_search_test()
/*작은 크기의 배열에서 검색을 수행하는 테스트함수*/
{
    auto N = 2;
    std::vector<int> S{1, 3, 2, 4, 5, 7, 9, 8, 6};
    std::sort(S.begin(), S.end());

    if (linear_search(N, S))
        std::cout << "선형 검색으로 원소를 찾았습니다." << std::endl;
    else
        std::cout << "선형 검색으로 원소를 찾지 못했습니다." << std::endl;

    if (binary_search(N, S))
        std::cout << "선형 검색으로 원소를 찾았습니다." << std::endl;
    else
        std::cout << "선형 검색으로 원소를 찾지 못했습니다." << std::endl;
}

void run_large_search_test(int size, int N)
/*큰 배열에서 검색을 수행하는 테스트 함수*/
{
    std::vector<int> S;
    std::random_device rd;
    std::mt19937 rand(rd());

    //[1, size] 범위에서 정수 난수 발생
    std::uniform_int_distribution<std::mt19937::result_type> uniform_dist(1, size);

    // S에 난수 추가
    for (auto i = 0; i < size; i++)
        S.push_back(uniform_dist(rand));

    std::sort(S.begin(), S.end());

    //검색 시간 측정 시작
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    bool search_result = binary_search(N, S);

    // 검색 시간 측정 종료
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    auto diff = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
    std::cout << "이진 검색 수행 시간: " << diff.count() << std::endl;

    if (search_result)
        std::cout << "원소를 찾았습니다." << std::endl;
    else
        std::cout << "원소를 찾지 못했습니다." << std::endl;
}

int main()
{
    run_small_search_test();
    //난수 벡터 중 36543 찾기
    run_large_search_test(10000, 36543);
    run_large_search_test(100000, 36543);
    run_large_search_test(1000000, 36543);

    return 0;
}