// --------------------------------------------------
// -*- C -*- Compatibility Header
//
// Copyright (C) 2023 Developer Jarvis (Pen Name)
//
// This file is part of the [Project Name] Library. This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.
//
// SPDX-License-Identifier: GPL-3.0-or-later
//
// random_password_generator - Options: length, numbers, symbols, uppercase, etc
//
// Author: Developer Jarvis (Pen Name)
// Contact: https://github.com/DeveloperJarvis
//
// --------------------------------------------------

// --------------------------------------------------
// header files
// --------------------------------------------------
#include <stdio.h>  // for printf()
#include <string.h> // for strcmp()
#include <stdlib.h> // for srand(), rand(), exit()
#include <time.h>   // for time()

#include "random_password_generator.h"

// --------------------------------------------------
// main function
// --------------------------------------------------
int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)
            display_help(argv[0]);
        else if (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--version") == 0)
            display_version(argv[0]);
    }
    else if (argc == 1)
    {
        srand(time(NULL));
        random_password();
    }
    else
    {
        printf("Invalid input\n");
        display_help(argv[0]);
    }
    return 0;
}

// --------------------------------------------------
// helper methods
// --------------------------------------------------
void display_help(const char *s)
{
    printf("Usage: %s [options]\n", s);
    printf(" -h --help\tDisplay help\n");
    printf(" -v --version\tDisplay version\n");
}

void display_version(const char *s)
{
    printf("%s version: 1.0.0\n", s);
}
// --------------------------------------------------
// password generator core
// --------------------------------------------------
void random_password()
{
    int length = user_input(0);
    int upperCase = user_input(1);
    int lowerCase = user_input(2);
    int digits = user_input(3);
    int specialCharacters = user_input(4);

    // Check if the sum of categories matches the length
    if (length == (upperCase + lowerCase + digits + specialCharacters))
    {
        char password[length + 1]; // Create password array
        int i = 0;
        // Add required characters to the array
        for (i = 0; i < upperCase; i++)
            password[i] = random_character(0); // Upper case
        for (i = upperCase; i < upperCase + lowerCase; i++)
            password[i] = random_character(1); // Lower case
        for (i = upperCase + lowerCase; i < upperCase + lowerCase + digits; i++)
            password[i] = random_character(2); // Digits
        for (i = upperCase + lowerCase + digits; i < length; i++)
            password[i] = random_character(3); // Special characters

        // Shuffle the password array to ensure randomness
        for (i = 0; i < length; i++)
        {
            int j = rand() % length;
            char temp = password[i];
            password[i] = password[j];
            password[j] = temp;
        }
        password[length] = '\0'; // Null terminator
        printf("Your required password: %s\n", password);
    }
    else
    {
        printf("Your input password length does not match provided count of upper case, lower case,\n");
        printf("digits and special characters\n");
        printf("Please check and retry\n");
    }
}

int user_input(int flag)
{
    int user_response;
    while (1)
    {
        if (flag == 0)
            printf("Enter length of your desired password: ");
        else if (flag == 1)
            printf("Enter number of Upper case characters required: ");
        else if (flag == 2)
            printf("Enter number of Lower case characters required: ");
        else if (flag == 3)
            printf("Enter number of Digits required: ");
        else if (flag == 4)
            printf("Enter number of Special characters required: ");
        // Try to read an integer input
        if (scanf("%d", &user_response) != 1)
        {
            printf("Invalid input. Please enter numeric value only\n");
            clear_input_buffer(); // Clear invalid input from buffer
            continue;
        }

        // Clear any remaining characters in the buffer
        clear_input_buffer();
        if (user_response <= 0)
        {
            printf("Input cannot be negative or zero. Please enter a positive value\n");
            clear_input_buffer();
            continue;
        }
        else
            break;
    }
    // printf("You entered: %d\n", user_response);
    // clear_input_buffer();
    return user_response;
}

void clear_input_buffer()
{
    int ch;
    // Consume all characters until newline or EOF
    while ((ch = getchar()) != '\n' && ch != EOF)
        ; // clearing input buffer
}

char random_character(int flag)
{
    char ch;
    switch (flag)
    {
    case 0: // upper case A to Z
    {
        ch = 'A' + (rand() % 26);
        break;
    }
    case 1: // lower case a to z
    {
        ch = 'a' + (rand() % 26);
        break;
    }
    case 2: // digits 0 to 9
    {
        ch = '0' + (rand() % 10);
        break;
    }
    case 3: // special characters
    {
        char special_chars[] = "!@#$%^&*()_-+=<>?/{}|:;,.";
        ch = special_chars[rand() % (sizeof(special_chars) - 1)];
        break;
    }
    default:
    {
        printf("Error occured generating random password\n");
        exit(1);
    }
    }
    return ch;
}
