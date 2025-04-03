#include <stdio.h>
#include <string.h>
#include "../../types/dates.h"

void dlsp(Date_sale *dates, int index) 
{
    int quantity = 999999;  
    char date[11];

    for (int i = 0; i < index; i++){
        if(dates[i].quantity < quantity){  
            quantity = dates[i].quantity;
            strcpy(date, dates[i].order_date);
        }
    }

    printf("Fecha con menos ventas en términos de cantidad de pizza: %s, cantidad: %d\n", date, quantity);
}