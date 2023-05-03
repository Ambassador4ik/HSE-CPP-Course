#include "stack.h"

Node::Node(int32_t value, Node *previous) : value(value), previous(previous) {
}

Stack::Stack() : head_(nullptr), size_(0) {
}

Stack::~Stack() {
    Clear();
}
void Stack::Push(int32_t value) {
    Node *temp = new Node(value, head_);
    head_ = temp;
    ++size_;
}
void Stack::Pop() {
    if (head_ != nullptr) {
        Node *temp = head_->previous;
        delete head_;
        head_ = temp;
        --size_;
    }
}
int32_t Stack::Top() const {
    if (head_ != nullptr) {
        return head_->value;
    }
    return 0;
}
int32_t Stack::Size() const {
    return size_;
}
void Stack::Clear() {
    while (head_ != nullptr) {
        Pop();
    }
    size_ = 0;
}
bool Stack::Empty() const {
    return size_ == 0;
}
