#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../types/dates.h"
#include "../../types/orders.h"
#include "../../utils/get_unique_dates_data.h"

void dlsp(Order *orders, int index) 
{

    Date_sale *dates=malloc(sizeof(Date_sale)*index);   // Se reajusta la memoria en la función
    int dates_length = get_unique_dates_data(orders, &dates, index);

    int quantity = 999999;  
    char date[11];

    for (int i = 0; i < dates_length; i++){
        if(dates[i].quantity < quantity){  
            quantity = dates[i].quantity;
            strcpy(date, dates[i].order_date);
        }
    }

    printf("Fecha con menos ventas en términos de cantidad de pizza: %s, cantidad: %d\n", date, quantity);
    free(dates);
}