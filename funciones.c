#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "funciones.h"

void ingresarProducto(char nombres[][MAX_NOMBRE], int tiemposFabricacion[], int recursosRequeridos[], int cantidades[], int *numProductos) {
    if (*numProductos >= MAX_PRODUCTOS) {
        printf("No se pueden ingresar mas productos.\n");
        return;
    }

    printf("Ingrese el nombre del producto: ");
    scanf("%s", nombres[*numProductos]);
    printf("Ingrese el tiempo de fabricacion (en unidades): ");
    scanf("%d", &tiemposFabricacion[*numProductos]);
    printf("Ingrese la cantidad de recursos requeridos: ");
    scanf("%d", &recursosRequeridos[*numProductos]);
    printf("Ingrese la cantidad demandada: ");
    scanf("%d", &cantidades[*numProductos]);

    (*numProductos)++;
}

void editarProducto(char nombres[][MAX_NOMBRE], int tiemposFabricacion[], int recursosRequeridos[], int cantidades[], int numProductos) {
    char nombreBuscar[MAX_NOMBRE];
    printf("Ingrese el nombre del producto a editar: ");
    scanf("%s", nombreBuscar);

    for (int i = 0; i < numProductos; i++) {
        if (strcmp(nombres[i], nombreBuscar) == 0) {
            printf("Producto encontrado. Ingrese los nuevos datos:\n");
            printf("Nuevo nombre: ");
            scanf("%s", nombres[i]);
            printf("Nuevo tiempo de fabricacion: ");
            scanf("%d", &tiemposFabricacion[i]);
            printf("Nuevos recursos requeridos: ");
            scanf("%d", &recursosRequeridos[i]);
            printf("Nueva cantidad demandada: ");
            scanf("%d", &cantidades[i]);
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

void eliminarProducto(char nombres[][MAX_NOMBRE], int tiemposFabricacion[], int recursosRequeridos[], int cantidades[], int *numProductos) {
    char nombreBuscar[MAX_NOMBRE];
    printf("Ingrese el nombre del producto a eliminar: ");
    scanf("%s", nombreBuscar);

    for (int i = 0; i < *numProductos; i++) {
        if (strcmp(nombres[i], nombreBuscar) == 0) {
            // Mover todos los elementos posteriores hacia adelante para sobrescribir el eliminado
            for (int j = i; j < *numProductos - 1; j++) {
                strcpy(nombres[j], nombres[j + 1]);
                tiemposFabricacion[j] = tiemposFabricacion[j + 1];
                recursosRequeridos[j] = recursosRequeridos[j + 1];
                cantidades[j] = cantidades[j + 1];
            }
            (*numProductos)--;
            printf("Producto eliminado.\n");
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

int calcularTiempoTotal(int tiemposFabricacion[], int cantidades[], int numProductos) {
    int tiempoTotal = 0;
    for (int i = 0; i < numProductos; i++) {
        tiempoTotal += tiemposFabricacion[i] * cantidades[i];
    }
    return tiempoTotal;
}

int calcularRecursosTotales(int recursosRequeridos[], int cantidades[], int numProductos) {
    int recursosTotal = 0;
    for (int i = 0; i < numProductos; i++) {
        recursosTotal += recursosRequeridos[i] * cantidades[i];
    }
    return recursosTotal;
}

bool verificarFactibilidad(int tiempoTotal, int recursosTotal, int tiempoLimite, int recursosLimite) {
    return tiempoTotal <= tiempoLimite && recursosTotal <= recursosLimite;
}

void mostrarProductos(char nombres[][MAX_NOMBRE], int tiemposFabricacion[], int recursosRequeridos[], int cantidades[], int numProductos) {
    printf("\n--- Lista de productos ---\n");
    for (int i = 0; i < numProductos; i++) {
        printf("Producto %d:\n", i + 1);
        printf("Nombre: %s\n", nombres[i]);
        printf("Tiempo de fabricacion: %d\n", tiemposFabricacion[i]);
        printf("Recursos requeridos: %d\n", recursosRequeridos[i]);
        printf("Cantidad: %d\n\n", cantidades[i]);
    }
}

void pausarConsola() {
    printf("\nPresione Enter para continuar...\n");
    getchar(); // Limpia el buffer de entrada
    getchar(); // Espera a que el usuario presione Enter
}