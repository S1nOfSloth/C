#include <stdio.h>

int main() {
    //FILE *inputFile, *outputFile;
    char name[50];
    char 
    int year;

    // Открываем исходный файл для чтения
    FILE* inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Ошибка открытия исходного файла\n");
        return 0;
    }

    // Открываем файл для записи отфильтрованных данных
    FILE* outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Ошибка открытия файла для записи\n");
        return 0;
    }

    // Читаем данные из исходного файла и фильтруем по заданному условию
    while (fscanf(inputFile, "%s %d", name, &year) != EOF) {
        if (year > 1980) {
            fprintf(outputFile, "%s %d\n", name, year);
        }
    }

    // Закрываем файлы
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
