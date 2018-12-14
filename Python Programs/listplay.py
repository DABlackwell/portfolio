# Daniel A. Brooks
# 269416

# Pseudocode:
#
# Import the random module.
# Define the main function:
#   Create an empty list named nums.
#   Use a loop to add 7 integers, from 20 to 80, to nums.
#   Use a while loop to display the 7 integers.
#   Display the largest and smallest integer in the list.
#   Create a slice which is missing the first and last elements.
#   Call the process function.
#
# Define the process function:
#   Sort the numbers in the slice from the main function.
#   Reverse the numbers.
#   Display the numbers using a for loop.
#
# Call the main function.


# Import the random module.
import random

# Define the main function.
def main():
    # Create an empty list named nums.
    nums = []

    # Use a loop to add 7 integers, from 20 to 80, to nums.
    while len(nums) < 7:
        nums.append(random.randint(20, 80))

    # Use a while loop to display the 7 integers.
    index = 0
    nums_string = ""
    while index < 7:
        add_num = str(nums[index])
        nums_string += (add_num + ' ')
        index += 1
    print('In the following list of numbers:\n', nums_string, '\n', sep='')

    # Display the largest and smallest integer in the list.
    print("    - The highest number is ", max(nums), '.', sep='')
    print("    - The lowest number is ", min(nums), '.', sep='')

    # Create a slice which is missing the first and last elements.
    num_slice = nums[1:6]
    
    # Call the process function.
    process(num_slice)

# Define the process function.
def process(nums_slice):
    # Sort the numbers in the slice from the main function.
    nums_slice.sort()
    
    # Reverse the numbers.
    nums_slice.reverse()

    # Display the numbers using a for loop.
    slice_string = ""
    for index in range(len(nums_slice)):
        add_num = str(nums_slice[index])
        slice_string += (add_num + ' ')
        index += 1
    print('    - The middle five numbers, sorted highest to lowest, are:')
    print('     ', slice_string)

# Call the main function.
main()
