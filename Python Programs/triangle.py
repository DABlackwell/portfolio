# Daniel A Brooks
# 269416

# Pseudocode:
# Import the math module.
# Define the main function:
#   Explain the purpose of the program.
#   Ask the user to enter the sides of a triangle.
#   Call the second function.
#   Display the results of the second function.
# Define the second function:
#   Calculate the area of the triangle.
#   Calculate the perimeter of the triangle.
#   Return the two calculations.
# Call the main function.

# Import the math module.
import math

# Define the main function.
def main():
    # Explain the purpose of the program.
    print('This program calculates the area and', \
          'perimeter of a triangle.')
    print()
    
    # Ask the user to enter the sides of a triangle.
    side_1 = float(input('Please enter the length of the first side: '))
    side_2 = float(input('Please enter the length of the second side: '))
    side_3 = float(input('Please enter the length of the third side: '))
    print()

    # Call the second function.
    area, perimeter = calculate_triangle(side_1, side_2, side_3)

    # Display the results of the second function.
    print('The area of your triangle is:', format(area, '.1f'))
    print('The perimeter of your triangle is:', perimeter)
    print()

# Define the second function.
def calculate_triangle(side_a, side_b, side_c):
    # Calculate the perimeter of the triangle.
    triangle_perimeter = float(side_a + side_b + side_c)
    # Calculate the area of the triangle.
    half_perim = triangle_perimeter / 2
    herons_radicand = half_perim * (half_perim - side_a) * \
                      (half_perim - side_b) * (half_perim - side_c)
    triangle_area = math.sqrt(herons_radicand)
    # Return the two calculations.
    return triangle_area, triangle_perimeter

# Call the main function.
main()
