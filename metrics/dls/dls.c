#include <stdio.h>
#include <string.h>
#include "../../types/dates.h"

void dls(Date_sale *sales, int index){
    Date_sale response = sales[0];
    for (int i=1; i<index; i++){
        if(response.income > sales[i].income){
            response = sales[i];
        }
    }
    printf("Fecha con menos venta: %s, Dinero: %.2f\n", response.order_date, response.income);
}