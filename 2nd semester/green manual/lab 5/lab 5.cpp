#include <iostream>

int main()
{
    int N, M, max_sum = 0;
    std::cout << "enter N: ";
    std::cin >> N;
    std::cout << "enter M: ";
    std::cin >> M;

    if (N < 3 || M < 3 )
    {
        std::cout << "error";
    }
    else
    {
        int a[N][M];
        int rmax = 1000000, rmin = 100000;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                a[i][j] = ((double)rand() / RAND_MAX) * (rmax - rmin) + rmin;
            }
        }
        std::cout << "\nYour matrix:\n";
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {

                std::cout << a[i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
        for (int i = 0; i < N - 2; i++)
        {
            for (int j = 0; j < M - 2; j++)
            {
                int tmp = 0;

                tmp = tmp + a[i][j] + a[i][j + 1] + a[i][j + 2];
                tmp = tmp + a[i + 1][j] + a[i + 1][j + 1] + a[i + 1][j + 2];
                tmp = tmp + a[i + 2][j] + a[i + 2][j + 1] + a[i + 2][j + 2];
                
                if (tmp > max_sum)
                {
                    max_sum = tmp;
                }
            }
        }

        std::cout << "\nMax sum of 3x3 submatrix = " << max_sum << "\nsubmatrix:\n";
        for (int i = 0; i < N - 2; i++)
        {
            for (int j = 0; j < M - 2; j++)
            {
                int tmp = 0;

                tmp = tmp + a[i][j] + a[i][j + 1] + a[i][j + 2];
                tmp = tmp + a[i + 1][j] + a[i + 1][j + 1] + a[i + 1][j + 2];
                tmp = tmp + a[i + 2][j] + a[i + 2][j + 1] + a[i + 2][j + 2];

                if (tmp == max_sum)
                {
                    std::cout << a[i][j] << " " << a[i][j + 1] << " " << a[i][j + 2] << std::endl;
                    std::cout << a[i + 1][j] << " " << a[i + 1][j + 1] << " " << a[i + 1][j + 2] << std::endl;
                    std::cout << a[i + 2][j] << " " << a[i + 2][j + 1] << " " << a[i + 2][j + 2] << std::endl;
                }
            }
        }
    }
    return 0;
}