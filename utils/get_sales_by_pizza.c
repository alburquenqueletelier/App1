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
        for (int j = 0; j<sales_index; j++){
            if(orders[i].pizza_id == (*sales)[j].id){
                (*sales)[j].quantity += orders[i].quantity;
                not_found_pizza = 1;
                break;
            }
        }
        if (not_found_pizza == 0) {
            (*sales)[sales_index].id = orders[i].pizza_id;
            strcpy((*sales)[sales_index].name, orders[i].pizza_name);
            (*sales)[sales_index].quantity = orders[i].quantity;
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