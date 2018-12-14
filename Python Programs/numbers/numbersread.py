# Daniel A. Brooks
# 269416

# Pseudocode:
# Define the main function:
#   Explain the purpose of the program to the user.
#   Open the numbers.txt file for reading.
#   Call the determine_even function.
#   Display the total number of odd and even integers.
#   Close the numbers.txt file.
# Define the determine_even function:
#   Create an odd counter and an even counter.
#   Read each line in the file:
#     Create a test for whether the number is odd or even:
#         If odd, add 1 to odd_counter; else, add 1 to even_counter.
#     Display the number.
#   Return the odd and even counters.
# Call the main function.

# Define the main function.
def main():
    # Explain the purpose of the program.
    print('This program will display the numbers in the "numbers.txt"', \
          'file\nand then total the number of even and odd', \
          'integers in the file.\n')

    # Open the numbers.txt file for reading.
    numbers_file = open('numbers.txt', 'r')

    # Call the determine_even function.
    odd_count, even_count = determine_even(numbers_file)

    # Display the total number of odd and even integers.
    print('\nTotal number of even integers: ', even_count)
    print('Total number of odd integers: ', odd_count)

    # Close the numbers.txt file.
    numbers_file.close()

# Define the determine_even function.
def determine_even(numbers_file):
    # Create an odd counter and an even counter.
    odd = 0
    even = 0
    
    # Read each line in the file.
    for line in numbers_file:
        
        # Create a test for odd or even.
        number = int(line)
        if (number % 2) == 0:
            even += 1
        else:
            odd += 1
            
        # Display the number.
        print(number)
    
    # Return the odd and even counters.
    return odd, even

# Call the main function.
main()
