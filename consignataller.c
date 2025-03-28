#include <stdio.h>
 
int main() {
    int id;
    int stock;
    int cantidad;
    int opcion;
    float precio, total_ganancias = 0, venta;
    char nombre[30];
 
    // Registro del producto
 
 
 
    do {
        printf("\nMenu de Opciones:\n");
        printf("1. Registrar producto\n");
        printf("2. Vender producto\n");
        printf("3. Reabastecer producto\n");
        printf("4. Consultar informacion del producto\n");
        printf("5. Mostrar ganancias\n");
        printf("6. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
 
        switch(opcion) {
        case 1:
                printf("Ingrese ID del producto: ");
                scanf("%d", &id);
                printf("Ingrese el nombre del producto: ");
                fflush(stdin);
                fgets(nombre, 30, stdin);
                printf("Ingrese la cantidad inicial en stock: ");
                scanf("%d", &stock);
                printf("Ingrese el precio unitario del producto: ");
                scanf("%f", &precio);
                break;
 
            case 2:
 
                do {
                    printf("Ingrese la cantidad a vender: ");
                    scanf("%d", &cantidad);
                    if (cantidad < 1)
                    {
                        printf("No se pueden ingresar cantidades negativas o cero. Ingrese nuevamente.\n");
                    }
                    if (cantidad>stock)
                    {
                        printf("No se puede realizar la venta, no existe suficiente stock\n");
                    }
                    
                } while (cantidad < 1 || cantidad > stock);
 
                venta = cantidad * precio;
                printf("El precio de esta venta es: %f\n", venta);
                total_ganancias += venta;
                stock -= cantidad;
                printf("El nuevo stock es: %d\n", stock);
                if (stock==0)
                {
                    printf("El stock del producto se terminó, reabastezca el producto.\n");
                }
                break;
 
            case 3:
                cantidad=0;
                printf("Ingrese la cantidad a agregar al stock: ");
                scanf("%d", &cantidad);
                stock+=cantidad;
                break;
 
            case 4:
 
                    printf("\nInformacion del producto:\n");
                    printf("ID: %d\n", id);
                    printf("Nombre: %s", nombre);
                    printf("Stock disponible: %d\n", stock);
                    printf("Precio unitario: %.2f\n", precio);
                break;
 
            case 5:
                printf("Ganancias totales acumuladas: $%.2f\n", total_ganancias);
                break;
 
            case 6:
                printf("Saliendo del programa...\n");
                break;
 
            default:
                printf("Opcion invalida. Intente nuevamente.\n");
        }
 
    } while (opcion != 5);
 
    return 0;
}