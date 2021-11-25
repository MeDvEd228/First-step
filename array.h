#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

int * ArrayFiller(int siz_x)
{
    int* a;
     a = (int*) malloc((sizeof(int)) * siz_x);
     for (int j = 0; j < siz_x; j++)
        {
            a[j] = (rand() % 50);
        }
        return a;
}



int ** bubbleSort(int **a, int m, int n) {
    int tmp;
    size_t i, j, k, jp, ip;
    size_t size = m*n;
    char flag;

    do {
        flag = 0;
        for (k = 1; k < size; k++) {
            //Вычисляем индексы текущего элемента
            j = k / m;
            i = k - j*m;
            //Вычисляем индексы предыдущего элемента
            jp = (k-1) / m;
            ip = (k-1) - jp*m;
            if (a[i][j] < a[ip][jp]) {
                tmp = a[i][j];
                a[i][j] = a[ip][jp];
                a[ip][jp] = tmp;
                flag = 1;
            }
        }
    } while(flag);

    return a;

}

int * SwapArrayInt(int* a, int X, int Y)
{
    int tmp = a[X];
    a[X] = a[Y];
    a[Y] = tmp;
    return a;
}

void ArrayPrinter2(int** arr,int X, int Y)
{
    for (int i = 0; i < X; i++) {
        for (int j = 0; j < Y; j++) {
            printf("%8d", arr[j][i]);
        }
        printf("\n");
    }
}

void ArrayPrinterFirst(int* arr,int X)
{
        for (int j = 0; j < X; j++) {
            printf("%5d", arr[j]);
        }
        printf("\n");
}

void FreeArray(int ** a, int X)
{
    for (int i = 0; i < X; i++) {
        free(a[i]);
    }
    free(a);
}

void TraboPradoKnut()
{
    double inputs[11], check = 400, result;
    int i;

    printf ("\nPlease enter 11 numbers :");

    for (i = 0; i < 11; i++)
    {
        scanf ("%lf", &inputs[i]);
    }

    printf ("\n\nEvaluating f(x) = |x|^0.5 + 5x^3 for the given inputs :");

    for (i = 10; i >= 0; i--)
        {
          result = sqrt (fabs (inputs[i])) + 5 * pow (inputs[i], 3);

          printf ("\nf(%lf) = ");

          if (result > check)
            {
              printf ("Overflow!");
            }

          else
            {
              printf ("%lf", result);
            }
        }
}







#endif // ARRAY_H_INCLUDED
