#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../types/dates.h"
#include "../../types/orders.h"
#include "../../utils/get_unique_dates_data.h"

// Promedio de pizzas al día en unidades de pizzas
void apd(Order *orders, int index) {

    Date_sale *dates=malloc(sizeof(Date_sale)*index);   // Se reajusta la memoria en la función
    int dates_length = get_unique_dates_data(orders, &dates, index);

    float sum = 0;
    for (int i=0; i<dates_length; i++){
        sum += dates[i].quantity;  // `quantity` es la cantidad de pizzas
    }
    float promedio = sum/dates_length;

    printf("Promedio de pizzas al dia: %.2f\n", promedio);

    free(dates);
}