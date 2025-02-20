#include <iostream>

using namespace std;


template <typename T>
struct Node{
    T Data;
    Node* Next;
    Node(T data, Node* next){
        Data = data;
        Next = next;
    }

};

template <typename T>
struct ListIterator
{
    using iterator_category = std::forward_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = T;
    using reference = T&;
    using pointer = T*;

    ListIterator( Node<T>* node) : _node(node){};

    reference operator*() const { return _node->Data; };//разыменование

    pointer operator->() {return &(_node->Data);};

    ListIterator& operator++() {_node = _node->Next; return *this;};

    ListIterator operator++(int) {ListIterator tmp = *this; _node = _node->Next; return tmp;};

    friend bool operator==(const ListIterator& a, const ListIterator& b) {return a._node == b._node;};

    friend bool operator!=(const ListIterator& a, const ListIterator& b){return a._node != b._node;};

private:
    Node<T>* _node;
};

template <typename T>
struct ConstListIterator
{
    using iterator_category = std::forward_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = T;
    using reference = const T&;
    using pointer = const T*;

    ConstListIterator( Node<T>* node) : _node(node){};

    const reference operator*() const { return _node->Data; };//разыменование

    const pointer operator->() {return &(_node->Data);};

    ConstListIterator& operator++() {_node = _node->Next; return *this;};

    ConstListIterator operator++(int) {ConstListIterator tmp = *this; _node = _node->Next; return tmp;};

    friend bool operator==(const ConstListIterator& a, const ConstListIterator& b) {return a._node == b._node;};

    friend bool operator!=(const ConstListIterator& a, const ConstListIterator& b) {return a._node != b._node;};

private:
    Node<T>* _node;
};


template <typename T>
class MyForwardList
{
private:
    Node<T>* _head;
    Node<T>* _tail;
public:
    MyForwardList() {
        _head = nullptr;
        _tail = nullptr;
    }

    void Add(T data) {
        if (_head == nullptr) {
            _head = new Node<T>(data, nullptr);
            _tail = _head;
        } else {
            _tail->Next = new Node<T>(data, nullptr);
            _tail = _tail->Next;
        }
    }
    // тут тоже допилить
    void Delete(T data) {
        ListIterator<T>* tmp = _head;

        if(tmp->_node->Data == data) { delete [] _head; _head = tmp->_node->Next; }
        
        while(tmp != nullptr){
            if (tmp->_node->Next->Data == data){
                ListIterator<T>* ctmp = tmp;
                tmp->_node->Next = tmp->_node->Next->Next;
                if (ctmp->_node->Next == _tail) { _tail = tmp->_node;}
                delete [] ctmp->_node->Next;
                return;
            }
            else tmp++;
        }
    }
//доделать костантный оператор 
    bool Contains(T data) {
        ListIterator<T>* tmp = _head;
        while(tmp != nullptr){
            if (tmp->Data == data){
                return true;
            }
            tmp = tmp->Next;
        }
        return false;
    }

    ListIterator<T> begin() {
        return ListIterator<T>(_head);
    }

    ListIterator<T> end() {
        return ListIterator<T>(_tail->Next);
    }

    ConstListIterator<T> cbegin() {
        return ConstListIterator<T>(_tail);
    }

    ConstListIterator<T> cend() {
        return ConstListIterator<T>(_tail);
    }

    // ~MyForwardList(){
    //     Node<T>* cur = _head;

    //     while (cur->Next != nullptr){

    //     }
    // }


};



int main() {
    MyForwardList<int> mfl;
    mfl.Add(5);
    mfl.Add(-5);
    mfl.Add(1);
    mfl.Add(100);

    mfl.Contains(100) ? cout << "Yes" << endl : cout << "No" << endl;
    mfl.Delete(1);
    mfl.Contains(1) ? cout << "Yes" << endl : cout << "No" << endl;
    for (auto a: mfl) {
        std::cout << a << std::endl;
    }


    return 0;
}