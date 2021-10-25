/*
 ============================================================================
 Author      : Begnis Valentin
 Description : Parcial 1 - Programación I
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 5

typedef struct{
	int id;
	char procesador[20];
	char marca[20];
	int precio;
} eNotebook;

int aplicarDescuento(int precio);
int contarCaracteres(char string[], char caracter);

int ordenarMarcaYPrecio(eNotebook vec[], int tam);
int mostrarNotebooks(eNotebook vec[], int tam);

int main(void) {
	setbuf(stdout, NULL);

	int precioProducto = 100, descuento = 5, precioFinal;

	char cadena[20] = "Hola como estas", caracter = 'o';
	int cantidadVeces;

	eNotebook notebooks[TAM] = {
		{1000, "Pentium", "Intel", 23000},
		{1001, "Celeron", "Intel", 12000},
		{1002, "Ryzen 5", "AMD", 48000},
		{1003, "i9", "Intel", 75000},
		{1004, "Ryzen 3", "AMD", 25000}
	};

	precioFinal = aplicarDescuento(precioProducto);
	printf("1. Precio final con descuento del %d\%%: $%d\n", descuento, precioFinal);

	cantidadVeces = contarCaracteres(cadena, caracter);

	printf("\n2. Cantidad de caracteres: \'%c\' presentes en la cadena: \"%s\" => %d\n",
			caracter,
			cadena,
			cantidadVeces);

	ordenarMarcaYPrecio(notebooks, TAM);
	printf("\n3.\n");
	mostrarNotebooks(notebooks, TAM);

	return EXIT_SUCCESS;
}

int aplicarDescuento(int precio)
{
	return precio - ((float) 5 * precio / 100);
}

int contarCaracteres(char string[], char caracter)
{
	int contador = 0, i = 0;

	if(string != NULL)
	{
		while(string[i] != '\0')
		{
			if(string[i] == caracter)
			{
				contador++;
			}
			i++;
		}
	}
	return contador;
}

int ordenarMarcaYPrecio(eNotebook vec[], int tam)
{
	int todoOk = 0;
	eNotebook auxNotebook;

	if(vec != NULL && tam > 0)
	{
		for(int i = 0; i < tam - 1; i++)
		{
			for(int j = i + 1; j < tam; j++)
			{
				if(strcmp(vec[i].marca, vec[j].marca) > 0 || (strcmp(vec[i].marca, vec[j].marca) == 0 &&
						vec[i].precio > vec[j].precio))
				{
					auxNotebook = vec[i];
					vec[i] = vec[j];
					vec[j] = auxNotebook;
				}
			}
		}
		todoOk = 1;
	}

	return todoOk;
}

int mostrarNotebooks(eNotebook vec[], int tam)
{
	int todoOk = 0;

	printf("      *** Listado de Notebooks ***     \n");
	printf("   Id      Procesador    Marca   Precio\n");
	printf("-------------------------------------------\n");

	if(vec != NULL && tam > 0)
	{
		for(int i = 0; i< tam; i++)
		{
			printf("  %d      %7s      %5s   %d\n", vec[i].id, vec[i].procesador,
					vec[i].marca,
					vec[i].precio);
		}
	}
	return todoOk;
}

