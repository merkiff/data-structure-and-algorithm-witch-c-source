/*한 번에 하나의 데이터를 입력, 같은 과정을 연속적으로 수행 
-> 데이터를 받을 때마다 중앙값을 계산*/
#include <iostream>
#include <queue>
#include <vector>

/*데이터 저장 컨테이너
new data < median: 최대 힙(stores the larger half of the data.)
new data > median: 최소 힙(stores the smaller half of the data.)
=> 최상단 원소를 이용해 중앙값 계산*/
struct median
{
	//우선순위 큐를 통한 힙 구현
	//top은 우선순위가 높은 원소(가장 큰 값)를, pop은 top 원소를 제거 
	std::priority_queue<int> maxHeap;
	std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;


	/*새로 들어온 데이터를 저장하는 함수.*/
	void insert(int data)
	{
		//maxHeap이 비어 있는 경우 새 데이터 포인트는 maxHeap에 추가됩니다.
		//maxHeap은 최대 힙이므로 항상 데이터의 최대 절반을 저장합니다.
		if (maxHeap.size() == 0)
		{
			maxHeap.push(data);
			return;
		}

		//요소 수가 같은 경우 새 데이터는 중앙값보다 작거나 같으면 maxHeap에 추가되고 그렇지 않으면 minHeap에 추가됩니다.
		//maxHeap에 항상 중앙값보다 큰 절반이 있고 minHeap에 항상 중앙값보다 작은 절반이 있도록 하기 위한 것입니다.
		if (maxHeap.size() == minHeap.size())
		{
			if (data <= get())
				maxHeap.push(data);
			else
				minHeap.push(data);
			return;
		}

		//maxHeap에 요소가 minHeap보다 적은 경우 새 데이터는 중앙값보다 크면 minHeap에 추가되고 그렇지 않으면 maxHeap에 추가됩니다.
		// 이것은 maxHeap에 항상 데이터의 중앙값보다 큰 절반이 있고 minHeap에 항상 데이터의 중앙값보다 작은 절반이 있도록 하기 위한 것입니다.
		if (maxHeap.size() < minHeap.size())
		{
			//더 이상 minHeap의 top이 중앙값이 아님
			if (data > get())
			{
				maxHeap.push(minHeap.top());
				minHeap.pop();
				minHeap.push(data);
			}
			else
				maxHeap.push(data);
			return;
		}

		//new data < median: 최대 힙
		if (data < get())
		{
			minHeap.push(maxHeap.top());
			maxHeap.pop();
			maxHeap.push(data);
		}
		else
			minHeap.push(data);
	}

	/*중앙값을 구하여 반환하는 함수*/
	double get()
	{
		//데이터 개수가 짝수일 때
		if (maxHeap.size() == minHeap.size())
			return (maxHeap.top() + minHeap.top()) / 2.0;
		
		//데이터 개수가 홀수일 때 수가 더 많은 쪽의 최상단 원소가 중앙값이 된다
		if (maxHeap.size() < minHeap.size())
			return minHeap.top();

		//마찬가지
		return maxHeap.top();
	}
};

int main()
{
	median med;
	
	med.insert(1);
	std::cout << "1 삽입 후 중앙값: " << med.get() << std::endl;

	med.insert(3);
	std::cout << "5 삽입 후 중앙값: " << med.get() << std::endl;

	med.insert(5);
	std::cout << "2 삽입 후 중앙값: " << med.get() << std::endl;

	med.insert(4);
	std::cout << "4 삽입 후 중앙값: " << med.get() << std::endl;

	/*med.insert(10);
	std::cout << "10 삽입 후 중앙값: " << med.get() << std::endl;

	med.insert(40);
	std::cout << "40 삽입 후 중앙값: " << med.get() << std::endl;*/

}