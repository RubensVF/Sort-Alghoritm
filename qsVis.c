#include <GL/glut.h> //Libreria de Open GL y sus complementos
#include <stdlib.h>
#include <unistd.h>
#include "./Alghortims/sort.h"


//Variables globales

float *sample;            //Array muestra de elementos a ordenar.
int n;                    //Tamaño de la muestra.
float x;                  //Ancho de los rectangulos
float y;                  //Altura maxima

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


//Funcion que renderiza la ecena,
void renderFunction()
{
   bubbleSort(sample,n,drawbar);
   selectionSort(sample,n,drawbar);
   insertionSort(sample,n,drawbar);
   shellSort(sample,n,drawbar);
   mergeSort(sample,n,drawbar);
   quickSort(sample,n,drawbar); 
   heapSort(sample,n,drawbar);
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

   n = 10;
   sample = (float *)malloc(sizeof(float) * n);
   sample[0] = 20;
   sample[1] = 9;
   sample[2] = 8;
   sample[3] = 7;
   sample[4] = 6;
   sample[5] = 5;
   sample[6] = 4;
   sample[7] = 3;
   sample[8] = 2;
   sample[9] = 10;
   x = 2 / ((float)n);
   y = max(sample, n);

   glutInit(&argc, argv);                 // Initialize GLUT
   glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
   glutInitWindowSize(800, 800);          // Set the window's initial width & height
   glutInitWindowPosition(50, 50);        // Position the window's initial top-left corner
   glutDisplayFunc(renderFunction);       // Register display callback handler for window re-paint
   glutMainLoop();                        // Enter the event-processing loop
   return 0;
}