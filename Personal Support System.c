#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char date[20];
    char diary[5000];
    char task[1000];
    char event[1000];
    char time[10];
    char subject[50];
    char days[20];
    char timings[10];
} data;

void diary();
void task();
void schedule();
void events();
void menu();
void menuselect();

int main()
{
    //main intro
    char n, name[50], goal[100];

    system("cls");
    printf("\n\n\t\t\t\t    WELCOME TO YOUR PERSONAL SUPPORT SYSTEM\n\n\nDo you have an account?\n(Press Y for Yes and N for No)  ");
    scanf("%c", &n);
    if (n == 'y' || n == 'Y')
    {
        menu();
    }
    else if (n == 'N' || n == 'n')
    {
        printf("Enter your name: \n");
        gets(name);
        fflush(stdin);
        system("cls");
        printf("Enter your Goal:");
        gets(goal);
        fflush(stdin);
        system("cls");
        printf("\t\t\t\t\t*****Welcome %s*****\n", name);
        printf("\t\t\t\tI am your Personal support system\n");
        printf("\t\t\t\tHere to help you become a %s\n", goal);
        printf("\t\t\t\t\t**WORK HARD!!**\n");
        printf("\t\t\t\t\tHow can I help you today?\n");
        printf("\n\n\n\n\n\n\n\nPress any key\n");
        getch();
        menu();
    }
    else
    {
        printf("\nWrong input. Please try again\n");
        getch();
        main();
    }
}
void menu()
{
    //Main input
    int select;
    system("cls");
    printf("\n\t\t\t\t\t-------------\n");
    printf("\t\t\t\t\t| Main Menu |\n");
    printf("\t\t\t\t\t-------------\n\n");
    printf("1. Dear Me!\n");
    printf("2. Mission Today!\n");
    printf("3. Class Schedule\n");
    printf("4. Don't Miss!\n");
    printf("5. EXIT\n\n");
    printf("Select your option:  ");
    scanf("%d", &select);
    system("cls");

    switch (select)
    {
    case 1:
        diary();
        break;
    case 2:
        task();
        break;
    case 3:
        schedule();
        break;
    case 4:
        events();
        break;
    case 5:
    {
        system("cls");
        printf("\n\n\t\t\t\tTHANK YOU");
        printf("\n\n\n\n\n\t\t\tHAVE A GREAT DAY!!!!");
        Sleep(60);
        exit(0);
        break;
    }
    default:
    {
        system("cls");
        printf("Incorrect Input\n Please try again\n");
        getch();
        menuselect();
    }
    }
}
void menuselect()
{
    char b[2];
    char str1[] = "m";
    system("cls");
    printf("For main menu press M and for exit press other key\n");
    scanf("%s", b);
    if (strcasecmp(b, str1) == 0)
    {
        menu();
    }
}
void diary()
{
    int choose;
    FILE *f;
    // char test;
    printf("1.Write my day\n");
    printf("2.Read my day\n");
    scanf("%d", &choose);
    if (choose == 1)
    {
        system("cls");
        data d = {"", "", "", "", "", "", "", ""};
        f = fopen("test.txt", "a");
        if (f == NULL)
        {
            printf("File cannot be opened\n");
            getch();
        }
        else
        { //diary input
            system("cls");
            printf("Enter date (XX/XX/XXXX):  ");
            scanf("%s", d.date);
            system("cls");
            printf("Write your day:\n");
            fflush(stdin);
            gets(d.diary);
            fwrite(&d, sizeof(data), 1, f);
            fclose(f);
            menuselect();
            getch();
        }
    }
    else if (choose == 2)
    { //diary output
        data d = {"", "", "", "", "", "", "", ""};
        f = fopen("test.txt", "rb");
        if (f)
        {
            system("cls");
            char dateinput[20];
            printf("Enter date (XX/XX/XXXX):  ");
            scanf("%s", dateinput);
            int x = 0;
            system("cls");
            printf("**Your Day**\n");
            while (fread(&d, sizeof(data), 1, f))
            {
                if (strcmp(d.date, dateinput) == 0 && strcmp(d.diary, "") != 0)
                {
                    printf("%s\n", d.diary);
                    getch();
                    x = 1;
                }
            }
            if (x == 0)
            {
                printf("Not found\n");
            }
            fclose(f);
            getch();
            menuselect();
        }
    }
    else
    {
        printf("Wrong input please try again.Press any key\n");
        getch();
        menuselect();
    }
}
void task()
{
    int choose;
    FILE *f;
    //char test;
    printf("1.Write my task\n");
    printf("2.View my tasks\n");
    scanf("%d", &choose);
    if (choose == 1)
    {
        data d = {"", "", "", "", "", "", "", ""};
        f = fopen("test.txt", "a");
        if (f == NULL)
        {
            printf("File cannot be opened\n");
            getch();
            menuselect();
        }
        else
        {
            printf("Enter date (XX/XX/XXXX):  ");
            scanf("%s", d.date);
            system("cls");
            while (1)
            {
                printf("Write your task:\n");
                fflush(stdin);
                gets(d.task);
                fwrite(&d, sizeof(data), 1, f);
                printf("Add more?(Y for YES and N for NO)\n");
                char a;
                scanf("%c", &a);
                if (a == 'y' || a == 'Y')
                {
                    system("cls");
                    continue;
                }
                else if (a == 'n' || a == 'N')
                {
                    fclose(f);
                    break;
                }
            }
        }
        fclose(f);
        menuselect();
    }
    else if (choose == 2)
    {
        data d = {"", "", "", "", "", "", "", ""};
        f = fopen("test.txt", "rb");
        if (f)
        {
            char date[20];
            printf("Enter date (XX/XX/XXXX):  ");
            scanf("%s", date);
            int x = 0;
            system("cls");
            printf("**Your Tasks**\n");
            while (fread(&d, sizeof(data), 1, f))
            {
                if (strcmp(d.date, date) == 0 && strcmp(d.task, "") != 0)
                {
                    printf("%s\n", d.task);
                    x = 1;
                }
            }
            if (x == 0)
            {
                printf("Not found\n");
            }
            fclose(f);
            getch();
            menuselect();
        }
    }
    else
    {
        printf("Wrong input please try again.Press any key\n");
        getch();
        menuselect();
    }
}

