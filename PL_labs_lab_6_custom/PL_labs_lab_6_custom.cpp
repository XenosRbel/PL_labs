// PL_labs_lab_6_custom.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

using namespace std;

enum class Side
{
	left,
	right,
	none
};

class  BinaryTree
{
public:
	BinaryTree(int val, BinaryTree* parent);
	~BinaryTree();
	BinaryTree* parent;
	BinaryTree* left;
	BinaryTree* right;
	int val;
	void add(int val);
	BinaryTree* search(int val);
	int count(int c);
	void print_tree();
	bool remove(int val);
	int count_partial_nodes();

private:
	BinaryTree* search(BinaryTree* tree, int val);
	void print_tree(BinaryTree* start_node, Side side, string indent = "");
	int count_partial_nodes(BinaryTree* tree);
	void destroy_tree(BinaryTree* tree);
};

BinaryTree::BinaryTree(int val, BinaryTree* parent)
{
	this->val = val;
	this->parent = parent;
	this->left = NULL;
	this->right = NULL;
}

BinaryTree::~BinaryTree()
{
	destroy_tree(this->parent);
}

void BinaryTree::destroy_tree(BinaryTree* tree) {
	if (tree != NULL) {
		destroy_tree(tree->left);
		destroy_tree(tree->right);
		delete tree;
	}
}

void BinaryTree::add(int val)
{

	if (val < this->val) {
		if (this->left != NULL) {
			this->left->add(val);
		}
		else {
			this->left = new BinaryTree(val, this);
		}
	}
	else if (val >= this->val) {
		if (this->right != NULL) {
			this->right->add(val);
		}
		else {
			this->right = new BinaryTree(val, this);
		}
	}
	/*if ((val < this->val))
	{
		if (this->left == NULL)
		{
			this->left = new BinaryTree(val, this);
		}
		else if (this->left != NULL)
		{
			this->left->add(val);
		}
	}
	else
	{
		if (this->right == NULL)
		{
			this->right = new BinaryTree(val, this);
		}
		else if (this->right != NULL)
		{
			this->right->add(val);
		}
	}*/
}

BinaryTree* BinaryTree::search(int val)
{
	return search(this, val);
}

int BinaryTree::count(int c)
{
	if ((this->left != NULL) && (this->right != NULL)) c++;
	if (this->left != NULL) this->left->count(c);
	if (this->right != NULL) this->right->count(c);
	return c;
}

void BinaryTree::print_tree()
{
	print_tree(this, Side::none);
}

bool BinaryTree::remove(int val)
{
	BinaryTree* tree = this->search(val);
	if (tree == NULL) return false;

	BinaryTree* current_tree;

	if (tree == this)
	{
		if (tree->right != NULL)
		{
			current_tree = tree->right;
		}
		else
		{
			current_tree = tree->left;
		}

		while (current_tree->left != NULL)
		{
			current_tree = current_tree->left;
		}

		int temp = current_tree->val;
		this->remove(temp);
		tree->val = temp;

		return true;
	}

	if (tree->left == NULL && tree->right == NULL && tree->parent != NULL)
	{
		if (tree == tree->parent->left)
		{
			tree->parent->left = NULL;
		}
		else
		{
			tree->parent->right = NULL;
		}
		return true;
	}

	//Удаление узла, имеющего левое поддерево, но не имеющее правого поддерева
	if (tree->left != NULL && tree->right == NULL)
	{
		//Меняем родителя
		tree->left->parent= tree->parent;

		if (tree == tree->parent->left)
		{
			tree->parent->left = tree->left;
		}
		else if (tree == tree->parent->right)
		{
			tree->parent->right = tree->left;
		}
		return true;
	}

	//Удаление узла, имеющего правое поддерево, но не имеющее левого поддерева
	if (tree->left == NULL && tree->right != NULL)
	{
		tree->right->parent = tree->parent;

		if (tree == tree->parent->left)
		{
			tree->parent->left = tree->right;
		}
		else if (tree == tree->parent->right)
		{
			tree->parent->right = tree->right;
		}
		return true;
	}

	//Удаляем узел, имеющий поддеревья с обеих сторон
	if (tree->right != NULL && tree->left != NULL)
	{
		current_tree = tree->right;

		while (current_tree->left != NULL)
		{
			current_tree = current_tree->left;
		}

		//Если самый левый элемент является первым потомком
		if (current_tree->parent == tree)
		{
			current_tree->left = tree->left;
			tree->left->parent = current_tree;
			current_tree->parent = tree->parent;

			if (tree == tree->parent->left)
			{
				tree->parent->left = current_tree;
			}
			else if (tree == tree->parent->right)
			{
				tree->parent->right = current_tree;
			}
			return true;
		}
		//Если самый левый элемент НЕ является первым потомком
		else
		{
			if (current_tree->right != NULL)
			{
				current_tree->right->parent = current_tree->parent;
			}

			current_tree->parent->left = current_tree->right;
			current_tree->right = tree->right;
			current_tree->left = tree->left;

			tree->left->parent = current_tree;
			tree->right->parent = current_tree;

			current_tree->parent = tree->parent;

			if (tree == tree->parent->left)
			{
				tree->parent->left= current_tree;
			}
			else if (tree == tree->parent->right)
			{
				tree->parent->right = current_tree;
			}

			return true;
		}
	}
	return false;
}

