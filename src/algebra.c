#include "algebra.h"
#include <stdio.h>
#include <math.h>

Matrix create_matrix(int row, int col)
{
    Matrix m;
    m.rows = row;
    m.cols = col;
    return m;
}

Matrix add_matrix(Matrix a, Matrix b)
{
    if (a.cols != b.cols || a.rows != b.rows)
    {
        printf("Error: Matrix a and b must have the same rows and cols.\n");
        return create_matrix(0, 0);
    }
    if (a.rows <= 0 || a.cols <= 0 || a.rows > MAX_MATRIX_SIZE || a.cols > MAX_MATRIX_SIZE)
    {
        printf("Error: Invalid matrix dimensions.\n");
        return create_matrix(0, 0);
    }

    Matrix add_result = create_matrix(a.rows, a.cols);
    for (int i = 0; i < a.rows; i++)
    {
        for (int j = 0; j < a.cols; j++)
        {
            add_result.data[i][j] = a.data[i][j] + b.data[i][j];
        }
    }
    return add_result;
}

Matrix sub_matrix(Matrix a, Matrix b)
{
    if (a.cols != b.cols || a.rows != b.rows)
    {
        printf("Error: Matrix a and b must have the same rows and cols.\n");
        return create_matrix(0, 0);
    }
    if (a.rows <= 0 || a.cols <= 0 || a.rows > MAX_MATRIX_SIZE || a.cols > MAX_MATRIX_SIZE)
    {
        printf("Error: Invalid matrix dimensions.\n");
        return create_matrix(0, 0);
    }

    Matrix sub_result = create_matrix(a.rows, a.cols);
    for (int i = 0; i < a.rows; i++)
    {
        for (int j = 0; j < a.cols; j++)
        {
            sub_result.data[i][j] = a.data[i][j] - b.data[i][j];
        }
    }
    return sub_result;
}
Matrix mul_matrix(Matrix a, Matrix b)
{
    if (a.cols != b.rows)
    {
        printf("Error: The number of cols of matrix a must be equal to the number of rows of matrix b.\n");
        return create_matrix(0, 0);
    }
    if (a.rows <= 0 || a.cols <= 0 || b.rows <= 0 || b.cols <= 0 ||
        a.rows > MAX_MATRIX_SIZE || a.cols > MAX_MATRIX_SIZE || b.cols > MAX_MATRIX_SIZE)
    {
        printf("Error: Invalid matrix dimensions.\n");
        return create_matrix(0, 0);
    }
    Matrix mul_result = create_matrix(a.rows, b.cols);
    for (int i = 0; i < a.rows; i++)
    {
        for (int j = 0; j < b.cols; j++)
        {
            double sum = 0;
            for (int k = 0; k < a.cols; k++)
            {
                sum += a.data[i][k] * b.data[k][j];
            }
            mul_result.data[i][j] = sum;
        }
    }
    return mul_result;
}

Matrix scale_matrix(Matrix a, double k)
{
    if (a.rows <= 0 || a.cols <= 0 || a.rows > MAX_MATRIX_SIZE || a.cols > MAX_MATRIX_SIZE)
    {
        printf("Error: Invalid matrix dimensions.\n");
        return create_matrix(0, 0);
    }
    Matrix scale_result = create_matrix(a.rows, a.cols);
    for (int i = 0; i < a.rows; i++)
    {
        for (int j = 0; j < a.cols; j++)
        {
            scale_result.data[i][j] = a.data[i][j] * k;
        }
    }
    return scale_result;
}

