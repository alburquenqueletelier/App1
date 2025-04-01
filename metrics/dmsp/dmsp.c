#include <stdio.h>
#include <string.h>
#include "../../types/dates.h"

void dmsp(Date_sale *dates, int index)
{
    int quantity = 0;
    char date[11];
    for (int i = 0; i < index; i++){
        if(dates[i].quantity > quantity){
            quantity = dates[i].quantity;
            strcpy(date, dates[i].order_date);
        }
    }
    printf("Fecha con más venta en términos de cantidad de pizza:  %s, cantidad: %d\n", date, quantity);
    
}