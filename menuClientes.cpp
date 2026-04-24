#include <iostream>
#include "rlutil.h"
#include "menuClientes.h"
#include "ClsArchivoCliente.h"
#include "showItem.h"

void menuClientes()
{
    archivoCli cl("clientes.dat");

    int op = 1, y = 0;

    do
    {
        rlutil::hidecursor();

        setColor(rlutil::WHITE);
        setBackgroundColor(rlutil::BLACK);

        rlutil::locate(40, 10);
        std::cout << "+=====================================+" << std::endl;
        rlutil::locate(40, 11);
        std::cout << "||           MENU CLIENTES           ||" << std::endl;
        rlutil::locate(40, 12);
        std::cout << "+=====================================+" << std::endl;
        showItem("            AGREGAR CLIENTE            ", 40, 13, y == 0);
        showItem("          BUSCAR CLIENTE POR DNI       ", 40, 14, y == 1);
        showItem("            MODIFICAR E-MAIL           ", 40, 15, y == 2);
        showItem("           MODIFICAR TELEFONO          ", 40, 16, y == 3);
        showItem("       MOSTRAR TODOS LOS CLIENTES      ", 40, 17, y == 4);
        showItem("         DAR DE ALTA UN CLIENTE        ", 40, 18, y == 5);
        showItem("         DAR DE BAJA UN CLIENTE        ", 40, 19, y == 6);
        rlutil::locate(40, 20);
        std::cout << "---------------------------------------" << std::endl;
        showItem("        VOLVER AL MENU PRINCIPAL       ", 40, 21, y == 7);

        int key = rlutil::getkey();

        switch(key)
        {
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

            if(y > 7)
            {
                y = 7;
            }
            break;

        case 1: //ENTER

            switch(y)
            {
            case 0:
                system("cls");
                cl.AgregarArchivoCli();
                break;

            case 1:
                system("cls");
                cl.MostrarClienteDni();
                break;

            case 2:
                system("cls");
                cl.ModificarEmail();
                break;
            case 3:
                system("cls");
                cl.ModificarTelefono();
                break;
            case 4:
                system("cls");
                cl.MostrarArchivoCliente();
                break;

            case 5:
                system("cls");
                cl.altaCliente();
                break;

            case 6:
                system("cls");
                cl.BajaCliente();
                break;


            case 7:
                op = 0;
                break;
            }
        }
    }
    while(op != 0);

    system("cls");
    return;
}


