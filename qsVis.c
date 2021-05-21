#include <GL/glut.h> //Libreria de Open GL y sus complementos
#include <stdlib.h>
#include <unistd.h>
#include "./Alghortims/sort.h"


//Variables globales

float *sample;            //Array muestra de elementos a ordenar.
int n;                    //Tamaño de la muestra.
float x;                  //Ancho de los rectangulos
float y;                  //Altura maxima
int methodslected = 0;        //Metodo sleccionado en el menu
//Funcion que dibuja
void drawbar(float arr[], int size)
{

   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)

   for (int i = 0; i < size; i++)
   {
      // Dibuja un rectangulo con 4 vertices
      glBegin(GL_QUADS);                             // Objeto que representa el un rectangulo en dos dimensiones
      glColor3f(0.0f, 0.0f, 1.0f);                   // Color del rectangulo
      glVertex2f(-1.0 + i * x, -1.0);                // (x1,y1)
      glVertex2f(-1.0 + x * (i + 1), -1.0);          // (x2,y2)
      glVertex2f(-1.0 + x * (i + 1),-1.0  + 2*arr[i] / y); // (x3,y3)
      glVertex2f(-1.0 + i * x, -1.0 + 2*arr[i] / y);       // (x4,y4)
      glEnd();
   }

   glFlush(); //Renderiza el objeto creado.
   usleep(100000);
}

void menu(int choice){
   methodslected = choice;
   glutPostRedisplay();
}

//Funcion que renderiza la ecena,
void renderFunction()
{  
   switch (methodslected)
   {
   case 0:
      drawbar(sample,n);
      break;
   case 1:
      bubbleSort(sample,n,drawbar);
      methodslected=-1;
      break;
   case 2:
      selectionSort(sample,n,drawbar);
      methodslected=-1;
      break;
   case 3:
      insertionSort(sample,n,drawbar);
      methodslected=-1;
      break;   
   case 4:
      shellSort(sample,n,drawbar);
      methodslected=-1;
      break;
   case 5:
      mergeSort(sample,n,drawbar);
      methodslected=-1;
      break;
   case 6:
      quickSort(sample,n,drawbar);
      methodslected=-1;
      break;
   case 7:
      heapSort(sample,n,drawbar);
      methodslected=-1;
      break;

   default: 
      break;
   }
}


float max(float x[], int k)
{
   int i;
   float t;
   t = x[0];
   for (i = 1; i < k; i++)
   {
      if (x[i] > t)
         t = x[i];
   }
   return (t);
}

int main(int argc, char **argv)
{

   printf("Introduzca el tamaño del arreglo:");
   scanf("%d", &n);
   sample = (float *)malloc(sizeof(float) * n);
   
   for(int i = 0;i<n;i++){
      printf("sample[%d] = ",i);
      scanf("%f",&sample[i]);
   }

   x = 2 / ((float)n);
   y = max(sample, n);

   glutInit(&argc, argv);                 // Initialize GLUT
   glutCreateWindow("Algortimos de ordenamiento"); // Create a window with the given title
   glutInitWindowSize(800, 800);          // Set the window's initial width & height
   glutInitWindowPosition(50, 50);        // Position the window's initial top-left corner
   glutDisplayFunc(renderFunction);       // Register display callback handler for window re-paint

   glutCreateMenu(menu);
	glutAddMenuEntry("Intercambio directo", 1);
	glutAddMenuEntry("Seleccion directa", 2);
	glutAddMenuEntry("Insercion directa ", 3);
	glutAddMenuEntry("Shellsort", 4);
	glutAddMenuEntry("Heapsort", 5);
   glutAddMenuEntry("Quicksort", 6);
   glutAddMenuEntry("Mergesort", 7);

   glutAttachMenu(GLUT_RIGHT_BUTTON);

   glutMainLoop();                        // Enter the event-processing loop


   return 0;
}