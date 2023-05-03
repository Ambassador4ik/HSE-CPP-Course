#include "password.h"

bool HasLength(const std::string& password) {
    const int min_length = 8;
    const int max_length = 14;
    int len = static_cast<int>(password.length());
    return len >= min_length && len <= max_length;
}

bool ValidatePassword(const std::string& password) {
    const int max_ascii_value = 126;
    const int min_ascii_value = 33;

    bool special_safe_class = false;
    bool digit_safe_class = false;
    bool lower_safe_class = false;
    bool upper_safe_class = false;

    for (char c : password) {
        if (c < min_ascii_value || c > max_ascii_value) {
            return false;
        }
        if (!std::isalnum(c)) {
            special_safe_class = true;
        } else if (std::isdigit(c)) {
            digit_safe_class = true;
        } else if (std::islower(c)) {
            lower_safe_class = true;
        } else if (std::isupper(c)) {
            upper_safe_class = true;
        }
    }
    return special_safe_class + digit_safe_class + lower_safe_class + upper_safe_class >= 3 && HasLength(password);
}
