#include "caesar_cipher.h"

std::string Decipher(const std::string& cipher, size_t shift) {
    std::string deciphered;
    const int alphabet_size = 26;
    for (size_t i = 0; i < cipher.length(); ++i) {
        deciphered += static_cast<char>(((cipher[i] - shift - 'A' + alphabet_size) % alphabet_size + 'A'));
    }
    return deciphered;
}
