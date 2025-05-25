// Вивести слова, які розпочинаються й закінчуються на одну й ту саму літеру
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

void words(char* name)
{
  FILE* f;

  char s[100], *t;

  f = fopen(name, "rt");
  if (f == NULL)
    { cout<<"Cannot open file\n"; 
    return; }

  cout<<"\nСлова, які починаються та закінчуються на той самий символ:" <<endl;

  while (fgets(s, 100, f)) {
  s[strcspn(s, "\n")] = '\0';
  for (t = strtok(s, " .,;?!-");
    t != NULL; t = strtok(NULL, " .,;?!-"))
    if (t[0] == t[strlen(t)-1])
      puts(t);
}
fclose(f);

int main() {

    char name[]="myfile.txt";

    words(name);
    return 0;
}
