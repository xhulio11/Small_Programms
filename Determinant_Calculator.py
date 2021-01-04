import copy


def re_arranger(array, column):
    # getting an array without the first row
    # with deep copy we make an array that won't affect the original array
    new_array = copy.deepcopy(array)

    new_array.pop(0)
    # getting an array without the column which is chosen
    for i in range(len(new_array)):
        new_array[i].pop(column)
    return new_array


def det(array):

    # det = a11*a22-a12*a21
    if len(array) == 2:
        value = array[0][0]*array[1][1]-array[0][1]*array[1][0]
        return value
    else:
        result = 0
        for i in range(len(array)):
            # calculating det for each smaller array and sum everything together
            a = det(re_arranger(array, i))
            # result = result + {(-1)^(1=row + (1+i) = column)}*array[0][i]*det(smaller array)
            result = result + ((-1)**(2+i))*array[0][i]*a

        return result


def user_input():
    # n = number of columns and rows
    n = input("Give me the size of the array: ")
    if not n.isdigit():
        print("You have given a wrong input of array's length.")  # Controlling the input
        print("Please try again giving an integer number.")
        user_input()
    n = int(n)

    array = []

    # getting the 2 dimensional array
    for i in range(n):
        array.append(list(map(int, input().split())))

    return array


arr = user_input()
print(f"The Determinant of the array is: {det(arr)}")



