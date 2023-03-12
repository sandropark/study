#include <stdio.h>
#include "cs50.h"   // 소스 코드와 헤더 파일이 같은 디렉토리에 있는 경우
#include <string.h>

typedef struct
{
    string name;
    string number;
}
person;

int main(void) 
{
    person people[4];
    people[0].name = "SANDRO";
    people[0].number = "010-3324-1415";
    people[1].name = "SUMMER";
    people[1].number = "010-1423-5432";
    people[2].name = "MIKA";
    people[2].number = "010-3411-6372";
    people[3].name = "SORI";
    people[3].number = "010-2234-5566";

    for (int i = 0; i < 4; i++)
    {
        if (strcmp(people[i].name, "MIKA") == 0)
            printf("%s\n", people[i].number);
    }
}