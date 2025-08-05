#include <cs50.h>
#include <stdio.h>

int calculate_checksum(long number);
int get_length(long number);
int get_start_digits(long number, int length);

int main(void)
{
    // Prompt for credit card number
    long number = get_long("Number: ");

    // Validate checksum
    int checksum = calculate_checksum(number);
    if (checksum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    // Determine length and starting digits
    int length = get_length(number);
    int start_digits = get_start_digits(number, length);

    // Identify card type
    if ((start_digits == 34 || start_digits == 37) && length == 15)
    {
        printf("AMEX\n");
    }
    else if (start_digits >= 51 && start_digits <= 55 && length == 16)
    {
        printf("MASTERCARD\n");
    }
    else if ((start_digits / 10 == 4) && (length == 13 || length == 16))
    {
        // Only the first digit matters for VISA, so divide by 10
        printf("VISA\n");
    }
    else
    {
        // Any other format is invalid
        printf("INVALID\n");
    }
}

// Calculate checksum using Luhn’s algorithm
int calculate_checksum(long number)
{
    int sum = 0;
    int position = 0;

    while (number > 0)
    {
        int digit = number % 10;

        if (position % 2 == 1)
        {
            // Multiply every other digit by 2
            int product = digit * 2;
            sum += product / 10 + product % 10;
        }
        else
        {
            // Add untouched digits directly
            sum += digit;
        }

        number /= 10;
        position++;
    }

    return sum;
}

// Count number of digits in card
int get_length(long number)
{
    int length = 0;
    while (number > 0)
    {
        number /= 10;
        length++;
    }
    return length;
}

// Get first two digits of card number
int get_start_digits(long number, int length)
{
    while (length > 2)
    {
        number /= 10;
        length--;
    }
    return number;
}
