#include <iostream>

struct Node {
  int val;
  Node* next;
};

// Инициализации элемента односвязного списка нулями

void init(Node* node)
{
	node->val = 0;
	node->next = NULL;
}

// Отображения односвязного списка на экран
void show(Node* head)
{
	Node *print = head;
	while (print != NULL)
	{
		std::cout << print->val << " ";
		print = print->next;
	}
	std::cout << "\n";
}

// Добавления элемента в односвязный список
void pushNode(Node* head,Node* node) 
{
	Node* p = head;
	while (p->next != NULL) 
	p = p->next;
	p->next = new Node;
	p = p->next;
	p->val = node->val;
	p->next = NULL;	
}


// Написать функцию инициализации size элементов списка заданным значением val.
void initList(Node* head, int size, int val)  {

}

// Написать функцию копирования элементов массива source в новый массив dest
void copyMas(Node* source, Node* dest) {

}
  

// Написать функцию сравнение списков source и dest. Если списки равны 0, если не равны -1
int compareMas(Node* source, Node* dest)
{
	Node *list1 = source;
	Node *list2 = dest;
	int a = 0;
	while ((list1 != NULL) and (list2 != NULL))
	{
		if(list1->val != list2->val)
		{
			a = -1;
		}
		list1 = list1->next;
		list2 = list2->next;
	}
  return a;
}


// Написать функцию удаления со сдвигом влево n-го элемента списка.
void deleteList(Node* head,int n) {

}


// Написать функцию сдвига значений вправо на n-элементов с заполнением крайних элементов нулями
void rShiftList(Node* head,int n) {

}



// Написать функцию сдвига значений влево на n-элементов с заполнением крайних элементов нулями.
void lShiftList(Node* head,int n) {

}


//Написать функцию сдвига значений влево на n-элементов с переносом вытесненных элементов в конец
void lRoundShiftMas(Node* head,int n, int size) {

}


// Написать функцию вычисления среднего значения элементов списка.
int averageList(Node* head, int size) {
  return 0;
}



// Написать функцию вычисления средне квадратического отклонения элементов списка.
int skoFromList(Node* head, int size) {
  return 0;
}

int testCompare()
{
	Node *source = new Node;
	init (source);
	Node *dest = new Node;
	init (dest);
	if (compareMas(source,dest) == 0)
	return -1;
	else
	return 0;
}

int testPush()
{
	Node *head = new Node;
	init(head);
	Node node{1};
	pushNode(head, new Node);
	if ((head->val != 0) or (head->next->val !=1))
	return -1;
	else
	return 0;
}

int testInit()
{
	Node *head = new Node;
	init (head);
	if (head->val != 0)
	return -1;
	else
	return 0;
}

int testShow()
{
	Node *head = new Node;
	init(head);
	Node node{1};
	show(head);
	return 0;
}

int compareMas(Node* source, Node* dest)
{
	Node *list1 = source;
	Node *list2 = dest;
	int a = 0;
	while ((list1 != NULL) and (list2 != NULL))
	{
		if(list1->val != list2->val)
			a = -1;
		else
			a = 0;
		list1 = list1->next;
		list2 = list2->next;
	}
  return a;
}

static void runTest(int (*testFunction)(),const std::string& testName)
{
  if(testFunction()==0)
    std::cout << "Test "<< testName << " - OK" << std::endl;
  else 
    std::cout << "Test "<< testName << " - FAIL" << std::endl;
}

int main()
{
  runTest(testPush,"Push");
  runTest(testInit,"Init");
  runTest(testShow,"Show");
  runTest(testCompare,"Compare");
}
