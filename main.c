#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 5

struct Wine {
    char brand[30];
    char location[30];
    float strength;     
    float volume;       
    char color[15];
};

int main() {
    system("chcp 65001");
    
    struct Wine wines[N];
    char searchBrand[30];
    FILE *outFile = fopen("wine_out.txt", "w");

    if (outFile == NULL) {
        printf("Не вдалося створити файл.\n");
        return 1;
    }

    printf("Введіть дані про %d вин:\n", N);
    for (int i = 0; i < N; i+=1) {
        printf("\nВино #%d:\n", i + 1);
        printf("Марка: ");
        scanf(" %[^\n]", wines[i].brand);
        printf("Місце розливу: ");
        scanf(" %[^\n]", wines[i].location);
        printf("Міцність (%%): ");
        scanf("%f", &wines[i].strength);
        printf("Ємність пляшки (л): ");
        scanf("%f", &wines[i].volume);
        printf("Колір: ");
        scanf(" %[^\n]", wines[i].color);
    }

    printf("\nВведіть марку вина для пошуку: ");
    scanf(" %[^\n]", searchBrand);

    printf("\nВина з маркою \"%s\":\n", searchBrand);
    fprintf(outFile, "Вина з маркою \"%s\":\n", searchBrand);
    int found = 0;

    for (int i = 0; i < N; i+=1) {
        if (strcmp(wines[i].brand, searchBrand) == 0) {
            found = 1;
            printf("Марка: %s\n", wines[i].brand);
            printf("Місце розливу: %s\n", wines[i].location);
            printf("Міцність: %.2f%%\n", wines[i].strength);
            printf("Ємність: %.2f л\n", wines[i].volume);
            printf("Колір: %s\n\n", wines[i].color);

            fprintf(outFile, "Марка: %s\n", wines[i].brand);
            fprintf(outFile, "Місце розливу: %s\n", wines[i].location);
            fprintf(outFile, "Міцність: %.2f%%\n", wines[i].strength);
            fprintf(outFile, "Ємність: %.2f л\n", wines[i].volume);
            fprintf(outFile, "Колір: %s\n\n", wines[i].color);
        }
    }

    if (!found) {
        printf("Вина з такою маркою не знайдено.\n");
        fprintf(outFile, "Вина з такою маркою не знайдено.\n");
    }

    fclose(outFile);
    printf("Результати збережено у файл wine_out.txt\n");

    return 0;
}

