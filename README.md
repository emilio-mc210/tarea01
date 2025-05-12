# tarea01
Tarea 1 de plataformas abiertas.

Compilar con:

gcc -Wall archivo_fuente.c -o ejecutable

Funcionamiento:

Para ingresar una matriz se debe modificar el archivo "T1_C4G81.txt", en el cual se debe colocar cada entrada separada por espacios y cada fila en una linea distinta. Al final de cada fila no se debe colocar un espacio o el programa mostrará un mensaje de error.
El archivo "T1_C4G81.txt" contiene un ejemplo de cómo se debe ingresar una matriz.

Validaciones del programa:

    1. El programa verifica que el número total de datos coincida con N × N.

    2. El formato de la matriz en el documento "T1_C4G81.txt".

    3. Si la cantidad de elementos no corresponde al tamaño especificado, o si hay caracteres no binarios, el programa mostrará un mensaje de error.

Detalles:

    1. Se utiliza malloc() para generar la matriz con memoria dinámica, en tiempo de ejecución, adaptándose al tamaño indicado en el archivo.

    2. Después, se recorre la matriz para encontrar la diagonal con la secuencia más larga de 1s en la dirección hacia la esquina inferior izquierda (de derecha a izquierda).

Resultados con matrices de distintos tamaños:

    La matriz es: 
    1 0 1 
    1 0 1 
    0 1 1 

    La secuencia de 1s mas grande es: 4

    La matriz es: 
    1 0 1 0 
    1 0 1 1 
    0 1 1 1 
    0 0 1 1 

    La secuencia de 1s mas grande es: 5

    La matriz es: 
    1 0 1 0 1 0 1 0 
    1 0 1 1 1 0 1 1 
    0 1 1 1 0 1 1 1 
    0 0 1 1 1 0 1 1 
    0 0 1 1 0 0 1 1 
    1 0 1 1 1 0 1 0 
    0 1 1 1 1 1 1 0 
    0 0 1 1 1 0 1 0 

    La secuencia de 1s mas grande es: 6