void events()
{
    int choose;
    FILE *f;
    //char test;
    system("cls");
    printf("1.Write my Events\n");
    printf("2.View my Events\n");
    scanf("%d", &choose);
    if (choose == 1)
    {
        data d = {"", "", "", "", "", "", "", ""};
        f = fopen("test.txt", "a");
        if (f == NULL)
        {
            printf("File cannot be opened\n");
            getch();
            menuselect();
        }
        else
        {
            printf("Enter date (XX/XX/XXXX):  ");
            scanf("%s", d.date);
            system("cls");
            while (1)
            {
                printf("Write your events:\n");
                fflush(stdin);
                gets(d.event);
                printf("Enter time:\n");
                gets(d.time);
                fwrite(&d, sizeof(data), 1, f);
                printf("Add more?(Y for YES and N for NO) \n");
                char a;
                scanf("%c", &a);
                if (a == 'y' || a == 'Y')
                    continue;

                else if (a == 'n' || a == 'N')
                {
                    break;
                }
            }
            fclose(f);
        }
        menuselect();
    }
    else if (choose == 2)
    {
        data d = {"", "", "", "", "", "", "", ""};
        f = fopen("test.txt", "rb");
        if (f)
        {
            char edate[20];
            printf("Enter date (XX/XX/XXXX):  \n");
            scanf("%s", edate);
            int x = 0;
            system("cls");
            printf("**Your Events:**\n");
            printf("\n%s\n", edate);
            while (fread(&d, sizeof(data), 1, f))
            {
                int i = 1;
                if (strcmp(d.date, edate) == 0 && strcmp(d.event, "") != 0)
                {

                    printf("%s\t----\t", d.event);
                    printf("%s\n", d.time);
                    x = 1;
                }
            }
            x = 1;
            if (x == 0)
            {
                printf("Not found\n");
            }
            fclose(f);
            getch();
            menuselect();
        }
    }
    else
    {
        printf("Wrong input please try again.Press any key\n");
        getch();
        menuselect();
    }
}

void schedule()
{
    int choose;
    FILE *f;
    //char test;
    printf("1.Add my schedule\n");
    printf("2.View my schedule\n");
    scanf("%d", &choose);
    if (choose == 1)
    {
        data d = {"", "", "", "", "", "", "", ""};
        f = fopen("test.txt", "a");
        if (f == NULL)
        {
            printf("File cannot be opened\n");
            getch();
        }
        else
        {
            system("cls");
            printf("Enter Subject name:  ");
            fflush(stdin);
            gets(d.subject);
            printf("\n");
            while (1)
            {
                printf("Enter Day name:\n");
                fflush(stdin);
                gets(d.days);
                fflush(stdout);
                printf("Enter timing:\n");
                fflush(stdin);
                gets(d.timings);
                fflush(stdout);
                fwrite(&d, sizeof(data), 1, f);
                char a;
                printf("Add another day?(Y for Yes/N for No)\n");
                scanf("%c", &a);
                if (a == 'y' || a == 'Y')
                {
                    continue;
                }
                else if (a == 'n' || a == 'N')
                {
                    break;
                }
            }
            fclose(f);
        }
        menuselect();
    }
    else if (choose == 2)
    {
        data d = {"", "", "", "", "", "", "", ""};
        f = fopen("test.txt", "rb");
        if (f)
        {
            char sub[20];
            printf("Enter Subject:\n");
            scanf("%s", sub);
            int x = 0;
            system("cls");
            while (fread(&d, sizeof(data), 1, f))
            {
                if (strcasecmp(d.subject, sub) == 0 && strcmp(d.subject, "") != 0)
                {
                    printf("%s\t", d.subject);
                    printf("\t\t\t%s\t\t%s\n", d.days, d.timings);
                    x = 1;
                }
            }
            if (x == 0)
            {
                printf("Not found\n");
                getch();
            }
            fclose(f);
        }
        getch();
        menuselect();
    }
    else
    {
        printf("Wrong input please try again.Press any key\n");
        getch();
        menuselect();
    }
}