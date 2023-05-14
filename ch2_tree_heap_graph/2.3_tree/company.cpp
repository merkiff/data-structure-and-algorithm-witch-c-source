#include <iostream>
#include <queue>

/*�� ������ �ִ� �� ���� ���� ������ �Ŵ��� �� �ִٰ� ���� -> ���� Ʈ��*/

/*���� Ʈ���� ���� �⺻ ����*/
struct node
{
	std::string position;	//��å
	node* first;
	node* second;
};

struct org_tree
{
	node* root;
	/*-��Ʈ ��带 �����ϴ� �Լ�. ��Ʈ ���� CEO
	-���ο� Ʈ���� ����� ���� �Լ�*/
	static org_tree create_org_structure(const std::string& pos)
	{
		org_tree tree;
		tree.root = new node{ pos, NULL, NULL };
		return tree;
	}
	/*Ư�� ��å �̸��� �ش��ϴ� ��带 ã�Ƽ� ��ȯ�ϴ� �Լ�*/
	static node* find(node* root, const std::string& value)
	{
		if (root == NULL)	//���� ��Ʈ ��� �˻�
			return NULL;
		if (root->position == value)	//���� ���� Ʈ�� �˻�
			return root;
		auto firstFound = org_tree::find(root->first, value);

		if (firstFound != NULL)	//������ ���� Ʈ�� �˻�
			return firstFound;

		return org_tree::find(root->second, value);
	}
	/*���� ������ �߰��ϴ� �Լ�
	����� ��å �̸��� ���� ������ ��å �̸��� ���ڷ�
	����� ��å�� �̹� Ʈ���� ����
	���Ҹ� ���������� �����ϸ� true, �����ϸ� false*/
	bool addSubordinate(const std::string& manager, const std::string& subordinate)
	{
		auto managerNode = org_tree::find(root, manager);

		if (!managerNode)
		{
			std::cout << manager << "��(��) ã�� �� �����ϴ�: " << std::endl;
			return false;
		}

		if (managerNode->first && managerNode->second)
		{
			std::cout << manager << " �Ʒ��� " << subordinate << "��(��) �߰��� �� �����ϴ�." << std::endl;
			return false;
		}
		if (!managerNode->first)
			managerNode->first = new node{ subordinate, NULL, NULL };
		else
			managerNode->second = new node{ subordinate, NULL, NULL };

	std::cout << manager << " �Ʒ��� " << subordinate << "��(��) �߰��߽��ϴ�." << std::endl;

		return true;
	}

	/*���� ���� ��ȸ(level order traversal)*/
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

	tree.addSubordinate("CEO", "�λ���");
	tree.addSubordinate("�λ���", "IT����");
	tree.addSubordinate("�λ���", "�����ú���");
	tree.addSubordinate("IT����", "��������");
	tree.addSubordinate("IT����", "�۰�������");
	tree.addSubordinate("�����ú���", "��������");
	tree.addSubordinate("�����ú���", "ȫ������");
	tree.addSubordinate("�λ���", "�繫����");

	org_tree::levelOrder(tree.root);	//���� ���� ��ȸ ����
}

/*���� ��ȸ(preorder traversal)*/
//static void preOrder(node* start)
//{
//	if (!start)
//		return;
//	std::cout << start->position << ", ";
//	preOrder(start->first);
//	preOrder(start->second);
//}
/*���� ��ȸ(in-order traversal)*/
//static void inOrder(node* start)
//{
//	if (!start)
//		return;
//	inOrder(start->first);
//	std::cout << start->position << ", ";
//	inOrder(start->second);
//}
///*���� ��ȸ*/
//static void postOrder(node* start)
//{
//	if (!start)
//		return;
//	postOrder(start->first);
//	postOrder(start->second);
//	std::cout << start->position << ", ";
//}

