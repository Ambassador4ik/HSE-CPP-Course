#pragma once

template <class Iterator, class T>
Iterator FindLast(Iterator first, Iterator last, const T& val) {
    if (first == last) {
        return last;
    }
    auto result = last;
    while (true) {
        auto next = first;
        ++next;
        if (*first == val) {
            result = first;
        }
        if (next == last) {
            break;
        }
        first = next;
    }
    return result;
}
