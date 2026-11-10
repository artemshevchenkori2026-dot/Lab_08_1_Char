// Lab_08_1_Char.cpp
// Варіант 29
// Лабораторна робота № 8.1
// Пошук та заміна символів у літерному рядку.
// Використання стандартних функцій мови C для рядків char[].

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

// Перевірка наявності четвірки однакових сусідніх символів за допомогою стандартних функцій C
bool Include(const char* str) {
    size_t len = strlen(str);
    if (len < 4) return false;

    for (size_t i = 0; i <= len - 4; i++) {
        // Перевірка, чи збігаються 4 послідовні символи
        if (str[i] == str[i + 1] && str[i] == str[i + 2] && str[i] == str[i + 3]) {
            return true;
        }
    }
    return false;
}

// Заміна кожної четвірки сусідніх однакових символів парою зірочок "**" з використанням C-функцій
char* Change(char* str) {
    size_t len = strlen(str);
    if (len < 4) return str;

    char* t = new char[len + 1];
    char* p;
    int pos1 = 0, pos2 = 0;
    *t = '\0';

    size_t i = 0;
    while (i <= len - 4) {
        if (str[i] == str[i + 1] && str[i] == str[i + 2] && str[i] == str[i + 3]) {
            pos2 = (int)i;
            strncat(t, str + pos1, pos2 - pos1);
            strcat(t, "**");
            i += 4;
            pos1 = (int)i;
        }
        else {
            i++;
        }
    }
    strcat(t, str + pos1);
    strcpy(str, t);
    delete[] t;
    return str;
}

int main() {
    char str[101];

    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    if (Include(str)) {
        cout << "String contains four consecutive identical characters." << endl;
    }
    else {
        cout << "String does not contain four consecutive identical characters." << endl;
    }

    char* dest = new char[151];
    strcpy(dest, str);
    Change(dest);

    cout << "Modified string (param) : " << dest << endl;

    delete[] dest;
    return 0;
}