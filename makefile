################################################
################ Para compilar ################
################################################
## Para compilar ejecute el siguiente comando en la terminal:
## make
## Recuerde que debe estar en la carpeta raíz del proyecto. 

################################################
################ Agregar script ################
################################################
## Instrucciones para agregar un nuevo script:
## 1. Agregar carpeta/nombre_del_archivo.o en la sección "OBJECTS".
## 2. Antes de la regla "clean", agregar:
##    carpeta/nombre_del_archivo.o: carpeta/nombre_del_archivo.c carpeta/nombre_del_archivo.h
## 3. Luego, agregar:
##   	$(COMPILER) $(COMPILER_FLAGS) -c carpeta/nombre_del_archivo.c -o carpeta/nombre_del_archivo.o

############################################################
################ Instrucciones compilador ################
############################################################

## Acá se definen variables de configuración
COMPILER = gcc
## -Wall dice al compilador que muestre todos los warnings para mejorar el código
## -g permite depurar el código
COMPILER_FLAGS = -Wall -g		
## OBJECTS es una lista de archivos objeto que se crean en base a los archivos fuentes
## con el objeto de luego enlazarlos para crear el archivo final (app1)
OBJECTS = main.o utils/csv_convert.o utils/get_sales_by_pizza.o metrics/pms/pms.o

# Regla para compilar el programa
all: app1 clean_objects

app1: $(OBJECTS)
	$(COMPILER) $(OBJECTS) -o app1

main.o: main.c utils/csv_convert.h utils/get_sales_by_pizza.h metrics/pms/pms.h
	$(COMPILER) $(COMPILER_FLAGS) -c main.c

utils/csv_convert.o: utils/csv_convert.c utils/csv_convert.h
	$(COMPILER) $(COMPILER_FLAGS) -c utils/csv_convert.c -o utils/csv_convert.o

utils/get_sales_by_pizza.o: utils/get_sales_by_pizza.c utils/get_sales_by_pizza.h
	$(COMPILER) $(COMPILER_FLAGS) -c utils/get_sales_by_pizza.c -o utils/get_sales_by_pizza.o

metrics/pms/pms.o: metrics/pms/pms.c metrics/pms/pms.h
	$(COMPILER) $(COMPILER_FLAGS) -c metrics/pms/pms.c -o metrics/pms/pms.o

clean_objects:
	del /s /q *.o;

clean:
	del /s /q *.o;
	rm -f app1
