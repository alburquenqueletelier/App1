#include <stdio.h>
#include <stdlib.h>
#include "../../types/sales.h"
#include "../../types/orders.h"
#include "../../utils/get_sales_by_pizza.h"

void pms(Order *orders , int index){
    
    Sale *sales=malloc(sizeof(Sale) * index);  // Se reajusta la memoria en la función
    int sales_length = get_sales_by_pizza(orders, &sales, index);
    Sale sale = sales[0];

    // printf("\n sales[%d].pizza_name_id: %s, name: %s, quantity: %d", 0, sales[0].pizza_name_id, sales[0].name, sales[0].quantity);
    for (int i=0; i<sales_length; i++){
        if(sale.quantity < sales[i].quantity){
            sale = sales[i];
            // printf("sales[%d]: \n", i);
            // printf("name: %s, quantity: %d \n", sales[i].name, sales[i].quantity);
        }
    }
    // Si hay una pizza con la misma cantidad entonces va a imprimir la primera que 
    // encuentra en sales dada la condición de menor estricto
    printf("Pizza más vendida: %s Cantidad: %d \n", sale.name, sale.quantity);
    free(sales);
}