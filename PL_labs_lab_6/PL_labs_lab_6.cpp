// PL_labs_lab_6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
// Вриант 20


#include <iostream>

using namespace std;


struct node {
	int value;
	node* left;
	node* right;
};

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
	~ BinaryTree();
	BinaryTree* parent;
	BinaryTree* left;
	BinaryTree* right;
	int val;
	void add(int val);
	BinaryTree* search(int val);
	int count(int c);
	void print_tree();
	bool remove(int val);

private:
	BinaryTree* search(BinaryTree* tree, int val);
	void print_tree(BinaryTree* start_node, Side side, string indent = "");
};

 BinaryTree:: BinaryTree(int val, BinaryTree* parent)
{
	 this->val = val;
	 this->parent = parent;
	 this->left = NULL;
	 this->right = NULL;
}

 BinaryTree::~ BinaryTree()
{
}

 void BinaryTree::add(int val)
 {
	 if ((val == this->val) < 0)
	 {
		 if (this->left == NULL)
		 {
			 this->left = new BinaryTree(val, this);
		 }
		 else if (this->left != NULL)
		 {
			 this->add(val);
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
	 }
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
	 return false;
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
		 cout << " " << indent << "\t" << node_side << "\t-" << start_node->val <<"" << endl;
		 indent += string(' ', 3);

		 print_tree(start_node->left, Side::left, indent);
		 print_tree(start_node->right, Side::right, indent);
	 }
 }

class btree {
public:
	btree();
	~btree();

	void insert(int key);
	node* search(int key);
	void destroy_tree();
	void inorder_print();
	void postorder_print();
	void preorder_print();
	int count_partial_nodes();

private:
	void destroy_tree(node* leaf);
	void insert(int key, node* leaf);
	node* search(int key, node* leaf);
	void inorder_print(node* leaf);
	void postorder_print(node* leaf);
	void preorder_print(node* leaf);
	int count_partial_nodes(node* leaf);

	node* root;
};


btree::btree() {
	root = NULL;
}

btree::~btree() {
	destroy_tree();
}

void btree::destroy_tree(node* leaf) {
	if (leaf != NULL) {
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}

void btree::insert(int key, node* leaf) {

	if (key < leaf->value) {
		if (leaf->left != NULL) {
			insert(key, leaf->left);
		}
		else {
			leaf->left = new node;
			leaf->left->value = key;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
		}
	}
	else if (key >= leaf->value) {
		if (leaf->right != NULL) {
			insert(key, leaf->right);
		}
		else {
			leaf->right = new node;
			leaf->right->value = key;
			leaf->right->right = NULL;
			leaf->right->left = NULL;
		}
	}

}

void btree::insert(int key) {
	if (root != NULL) {
		insert(key, root);
	}
	else {
		root = new node;
		root->value = key;
		root->left = NULL;
		root->right = NULL;
	}
}

node* btree::search(int key, node* leaf) {
	if (leaf != NULL) {
		if (key == leaf->value) {
			return leaf;
		}
		if (key < leaf->value) {
			return search(key, leaf->left);
		}
		else {
			return search(key, leaf->right);
		}
	}
	else {
		return NULL;
	}
}

node* btree::search(int key) {
	return search(key, root);
}

void btree::destroy_tree() {
	destroy_tree(root);
}

void btree::inorder_print() {
	inorder_print(root);
	cout << "\n";
}

void btree::inorder_print(node* leaf) {
	if (leaf != NULL) {
		inorder_print(leaf->left);
		cout << leaf->value << ",";
		inorder_print(leaf->right);
	}
}

void btree::postorder_print() {
	postorder_print(root);
	cout << "\n";
}

void btree::postorder_print(node* leaf) {
	if (leaf != NULL) {
		inorder_print(leaf->left);
		inorder_print(leaf->right);
		cout << leaf->value << ",";
	}
}

void btree::preorder_print() {
	preorder_print(root);
	cout << "\n";
}

int btree::count_partial_nodes()
{
	return count_partial_nodes(root);
}

int btree::count_partial_nodes(node* leaf)
{
	int count_not_full = 0;
	if (((leaf->left == NULL) || (leaf->right == NULL))
		&& (leaf->left != NULL) || (leaf->right == NULL))
	{
		count_not_full++;
	}

	if (leaf->left != NULL)
	{
		count_not_full += count_partial_nodes(leaf->left);
	}

	if (leaf->right != NULL)
	{
		count_not_full += count_partial_nodes(leaf->right);
	}

	return count_not_full;
}

void btree::preorder_print(node* leaf) {
	if (leaf != NULL) {
		cout << leaf->value << ",";
		inorder_print(leaf->left);
		inorder_print(leaf->right);
	}
}

int main() 
{
	setlocale(LC_ALL, "russian");

	btree* tree = new btree();

	tree->insert(10);
	tree->insert(6);
	tree->insert(14);
	tree->insert(5);
	tree->insert(8);
	tree->insert(11);
	tree->insert(18);
	tree->insert(3);
	tree->insert(7);

	tree->preorder_print();

	int not_full_nodes = tree->count_partial_nodes();

	std::cout << "Количество неполных узлов дерева:\t "<< not_full_nodes <<"." << std::endl;

	delete tree;
	
	BinaryTree* binary_tree;

	string key;

	binary_tree = new BinaryTree(8, NULL);
	binary_tree->add(3);
	binary_tree->add(10);
	binary_tree->add(1);
	binary_tree->add(6);
	binary_tree->add(4);
	binary_tree->add(7);
	binary_tree->add(14);
	binary_tree->add(16);

	binary_tree->print_tree();
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
