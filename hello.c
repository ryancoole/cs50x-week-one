#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt the user for their name and store in a variable
    string name = get_string("What is your name?\n");

    // Print a message using the value entered by the user
    printf("hello, %s\n", name);
}
