#include <stdio.h>
#include <stdlib.h>
#include "../../types/sales.h"
#include "../../types/orders.h"
#include "../../utils/get_sales_by_pizza.h"

void pls(Order *orders, int index){

    Sale *sales=malloc(sizeof(Sale) * index);  // Se reajusta la memoria en la función
    int sales_length = get_sales_by_pizza(orders, &sales, index);
    
    Sale sale = sales[0];
    for (int i=0; i<sales_length; i++){
        if(sale.quantity > sales[i].quantity){
            sale = sales[i];
        }
    }
    // Si hay una pizza con la misma cantidad entonces va a imprimir la primera que 
    // encuentra en sales dada la condición de menor estricto
    printf("Pizza menos vendida: %s Cantidad: %d \n", sale.name, sale.quantity);
    free(sales);
}