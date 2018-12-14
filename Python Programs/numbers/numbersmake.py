# Daniel A. Brooks
# 269416

# Pseudocode:
# Import the random module.
# Define the main function:
#   Create ranges for the random_loop.
#   Describe what the program is doing to the user.
#   Create/open a numbers.txt file.
#   Call the generate_randoms function.
#   Close the numbers.txt file.
#   Display a success message.
# Define the generate_randoms function:
#   Generate 12 random integers from 1 to 100.
#   Write the integers to the file.

# Import the random module.
import random

# Define the main function.
def main():
    # Create ranges for the random_loop.
    number_of_randoms = 12
    range_of_randoms = 100

    # Describe what the program is doing.
    print('This program will generate', number_of_randoms, \
          'random numbers from 1 to', range_of_randoms, 'and', \
          '\nwrite them to a file named "numbers.txt".\n')

    # Create/open a numbers.txt file.
    number_file = open('numbers.txt', 'w')

    # Call the random_loop function.
    generate_randoms(number_file, number_of_randoms, range_of_randoms)

    # Close the numbers.txt file.
    number_file.close()

    #Display a success message.
    print('File "numbers.txt" has been written successfully.')

# Define the generate_randoms function.
def generate_randoms(number_file, num_of_randoms, random_range):
    # Generate the random integers.
    for x in range(1, num_of_randoms + 1):
        random_number = str(random.randint(1, random_range))
        number_file.write(random_number + '\n')

# Call the main function.
main()
