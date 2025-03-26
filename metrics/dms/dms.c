#include <stdio.h>
#include <string.h>
#include "../../types/dates.h"

// dms: Fecha con más ventas en términos de dinero (junto a la cantidad de dinero recaudado)
void dms(Date_sale *dates, int index)
{
    float money = 0;
    char date[11];
    for (int i = 0; i < index; i++){
        if(dates[i].income > money){
            money = dates[i].income;
            strcpy(date, dates[i].order_date);
        }
    }
    printf("Fecha con más venta: %s, Dinero: %.2f\n", date, money);
    
}