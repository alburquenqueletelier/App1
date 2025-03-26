#include <stdio.h>
#include <string.h>
#include "../types/orders.h"
#include "../types/dates.h"


void get_unique_dates_data(Order *orders, Date_sale *dates, int index){

    if (dates == NULL){
        printf("Error al asignar memoria\n");
        return ;
    }

    int date_index = 0;
    for (int i=0; i<index; i++){
        int not_found = 0;
        for(int j=0; j<date_index; j++){
            if (strcmp(dates[j].order_date, orders[i].order_date) == 0){
                dates[j].income += orders[i].total_price;
                dates[j].quantity += orders[i].quantity;
                not_found = 1;
            }
        }
        
        if (not_found == 0){
            strcpy(dates[date_index].order_date, orders[i].order_date);
            dates[date_index].income = orders[i].total_price;
            dates[date_index].quantity = orders[i].quantity;
            date_index++;
        }
    }

    // Solo para debuggear
    // printf("Fechas unicas: \n");
    // for (int i=0; i<date_index; i++){
    //     printf("Date: %s, Income: %.2f, Sales: %d\n", dates[i].order_date, dates[i].income, dates[i].quantity);
    // }
}