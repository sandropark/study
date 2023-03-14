#include <stdio.h>

typedef char *string;
int compare_string(string s, string t);

int main(void)
{
    string s = "EMMA";
    printf("%s\n", s);

    printf("%p\n", s);
    printf("%p\n", &s[0]);
    printf("%p\n", &s[1]);
    printf("%p\n", &s[2]);
    printf("%p\n", &s[3]);

    printf("%c\n", *s);
    printf("%c\n", *(s+1));

    string t = "EMMA";

    printf("%i\n", compare_string(s, t));
}

int compare_string(string s, string t)
{
    for (int i = 0; ; i++)
    {
        char a = s[i];
        char b = t[i];

        if (a == '\0' || b == '\0') 
        {
            if (a != '\0' || b != '\0') return 0;
            break;
        }
        if (a != b) return 0;
    }
    return 1;
}