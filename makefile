################################################
################ Para compilar ################
################################################
## Para compilar ejecute el siguiente comando en la terminal:
## make
## Recuerde que debe estar en la carpeta raíz del proyecto. 

################################################
################ Agregar script ################
################################################
## 1. Asegurarse de que el script creado esté en la raíz del proyecto (de lo contrario debera realizar ajustes)
## En Instrucciones Compilador: 
## 2. Agregar el nombre_del_archivo.o en el archivo Makefile en la sección "OBJECTS"
## 3. Antes del clean, agregar la linea:
## nombre_del_archivo.o: nombre_del_archivo.c nombre_del_archivo.h
## 4. Realizar un salto de línea y luego agregar sangría para agregar:
## 	$(COMPILER) $(COMPILER_FLAGS) -c nombre_del_archivo.c

############################################################
################ Instrucciones compilador ################
############################################################

## Acá se definen variables para hacer el makefile más fácil de manejar
COMPILER = gcc
## -Wall dice al compilador que muestre todos los warnings para mejorar el código
## -g permite depurar el código
COMPILER_FLAGS = -Wall -g		
## OBJECTS es una lista de archivos objeto que se crean en base a los archivos fuentes
## con el objeto de luego enlazarlos para crear el archivo final (app1)
OBJECTS = main.o csv_convert.o

# Regla para compilar el programa
all: app1

app1: $(OBJECTS)
	$(COMPILER) $(OBJECTS) -o app1

main.o: main.c csv_convert.h
	$(COMPILER) $(COMPILER_FLAGS) -c main.c

csv_convert.o: csv_convert.c csv_convert.h
	$(COMPILER) $(COMPILER_FLAGS) -c csv_convert.c

clean:
	rm -f $(OBJECTS) app1
