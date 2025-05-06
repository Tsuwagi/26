// Обчислити кількість рядків, які починаються і закінчуються на одну й ту саму літеру

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

bool first_last_letter(char* line) {
    int len = strlen(line);

    if (len > 0 && line[len - 1] == '\n') 
    len--;

    if (len == 0) 
    return false;

    int first = 0;
    int last = len - 1;

    return line[first] == line[last];
}

int main() {
    FILE* f;
    char s[100];
    int count = 0;

    f = fopen("myfile.txt", "rt");
    if (f == NULL) {
        cout << "Неможливо відкрити файл\n";
        return 1;
    }

    while (fgets(s, 100, f)) {
        if (first_last_letter(s)) {
            count++;
        }
    }

    fclose(f);
    cout << "Кількість рядків: " << count << endl;
    return 0;
}
