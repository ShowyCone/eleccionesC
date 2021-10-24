// Librerías utilizadas
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int main() {
    // Declaración e inicialicación de las variables
    int i,
    election,
    comparation1,
    comparation2,
    electors = 3000,
    nullVotes = 0,
    votes[5] = {0, 0, 0, 0, 0};
    bool final = false;
    char att[10],
    option1[10] = "INGRESAR",
    option2[10] = "CERRAR",
    headerMatrix[2][20] = {
        "   CANDIDATOS    ",
        "      VOTOS      "
    },
    candidates[6][20] = {
        "  Efraim Campos  ",
        "   Bruno Perez   ",
        "Bautista Gonzalez",
        " Salvador Garcia ",
        " Gustavo Barrios "
    };
    
    // El ciclo del programa (estará activo hasta que se escriba "CERRAR" o hasta que hayan pasado los 3000 electores)
    while (final == false || electors == 0) {
        printf("Para ingresar al sistemas escriba 'INGRESAR'\n");
        printf("Para finalizar y obtener resultados escriba 'CERRAR'\n\n");
        scanf("%s", att);
        
        // Comparando strings con la librería <string.h>
        comparation1 = strcmp(option1, att); // Si es igual retorna 0
        comparation2 = strcmp(option2, att); // Si es igual retorna 0

        // Condicional para confirmar asistencia de cada elector o de lo contrario cerrar el programa
        if (comparation1 == 0 && comparation2 < 0) {
            printf("\nElija al candidato que apoya usando los números:\n\n");

            // For que itera el mismo mensaje cambiando el índice del array
            for (i = 0; i <= 4; i++) {
                printf("Escriba %d para votar por %s|\n\n", i, candidates[i]);
            }
            scanf("%d", &election);
            printf("¡Su voto ha sido realizado con exito!\n\n");

            /* For que recorre el array para contar el voto correspondiente al candidato correcto
               O de lo contrario contar el voto nulo */
            for (i = 0; i <= 4 ; i++) {
                if (i == election && election <= 4 && election >= 0)
                    votes[i] += 1;
                else if(election <= -1 || election >= 5) {
                    nullVotes += 1;
                    i = 4;
                }
            }
            electors -= 1;
        } else if (comparation2 == 0 && comparation1 > 0) {
            // Renderización de la matriz

            printf("\nResultado de los votos:\n");
            printf("\n_________________________________________\n");
            printf("| %s | %s |\n", headerMatrix[0], headerMatrix[1]);
            for (i = 0; i <= 4; i++)
                printf("| %s |         %d         |\n", candidates[i], votes[i]);
            printf("|_______________________________________|\n");
            printf("|    Votos nulos     |        %d         |", nullVotes);
            printf("\n|_______________________________________|\n");
            printf("\nHa habido una abstencion de %d electores.\n", electors);
            final = true;
        } else 
            printf("\n!Error¡\nIngrese una opcion valida (RECUERDE ACTIVAR MAYUSCULAS).\n\n");
    }
    system("pause");
    return 0;
}
