//------------------------------------------------------------------------------
// main.cpp - содержит главную функцию,
// обеспечивающую простое тестирование
//------------------------------------------------------------------------------


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "number.h"
#include "number.cpp"
#include "fraction.h"
#include "fraction.cpp"
#include "complexNumber.h"
#include "complexNumber.cpp"
#include "coordinates.h"
#include "coordinates.cpp"
#include "TestsGenerator.cpp"


void BubbleSort(number* numbers, int n);
void PrintResultsToConsole(number* numbers, int n);
void PrintResultsToFile(number* numbers, int n, char* outputpath);
void LogError(char* errors);


// условие 11, обработка 12
int main(int argc, char* argv[]) {
    if (argc == 1) {
        printf("Run main <input.txt> to specify input file \n"
               "or\n"
               "run main <input.txt> <output.txt> to specify"
               "input file, output will be written into output.txt\n"
               "or\n"
               "run main -generate <amount> <lowerbound> <upperbound> <out.txt> to generate "
               "a text file with tests\n");
        return 0;
    }

    if (argc == 6) {
        if (strcmp(argv[1], "-generate") != 0) {
            printf("Unknown command %s\n"
                   "Exiting.\n", argv[1]);
            return 0;
        }
        RunGenerator(argc, argv);
        return 0;
    }
    double startingtime = (double)clock();
    startingtime = startingtime / CLOCKS_PER_SEC;

    char* inputpath;
    char* outputpath;

    inputpath = argv[1];
    if (argc == 3) {
        outputpath = argv[2];
    }

    FILE* inputfile = fopen(inputpath, "r");
    int type;
    double first;
    double second;

    number numbers[3000];
    char* errors;
    int counter = 0;
    while (fscanf(inputfile, "%d %lf %lf", &type, &first, &second) != EOF) {
        if ((type == 2) && (fabs(second) < 0.00001)) {
            char error[100];
            snprintf(error, 99, "A provided fraction has a zero denumenator"
                                                  "(line %d)\n", counter + 1);
            errors = strcat(errors, error);
            continue;
        }
        if (counter == 3000) {
            char error[100];
            snprintf(error, 99, "Amount of numbers in file exceeded maximum of 1000.\n");
            errors = strcat(errors, error);
            break;
        }

        numbers[counter] = *In(type, first, second);
        counter++;
    }
    LogError(errors);
    delete errors;
    fclose(inputfile);

    BubbleSort(numbers, counter);

    printf("Program finished in %f seconds.\n", (double)(clock())/CLOCKS_PER_SEC - startingtime);
    if (argc == 2) {
        printf("\nPrinting results to console, (%d lines)\n", counter);
        PrintResultsToConsole(numbers, counter);
    } else {
        printf("\nWriting results to file (%s)\n", outputpath);
        PrintResultsToFile(numbers, counter, outputpath);
    }
    return 0;
}
//dasddasdsasd
void LogError(char* errors) {
    if (!errors)
        return;
    if (strcmp(errors, ""))
        return;
    printf("There were errors during program execution. See errors.log for further detail\n");
    FILE* logfile = fopen("errors.log", "w");
    fprintf(logfile, "%s", errors);
    fclose(logfile);
}

void PrintResultsToConsole(number* numbers, int n) {
    for(int i = 0; i < n; i++) {
        printf("%s\n", Out(numbers[i]));
    }
}

void PrintResultsToFile(number* numbers, int n, char* outputpath) {
    FILE* outputfile = fopen(outputpath, "w");
    for(int i = 0; i < n; i++) {
        fprintf(outputfile, "%s", Out(numbers[i]));
        fprintf(outputfile, "\n");
    }
    fclose(outputfile);
}


void BubbleSort(number* numbers, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ConvertToReal(numbers[j]) > ConvertToReal(numbers[j + 1])) {
                number intermed = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = intermed;
            }
        }
    }
}

