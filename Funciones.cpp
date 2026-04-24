#include<iostream>
#include<cstdio>
#include"ClsArchivoArticulo.h"
#include "ClsArchivoCliente.h"
#include "ClsArchivoVentas.h"
#include "ClsArchivoItemVenta.h"
#include "Funciones.h"

/// Articulos

void copiaSeguridadArticulos()
{

    articulo art;
    FILE *pArt, *pBak;
    pArt=fopen("articulos.dat","rb");
    if (pArt==NULL)
    {
        std::cout<< "No se pudo abrir el archivo 1"<<std::endl;
        return ;
    }
    pBak=fopen("articulos.bkp","wb");
    if (pBak==NULL)
    {
        std::cout<< "No se pudo abrir el archivo 2"<<std::endl;
        fclose(pArt);
        return ;
    }
    while (fread(&art,sizeof art,1,pArt)==1)
    {
        fwrite(&art,sizeof art,1,pBak);
    }
    fclose(pBak);
    fclose(pArt);
    std::cout<<"Copia de seguridad 'Articulos' realizada con exito "<<std::endl;
    system("pause");
    system("cls");
}


void restaurarArticuos()
{
    articulo art;
    FILE *pArt, *pBak;
    pBak=fopen("articulos.bkp","rb");
    if (pBak==NULL)
    {
        std::cout<< "No se pudo abrir el archivo 2"<<std::endl;
        return ;
    }
    pArt=fopen("articulos.dat","wb");
    if (pArt==NULL)
    {
        std::cout<< "No se pudo abrir el archivo 1"<<std::endl;
        fclose(pBak);
        return ;
    }
    while (fread(&art,sizeof art,1,pBak)==1)
    {
        fwrite(&art,sizeof art,1,pArt);
    }
    fclose(pArt);
    fclose(pBak);
    std::cout<<"'Articulos' restaurado exitosamente"<<std::endl;
    std::cout<<std::endl;
    system("pause");
    system("cls");
}

/// Clientes
void copiaSeguridadClientes()
{

    Cliente cli;
    FILE *pCli, *pBak;
    pCli=fopen("clientes.dat","rb");
    if (pCli==NULL)
    {
        std::cout<< "No se pudo abrir el archivo 1"<<std::endl;
        return ;
    }
    pBak=fopen("clientes.bkp","wb");
    if (pBak==NULL)
    {
        std::cout<< "No se pudo abrir el archivo 2"<<std::endl;
        fclose(pCli);
        return ;
    }
    while (fread(&cli,sizeof cli,1,pCli)==1)
    {
        fwrite(&cli,sizeof cli,1,pBak);
    }
    fclose(pBak);
    fclose(pCli);
    std::cout<<"Copia de seguridad 'Clientes' realizada con exito "<<std::endl;
    std::cout<<std::endl;
    system("pause");
    system("cls");
}


void restaurarClientes()
{
    Cliente cli;
    FILE *pCli, *pBak;
    pBak=fopen("clientes.bkp","rb");
    if (pBak==NULL)
    {
        std::cout<< "No se pudo abrir el archivo 2"<<std::endl;
        return ;
    }
    pCli=fopen("clientes.dat","wb");
    if (pCli==NULL)
    {
        std::cout<< "No se pudo abrir el archivo 1"<<std::endl;
        fclose(pBak);
        return ;
    }
    while (fread(&cli,sizeof cli,1,pBak)==1)
    {
        fwrite(&cli,sizeof cli,1,pCli);
    }
    fclose(pCli);
    fclose(pBak);
    std::cout<<"'Clientes' restaurado exitosamente"<<std::endl;
    std::cout<<std::endl;
    system("pause");
    system("cls");
}

///Ventas

void copiaSeguridadVentas()
{

    Ventas ven;
    FILE *pVen, *pBak;
    pVen=fopen("ventas.dat","rb");
    if (pVen==NULL)
    {
        std::cout<< "No se pudo abrir el archivo 1"<<std::endl;
        return ;
    }
    pBak=fopen("ventas.bkp","wb");
    if (pBak==NULL)
    {
        std::cout<< "No se pudo abrir el archivo 2"<<std::endl;
        fclose(pVen);
        return ;
    }
    while (fread(&ven,sizeof ven,1,pVen)==1)
    {
        fwrite(&ven,sizeof ven,1,pBak);
    }
    fclose(pBak);
    fclose(pVen);
    std::cout<<"Copia de seguridad 'Ventas' realizada con exito "<<std::endl;

    ItemVenta itVen;    /// Item Venta copia de seguridad
    FILE *pitVen, *pitBak;
    pitVen=fopen("ItemVenta.dat","rb");
    if (pitVen==NULL)
    {
        std::cout<< "No se pudo abrir el archivo 1"<<std::endl;
        return ;
    }
    pitBak=fopen("ItemVenta.bkp","wb");
    if (pitBak==NULL)
    {
        std::cout<< "No se pudo abrir el archivo 2"<<std::endl;
        fclose(pitVen);
        return ;
    }
    while (fread(&itVen,sizeof itVen,1,pitVen)==1)
    {
        fwrite(&itVen,sizeof itVen,1,pitBak);
    }
    fclose(pitBak);
    fclose(pitVen);
    std::cout<<"Copia de seguridad 'Item de las ventas 'realizada con exito "<<std::endl;
    system("pause");
    system("cls");
}


void restaurarVentas()
{
    Ventas ven;
    FILE *pVen, *pBak;
    pBak=fopen("ventas.bkp","rb");
    if (pBak==NULL)
    {
        std::cout<< "No se pudo abrir el archivo 2"<<std::endl;
        return ;
    }
    pVen=fopen("ventas.dat","wb");
    if (pVen==NULL)
    {
        std::cout<< "No se pudo abrir el archivo 1"<<std::endl;
        fclose(pBak);
        return ;
    }
    while (fread(&ven,sizeof ven,1,pBak)==1)
    {
        fwrite(&ven,sizeof ven,1,pVen);
    }
    fclose(pVen);
    fclose(pBak);
    std::cout<<"'Ventas' restaurado exitosamente"<<std::endl;
    std::cout<<std::endl;

    ItemVenta itVen;         /// Item Venta copia de seguridad
    FILE *pitVen, *pitBak;
    pitBak=fopen("ItemVenta.bkp","rb");
    if (pitBak==NULL)
    {
        std::cout<< "No se pudo abrir el archivo 2"<<std::endl;
        return ;
    }
    pitVen=fopen("ItemVenta.dat","wb");
    if (pitVen==NULL)
    {
        std::cout<< "No se pudo abrir el archivo 1"<<std::endl;
        fclose(pitBak);
        return ;
    }
    while (fread(&itVen,sizeof itVen,1,pitBak)==1)
    {
        fwrite(&itVen,sizeof itVen,1,pitVen);
    }
    fclose(pitVen);
    fclose(pitBak);
    std::cout<<"Items de ventas Restaurado exitosamente"<<std::endl;
    std::cout<<std::endl;
    system("pause");
    system("cls");
}

void restaurarTodo()
{
    restaurarArticuos();
    restaurarClientes();
    restaurarVentas();
    std::cout<<"Todos los archivos fueron restaurados"<<std::endl;
    std::cout<<std::endl;
    system("pause");
    system("cls");

}

void copiaSeguridadTodo()
{

    copiaSeguridadArticulos();
    copiaSeguridadClientes();
    copiaSeguridadVentas();
    std::cout<<"Coopia de seguridad de todos los archivos realizada "<<std::endl;
    std::cout<<std::endl;
    system("pause");
    system("cls");
}

