#ifndef CSV_CONVERT   // verifica si existe csv_convert.h
#define CSV_CONVERT   // sino existe, define csv_convert.h

typedef struct Order
{
    int pizza_id;
    int order_id;
    int quantity;

    float unit_price;
    float total_price;

    char pizza_name_id[50];
    char order_date[20];
    char order_time[10];
    char pizza_size[3];
    char pizza_category[20];
    char pizza_ingredients[50];
    char pizza_name[50];
} Order;

int csv_convert(char *file_name, Order *orders, int *index);   

#endif  // end of check intercambio.h