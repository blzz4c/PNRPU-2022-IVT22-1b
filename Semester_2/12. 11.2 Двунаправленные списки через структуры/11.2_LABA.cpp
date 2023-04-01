#include <iostream>
using namespace std;

struct ListElem
{
    string data;
    ListElem* next;
    ListElem* prev;
};

ListElem* createList(int n)
{
    ListElem* start;
    ListElem* prev, * curr;
    start = new ListElem;
    cin >> start->data;
    start->next = nullptr;
    start->prev = nullptr;
    prev = start;
    for (int i = 0; i < n - 1; i++)
    {
        curr = new ListElem;
        cin >> curr->data;
        curr->next = nullptr;
        curr->prev = prev;
        prev->next = curr;
        prev = curr;
    }
    return start;
}

void delElems(ListElem* start, string element, int& size) { 
    ListElem* curr = start;
    ListElem* temp;
    int pos = 0;
    while (curr->data != element && curr->next != nullptr)
    {
        curr = curr->next;
        pos++;
    }
    if (curr->data == element) {
        if (pos == size - 1) {
            curr = start;
            for (int i = 0; i < pos - 2; i++)
            {
                curr = curr->next;
            }
            temp = curr->next->next;
            curr->next = temp;
            size--;
        }
        else if (pos == 0) {
            temp = curr->next->next;
            curr->next = temp;
            size--;
        }
        else {
            temp = curr->next->next;
            curr->next = temp;
            curr = start;
            for (int i = 0; i < pos - 2; i++)
            {
                curr = curr->next;
            }
            temp = curr->next->next;
            curr->next = temp;
            size -= 2;
        }
    }
    else {
        cout << "Искомый элемент не найден.\n";
    }
}

void addLElems(ListElem*& start, int k, int& size) {
    for (int i = 1; i < k + 1; i++) {
        size++;
        ListElem* first = start;
        ListElem* last;
        for (int j = 1; j < i - 1; j++) {
            first = first->next;
        }
        last = first->next;
        ListElem* new_element = new ListElem;
        cout << "Введите элемент: ";
        cin >> new_element->data;

        if (i == 1) {
            new_element->prev = nullptr;
            start->prev = new_element;
            new_element->next = start;
            start = new_element;
        }
        else {
            new_element->prev = first;
            new_element->next = last;
            last->prev = new_element;
            first->next = new_element;
        }
    }
}
void addRElems(ListElem* start, int k, int& size) {
    for (int i = 1; i < k+1; i++) {
        size++;
        ListElem* first = start;
        ListElem* last;
        for (int j = 1; j < size - 1; j++) {
            first = first->next;
        }
        last = first->next;
        ListElem* new_element = new ListElem;
        cout << "Введите элемент: ";
        cin >> new_element->data;
        new_element->prev = first;
        new_element->next = last;
        first->next = new_element;
    }
}

void printList(ListElem* first, int n) {
    ListElem* curr = first;
    for (int i = 0; i < n; i++) {
        cout << curr->data << ' ';
        curr = curr->next;
    }
    cout << endl;
}

void deleteList(ListElem* list) {
    delete list;
}

int main() {
    system("chcp 1251>NULL");
    int size, k, pos;
    string element;
    cout << "Введите размер списка: ";
    cin >> size;
    cout << "Введите значения элементов в списке: ";
    ListElem* list = createList(size);
    cout << "Вывод списка\n";
    printList(list, size);

    cout << "Введите количество добавляемых элементов с левой стороны: ";
    cin >> k;
    addLElems(list, k, size);
    cout << "Вывод списка\n";
    printList(list, size);

    cout << "Введите количество добавляемых элементов с правой стороны: ";
    cin >> k;
    addRElems(list, k, size);
    cout << "Вывод списка\n";
    printList(list, size);

    cout << "Введите элемент, где хотите перед и после него удалить элементы: ";
    cin >> element;
    delElems(list, element, size);
    cout << "Вывод списка\n";
    printList(list, size);
    deleteList(list);
}