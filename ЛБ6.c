#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum Mark { Excellent = 5, Good = 4, Sat = 3, NotSat = 2 };
enum MarkType { Zachet, Examen };
enum Color { Red, Green, Blue };
enum Material { Metal = 1, Glass };

void enum_example(void)
{
    enum Color c = Red; //0
    enum Material m = Glass; //2
}

struct Subject
{
    char name[25];
    enum MarkType markType;
    union {
        _Bool zachet;
        enum Mark mark;
    } mark;
    char date[12];
    char teacher[25];
};

struct Term
{
    unsigned short number;
    struct Subject subjects[20];
};
struct Zachetka
{
    char firstName[25];
    char lastName[25];
    char middleName[25];
    struct Term terms[10];
};


int main()
{

    struct Zachetka z =
    {
        .firstName = "Roman",
        .lastName = "Kukin",
        .middleName = "Victorvich",
        .terms =
        {
            [0] = {
                    .number = 8,
                    .subjects = {
                                  [0] = {.name = " Programming",
                                        .markType = Zachet,
                                        .mark = {.zachet = 1},
                                        .date = "25.12.2021",
                                        .teacher = "Barkov"


                                       },
                                  [1] = {.name = "Kisiy",
                                        .markType = Examen,
                                        .mark = {.mark = Excellent},
                                        .date = "25.12.2021",
                                        .teacher = "Dokuchaev"


                                       }
                                },
                  }

        }

    };

    struct Subject newSubjet =
    {
      .name = "Phisical Education",
      .markType = Examen,
      .mark = {.mark = Excellent},
      .date = "31.12.2021",
      .teacher = "Korolev"
    };
    z.terms[0].subjects[2] = newSubjet;
    strcpy_s(z.terms[0].subjects[3].name, 80, "Chemistry");
    z.terms[0].subjects[3].markType = Examen;
    z.terms[0].subjects[3].mark.mark = Excellent;
    strcpy_s(z.terms[0].subjects[3].date, 11, "31.10.2021");
    strcpy_s(z.terms[0].subjects[3].teacher, 25, "Mariana");

    printf("%-20s|%-6s|%-11s|%-20s|\r\n", "Name", "Mark", "Date", "Teacher");
    for (int i = 0; i < 3; ++i)
    {
        printf("%-20s|", z.terms[0].subjects[i].name);
        if (z.terms[0].subjects[i].markType == Zachet)
        {
            printf("%-6s|", z.terms[0].subjects[i].mark.zachet ? "Zachet" : "Ne Zachet");

        }
        else
        {
            printf("%-6d|", z.terms[0].subjects[i].mark.mark);
        }

        printf("%-11s|", z.terms[0].subjects[i].date);
        printf("%-11s|", z.terms[0].subjects[i].teacher);
        printf("\r\n");
    }
    return 0;

};


