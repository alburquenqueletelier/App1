#include <stdio.h>
#include <string.h>
#include "../../types/orders.h"

// Promedio de pizzas por orden
void apo(Order *orders, int index) {

    float sum = 0;
    int orders_id[index];
    float quantity_by_orders[index];
    int real_index = 0;
    for (int i=0; i<index; i++){
        int found_order = 0;
        for (int j=0; j<real_index; j++){
            if(orders[i].order_id == orders_id[j]){
                quantity_by_orders[j] += orders[i].quantity;
                found_order = 1;
            }
        }
        if (!found_order){
            orders_id[real_index] = orders[i].order_id;
            quantity_by_orders[real_index] = orders[i].quantity;
            real_index+=1;
        }
    }

    for (int i=0; i<real_index; i++){
        sum += quantity_by_orders[i];
    }

    float average = sum/real_index;

    printf("Promedio de pizzas por orden: %.2f\n", average) ;
}