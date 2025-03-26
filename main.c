#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// include metrics //
#include "metrics/pms/pms.h"
#include "metrics/pls/pls.h"
#include "metrics/dms/dms.h"

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
    Sale *sales=malloc(sizeof(Sale) * index);  // No es lo más óptimo ya que el arreglo de ventas por pizza puede ser menor que las filas del archivo.csv
    get_sales_by_pizza(orders, sales, index);

    // Obtener array de ventas e ingresos totales por día
    Date_sale *dates=malloc(sizeof(Date_sale)*index); // No óptimo porque días casi siempre menor o igual que maximos registros del csv
    get_unique_dates_data(orders, dates, index);

    // Ejecutar las métricas en el orden que se ingresaron en argv
    for(int argv_i=2; argv_i<argc; argv_i++){
        // pms: Pizza más vendida
        if (strcmp(argv[argv_i],"pms") == 0){
            pms(sales, index);
        }
        
        // pls: Pizza menos vendida
        if (strcmp(argv[argv_i],"pls") == 0){
            pls(sales, index);
        }

        // dms: Día más vendido
        if (strcmp(argv[argv_i], "dms") == 0){
            dms(dates, index);
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