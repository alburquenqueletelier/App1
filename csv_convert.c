#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Order {
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

};



int csv_to_array(struct Order *orders,int *index){ //llena un array con estructuras  para cada orden
    char *data;
    char buffer[1000];
    
    FILE *csv;
    
    csv = fopen("ventas.csv","r"); //cambiarlo despues para que sea un parametro
    if (csv==NULL){
        printf("Error abriendo el archivo");
        return 0;

    }
    
    // leer la primera linea por separado para no almacenarla en la estructura 
    fgets(buffer, sizeof(buffer), csv);
    //printf("%s\n",buffer);

    //parseo
    while(fgets(buffer,sizeof(buffer),csv)){

        data = strtok(buffer,",");
        orders[*index].pizza_id = atoi(data);

        data = strtok(NULL,",");
        orders[*index].order_id = atoi(data);

        data = strtok(NULL,",");
        strcpy(orders[*index].pizza_name_id, data);

        data = strtok(NULL,",");
        orders[*index].quantity = atoi(data);

        data = strtok(NULL,",");
        strcpy(orders[*index].order_date, data);

        data = strtok(NULL,",");
        strcpy(orders[*index].order_time, data);

        data = strtok(NULL,",");
        orders[*index].unit_price = atof(data);

        data = strtok(NULL,",");
        orders[*index].total_price = atof(data);
        
        data = strtok(NULL,",");
        strcpy(orders[*index].pizza_size, data);

        data = strtok(NULL,",");
        strcpy(orders[*index].pizza_category, data);

        data = strtok(NULL,"\"");//
        strcpy(orders[*index].pizza_ingredients, data);


        data = strtok(NULL,",");
        strcpy(orders[*index].pizza_name, data);
        
        (*index)++;
    }
    

    fclose(csv);
    return 1;



}

int main(void){
/*
    int index = 0;
    struct Order orders[100];
    csv_to_array(orders,&index);

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
   
*/
    return 0;
}

