#include <iostream>

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
class MyForwardList{
private:
    Node* _head;
    Node* _tail;

public:
    ListIterator() {
        _head = nullptr;
        _tail = nullptr;
    }

    void Add(){
        if (_head == nullptr){
            _head = new Node<T>(data, nullptr)
        }

    }
    void Delete(){}
    bool Contane(){}

    ListIterator begin(){
        return ListIterator<T>(_head);
    }
    ListIterator end(){
        return ListIterator<T>(_tail->Next);
    }
    ConstListIterator cbegin(){
        return ConstListIterator<T>(_head);
    }
    ConstListIterator cend(){
        return ConstListIterator<T>(_tail->Next);
    }
};


int main(){

    return 0;
}