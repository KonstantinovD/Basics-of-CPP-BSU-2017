#include <iostream>
using namespace std;

struct Number_Sum
{
    int Number;
    int Sum;
};

void outputMatrix(int m, int n, int** matrix)
{
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
    
}

static void sortArray(Number_Sum* arr, int size)//Sort array to compare "numbers" with the initial order of rows
{
    Number_Sum tempVar;
    
    for (int i = 0; i < size; i++)
    {
        int min = arr[i].Sum;
        int Iter = i;
        for (int j = i; j < size; j++)
        {
            if (min > arr[j].Sum)
            {
                Iter = j;
                min = arr[j].Sum;
            }
        }
        tempVar = arr[i];
        arr[i] = arr[Iter];
        arr[Iter] = tempVar;
    }


}

int** rebildMatrix(int m, int n, int** matrix, Number_Sum* matrSort)
{
    int tempVar;
    int** matrix2 = new int*[m];
    for (int i = 0; i < m; i++)
    {
        matrix2[i] = matrix[matrSort[i].Number];
    }
    delete[] matrix;
    return matrix2;
}

int** sortMatrix(int m, int n, int** matrix)
{
    

    Number_Sum* matrSort = new Number_Sum[m];

    for (int i = 0; i < m; i++)
    {
        matrSort[i].Number = i;
        matrSort[i].Sum = 0;
        for (int j = 0; j < n; j++)//count sum of the current row
        {
            matrSort[i].Sum += matrix[i][j];
        }
    }

    sortArray(matrSort, m);

    matrix = rebildMatrix(m, n, matrix, matrSort);
    delete[] matrSort;

    return matrix;
}

int main()
{
    
    int mSize, nSize;

    cout << "input number of rows and number of columns" << endl;
    cin >> mSize >> nSize;

    cout << "input all elements" << endl;

    int** matrix = new int*[mSize];
    for (int i = 0; i < mSize; i++)
    {
        matrix[i] = new int[nSize];
        for (int j = 0; j < nSize; j++) cin >> matrix[i][j];
    }
    matrix = sortMatrix(mSize, nSize, matrix);

    outputMatrix(mSize, nSize, matrix);
    
    for (int i = 0; i < mSize; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    system("pause");
}