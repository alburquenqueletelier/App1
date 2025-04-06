#include <string.h>
#include <stdio.h>
#include "../../types/orders.h"

typedef struct {
	char ingredient_name[40];
	int ingredient_frequency;
} Ingredient;

// Calcular la suma de todos los ingredientes en todas las ordenes
int ingredient_total(Order *orders, int size){
	int total_ingredients = 0;
	for(int i = 0; i < size; i++){
		total_ingredients = total_ingredients + orders[i].ingredient_count;
	}

	return total_ingredients;

}
// Inicializar el struct de ingredientes
void initialize_ingredients(Ingredient *ingredients, int ingredients_size){
	for(int i = 0; i < ingredients_size; i++){
		ingredients[i].ingredient_frequency = 0;
		strcpy(ingredients[i].ingredient_name, "Null");
	}
}

// Llenar el array de structs con cada ingrediente unico y las veces que aparece. Retornar cantidad de ingredientes unicos
int ingredient_array_fill(Order *orders, int orders_size, Ingredient *ingredients, int ingredients_size){

	int unique_ingredients_count = 0;
	
	for(int i = 0; i < orders_size; i++){
		for(int j = 0; j < orders[i].ingredient_count; j++){
			for(int k = 0; k < ingredients_size; k++){

				if(strcmp(orders[i].pizza_ingredients[j],ingredients[k].ingredient_name) == 0){
					ingredients[k].ingredient_frequency++;
					break;
				}
				if(strcmp(ingredients[k].ingredient_name, "Null") == 0){
					strcpy(ingredients[k].ingredient_name , orders[i].pizza_ingredients[j]);
					ingredients[k].ingredient_frequency++;
                    unique_ingredients_count++;
					break;
				}
			}
			
		}
	}

	return unique_ingredients_count;

}


void ims(Order *orders, int size){
	char most_sold_ingredient[40];
	int ingredients_size = ingredient_total(orders,size);
	Ingredient ingredients[ingredients_size];
	initialize_ingredients(ingredients, ingredients_size);
	int unique_ingredients_count = ingredient_array_fill(orders, size, ingredients, ingredients_size);

	//calcular ims ;
	int max_sales = 0;
	for(int i = 0; i < unique_ingredients_count; i++){
		if(ingredients[i].ingredient_frequency > max_sales){
			max_sales = ingredients[i].ingredient_frequency;
			strcpy(most_sold_ingredient ,ingredients[i].ingredient_name);

		}

	}
        printf("Ingrediente mas vendido: %s ventas: %d \n", most_sold_ingredient, max_sales);


	

	


}




