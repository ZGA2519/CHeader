// header file create by Organ
// Use for stupid thing, Dont care about it!!
#ifndef ORGAN_H
#define ORGAN_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// function prototype
void printfln(const char *format_string, ...);
int inputi(const char *format_string, ...);
float inputf(const char *format_string, ...);
double inputd(const char *format_string, ...);
char *inputs(const char *format_string, ...);
char *strtrim(char *str);
int isum(int num_args, ...);
double dsum(int num_args, ...);
int randRange(int min_num, int max_num);

// bool checkChar(void *ptr)
// {
//     return sizeof(*(char *)ptr) == sizeof(char);
// }

// bool checkInt(void *ptr)
// {
//     return sizeof(*(int *)ptr) == sizeof(int);
// }

// bool checkDouble(void *ptr)
// {
//     return sizeof(*(double *)ptr) == sizeof(double);
// }

// void *scanInput(void *var, const char *format_string, ...)
// {
//     va_list arg;
//     va_start(arg, format_string);
//     vprintf(format_string, arg);
//     va_end(arg);

//     char input[100];
//     if (fgets(input, sizeof(input), stdin) == NULL)
//     {
//         printf("Error reading input.\n");
//         return 0;
//     }

//     int num_parsed;
//     if (checkChar(var))
//     {
//         num_parsed = sscanf(input, "%c", (char *)var);
//     }
//     else if (checkInt(var))
//     {
//         num_parsed = sscanf(input, "%d", (int *)var);
//     }
//     else if (checkDouble(var))
//     {
//         num_parsed = sscanf(input, "%lf", (double *)var);
//     }
//     else
//     {
//         printf("Error: unsupported variable type.\n");
//         return 0;
//     }

//     if (num_parsed < 1)
//     {
//         printf("Error: invalid input.\n");
//         return 0;
//     }

//     return var;
// }

// printf and new line
void printfln(const char *format_string, ...)
{
    va_list args;
    va_start(args, format_string);
    vprintf(format_string, args);
    va_end(args);
    printf("\n");
}
// print message and scan integer form user
int inputi(const char *format_string, ...)
{
    // print format string
    va_list args;
    va_start(args, format_string);
    vprintf(format_string, args);
    va_end(args);
    // get a input from user
    int input;
    if (scanf("%i", &input))
    {
        return input;
    }
    else
    {
        printf("/*ERROR(return 0)*/");
        return 0;
    }
}

// print message and scan float form user
float inputf(const char *format_string, ...)
{
    // print format string
    va_list args;
    va_start(args, format_string);
    vprintf(format_string, args);
    va_end(args);
    // get a input from user
    float input;
    if (scanf("%f", &input))
    {
        return input;
    }
    else
    {
        printf("/*ERROR(return 0)*/");
        return 0;
    }
}

// print message and scan double form user
double inputd(const char *format_string, ...)
{
    // print format string
    va_list args;
    va_start(args, format_string);
    vprintf(format_string, args);
    va_end(args);
    // get a input from user
    double input;
    if (scanf("%lf", &input))
    {
        return input;
    }
    else
    {
        printf("/*ERROR(return 0)*/");
        return 0;
    }
}

// print message and get string form user
char *inputs(const char *format_string, ...)
{
    char *input = NULL; // allocate input string as NULL
    size_t size = 0;    // initialize size to 0

    // print format string
    va_list args;
    va_start(args, format_string);
    vprintf(format_string, args);
    va_end(args);

    // use getline to read a line of input from the user
    if (getline(&input, &size, stdin) == -1)
    {
        return "/*ERROR*/";
    }

    // remove leading and trailing white space from the input string
    input = strtrim(input);

    // return the input string
    return input;
}

// remove leading and trailing white space from the input string
char *strtrim(char *str)
{
    char *end;

    // trim leading white space
    while (isspace(*str))
    {
        str++;
    }

    if (*str == 0)
    { // all spaces?
        return str;
    }

    // trim trailing white space
    end = str + strlen(str) - 1;
    while (end > str && isspace(*end))
    {
        end--;
    }

    // write new null terminator
    *(end + 1) = 0;

    return str;
}

// add number together
int isum(int num_args, ...)
{
    va_list args;
    va_start(args, num_args);

    int result = 0;
    for (int i = 0; i < num_args; i++)
    {
        result += va_arg(args, int); // Get the next argument from the list
    }

    va_end(args);
    return result;
}

double dsum(int num_args, ...)
{
    va_list args;
    va_start(args, num_args);

    double result = 0;
    for (int i = 0; i < num_args; i++)
    {
        result += va_arg(args, double); // Get the next argument from the list
    }

    va_end(args);
    return result;
}


int randRange(int min_num, int max_num)
{
    srand(time(0));
    return min_num + rand() % (max_num - min_num + 1);
}

void sus()
{
    int n = randRange(1, 3);
    switch (n)
    {
    case 1:
        printf("You are Imposter\n");
        break;
    case 2:
        printf("You sus\n");
        break;
    case 3:
        printf("lmao\n");
        break;
    default:
        break;
    }
}

#endif
