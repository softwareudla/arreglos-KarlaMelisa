#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char nombre[5][20];
  char asig[3][20];
  float nota[5][3][5];
  float prom_est=0, prom_asig=0;
  
    //Ingreso de estudiantes
  for( int i=0; i < 5; i++) { 
      // Ingresar nombres
      printf("Ingrese el nombre del estudiante %d: \n",i+1);
      scanf("%s", nombre[i]);
          for( int j=0; j < 3; j++)
          {
              // Ingresar asignaturas
              printf("Ingrese el nombre de la asignatura %d: \n",j+1);
              scanf("%s", asig[j]);
              // Ingresar notas
                          for (int k = 0; k < 3; k++) {
                                  printf("Ingrese la nota %d de %s en %s (0-10): ",k+1, nombre[i], asig[j]);
                                  scanf("%f", &nota[i][j][k]);
                                  if (nota[i][j][k] < 0 || nota[i][j][k] > 10){ 
                                    printf ("Ingrese un numero entre 0  y 10\n");

                                  }
                
                          }
                      }
                  }
//Calculo de promedios
    float promE[5];
    float promA[3];
    float maxEs[5];
    float minEs[5];
    float maxAsig[3];
    float minAsig[3];
    int aprobados[3];
             for (int i = 0; i < 5; i++) {
                promE[i] = 0;
                maxEs[i] = 0;
                minEs[i] = 10;
                 for (int j = 0; j < 3; j++) {
                     float sumaNotas = 0;
                     for (int k = 0; k < 3; k++) {
                         sumaNotas += nota[i][j][k];
                         // Calcular máximas y mínimas
                         
                             if (nota[i][j][k] > maxEs[i]) {
                                 maxEs[i] = nota[i][j][k];
                             }
                             if (nota[i][j][k] < minEs[i]) {
                                 minEs[i] = nota[i][j][k];
                             }
                         }
                     promE[i] += sumaNotas / 9; // Promedio por estudiante
                     promA[j] += sumaNotas /3; // Promedio por asignatura
                     promA[j] /= 3; 

                     // Contar aprobados
                     aprobados[j] = 0; // Reiniciar contador
                     for (int k = 0; k < 3; k++) {
                         if (nota[i][j][k] >= 6) {
                             aprobados[j]++;
                    }
             
        }
    }
   
    }

    // Mostrar resultados
    printf("\nResultados:\n");
    for (int i = 0; i < 5; i++) {
        printf("Estudiante %s - Promedio: %.2f, Max: %.2f, Min: %.2f\n",
               nombre[i], promE[i], maxEs[i], minEs[i]);
    }
    for (int j = 0; j < 3; j++) {
        printf("Asignatura %s - Promedio: %.2f, Max: %.2f, Min: %.2f, Aprobados: %d\n",
               asig[j], promA[j], maxAsig[j], minAsig[j], aprobados[j]);
    }
    return 0;
}