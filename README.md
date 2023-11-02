# String Find and Replace in C++

This C++ program is designed to find and replace substrings within a given string. It provides a versatile and efficient way to manipulate strings, offering the following functionalities:

## Functions

The program consists of several functions, each serving a specific purpose:

- `StringLength(char str[])`: Calculates the length of a string.
- `FindString(char mainstr[], char substr[])`: Finds the index of a substring within the main string.
- `RightShift(char mainstr[], int starting_index, int repetition)`: Shifts characters to the right in the main string.
- `replaceWithBiggerString(char mainstr[], char replacestr[], int index, int length_findstr)`: Replaces a substring with a larger replacement string.
- `LeftShift(char mainstr[], int starting_index, int repetition)`: Shifts characters to the left in the main string.
- `replaceWithSmallerString(char mainstr[], char replacestr[], int index, int length_findstr)`: Replaces a substring with a smaller replacement string.
- `replaceWithEqualStrings(char mainstr[], char replacestr[], int index)`: Replaces a substring with a replacement string of equal length.
- `findreplace(char mainstr[], char findstr[], char replacestr[])`: The main function to interact with the program, allowing users to input the main string, find string, and replacement string. It then finds the specified substring in the main string, replaces it with the replacement string, and returns the index where the replacement occurred.

## How It Works

The program starts by calculating the length of a string using the `StringLength` function. It iterates through the string until it reaches the null terminator ('\0') and counts the number of characters.

The `FindString` function is used to locate the substring within the main string. It returns the index where the substring starts within the main string.

To replace the substring, the program provides three different scenarios:

1. If the replacement string is larger than the substring to be replaced, it uses the `RightShift` function to make space for the larger replacement string and then copies the replacement string in place.
2. If the replacement string is smaller than the substring to be replaced, it uses the `LeftShift` function to create space for the smaller replacement string and then copies the replacement string in place.
3. If the replacement string has the same length as the substring to be replaced, it directly copies the replacement string over the substring.

The `findreplace` function takes user input for the main string, find string, and replacement string. It calls the above functions to find and replace the substring. If the substring is found, the program performs the replacement and returns the index where the replacement occurred. If the substring is not found, it returns -1.

## Usage

1. Compile and run the program.
2. Enter the main string, find string, and replacement string when prompted.
3. The program will display the modified main string and the index where the replacement occurred (or -1 if not found).

This C++ program is a versatile tool for finding and replacing substrings within a given string. It offers various replacement scenarios and efficiently handles string manipulation tasks. Enjoy using it for your string operations!
