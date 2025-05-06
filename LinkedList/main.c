#include "list.h"
#include <stdio.h>

void printMenu() {
    printf("\n--- MENOY ---\n");
    printf("1. Eisagogi stoixeioy sthn arxh\n");
    printf("2. Eisagogi stoixeioy meta apo kombo\n");
    printf("3. Diagrafi stoixeioy apo thn arxh\n");
    printf("4. Diagrafi stoixeioy meta apo kombo\n");
    printf("5. Ektiposi ths listas\n");
    printf("6. Katastrofi ths listas\n");
    printf("7. Eksodos\n");
    printf("Epilogi: ");
}

int main() {
    NodePtr head;
    LL_init(&head);  // Arxikopoiisi ths listas

    int choice;
    elem x, y;

    do {
        printMenu();
        if (scanf("%d", &choice) != 1) {  // An den diavase egkyri epilogi
            while (getchar() != '\n');    // Katharismos buffer eisodou
            choice = -1;  // Ayto tha odigisei sthn "default" periptosi
        }

        switch (choice) {
            case 1:  // Eisagogi stoixeioy sthn arxh
                printf("Dose to stoixeio poy theleis na eisageis: ");
                scanf("%d", &x);
                if (LL_insert_start(&head, x)) {
                    printf("Epityxis eisagogi!\n");
                } else {
                    printf("Apotypxia eisagogis.\n");
                }
                break;

            case 2:  // Eisagogi stoixeioy meta apo kombo
                printf("Dose to stoixeio poy theleis na eisageis: ");
                scanf("%d", &x);
                printf("Dose to stoixeio meta apo to opoio theleis na eisageis: ");
                scanf("%d", &y);

                NodePtr temp = head;
                while (temp != NULL && temp->data != y) {
                    temp = temp->next;
                }

                if (temp != NULL) {
                    if (LL_insert_after(temp, x)) {
                        printf("Epityxis eisagogi!\n");
                    } else {
                        printf("Apotypxia eisagogis.\n");
                    }
                } else {
                    printf("To stoixeio %d den vrethike sthn lista.\n", y);
                }
                break;

            case 3:  // Diagrafi stoixeioy apo thn arxh
                if (LL_delete_start(&head, &x)) {
                    printf("Diagrafike to stoixeio: %d\n", x);
                } else {
                    printf("H lista einai adeia.\n");
                }
                break;

            case 4:  // Diagrafi stoixeioy meta apo kombo
                printf("Dose to stoixeio meta apo to opoio theleis na diagrafeis: ");
                scanf("%d", &y);

                NodePtr prev = head;
                while (prev != NULL && prev->data != y) {
                    prev = prev->next;
                }

                if (prev != NULL) {
                    if (LL_delete_after(prev, &x)) {
                        printf("Diagrafike to stoixeio: %d\n", x);
                    } else {
                        printf("Den yparxei stoixeio meta to %d.\n", y);
                    }
                } else {
                    printf("To stoixeio %d den vrethike sthn lista.\n", y);
                }
                break;

            case 5:  // Ektiposi ths listas
                printf("H lista einai: ");
                LL_print(head);
                break;

            case 6:  // Katastrofi ths listas
                if (LL_destroy(&head)) {
                    printf("H lista katastrafike epityxos.\n");
                } else {
                    printf("H lista einai hdh adeia.\n");
                }
                break;

            case 7:  // Eksodos
                printf("Eksodos...\n");
                break;

            default:
                printf("Mi egkyri epilogi. Dokimase ksana.\n");
        }
    } while (choice != 7);

    return 0;
}