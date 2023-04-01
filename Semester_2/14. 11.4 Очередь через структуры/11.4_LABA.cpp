#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

struct Queue
{
	Node* front;
	Node* back;
	int size;
	void init()
	{
		front = nullptr;
		back = nullptr;
		size = 0;
	}
};

void push(Queue*& queue, int data)
{
	Node* tmp = new Node;
	tmp->data = data;
	tmp->next = nullptr;
	if (queue->size == 0)
	{
		queue->front = tmp;
		queue->back = tmp;
	}
	else
	{
		queue->back->next = tmp;
		queue->back = tmp;
	}
	queue->size++;
}

void pop(Queue*& queue)
{
	if (queue->size == 0)
	{
		return;
	}
	queue->front = queue->front->next;
	queue->size--;
}
void insert_element(Queue*& queue, int pos, int data)
{
	Queue* tmp = new Queue;
	tmp->init();
	for (int i = 1; i < pos; i++)
	{
		push(tmp, queue->front->data);
		pop(queue);
	}
	push(tmp, data);
	int init_size = queue->size;
	for (int i = 0; i < init_size; i++)
	{
		push(tmp, queue->front->data);
		pop(queue);
	}
	queue=tmp;
}
void insert_elements(Queue*& queue, int pos, int k)
{
	Queue* tmp = new Queue;
	tmp->init();
	int data;
	cout << "Введите элементы, которые хотите добавить: ";
	for (int i = 1; i < pos; i++)
	{
		push(tmp, queue->front->data);
		pop(queue);
	}
	for (int i = 0; i < k; i++)
	{
		cin >> data;
		push(tmp, data);
	}
	int init_size = queue->size;
	for (int i = 0; i < init_size; i++)
	{
		push(tmp, queue->front->data);
		pop(queue);
	}
	queue=tmp;
}
void delete_element(Queue*& queue, int pos)
{
	Queue* tmp = new Queue;
	tmp->init();
	for (int i = 1; i < pos; i++)
	{
		push(tmp, queue->front->data);
		pop(queue);
	}
	pop(queue);
	int init_size = queue->size;
	for (int i = 0; i < init_size; i++)
	{
		push(tmp, queue->front->data);
		pop(queue);
	}
	queue=tmp;
}

void delete_elements(Queue*& queue, int pos, int k)
{
	Queue* tmp = new Queue;
	tmp->init();
	for (int i = 1; i < pos; i++)
	{
		push(tmp, queue->front->data);
		pop(queue);
	}
	for (int i = 0; i < k; i++)
	{
		pop(queue);
	}
	int init_size = queue->size;
	for (int i = 0; i < init_size; i++)
	{
		push(tmp, queue->front->data);
		pop(queue);
	}
	queue=tmp;
}

Queue* createQueue(int n)
{
	Queue* queue = new Queue;
	queue->init();
	int data;
	for (int i = 0; i < n; i++)
	{
		cin >> data;
		push(queue, data);
	}
	return queue;
}

void printQueue(Queue*& queue)
{
	Node* curr = new Node;
	curr = queue->front;
	for (int i = 0; i < queue->size; i++)
	{
		cout << curr->data << ' ';
		curr = curr->next;
	}
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	int size, data, pos, k, element;
	cout << "Введите размер очереди: ";
	cin >> size;
	cout << "Введите элементы очереди" << endl;
	Queue* queue = createQueue(size);
	cout << "Вывод очереди" << endl;
	printQueue(queue);
	cout << "Введите элемент, который хотите добавить: ";
	cin >> data;
	push(queue, data);
	cout << "Вывод очереди" << endl;
	printQueue(queue);
	pop(queue);
	cout << "Вывод очереди" << endl;
	printQueue(queue);
	cout << "Введите элемент и позицию куда хотите добавить этот элемент: ";
	cin >> data;
	cin >> pos;
	insert_element(queue, pos, data);
	cout << "Вывод очереди" << endl;
	printQueue(queue);
	cout << "Введите количество элементов и позицию, куда хотите добавить: ";
	cin >> k;
	cin >> pos;
	insert_elements(queue, pos, k);
	cout << "Вывод очереди" << endl;
	printQueue(queue);
	cout << "Введите позицию откуда хотите удалить элемент: ";
	cin >> pos;
	delete_element(queue, pos);
	cout << "Вывод очереди" << endl;
	printQueue(queue);
	cout << "Введите количество элементов и позицию, откуда хотите удалить: ";
	cin >> k;
	cin >> pos;
	delete_elements(queue, pos, k);
	cout << "Вывод очереди" << endl;
	printQueue(queue);
	return 0;
}
