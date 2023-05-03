#include "sort_students.h"

int Compare(Date first, Date second) {
    if (first.year > second.year) {
        return 1;
    }
    if (first.year < second.year) {
        return -1;
    }
    if (first.month > second.month) {
        return 1;
    }
    if (first.month < second.month) {
        return -1;
    }
    if (first.day > second.day) {
        return 1;
    }
    if (first.day < second.day) {
        return -1;
    }
    return 0;
}

int CompareByName(Student first, Student second) {
    if (first.last_name.compare(second.last_name) > 0) {
        return 1;
    }
    if (first.last_name.compare(second.last_name) < 0) {
        return -1;
    }
    if (first.name.compare(second.name) > 0) {
        return 1;
    }
    if (first.name.compare(second.name) < 0) {
        return -1;
    }
    return 0;
}

int Compare(Student first, Student second, SortKind sort_kind) {
    if (sort_kind == SortKind::Date) {
        int date_comp = Compare(first.birth_date, second.birth_date);
        if (date_comp != 0) {
            return date_comp;
        }
        return CompareByName(first, second);
    }
    if (sort_kind == SortKind::Name) {
        int name_comp = CompareByName(first, second);
        if (name_comp != 0) {
            return name_comp;
        }
        return Compare(first.birth_date, second.birth_date);
    }
    return 0;
}

void SortStudents(std::vector<Student>& students, SortKind sort_kind) {
    int arr_size = static_cast<int>(students.size());
    for (int i = 0; i < arr_size; ++i) {
        for (int j = i + 1; j < arr_size; ++j) {
            if (Compare(students[i], students[j], sort_kind) > 0) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}
