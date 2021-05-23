#include <GL/glut.h> //Libreria de Open GL y sus complementos
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

//Variables globales

float *sample;            //Array muestra de elementos a ordenar.
int n;                    //Tamaño de la muestra.
float x;                  //Ancho de los rectangulos
float y;                  //Altura maxima
int methodslected = 0;        //Metodo sleccionado en el menu

//Funcion para intercambiar valores en arreglos
void swap(float *xp, float *yp);
 //Metodos de ordenamiennto 
void bubbleSort(float arr[], int n, void display(float*,int));

void selectionSort(float arr[], int n, void display(float*,int));

void insertionSort(float arr[], int n, void display(float*,int));

void shellSort(float arr[], int n, void display(float*,int));

int partition (float arr[], int low, int high, int n,void display(float*,int));

void quickSortaux(float arr[], int low, int high,int n,void display(float*,int));

void quickSort(float arr[], int n,void display(float*,int));

void merge(float arr[], int l, int m, int r,int n, void display(float*,int));

void mergeSortaux(float arr[], int l, int r,int n, void display(float*,int));

void mergeSort(float arr[], int n, void display(float*,int));

void heapify(float arr[], int n, int i,void display(float*,int));

void heapSort(float arr[], int n,void display(float*,int));





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


void swap(float *xp, float *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
// A function to implement bubble sort
void bubbleSort(float arr[], int n, void display(float*,int))
{
   display(arr,n);    
   float x[n];
   for(int k = 0; k<n; k++){
       x[k] = arr[k];
   }
   int i, j;
   for (i = 0; i < n-1; i++)     
 
       // Last i elements are already in place  
       for (j = 0; j < n-i-1; j++)
           if (x[j] > x[j+1]){
              swap(&x[j], &x[j+1]);
             display(x,n);
           }
}
 
void selectionSort(float arr[], int n, void display(float*,int))
{
    display(arr,n);    
    float x[n];
    for(int k = 0; k<n; k++){
       x[k] = arr[k];
    }

    int i, j, min_idx;
  
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (x[j] < x[min_idx])
            min_idx = j;
  
        // Swap the found minimum element with the first element
        swap(&x[min_idx], &x[i]);
        display(x,n);
    }
}


void insertionSort(float arr[], int n, void display(float*,int))
{
    display(arr,n);    
    float x[n];
    for(int k = 0; k<n; k++){
       x[k] = arr[k];
    }
    int i, j;
    float key;
    for (i = 1; i < n; i++)
    {
        key = x[i];
        j = i - 1;
 
        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && x[j] > key)
        {
            x[j + 1] = x[j];
            j = j - 1;
        }
        x[j + 1] = key;
        display(x,n);

    }
}

/* function to sort arr using shellSort */
void shellSort(float arr[], int n, void display(float*,int))
{
    display(arr,n);    
    float x[n];
    for(int k = 0; k<n; k++){
       x[k] = arr[k];
    }
    // Start with a big gap, then reduce the gap
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted
        for (int i = gap; i < n; i += 1)
        {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            int temp = x[i];
 
            // shift earlier gap-sorted elements up until the correct
            // location for a[i] is found
            int j;           
            for (j = i; j >= gap && x[j - gap] > temp; j -= gap)
                x[j] = x[j - gap];
             
            //  put temp (the original a[i]) in its correct location
            x[j] = temp;
            
        }
        display(x,n);
    }
}
 




// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(float arr[], int l, int m, int r,int n, void display(float*,int))
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    /* create temp arrays */
    float L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
            display(arr,n); 
        }
        else {
            arr[k] = R[j];
            j++;
            display(arr,n);
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
        display(arr,n);
    }
 
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
        display(arr,n);
    }
}
 
/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSortaux(float arr[], int l, int r,int n, void display(float*,int))
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;
 
        // Sort first and second halves
        mergeSortaux(arr, l, m,n,display);
        mergeSortaux(arr, m + 1, r,n,display);
 
        merge(arr, l, m, r,n,display);
    }
}

void mergeSort(float arr[], int n, void display(float*,int))
{
    display(arr,n);    
    float x[n];
    for(int k = 0; k<n; k++){
       x[k] = arr[k];
    }
    mergeSortaux(x, 0, n - 1,n,display);
}
  

int partition (float arr[], int low, int high, int n,void display(float*,int))
{
    float pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
 
    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
            display(arr,n);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    display(arr,n);
    return (i + 1);
}
 
/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSortaux(float arr[], int low, int high,int n,void display(float*,int))
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high,n,display);
 
        // Separately sort elements before
        // partition and after partition
        quickSortaux(arr, low, pi - 1,n,display);
        quickSortaux(arr, pi + 1, high,n,display);
    }
}

void quickSort(float arr[], int n,void display(float*,int)){

     display(arr,n);    
    float x[n];
    for(int k = 0; k<n; k++)
        x[k] = arr[k];
   
    quickSortaux(x, 0, n - 1,n,display);

}

void heapify(float arr[], int n, int i,void display(float*,int))
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        display(arr,n);
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest,display);
    }
}
 
// main function to do heap sort
void heapSort(float arr[], int n,void display(float*,int))
{
    display(arr,n);    
    float x[n];
    for(int k = 0; k<n; k++)
        x[k] = arr[k];

    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(x, n, i,display);
 
    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(&x[0], &x[i]);
        display(x,n);
        // call max heapify on the reduced heap
        heapify(x, i, 0,display);
    }
}
 
