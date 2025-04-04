#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../types/dates.h"
#include "../../types/orders.h"
#include "../../utils/get_unique_dates_data.h"


void dls(Order *orders, int index){
    Date_sale *dates=malloc(sizeof(Date_sale)*index);   // Se reajusta la memoria en la función
    int dates_length = get_unique_dates_data(orders, &dates, index);

    Date_sale response = dates[0];
    for (int i=1; i<dates_length; i++){
        if(response.income > dates[i].income){
            response = dates[i];
        }
    }
    printf("Fecha con menos venta: %s, Dinero: %.2f\n", response.order_date, response.income);
    free(dates);
}