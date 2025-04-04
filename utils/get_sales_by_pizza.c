#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../types/orders.h"
#include "../types/sales.h"

int get_sales_by_pizza(Order *orders, Sale **sales, int index){

    if (*sales == NULL) {
        printf("Error al asignar memoria\n");
        return -1;
    }

    int sales_index = 0;

    for(int i=0; i<index; i++){
        int not_found_pizza = 0;
        // printf("orders[%d]: pizza_name_id: %s, name: %s, quantity: %d\n",
        //     i, orders[i].pizza_name_id, orders[i].pizza_name, orders[i].quantity);
     
        for (int j = 0; j<sales_index; j++){
            if(strcmp((*sales)[j].name, orders[i].pizza_name) == 0){
                (*sales)[j].quantity += orders[i].quantity;
                not_found_pizza = 1;
            }
        }
        if (not_found_pizza == 0) {
            strcpy((*sales)[sales_index].name, orders[i].pizza_name);
            (*sales)[sales_index].quantity = orders[i].quantity;
            // printf("\n sales[%d].pizza_name_id: %s, name: %s, quantity: %d", sales_index, (*sales)[sales_index].pizza_name_id, (*sales)[sales_index].name, (*sales)[sales_index].quantity);
            sales_index++; 
        }
    }

    Sale *tmp = realloc(*sales, sizeof(Sale) * sales_index);
    if (tmp == NULL){
        printf("Error al asignar memoria\n");
        free(tmp); // Liberamos memoria - Memoria de sales se libera en main. 
        return -1;
    }
    *sales = tmp;
    return sales_index;
}