#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "csv_convert.h"
#include "../types/orders.h"

int csv_convert(char *file_name, Order **orders, int *index)
{ // llena un array con estructuras  para cada orden
    char *data;
    char *ingredient; // Puntero a ocupar en la separacion de ingredientes
    char buffer[1000];

    FILE *csv;

    csv = fopen(file_name, "r"); // cambiarlo despues para que sea un parametro
    if (csv == NULL)
    {
        printf("Error abriendo el archivo");
        return 0;
    }

    // Se lee el archivo completamente para conocer el tamaño y así asginar memoria 
    // una sola vez con malloc al array de orders
    int count = 0;
    fgets(buffer, sizeof(buffer), csv);  // Leer y saltar la cabecera
    while (fgets(buffer, sizeof(buffer), csv)) {
        count++;
    }

    // Asignar memoria dinámica para orders
    *orders = malloc(count * sizeof(Order));
    if (*orders == NULL) {
        printf("Error al asignar memoria\n");
        fclose(csv);
        return 0;
    }

    // Volver al inicio del archivo para leer los datos
    fseek(csv, 0, SEEK_SET);  // SEEK_SET es una constante usada en fseek para mover el puntero a la posición del 2do argumento
    // leer la primera linea por separado para no almacenarla en la estructura
    fgets(buffer, sizeof(buffer), csv);
    // printf("%s\n",buffer);

    // parseo
    while (fgets(buffer, sizeof(buffer), csv))
    {
        // Eliminar el salto de línea del final de la línea leída
        // para evitar que se impriman esos saltos en terminal
        buffer[strcspn(buffer, "\n")] = '\0';

        data = strtok(buffer, ",");
        (*orders)[*index].pizza_id = atoi(data);

        data = strtok(NULL, ",");
        (*orders)[*index].order_id = atoi(data);

        data = strtok(NULL, ",");
        strcpy((*orders)[*index].pizza_name_id, data);

        data = strtok(NULL, ",");
        (*orders)[*index].quantity = atoi(data);

        data = strtok(NULL, ",");
        strcpy((*orders)[*index].order_date, data);

        data = strtok(NULL, ",");
        strcpy((*orders)[*index].order_time, data);

        data = strtok(NULL, ",");
        (*orders)[*index].unit_price = atof(data);

        data = strtok(NULL, ",");
        (*orders)[*index].total_price = atof(data);

        data = strtok(NULL, ",");
        strcpy((*orders)[*index].pizza_size, data);

        data = strtok(NULL, ",");
        strcpy((*orders)[*index].pizza_category, data);

        // Separacion de ingredientes 
        data = strtok(NULL, "\""); // Los ingredientes estan delimitados por comillas

        // Puntero a la cadena de ingredientes
        char *ingredients_copy = strdup(data);
        // El puntero ingredient sera util para apuntar a las comas que separan cada ingrediente
        ingredient = ingredients_copy;


        int i = 0; // declarar i previamente nos permitira usar esto como indice para el ultimo ingrediente, el que no termina con coma

        // Ciclo para cada ingrediente
        for(i = 0;i < 20;i++){

            ingredient = strchr(ingredient,','); // ingredient apunta a la primera coma

            if(ingredient == NULL){ // si no se encuentran mas comas
                break;
            }

            *ingredient = '\0'; // convertir la coma en un string terminator para tener una cadena con solo un ingrediente
            //
            //printf("Ingrediente %d: %s\n", i, ingredients_copy);
            strcpy((*orders)[*index].pizza_ingredients[i],ingredients_copy); // asignar el ingrediente al array de ingredientes en la estructura

            ingredient++; // avanzamos el puntero al primer caracter del siguiente ingrediente

            // si el ingrediente comienza con un espacio en blanco, avanza al siguiente caracter
            if((*ingredient) == ' '){
                ingredient++; 
            }

            ingredients_copy = ingredient; // hacemos que ingredients_copy tambien apunte al primer caracter del ingrediente para luego poder mover ingredient
        }

        // para los ingredientes que van despues de la ultima coma

        //printf("Ingrediente %d: %s\n", i, ingredients_copy);
        strcpy((*orders)[*index].pizza_ingredients[i],ingredients_copy); // asignar el ingrediente al array de ingredientes en la estructura


        data = strtok(NULL, ",");
        strcpy((*orders)[*index].pizza_name, data);

        (*index)++;
    }

    fclose(csv);
    return 1;
}

