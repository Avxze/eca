#include <iostream>

using namespace std;

const int ROWS = 32; // Determine the number of generations
const int COLS = ROWS * 2 + 1;

int main()
{
    int grid[ROWS][COLS] = {0};

    grid[0][COLS / 2] = 1; // First generation – one alive cell in the center

    // Generate successive generations
    for (int row = 1; row < ROWS; row++)
    {
        for (int col = 1; col < COLS - 1; col++)
        {
            grid[row][col] = grid[row - 1][col - 1] ^ grid[row - 1][col + 1]; // Rule 90 - left cell XOR right cell
        }
    }

    // Display the result
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            if (grid[row][col] == 1)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }

    return 0;
}
