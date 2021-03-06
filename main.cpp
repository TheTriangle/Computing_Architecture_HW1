//------------------------------------------------------------------------------
// main.cpp - содержит главную функцию,
// обеспечивающую простое тестирование
//------------------------------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "number.h"
#include "fraction.h"
#include "fraction.cpp"
#include "complexNumber.h"
#include "complexNumber.cpp"
#include "coordinates.h"
#include "coordinates.cpp"
#include "TestsGenerator.cpp"
#include "deck.h"
#include "deck.cpp"


void PrintResultsToConsole(deck numbers, FILE* input, int amount);
void PrintResultsToFile(deck numbers, char* outputpath, FILE* input, int amount);
void LogError(char* errors);


// Условие 11, обработка 12
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
    FILE* errorslog = fopen("errors.log", "w");
    int type;
    double first;
    double second;

    deck numbers;
    char* errors;
    int counter = 0;
    bool errorsrisen = false;
    while (fscanf(inputfile, "%d %lf %lf", &type, &first, &second) != EOF) {
        if ((type == 1) && (fabs(second) < 0.00001)) {
            fprintf(errorslog, "A provided fraction has a zero denumenator"
                                                  "(line %d)\n", counter + 1);
            errorsrisen = true;
            continue;
        }

        number newnum = *In(type, first, second);
        PushFront(numbers, newnum);
        counter++;
    }
    if (errorsrisen)
        printf("Errors produced during program execution. Check errors.log for further info\n");
    fclose(errorslog);
    BubbleSort(numbers);

    printf("Program finished in %f seconds.\n", (double)(clock())/CLOCKS_PER_SEC - startingtime);
    if (argc == 2) {
        printf("\nPrinting results to console, (%d lines)\n", counter);
        PrintResultsToConsole(numbers, inputfile, counter);
    } else {
        printf("\nWriting results to file (%s)\n", outputpath);
        PrintResultsToFile(numbers, outputpath, inputfile, counter);
    }
    fclose(inputfile);
    return 0;
}

void PrintResultsToConsole(deck numbers, FILE* input, int amount) {
    printf("Given input file:\n"
           "---------------------------------------------------------\n");
    rewind(input);
    int c;
    while ((c = getc(input)) != EOF)
        printf("%c", c);

    printf("\n"
           "---------------------------------------------------------\n\n"
           "Output:\n");

    while(Size(numbers) != 0) {
        printf("%s\n", Out(PopBack(numbers)));
    }

    printf("\n%d lines in total.", amount);
}

void PrintResultsToFile(deck numbers, char* outputpath, FILE* input, int amount) {
    FILE* outputfile = fopen(outputpath, "w");

    fprintf(outputfile, "Given input file:\n"
           "---------------------------------------------------------\n");
    rewind(input);
    int c;
    while ((c = getc(input)) != EOF)
        fprintf(outputfile, "%c", c);

    fprintf(outputfile, "\n"
           "---------------------------------------------------------\n\n"
           "Output:\n");

    while(Size(numbers) != 0) {
        fprintf(outputfile, "%s\n", Out(PopBack(numbers)));
    }
    fprintf(outputfile, "\n%d lines in total.", amount);
    fclose(outputfile);
}