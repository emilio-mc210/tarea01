#include<stdio.h>
#include<stdlib.h>

int encontrar_tamano(FILE *archivo){
    char caracter;
    int filas = 1, columnas = 1, max_col = 0;
    //Se recorre el archivo caracter por caracter
    while((caracter = fgetc(archivo)) != EOF){
        if(caracter == ' '){
            columnas++;
        }
        else if(caracter == '\n'){
            filas++;
            if(columnas > max_col){
                max_col = columnas;
            }else if(columnas != max_col){
                return -1; //Hay filas mas grandes que otras
            }
            columnas = 1;
        }
    }
    //Se comprueba que la matriz sea cuadrada
    if(filas != max_col){
        return -1;
    }
    return filas;
}

int llenar_matriz(FILE *archivo, int tamano, int **matriz){
    rewind(archivo);
    for(int i=0; i<tamano; i++){
        for(int j=0; j<tamano; j++){
            //Llenar la matriz y revisar si hay filas mas pequenas que otras
            if(fscanf(archivo, "%i", &matriz[i][j]) != 1){
                printf("Error: La matriz no es cuadrada.\n");
                return 1;
            }
            //Revisar si es binaria
            if(matriz[i][j] != 0 && matriz[i][j] !=1){
                printf("Error: La matriz no es binaria.\n");
                return 1;
            }
        }
    }

    //Cerrar archivo
    fclose(archivo);

    return 0;
}

int encontrar_diagonal_mas_larga(int **matriz, int tamano){
    int diagonal = 0, maximo = 0;
    int i,j,k;

    //Revisar diagonales hacia la esquina inferior izquierda (de derecha a izquierda)
    //Ciclo que revisa diagonales desde la inferior derecha a la central
    for(k=tamano-1; k>=0; k--){
        for(i=k, j=tamano-1; i<tamano; i++, j--){
            if(matriz[i][j] == 1){
                diagonal++;
                if(diagonal > maximo){
                    maximo = diagonal;
                }
            }
            else{
                diagonal = 0;
            }
        }
    }
    //Diagonales a la izquierda de la central hasta la esquina superior izquierda
    for(k=tamano-2; k>=0; k--){ //tamano-2 para no repetir la central
        for(i=0, j=k; j>=0; i++, j--){ 
            if(matriz[i][j] == 1){
                diagonal++;
                if(diagonal > maximo){
                    maximo = diagonal;
                }
            }
            else{
                diagonal = 0;
            }
        }
    }

    return maximo;
}

int main() {
    //Abrir el archivo
    FILE *archivo = fopen("T1_C4G871.txt", "r");

    //Revisar que el archivo existe
    if(archivo == NULL){
        printf("Error: no se logra abrir el archivo.\n");
        fclose(archivo);
        return 1;
    }

    //Obtener el tamano de la matriz
    int tamano = encontrar_tamano(archivo);
    if(tamano <= 0){
        printf("Error: La matriz no es cuadrada.\n");
        fclose(archivo);
        return 1;
    }

    //Crear la matriz de forma dinamica 
    int **matriz = malloc(tamano * sizeof(int*)); //Crea la cantidad de filas (n punteros de enteros)
    for(int i=0; i<tamano; i++){
        matriz[i] = malloc(tamano * sizeof(int)); //Le da tamano a cada fila (punteros de enteros)
    }

    //Llenar la matriz
    int resultado = llenar_matriz(archivo, tamano, matriz);

    if(resultado == 0){
        //Imprimir la matriz
        printf("La matriz es: \n");
        for(int i=0;i<tamano;i++){
            for(int j=0;j<tamano;j++){
                printf("%i ", matriz[i][j]);
            }
            printf("\n");
        }
        printf("\n");

        int diagonal_mas_larga = encontrar_diagonal_mas_larga(matriz, tamano);
        printf("La secuencia de 1s mas grande es: %d\n", diagonal_mas_larga);
    }

    //Liberar memoria
    for(int i=0; i<tamano; i++){
        free(matriz[i]);
    }
    
    return 0;
}