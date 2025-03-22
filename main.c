#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "csv_convert.h"

int main(int argc, char *argv[]) {

    Order orders[100];
    int index = 0;
    csv_convert(argv[1], orders, &index);
    for(int i = 0; i < index; i++){
        printf("%d,%d,%s,%d,%s,%s,%f,%f,%s,%s,%s,%s\n" ,
        orders[i].pizza_id,
        orders[i].order_id,
        orders[i].pizza_name_id,
        orders[i].quantity,
        orders[i].order_date,
        orders[i].order_time,
        orders[i].unit_price,
        orders[i].total_price,
        orders[i].pizza_size,
        orders[i].pizza_category,
        orders[i].pizza_ingredients,
        orders[i].pizza_name);
    }
    return 0;
};