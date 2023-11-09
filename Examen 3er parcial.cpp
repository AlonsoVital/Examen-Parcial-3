#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
void leer_csv(FILE *file, int columna, int count[], int tam)
{
	char linea[4000];
	int indice=0;
	int col=0;
	
	while(fgets(linea, sizeof(linea), file))
	{
		char*palabra=strtok(linea, ",");
		
		while(palabra!=NULL)
		{
			col++;
			if(col==columna)
			{
				indice=atoi(palabra);
				if(indice<tam)
				{
					contador[indice]++;
				}
			}
			palabra=strtok(NULL, ",");
		}
	}
}
*/

int main() 
{
	int filas=50;
	int max=3200;
	int lon=10240;
	
    FILE *file = fopen("emails.csv", "r");
    if (!file) 
	{
        perror("Error al abrir el archivo");
        return 1;
    }

    char buffer[lon];
    char *nombres[max];
    int count[max] = {0};
    int id = 659; 

    if (fgets(buffer, sizeof(buffer), file)) 
	{
        char *token = strtok(buffer, ",");
        int columna = 0;
        while (token && columna <= max) 
		{
            nombres[columna] = strdup(token); 
            token = strtok(NULL, ",");
            columna++;
        }
    }

    for (int filanueva = 0; filanueva <= id && fgets(buffer, sizeof(buffer), file); ++filanueva) 
	{
        
    }

    for (int filanueva = 0; filanueva <= filas && fgets(buffer, sizeof(buffer), file); ++filanueva) 
	{
        char *token = strtok(buffer, ",");
        int columna = 0;
        while (token && columna < max) 
		{
            count[columna] += atoi(token);  
            token = strtok(NULL, ",");
            columna++;
        }
    }

    fclose(file);

    FILE *file2 = fopen("180659.txt", "w");
    if (!file2) 
	{
        perror("Error al abrir el nuevo archivo");
        for (int i = 1; i < max; i++) 
		{
            free(nombres[i]);
        }
        return 1;
    }

    for (int i = 1; i < max && nombres[i] != NULL; i++) 
	{
        fprintf(file2, "%s, %d\n", nombres[i], count[i]);
        free(nombres[i]); 
    }

    fclose(file2);
    printf("\nTodo esta viento en popa\n");

    return 0;
}
