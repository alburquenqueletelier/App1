#ifndef ORDERS_H
#define ORDERS_H

typedef struct Order
{
    int pizza_id;
    int order_id;
    int quantity;

    float unit_price;
    float total_price;

    char pizza_name_id[50];
    char order_date[11];
    char order_time[9];
    char pizza_size[3];
    char pizza_category[20];
    char pizza_ingredients[20][40];
    char pizza_name[50];
} Order;

#endif 

