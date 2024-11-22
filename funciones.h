#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// Constantes
#define MAX_NOMBRE 100
#define MAX_PRODUCTOS 100

// Declaraciones de funciones
void ingresarProducto(char nombres[][MAX_NOMBRE], int tiemposFabricacion[], int recursosRequeridos[], int cantidades[], int *numProductos);
void editarProducto(char nombres[][MAX_NOMBRE], int tiemposFabricacion[], int recursosRequeridos[], int cantidades[], int numProductos);
void eliminarProducto(char nombres[][MAX_NOMBRE], int tiemposFabricacion[], int recursosRequeridos[], int cantidades[], int *numProductos);
int calcularTiempoTotal(int tiemposFabricacion[], int cantidades[], int numProductos);
int calcularRecursosTotales(int recursosRequeridos[], int cantidades[], int numProductos);
bool verificarFactibilidad(int tiempoTotal, int recursosTotal, int tiempoLimite, int recursosLimite);
void mostrarProductos(char nombres[][MAX_NOMBRE], int tiemposFabricacion[], int recursosRequeridos[], int cantidades[], int numProductos);
void pausarConsola();
