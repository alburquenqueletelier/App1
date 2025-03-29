#include <stdio.h>
#include <string.h> 
#include "../../types/orders.h"

typedef struct Category {
    
    char name[20];
    int quantity;

} Category;


void quantities_fill(Order *orders, int orders_size, int categories_size, Category *categories){
    for(int i = 0; i < categories_size; i++){
        for(int j = 0; j < orders_size;j++){

            if(strcmp(categories[i].name, orders[j].pizza_category) == 0){
                categories[i].quantity = categories[i].quantity + orders[j].quantity;

            }

        }
    }

}

void categories_fill(Order *orders, int orders_size, int categories_size, Category *categories){

    int index = 0;
    
    char explored[categories_size][20];
    // Llenar los nombres de las categorías
    for (int i = 0; i < orders_size; i++) {
        int is_explored = 0;

        // Verificar si la categoría ya ha sido registrada
        for (int j = 0; j < categories_size; j++) {
            if (strcmp(orders[i].pizza_category, explored[j]) == 0) {
                is_explored = 1;
                break;
            }
        }

        // Si la categoría es nueva, agregarla a explored
        if (is_explored == 0) {
            strcpy(explored[index], orders[i].pizza_category);
            index++;
        }
    }
    // Agregar las categorias de explored a las estructuras
    for (int i = 0; i < categories_size; i++){
        strcpy(categories[i].name, explored[i]);
        categories[i].quantity = 0; // Inicializar quantity 

    }


}




int unique_categories(Order *orders, int size) {
    char explored[size][20];
    int index = 0;

    for (int i = 0; i < size; i++) {
        int is_explored = 0;

        // Verificar si la categoría ya ha sido registrada
        for (int j = 0; j < index; j++) {
            if (strcmp(orders[i].pizza_category, explored[j]) == 0) {
                is_explored = 1;
                break;
            }
        }

        // Si la categoría es nueva, agregarla a explored
        if (is_explored == 0) {
            strcpy(explored[index], orders[i].pizza_category);
            index++;
        }
    }

    return index;  // Retorna el número de categorías únicas
}

void hp(Order *orders, int index){
    // Obtener cantidad de categorias unicas
    int categories_size = unique_categories(orders,index);

    // Crear array de estructuras category con la cantidad de categorias unicas
    Category categories[categories_size];

    //Asignar nombres y cantidad de pizzas vendidas por categoria
    categories_fill(orders, index, categories_size, categories);
    quantities_fill(orders, index, categories_size, categories);

    //Imprimir valores
    for(int i = 0; i < categories_size; i++){
        printf("Pizzas %s vendidas: %d \n", categories[i].name, categories[i].quantity);
    }
}

