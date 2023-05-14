/*�� ���� �ϳ��� �����͸� �Է�, ���� ������ ���������� ���� 
-> �����͸� ���� ������ �߾Ӱ��� ���*/
#include <iostream>
#include <queue>
#include <vector>

/*������ ���� �����̳�
new data < median: �ִ� ��(stores the larger half of the data.)
new data > median: �ּ� ��(stores the smaller half of the data.)
=> �ֻ�� ���Ҹ� �̿��� �߾Ӱ� ���*/
struct median
{
	//�켱���� ť�� ���� �� ����
	//top�� �켱������ ���� ����(���� ū ��)��, pop�� top ���Ҹ� ���� 
	std::priority_queue<int> maxHeap;
	std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;


	/*���� ���� �����͸� �����ϴ� �Լ�.*/
	void insert(int data)
	{
		//maxHeap�� ��� �ִ� ��� �� ������ ����Ʈ�� maxHeap�� �߰��˴ϴ�.
		//maxHeap�� �ִ� ���̹Ƿ� �׻� �������� �ִ� ������ �����մϴ�.
		if (maxHeap.size() == 0)
		{
			maxHeap.push(data);
			return;
		}

		//��� ���� ���� ��� �� �����ʹ� �߾Ӱ����� �۰ų� ������ maxHeap�� �߰��ǰ� �׷��� ������ minHeap�� �߰��˴ϴ�.
		//maxHeap�� �׻� �߾Ӱ����� ū ������ �ְ� minHeap�� �׻� �߾Ӱ����� ���� ������ �ֵ��� �ϱ� ���� ���Դϴ�.
		if (maxHeap.size() == minHeap.size())
		{
			if (data <= get())
				maxHeap.push(data);
			else
				minHeap.push(data);
			return;
		}

		//maxHeap�� ��Ұ� minHeap���� ���� ��� �� �����ʹ� �߾Ӱ����� ũ�� minHeap�� �߰��ǰ� �׷��� ������ maxHeap�� �߰��˴ϴ�.
		// �̰��� maxHeap�� �׻� �������� �߾Ӱ����� ū ������ �ְ� minHeap�� �׻� �������� �߾Ӱ����� ���� ������ �ֵ��� �ϱ� ���� ���Դϴ�.
		if (maxHeap.size() < minHeap.size())
		{
			//�� �̻� minHeap�� top�� �߾Ӱ��� �ƴ�
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

		//new data < median: �ִ� ��
		if (data < get())
		{
			minHeap.push(maxHeap.top());
			maxHeap.pop();
			maxHeap.push(data);
		}
		else
			minHeap.push(data);
	}

	/*�߾Ӱ��� ���Ͽ� ��ȯ�ϴ� �Լ�*/
	double get()
	{
		//������ ������ ¦���� ��
		if (maxHeap.size() == minHeap.size())
			return (maxHeap.top() + minHeap.top()) / 2.0;
		
		//������ ������ Ȧ���� �� ���� �� ���� ���� �ֻ�� ���Ұ� �߾Ӱ��� �ȴ�
		if (maxHeap.size() < minHeap.size())
			return minHeap.top();

		//��������
		return maxHeap.top();
	}
};

int main()
{
	median med;
	
	med.insert(1);
	std::cout << "1 ���� �� �߾Ӱ�: " << med.get() << std::endl;

	med.insert(3);
	std::cout << "5 ���� �� �߾Ӱ�: " << med.get() << std::endl;

	med.insert(5);
	std::cout << "2 ���� �� �߾Ӱ�: " << med.get() << std::endl;

	med.insert(4);
	std::cout << "4 ���� �� �߾Ӱ�: " << med.get() << std::endl;

	/*med.insert(10);
	std::cout << "10 ���� �� �߾Ӱ�: " << med.get() << std::endl;

	med.insert(40);
	std::cout << "40 ���� �� �߾Ӱ�: " << med.get() << std::endl;*/

}