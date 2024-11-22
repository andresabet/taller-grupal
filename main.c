#include <stdio.h>
#include "funciones.h"

int main() {
    // Arreglos separados para cada atributo del producto
    char nombres[MAX_PRODUCTOS][MAX_NOMBRE];
    int tiemposFabricacion[MAX_PRODUCTOS];
    int recursosRequeridos[MAX_PRODUCTOS];
    int cantidades[MAX_PRODUCTOS];
    int numProductos = 0;

    int tiempoLimite, recursosLimite;
    int opcion;

    // Configuración de los límites de producción
    printf("Ingrese el tiempo limite de produccion disponible: ");
    scanf("%d", &tiempoLimite);
    printf("Ingrese la cantidad total de recursos disponibles: ");
    scanf("%d", &recursosLimite);

    do {
        printf("\n--- Menu ---\n");
        printf("1. Ingresar producto\n");
        printf("2. Editar producto\n");
        printf("3. Eliminar producto\n");
        printf("4. Mostrar productos\n");
        printf("5. Calcular tiempo y recursos totales\n");
        printf("6. Verificar factibilidad de produccion\n");
        printf("7. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                ingresarProducto(nombres, tiemposFabricacion, recursosRequeridos, cantidades, &numProductos);

                pausarConsola(); // Pausa antes de regresar al menú
                break;
            case 2:
                editarProducto(nombres, tiemposFabricacion, recursosRequeridos, cantidades, numProductos);

                pausarConsola(); // Pausa antes de regresar al menú
                break;
            case 3:
                eliminarProducto(nombres, tiemposFabricacion, recursosRequeridos, cantidades, &numProductos);

                pausarConsola(); // Pausa antes de regresar al menú
                break;
            case 4:
                mostrarProductos(nombres, tiemposFabricacion, recursosRequeridos, cantidades, numProductos);

                pausarConsola(); // Pausa antes de regresar al menú
                break;
            case 5: {
                int tiempoTotal = calcularTiempoTotal(tiemposFabricacion, cantidades, numProductos);
                int recursosTotal = calcularRecursosTotales(recursosRequeridos, cantidades, numProductos);
                printf("Tiempo total de produccion: %d unidades\n", tiempoTotal);
                printf("Recursos totales necesarios: %d unidades\n", recursosTotal);

                pausarConsola(); // Pausa antes de regresar al menú
                break;
            }
            case 6: {
                int tiempoTotal = calcularTiempoTotal(tiemposFabricacion, cantidades, numProductos);
                int recursosTotal = calcularRecursosTotales(recursosRequeridos, cantidades, numProductos);

                    // Imprimir valores calculados para depuración
                    printf("Tiempo total calculado: %d\n", tiempoTotal);
                    printf("Recursos totales calculados: %d\n", recursosTotal);
                    printf("Límites -> Tiempo: %d, Recursos: %d\n", tiempoLimite, recursosLimite);

                if (verificarFactibilidad(tiempoTotal, recursosTotal, tiempoLimite, recursosLimite)) {
                    printf("La produccion es factible.\n");
                } else {
                    printf("La produccion no es factible.\n");
                }

                pausarConsola(); // Pausa antes de regresar al menú
                break;
            }
            case 7:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opcion no valida. Intente de nuevo.\n");
        }
    } while (opcion != 7);

    return 0;
}

