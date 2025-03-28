#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// include metrics //
#include "metrics/pms/pms.h"
#include "metrics/pls/pls.h"
#include "metrics/dms/dms.h"
#include "metrics/dls/dls.h"

// include librería utils //
#include "utils/csv_convert.h"
#include "utils/get_sales_by_pizza.h"
#include "utils/get_unique_dates_data.h"

// include types //
#include "types/orders.h"
#include "types/sales.h"
#include "types/dates.h"

int main(int argc, char *argv[]) {

    // Cambiar la memoria stack de orders por memoria dinámica
    Order *orders = NULL;
    int index = 0;
    csv_convert(argv[1], &orders, &index);

    // Obtener array de ventas por pizza
    Sale *sales=malloc(sizeof(Sale) * index);  // Se reajusta la memoria en la función
    int sales_length = get_sales_by_pizza(orders, &sales, index);

    // Obtener array de ventas e ingresos totales por día
    Date_sale *dates=malloc(sizeof(Date_sale)*index);   // Se reajusta la memoria en la función
    int dates_length = get_unique_dates_data(orders, &dates, index);

    // Ejecutar las métricas en el orden que se ingresaron en argv
    for(int argv_i=2; argv_i<argc; argv_i++){
        // pms: Pizza más vendida
        if (strcmp(argv[argv_i],"pms") == 0){
            pms(sales, sales_length);
        }
        
        // pls: Pizza menos vendida
        if (strcmp(argv[argv_i],"pls") == 0){
            pls(sales, sales_length);
        }

        // dms: Día más vendido
        if (strcmp(argv[argv_i], "dms") == 0){
            dms(dates, dates_length);
        }
        
        // dms: Día menos vendido
        if (strcmp(argv[argv_i], "dls") == 0){
            dls(dates, dates_length);
        }

        // Crear las métricas y añadirlas. 

        
    }

    // Esto es solo para ver que se imprimen los datos. Notar que no se imprimen los headers, esta ok.
    // for(int i = 0; i < index; i++){
    //     printf("%d,%d,%s,%d,%s,%s,%f,%f,%s,%s,%s,%s\n" ,
    //     orders[i].pizza_id,
    //     orders[i].order_id,
    //     orders[i].pizza_name_id,
    //     orders[i].quantity,
    //     orders[i].order_date,
    //     orders[i].order_time,
    //     orders[i].unit_price,
    //     orders[i].total_price,
    //     orders[i].pizza_size,
    //     orders[i].pizza_category,
    //     orders[i].pizza_ingredients,
    //     orders[i].pizza_name);
    // }

    free(orders);
    free(sales);
    free(dates);

    return 0;
};