int BinaryTree::count_partial_nodes()
{
	return count_partial_nodes(this);
}

int BinaryTree::count_partial_nodes(BinaryTree* tree)
{
	int count_not_full = 0;

	if (tree->left == 0 || tree->right == 0)
	{
		count_not_full++;
	}

	if (tree->left != NULL)
	{
		count_not_full += count_partial_nodes(tree->left);
	}

	if (tree->right != NULL)
	{
		count_not_full += count_partial_nodes(tree->right);
	}

	return count_not_full;
}

BinaryTree* BinaryTree::search(BinaryTree* tree, int val)
{
	if (tree == NULL)
	{
		return NULL;
	}

	switch (val == tree->val)
	{
	case 1:
		return search(tree->right, val);
	case -1:
		return search(tree->left, val);
	case 0:
		return tree;
	default:
		return NULL;
	}
}

void BinaryTree::print_tree(BinaryTree* start_node, Side side, string indent)
{
	if (start_node != NULL)
	{
		string node_side = side == Side::none ? "+" : side == Side::left ? "L" : "R";
		cout << "" << indent << " [" << node_side << "]- " << start_node->val << "" << endl;
		indent += string(" ", 3);

		print_tree(start_node->left, Side::left, indent);
		print_tree(start_node->right, Side::right, indent);
	}
}

void print_menu()
{
	cout << "Введите команду:" << endl;
	cout << "Создание дерева - 1\n"
			"Добавление новой записи - 2\n"
			"Определить количество неполных узлов дерева - 3\n"
			"Вывод информации - 4\n"
			"Выход - \"-q\"\n" 
		<< endl;
}

int main()
{
	setlocale(LC_ALL, "russian");

	BinaryTree* binary_tree = NULL;

	string key = "";

	print_menu();

	while (key != "-q")
	{
		std::getline(std::cin, key);

		if (key == "1")
		{
			cout << "Введите корневой элемент:\t" << endl;

			int val;
			std::cin >> val;

			binary_tree = new BinaryTree(int(val), NULL);
		}

		if (key == "2")
		{
			cout << "Введите элемент:\t" << endl;

			int val;
			std::cin >> val;

			binary_tree->add(int(val));
		}
		if (key == "3")
		{
			int not_full_nodes = binary_tree->count_partial_nodes();

			std::cout << "Количество неполных узлов дерева:\t " << not_full_nodes << "." << std::endl;
		}
		if (key == "4")
		{
			binary_tree->print_tree();
		}
		if (key == "-d")
		{
			binary_tree = new BinaryTree(10, NULL);
			binary_tree->add(6);
			binary_tree->add(14);
			binary_tree->add(4);
			binary_tree->add(8);
			binary_tree->add(11);
			binary_tree->add(18);
			binary_tree->add(3);
			binary_tree->add(7);
		}
		if (key == "-h")
		if (key == "help")
		{
			print_menu();
		}

		cout << "Введите команду:" << endl;
	}

	delete(binary_tree);
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
