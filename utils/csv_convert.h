#ifndef CSV_CONVERT   // verifica si existe csv_convert.h
#define CSV_CONVERT   // sino existe, define csv_convert.h
#include "../types/orders.h"

int csv_convert(char *file_name, Order **orders, int *index);   

#endif  // end of check intercambio.h