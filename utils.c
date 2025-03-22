#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "csv_convert.h"

int csv_convert(char *file_name, Order *orders, int *index)
{ // llena un array con estructuras  para cada orden
    char *data;
    char buffer[1000];

    FILE *csv;

    csv = fopen(file_name, "r"); // cambiarlo despues para que sea un parametro
    if (csv == NULL)
    {
        printf("Error abriendo el archivo");
        return 0;
    }

    // leer la primera linea por separado para no almacenarla en la estructura
    fgets(buffer, sizeof(buffer), csv);
    // printf("%s\n",buffer);

    // parseo
    while (fgets(buffer, sizeof(buffer), csv))
    {

        data = strtok(buffer, ",");
        orders[*index].pizza_id = atoi(data);

        data = strtok(NULL, ",");
        orders[*index].order_id = atoi(data);

        data = strtok(NULL, ",");
        strcpy(orders[*index].pizza_name_id, data);

        data = strtok(NULL, ",");
        orders[*index].quantity = atoi(data);

        data = strtok(NULL, ",");
        strcpy(orders[*index].order_date, data);

        data = strtok(NULL, ",");
        strcpy(orders[*index].order_time, data);

        data = strtok(NULL, ",");
        orders[*index].unit_price = atof(data);

        data = strtok(NULL, ",");
        orders[*index].total_price = atof(data);

        data = strtok(NULL, ",");
        strcpy(orders[*index].pizza_size, data);

        data = strtok(NULL, ",");
        strcpy(orders[*index].pizza_category, data);

        data = strtok(NULL, "\""); //
        strcpy(orders[*index].pizza_ingredients, data);

        data = strtok(NULL, ",");
        strcpy(orders[*index].pizza_name, data);

        (*index)++;
    }

    fclose(csv);
    return 1;
}

