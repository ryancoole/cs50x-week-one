#include <cs50.h>
#include <stdio.h>

// Function prototype
int get_height(void);

int main(void)
{
    // Get user input for pyramid height
    int height = get_height();

    // Loop through each row
    for (int row = 1; row <= height; row++)
    {
        // Print spaces for left pyramid
        for (int space = 0; space < height - row; space++)
        {
            printf(" ");
        }

        // Print left side hashes
        for (int hash = 0; hash < row; hash++)
        {
            printf("#");
        }

        // Print gap
        printf("  ");

        // Print right side hashes
        for (int hash = 0; hash < row; hash++)
        {
            printf("#");
        }

        // Move to next line
        printf("\n");
    }
}

// Prompt user until a valid height is given
int get_height(void)
{
    int h;
    do
    {
        h = get_int("Height: ");
    }
    while (h < 1 || h > 8);
    return h;
}
