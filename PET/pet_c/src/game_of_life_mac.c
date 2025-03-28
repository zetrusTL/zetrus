#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define WIDTH 80
#define HEIGHT 25

void print_grid(int grid[HEIGHT][WIDTH]);
void print_end_grid(int grid[HEIGHT][WIDTH]);
int count_neighbors(int grid[HEIGHT][WIDTH], int x, int y);

int update_grid(int grid[HEIGHT][WIDTH]);

void input_matrix(int grid[HEIGHT][WIDTH]);
int change_speed(char button, int *stop, int speed);
int check(int grid[HEIGHT][WIDTH], int new_grid[HEIGHT][WIDTH]);

int main()
{
    int stop = 0;

    int grid[HEIGHT][WIDTH] = {0};
    input_matrix(grid);

    int speed = 500;

    if (freopen("/dev/tty", "r", stdin))
        initscr();
    nodelay(stdscr, true);

    while (stop != 1)
    {
        char button = getch();
        speed = change_speed(button, &stop, speed);
        print_grid(grid);
        if (update_grid(grid) == 2000)
        {
            stop = 1;
        }

        usleep(speed * 1000);
    }

    endwin();

    print_end_grid(grid);
    printf("END GAME!");
    return 0;
}

// Функция для отрисовки сетки
void print_grid(int grid[HEIGHT][WIDTH])
{
    clear();

    // Отрисовка верхней границы
    for (int j = 0; j < WIDTH + 2; j++)
    {
        printw("-");
    }
    printw("\n");

    // Отрисовка сетки
    for (int i = 0; i < HEIGHT; i++)
    {
        printw("|"); // Левая граница
        for (int j = 0; j < WIDTH; j++)
        {
            if (grid[i][j] == 1)
            {
                printw("%c", '*');
            }
            else
            {
                printw("%c", ' ');
            }
        }
        printw("|\n"); // Правая граница
    }

    // Отрисовка нижней границы
    for (int j = 0; j < WIDTH + 2; j++)
    {
        printw("-");
    }
    printw("\n");
}

// Функция для подсчета соседей
int count_neighbors(int grid[HEIGHT][WIDTH], int x, int y)
{
    int count = 0;
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (i == 0 && j == 0)
                continue;
            int nx = (x + i + HEIGHT) % HEIGHT;
            int ny = (y + j + WIDTH) % WIDTH;
            count = count + grid[nx][ny];
        }
    }
    return count;
}

// Функция для обновления сетки
int update_grid(int grid[HEIGHT][WIDTH])
{
    int new_grid[HEIGHT][WIDTH];

    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            int neighbors = count_neighbors(grid, i, j);
            if (grid[i][j] == 1)
            {
                if (neighbors == 2 || neighbors == 3)
                {
                    new_grid[i][j] = 1;
                }
                else
                {
                    new_grid[i][j] = 0;
                }
            }
            else
            {
                if (neighbors == 3)
                {
                    new_grid[i][j] = 1;
                }
                else
                {
                    new_grid[i][j] = 0;
                }
            }
        }
    }

    int r = check(grid, new_grid);

    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            grid[i][j] = new_grid[i][j];
        }
    }
    return r;
}

void input_matrix(int grid[HEIGHT][WIDTH])
{
    for (int i = 0; i < HEIGHT; ++i)
    {
        for (int j = 0; j < WIDTH; ++j)
        {
            scanf("%d", &grid[i][j]);
        }
    }
}

int change_speed(char button, int *stop, int speed)
{
    if (button == '6')
    {
        speed = 1;
    }
    else if (button == '5')
    {
        speed = 100;
    }
    else if (button == '4')
    {
        speed = 400;
    }
    else if (button == '3')
    {
        speed = 700;
    }
    else if (button == '2')
    {
        speed = 1000;
    }
    else if (button == '1')
    {
        speed = 1500;
    }
    else if (button == 'q')
    {
        *stop = 1;
    }
    return speed;
}

int check(int grid[HEIGHT][WIDTH], int new_grid[HEIGHT][WIDTH])
{
    int ans = 0;
    for (int i = 0; i < HEIGHT; ++i)
    {
        for (int j = 0; j < WIDTH; ++j)
        {
            if (grid[i][j] == new_grid[i][j])
            {
                ans++;
            }
        }
    }
    return ans;
}

void print_end_grid(int grid[HEIGHT][WIDTH])
{
    clear();

    // Отрисовка верхней границы
    for (int j = 0; j < WIDTH + 2; j++)
    {
        printf("-");
    }
    printf("\n");

    // Отрисовка сетки
    for (int i = 0; i < HEIGHT; i++)
    {
        printf("|"); // Левая граница
        for (int j = 0; j < WIDTH; j++)
        {
            if (grid[i][j] == 1)
            {
                printf("%c", '*');
            }
            else
            {
                printf("%c", ' ');
            }
        }
        printf("|\n"); // Правая граница
    }

    // Отрисовка нижней границы
    for (int j = 0; j < WIDTH + 2; j++)
    {
        printf("-");
    }
    printf("\n");
}