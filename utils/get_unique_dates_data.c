#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../types/orders.h"
#include "../types/dates.h"


int get_unique_dates_data(Order *orders, Date_sale **dates, int index){

    if ((*dates) == NULL){
        printf("Error al asignar memoria\n");
        return -1;
    }

    int date_index = 0;
    for (int i=0; i<index; i++){
        int not_found = 0;
        for(int j=0; j<date_index; j++){
            if (strcmp((*dates)[j].order_date, orders[i].order_date) == 0){
                (*dates)[j].income += orders[i].total_price;
                (*dates)[j].quantity += orders[i].quantity;
                not_found = 1;
            }
        }
        
        if (not_found == 0){
            strcpy((*dates)[date_index].order_date, orders[i].order_date);
            (*dates)[date_index].income = orders[i].total_price;
            (*dates)[date_index].quantity = orders[i].quantity;
            date_index++;
        }
    }

    Date_sale *tmp = realloc(*dates, sizeof(Date_sale) * date_index); // Ajustamos memoria al tamaño de los datos
    if (tmp == NULL){
        printf("Error al asignar memoria\n");
        free(tmp); // Liberamos memoria - Memoria de sales se libera en main. 
        return -1;
    }
    *dates = tmp;

    // Solo para debuggear
    // printf("Fechas unicas: \n");
    // for (int i=0; i<date_index; i++){
    //     printf("Date: %s, Income: %.2f, Sales: %d\n", (*dates)[i].order_date, (*dates)[i].income, (*dates)[i].quantity);
    // }

    return date_index;
}