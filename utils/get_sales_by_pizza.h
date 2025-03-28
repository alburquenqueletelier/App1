#ifndef GET_UNIQUE_PIZZAS   // verifica si existe get_unique_pizzas.h
#define GET_UNIQUE_PIZZAS   // sino existe, define get_unique_pizzas.h

#include "../types/orders.h"
#include "../types/sales.h"

int get_sales_by_pizza(Order *orders, Sale **sales, int index);

#endif  // end of check intercambio.h