#include <stdio.h>
#define N 3

typedef float vector[N];
typedef vector matrix[N];

matrix A, A_1, L, L_T;
float sumII, sumJI;

void printMatrix(matrix matr)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%f\t", matr[i][j]);

        printf("\n");
    }
}

int main()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%f", &A[i][j]);
    
    printf("Matrix A \n");
    
    printMatrix(A);
    
    for(int i = 0; i < N; i++) 
    {
        for(int j = i+1; j < N; j++)
        {
            L[i][j] = 0;
        }
    } 
    
    L[0][0] = sqrt(A[0][0]);

    for(int i= 1; i < N; i++) 
    {
        L[i][0] = A[i][0]/L[0][0];
    }

    for(int i = 1; i < N; i++) 
    {
        sumII = 0;
        for(int p = 0; p < i; p++) 
        {
            sumII += L[i][p]*L[i][p];
        }
        L[i][i] = sqrt( A[i][i] - sumII);
        
        
        
        for(int j = i + 1; j < N; j++)
        {
            sumJI = 0;
            for(int p = 0; p < i; p++)
            {
                sumJI += L[j][p]*L[i][p];
            }
            
            L[j][i] = (A[j][i] - sumJI)/L[i][i]; 
        }
    }
    
    printf("\nMatrix L \n");
    
    printMatrix(L);
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            L_T[i][j] = L[j][i];
        }
    }

    for(int i = 0; i < N; i++) 
    {
        
        for(int j = 0; j < N; j++)
        {
            float sum = 0;
            for(int k = 0; k < N; k++)
            {
                sum += L[i][k] * L_T[k][j];
            }
            A_1[i][j] = sum;
        }
        
    }

    printf("\n\n A = L * L^T\n");
    printMatrix(A_1);
    
    return 0;
}