#include <iostream>
#include <queue>

/*한 직원은 최대 두 명의 부하 직원을 거느릴 수 있다고 가정 -> 이진 트리*/

/*이진 트리를 위한 기본 구조*/
struct node
{
	std::string position;	//직책
	node* first;
	node* second;
};

struct org_tree
{
	node* root;
	/*-루트 노드를 생성하는 함수. 루트 노드는 CEO
	-새로운 트리를 만드는 정적 함수*/
	static org_tree create_org_structure(const std::string& pos)
	{
		org_tree tree;
		tree.root = new node{ pos, NULL, NULL };
		return tree;
	}
	/*특정 직책 이름에 해당하는 노드를 찾아서 반환하는 함수*/
	static node* find(node* root, const std::string& value)
	{
		if (root == NULL)	//먼저 루트 노드 검사
			return NULL;
		if (root->position == value)	//왼쪽 서브 트리 검사
			return root;
		auto firstFound = org_tree::find(root->first, value);

		if (firstFound != NULL)	//오른쪽 서브 트리 검사
			return firstFound;

		return org_tree::find(root->second, value);
	}
	/*부하 직원을 추가하는 함수
	상사의 직책 이름과 부하 직원의 직책 이름을 인자로
	상사의 직책은 이미 트리에 존재
	원소를 정상적으로 삽입하면 true, 실패하면 false*/
	bool addSubordinate(const std::string& manager, const std::string& subordinate)
	{
		auto managerNode = org_tree::find(root, manager);

		if (!managerNode)
		{
			std::cout << manager << "을(를) 찾을 수 없습니다: " << std::endl;
			return false;
		}

		if (managerNode->first && managerNode->second)
		{
			std::cout << manager << " 아래에 " << subordinate << "을(를) 추가할 수 없습니다." << std::endl;
			return false;
		}
		if (!managerNode->first)
			managerNode->first = new node{ subordinate, NULL, NULL };
		else
			managerNode->second = new node{ subordinate, NULL, NULL };

	std::cout << manager << " 아래에 " << subordinate << "을(를) 추가했습니다." << std::endl;

		return true;
	}

	/*레벨 순서 순회(level order traversal)*/
	static void levelOrder(node* start)
	{
		if (!start)
			return;

		std::queue<node*> q;
		q.push(start);

		while (!q.empty())
		{
			int size = q.size();
			for (int i = 0; i < size; i++)
			{
				auto current = q.front();
				q.pop();

				std::cout << current->position << ", ";
				if (current->first)
					q.push(current->first);
				if (current->second)
					q.push(current->second);
			}

			std::cout << std::endl;
		}
	}
};

int main()
{
	auto tree = org_tree::create_org_structure("CEO");

	tree.addSubordinate("CEO", "부사장");
	tree.addSubordinate("부사장", "IT부장");
	tree.addSubordinate("부사장", "마케팅부장");
	tree.addSubordinate("IT부장", "보안팀장");
	tree.addSubordinate("IT부장", "앱개발팀장");
	tree.addSubordinate("마케팅부장", "물류팀장");
	tree.addSubordinate("마케팅부장", "홍보팀장");
	tree.addSubordinate("부사장", "재무부장");

	org_tree::levelOrder(tree.root);	//레벨 순서 조회 실행
}

/*전위 순회(preorder traversal)*/
//static void preOrder(node* start)
//{
//	if (!start)
//		return;
//	std::cout << start->position << ", ";
//	preOrder(start->first);
//	preOrder(start->second);
//}
/*중위 순회(in-order traversal)*/
//static void inOrder(node* start)
//{
//	if (!start)
//		return;
//	inOrder(start->first);
//	std::cout << start->position << ", ";
//	inOrder(start->second);
//}
///*후위 순회*/
//static void postOrder(node* start)
//{
//	if (!start)
//		return;
//	postOrder(start->first);
//	postOrder(start->second);
//	std::cout << start->position << ", ";
//}

