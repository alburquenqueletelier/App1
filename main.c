#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// include metrics //
#include "metrics/pms/pms.h"
#include "metrics/pls/pls.h"
#include "metrics/dms/dms.h"
#include "metrics/dls/dls.h"
#include "metrics/hp/hp.h"
#include "metrics/apd/apd.h"
#include "metrics/apo/apo.h"
#include "metrics/dmsp/dmsp.h"
#include "metrics/ims/ims.h"
#include "metrics/dlsp/dlsp.h"

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


    //Puntero a funcion
    void (*metrics[])(Order *orders, int index) = {apd,apo,dls,dlsp,dms,dmsp,hp,ims,pls,pms};
    char *metric_names[] = {"apd","apo","dls","dlsp","dms","dmsp","hp","ims","pls","pms"};

    int metrics_count = sizeof(metrics)/sizeof(metrics[0]);


    // Ejecutar las métricas en el orden que se ingresaron en argv
    void (*metric_selector)(Order *orders, int index);

    for(int argv_i = 2; argv_i<argc;argv_i++) {
        for(int i = 0; i < metrics_count; i++){
            if((strcmp(argv[argv_i],metric_names[i])) == 0){
                metric_selector = metrics[i];
                metric_selector(orders,index);
                break;
            }

        }

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

    return 0;
};
