#include <stdio.h>

int main() {
   int id = -1;
   int stock = 0;
   int cantidad;
   int opcion;
   float precio = 0, total_ganancias = 0, venta, descuento = 0;
   char nombre[30];
   int producto_registrado = 0;
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
       if (opcion != 1 && !producto_registrado) {
           printf("Debe registrar un producto antes de acceder a otras opciones.\n");
           continue;
       }
       switch (opcion) {
           case 1:
               do {
                   printf("Ingrese ID del producto: ");
                   scanf("%d", &id);
                   if (id <= 0) {
                       printf("Error: Solo se aceptan numeros positivos.\n");
                   }
               } while (id <= 0);
               getchar();  // Limpiar buffer
               printf("Ingrese el nombre del producto: ");
               fgets(nombre, 30, stdin);
               do {
                   printf("Ingrese la cantidad inicial en stock: ");
                   scanf("%d", &stock);
                   if (stock <= 0) {
                       printf("Error: Solo se aceptan numeros positivos.\n");
                   }
               } while (stock <= 0);
               do {
                   printf("Ingrese el precio unitario del producto: ");
                   scanf("%f", &precio);
                   if (precio <= 0) {
                       printf("Error: Solo se aceptan numeros positivos.\n");
                   }
               } while (precio <= 0);
               producto_registrado = 1;
               break;
           case 2:
               do {
                   printf("Ingrese la cantidad a vender: ");
                   scanf("%d", &cantidad);
                   if (cantidad <= 0) {
                       printf("Error: Solo se aceptan numeros positivos.\n");
                   } else if (cantidad > stock) {
                       printf("No hay suficiente stock. Ingrese nuevamente.\n");
                   }
               } while (cantidad <= 0 || cantidad > stock);
               if (cantidad >= 10) {
                   descuento = 20;
               } else if (cantidad >= 5) {
                   descuento = 10;
               } else {
                   descuento = 0;
               }
               venta = cantidad * precio * (1 - descuento / 100);
               printf("El precio de esta venta con un descuento del %.0f%% es: %.2f\n", descuento, venta);
               total_ganancias += venta;
               stock -= cantidad;
               printf("El nuevo stock es: %d\n", stock);
               if (stock == 0) {
                   printf("El stock del producto se termino, reabastezca el producto.\n");
               }
               break;
           case 3:
               do {
                   printf("Ingrese la cantidad a agregar al stock: ");
                   scanf("%d", &cantidad);
                   if (cantidad <= 0) {
                       printf("Error: Solo se aceptan numeros positivos.\n");
                   }
               } while (cantidad <= 0);
               stock += cantidad;
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
   } while (opcion != 6);
   return 0;
}
