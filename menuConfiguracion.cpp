#include <iostream>
#include "rlutil.h"
#include "Funciones.h"
#include "menuConfiguracion.h"
#include "ClsArchivoVentas.h"
#include "ClsArchivoCliente.h"
#include "ClsArchivoArticulo.h"
#include "showItem.h"

void menuConfiguracion(){
    int op = 1, y = 0;
     do {
        rlutil::hidecursor();

        setColor(rlutil::WHITE);
        setBackgroundColor(rlutil::BLACK);

        rlutil::locate(40, 10);
        std::cout << "+================================================+" << std::endl;
        rlutil::locate(40, 11);
        std::cout << "||               MENU CONFIGURACION             ||" << std::endl;
        rlutil::locate(40, 12);
      showItem("   Copia de seguridad del archivo de clientes    ", 40, 13, y == 0);
      showItem("   Copia de seguridad del archivo de articulos   ", 40, 14, y == 1);
      showItem("   Copia de seguridad del archivo de ventas      ", 40, 15, y == 2);
      showItem("       Restaurar el archivo de articulos         ", 40, 16, y == 3);
      showItem("         Restaurar el archivo de ventas          ", 40, 17, y == 4);
      showItem("        Restaurar el archivo de clientes         ", 40, 18, y == 5);
      showItem("     Copia de seguridad de todos los archivos    ", 40, 19, y == 6);
      showItem("         Restaurar todos los archivos            ", 40, 20, y == 7);
      rlutil::locate(40, 21);
        std::cout << "--------------------------------------------------" << std::endl;
      showItem("            Volver al menu principal             ", 40, 22, y == 8);
        int MM = rlutil::getkey();
        switch (MM){
        case 14: //UP
            rlutil::locate(38,13 + y);
            std::cout << " " << std::endl;
            y--;

            if(y < 0)
            {
                y = 0;
            }
            break;

        case 15: //DOWN
            rlutil::locate(38,13 + y);
            std::cout << " " << std::endl;
            y++;

            if(y > 8)
            {
                y = 8;
            }
            break;
        case 1: //ENTER
            switch(y){

        case 0:
            system("cls");
            copiaSeguridadClientes();
            break;

        case 1:
            system("cls");
            copiaSeguridadArticulos();
            break;

        case 2:
            system("cls");
            copiaSeguridadVentas();
            break;

        case 3:
            system("cls");
            restaurarArticuos();
            break;

        case 4 :
            system("cls");
            restaurarVentas();
            break;

        case 5 :
            system("cls");
            restaurarClientes();
            break;

        case 6 :
            system("cls");
            restaurarTodo();
            break;

        case 7 :
            system("cls");
            copiaSeguridadTodo();
            break;

        case 8: op = 0;
                break;
            }
        }
    }
    while(op != 0);
    system("cls");
    return;
}
