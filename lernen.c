/* =========================
   AUFGABE 1 – a1.c
   ========================= */
#include <stdio.h>
#include <stdlib.h>

char* kopiere(const char* s1, int n1, const char* s2, int n2) {
    char* ziel = malloc(n1 + n2 + 1);
    for (int i = 0; i < n1; i++) ziel[i] = s1[i];
    for (int i = 0; i < n2; i++) ziel[n1 + i] = s2[i];
    ziel[n1 + n2] = '\0';
    return ziel;
}

int main(void) {
    char s1[] = "Hallo";
    char s2[] = "Welt";
    int n1 = 5, n2 = 4;

    char* s3 = kopiere(s1, n1, s2, n2);
    printf("%s\n", s3);
    free(s3);
    return 0;

}
/* =========================
   NEXT VALUE AUFGABE (Collatz) – a_next.c
   - Eingabe: positiver int
   - Solange n != 1:
       gerade: n = n/2
       ungerade: n = 3*n + 1
       Schritte zählen
       "Next value is: <n>" ausgeben (für Zwischenschritte)
   - Am Ende: "Final value 1, number of steps: <steps>"
   - Bei falscher Eingabe: Fehlermeldung, sofort beenden
   ========================= */

#include <stdio.h>

int main(void)
{
    int n;
    int steps = 0;

    printf("Bitte geben Sie einen positiven int-Wert ein:\n");

    /* Fehleingabe abfangen */
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Fehler: Ungültige Eingabe.\n");
        return 0; /* ohne Berechnung beenden */
    }

    printf("Initial value is %d\n", n);

    while (n != 1) {
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = 3 * n + 1;
        }

        steps++;

        if (n != 1) {
            printf("Next value is %d\n", n);
        }
    }

    printf("Final value 1, number of steps: %d\n", steps);
    return 0;
}
/* =========================
   AUFGABE 2 – a2.c
   ========================= */


void einlesen(int v[], int n) {
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);
}

void spiegeln(int v[], int n) {
    int tmp;
    for (int i = 0; i < n/2; i++) {
        tmp = v[i];
        v[i] = v[n-1-i];
        v[n-1-i] = tmp;
    }
}

void ausgeben(const int v[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", v[i]);
    printf("\n");
}

int main(void) {
    int v[11];
    einlesen(v, 11);
    spiegeln(v, 11);
    ausgeben(v, 11);
    return 0;
}

/* =========================
   AUFGABE 3 – a3.c
   ========================= */
#include <stdio.h>

int main(int argc, char* argv[]) {
    if (argc != 2) { printf("Aufruf: %s <datei>\n", argv[0]); return 1; }

    FILE* fp = fopen(argv[1], "r");
    if (!fp) { printf("Fehler: Datei konnte nicht geöffnet werden\n"); return 1; }

    int c;
    while ((c = fgetc(fp)) != EOF) {
        if (c == '.') fputs("<++STOP++>", stdout);
        else putchar(c);
    }

    fclose(fp);
    return 0;
}
/* =========================
   AUFGABE 4 – a4.c
   ========================= */
#include <stdio.h>

void bubble_sort(int a[], int n) {
    for (int i = 0; i < n-1; i++) {
        int swapped = 0;
        for (int j = 0; j < n-1-i; j++) {
            if (a[j] > a[j+1]) {
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
}

int main(void) {
    FILE* in = fopen("zahlen.txt", "r");
    if (!in) { printf("Fehler: zahlen.txt nicht gefunden\n"); return 1; }

    int a[1000], n = 0, x;
    while (fscanf(in, "%d", &x) == 1) a[n++] = x;
    fclose(in);

    bubble_sort(a, n);

    FILE* out = fopen("zahlen.txt", "w");
    if (!out) { printf("Fehler: konnte nicht schreiben\n"); return 1; }

    for (int i = 0; i < n; i++) fprintf(out, "%d\n", a[i]);
    fclose(out);

    return 0;
}
