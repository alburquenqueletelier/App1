#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../types/dates.h"
#include "../../types/orders.h"
#include "../../utils/get_unique_dates_data.h"

// dms: Fecha con más ventas en términos de dinero (junto a la cantidad de dinero recaudado)
void dms(Order *orders, int index)
{
    Date_sale *dates=malloc(sizeof(Date_sale)*index);   // Se reajusta la memoria en la función
    int dates_length = get_unique_dates_data(orders, &dates, index);
    float money = 0;
    char date[11];
    for (int i = 0; i < dates_length; i++){
        if(dates[i].income > money){
            money = dates[i].income;
            strcpy(date, dates[i].order_date);
        }
    }
    printf("Fecha con más venta: %s, Dinero: %.2f\n", date, money);
    free(dates);
    
}