Matrix transpose_matrix(Matrix a)
{
    if (a.rows <= 0 || a.cols <= 0 || a.rows > MAX_MATRIX_SIZE || a.cols > MAX_MATRIX_SIZE)
    {
        printf("Error: Invalid matrix dimensions.\n");
        return create_matrix(0, 0);
    }
    Matrix transpose_result = create_matrix(a.cols, a.rows);
    for (int i = 0; i < transpose_result.rows; i++)
    {
        for (int j = 0; j < transpose_result.cols; j++)
        {
            transpose_result.data[i][j] = a.data[j][i];
        }
    }
    return transpose_result;
}
// 获取a_ij余子式的函数
Matrix get_cofactor(Matrix a, int p, int q, int n)
{
    Matrix cofactor;
    cofactor.cols = n - 1;
    cofactor.rows = n - 1;
    int i = 0;
    int j = 0;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (row != p && col != q)
            {
                cofactor.data[i][j] = a.data[row][col];
                j++;
                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
    return cofactor;
}
double det_matrix(Matrix a)
{
    if (a.cols != a.rows)
    {
        printf("Error: The matrix must be a square matrix.\n");
        return 0;
    }
    if (a.rows <= 0 || a.rows > MAX_MATRIX_SIZE)
    {
        printf("Error: Invalid matrix dimensions.\n");
        return 0;
    }
    else if (a.cols == 1)
    {
        return a.data[0][0];
    }
    else if (a.cols == 2)
    {
        double result_det_2dim = a.data[0][0] * a.data[1][1] - a.data[0][1] * a.data[1][0];
        return result_det_2dim;
    }
    else
    {
        double result_det = 0;
        // 按照第一行展开
        for (int i = 0; i < a.cols; i++)
        {
            Matrix cofactor = get_cofactor(a, 0, i, a.rows);
            result_det += (i % 2 == 0 ? 1 : -1) * a.data[0][i] * det_matrix(cofactor);
        }
        return result_det;
    }
}

Matrix inv_matrix(Matrix a)
{
    if (a.rows != a.cols)
    {
        printf("Error: The matrix must be a square matrix.\n");
        return create_matrix(0, 0);
    }
    if (a.rows <= 0 || a.rows > MAX_MATRIX_SIZE)
    {
        printf("Error: Invalid matrix dimensions.\n");
        return create_matrix(0, 0);
    }
    double det = det_matrix(a);
    if (det == 0)
    {
        printf("Error: The matrix is singular.\n");
        return create_matrix(0, 0);
    }

    int n = a.rows;
    Matrix a_star = create_matrix(n, n); // 伴随矩阵

    // 计算伴随矩阵
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // 计算代数余子式
            Matrix cofactor = get_cofactor(a, j, i, n);
            a_star.data[i][j] = ((i + j) % 2 == 0 ? 1 : -1) * det_matrix(cofactor);
        }
    }

    // 逆矩阵 = 伴随矩阵 / 行列式
    Matrix result_inv = scale_matrix(a_star, 1.0 / det);
    return result_inv;
}

int rank_matrix(Matrix a)
{
    if (a.rows <= 0 || a.cols <= 0 || a.rows > MAX_MATRIX_SIZE || a.cols > MAX_MATRIX_SIZE)
    {
        printf("Error: Invalid matrix dimensions.\n");
        return 0;
    }
    Matrix temp = a; // 复制一份
    int rank = (a.rows < a.cols) ? a.rows : a.cols;
    int row = 0; // 当前处理的行
    // 对每一列进行高斯消元
    for (int col = 0; col < a.cols && row < a.rows; col++)
    {
        if (temp.data[row][col] != 0)
        {
            // 主对角线元素非零，消去下方元素
            for (int i = row + 1; i < a.rows; i++)
            {
                if (temp.data[i][col] != 0)
                {
                    double factor = temp.data[i][col] / temp.data[row][col];
                    // 行运算
                    for (int j = col; j < a.cols; j++)
                    {
                        temp.data[i][j] -= factor * temp.data[row][j];
                    }
                }
            }
            row++; // 移动到下一行
        }
        else
        {
            // 主对角线元素为零，寻找下方非零元素
            int swap_row = -1;
            for (int i = row + 1; i < a.rows; i++)
            {
                if (temp.data[i][col] != 0)
                {
                    swap_row = i;
                    break;
                }
            }

            if (swap_row != -1)
            {
                // 找到非零元素，进行行交换
                for (int j = col; j < a.cols; j++)
                {
                    double t = temp.data[row][j];
                    temp.data[row][j] = temp.data[swap_row][j];
                    temp.data[swap_row][j] = t;
                }
                // 消去下方元素
                for (int i = row + 1; i < a.rows; i++)
                {
                    if (temp.data[i][col] != 0)
                    {
                        double factor = temp.data[i][col] / temp.data[row][col];
                        for (int j = col; j < a.cols; j++)
                        {
                            temp.data[i][j] -= factor * temp.data[row][j];
                        }
                    }
                }
                row++; // 移动到下一行
            }
            else
            {
                // 当前列主对角线及以下全为零，秩减一
                rank--;
                // 跳到下一列，无需移动行
            }
        }
    }

    return rank;
}

double trace_matrix(Matrix a)
{

    if (a.cols != a.rows)
    {
        printf("Error: The matrix must be a square matrix.\n");
        return 0;
    }
    if (a.rows <= 0 || a.cols <= 0 || a.rows > MAX_MATRIX_SIZE || a.cols > MAX_MATRIX_SIZE)
    {
        printf("Error: Invalid matrix dimensions.\n");
        return 0;
    }

    double trace_result = 0;
    for (int i = 0; i < a.rows; i++)
    {
        trace_result += a.data[i][i];
    }
    return trace_result;
}

void print_matrix(Matrix a)
{
    for (int i = 0; i < a.rows; i++)
    {
        for (int j = 0; j < a.cols; j++)
        {
            // 按行打印，每个元素占8个字符的宽度，小数点后保留2位，左对齐
            printf("%-8.2f", a.data[i][j]);
        }
        printf("\n");
    }
}
