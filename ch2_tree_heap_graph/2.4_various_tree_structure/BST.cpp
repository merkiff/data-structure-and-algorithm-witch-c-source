#include <iostream>

struct node
{
	int data;
	node* left;
	node* right;
};

struct bst
{
	node* root = nullptr;

	node* find(int value)
	{
		return find_impl(root, value);
	}
private:
	/*원소 검색은 재귀적으로 동작하기 때문에 실제 구현은 findImpl() 함수에 따로 작성*/
	node* find_impl(node* current, int value)
	{
		if (!current)
		{
			std::cout << std::endl;
			return NULL;
		}

		if (current->data == value)
		{
			std::cout << value << "을(를) 찾았습니다." << std::endl;
			return current;
		}

		if (value < current->data) //value 값이 현재 노드 왼쪽에 있는 경우
		{
			std::cout << current->data << "에서 왼쪽으로 이동: ";
			return find_impl(current->left, value);
		}
		//value 값이 현재 노드 오른쪽에 있는 경우
		std::cout << current->data << "에서 오른쪽으로 이동: ";
		return find_impl(current->right, value);
	}
public:
	void insert(int value)
	{
		if (!root)
			root = new node{ value, NULL, NULL };
		else
			insert_impl(root, value);
	}
private:
	/*왼쪽, 오른쪽 중 어디에 삽입해야 하는지 확인
	삽입할 쪽이 비어 있으면 새노드 추가, 다른 노드가 있다면 삽입 함수 재귀 호출*/
	void insert_impl(node* current, int value)
	{
		if (value < current->data)
		{
			if (!current->left)
				current->left = new node{ value, NULL, NULL };
			else
				insert_impl(current->left, value);
		}
		else
		{
			if (!current->right)
				current->right = new node{ value, NULL, NULL };
			else
				insert_impl(current->right, value);
		}
	}
public:
	/*중위 순환 함수*/
	void inorder()
	{
		inorder_impl(root);
	}
private:
	void inorder_impl(node* start)
	{
		if (!start)
			return;
		inorder_impl(start->left);	//왼쪽 방문
		std::cout << start->data << " ";	//현재 노드 출력
		inorder_impl(start->right);	//오른쪽 방문
	}
public:
	/*후속 노드를 찾는 함수*/
	node* successor(node* start)
	{
		auto current = start->right;
		while (current && current->left)
			current = current->left;
		return current;
	}

	void deleteValue(int value)
	{
		root = delete_impl(root, value);
	}

private:
	/*특정 노드를 삭제하면 해당 노드의 부모 노드 포인터 조정
	부모 노드 포인터가 새로 가리켜야 할 노드의 주소를 반환하도록 설정
	delete는 표준에 정의된 키워드이므로 함수명 설정에 주의*/
	node* delete_impl(node* start, int value)
	{
		if (!start)
			return NULL;

		if (value < start->data)
			start->left = delete_impl(start->left, value);
		else if (value > start->data)
			start->right = delete_impl(start->right, value);
		else
		{
			if (!start->left)	//자식 노드가 전혀 없거나, 왼쪽 자식 노드만 없는 경우
			{
				auto tmp = start->right;
				delete start;
				return tmp;
			}
			if (!start->right)	//오른쪽 자식 노드만 없는 경우
			{
				auto tmp = start->left;
				delete start;
				return tmp;
			}

			//자식 노드가 둘 다 있는 경우
			auto succNode = successor(start);
			start->data = succNode->data;

			//오른쪽 서브 트리에서 후속(successor)을 찾아 삭제
			start->right = delete_impl(start->right, succNode->data);
		}

		return start;
	}
};

int main()
{
	bst tree;
	tree.insert(12);
	tree.insert(10);
	tree.insert(20);
	tree.insert(8);
	tree.insert(11);
	tree.insert(15);
	tree.insert(28);
	tree.insert(4);
	tree.insert(2);

	std::cout << "중위 순회: ";
	tree.inorder();	//BST의 모든 원소를 오름차순으로 출력합니다.
	std::cout << std::endl;
	
	tree.deleteValue(12);
	std::cout << "12를 삭제한 후 중위 순회: ";
	tree.inorder();
	std::cout << std::endl;

	if (tree.find(12))
		std::cout << "원소 12는 트리에 있습니다." << std::endl;
	else
		std::cout << "원소 12는 트리에 없습니다." << std::endl;
}