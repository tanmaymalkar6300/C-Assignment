Assignment 4 


CODE


marks = [3, 46, 8, 31, 2, 85, 87]


def selectionsort(marks):

    for i in range(len(marks)):

        min_idx = i

        for j in range(i + 1, len(marks)):

            if marks[min_idx] > marks[j]:

                min_idx = j

        marks[i], marks[min_idx] = marks[min_idx], marks[i]


    print("Marks of the students after performing selection sort on the list:")

    for i in range(len(marks)):

        print(marks[i])


# Call selectionsort function

selectionsort(marks)


def bubblesort(marks):

    n = len(marks)

    for i in range(n - 1):

        for j in range(0, n - i - 1):

            if marks[j] > marks[j + 1]:

                marks[j], marks[j + 1] = marks[j + 1], marks[j]


    print("\nMarks of students after performing bubble sort on the list:")

    for i in range(len(marks)):

        print(marks[i])


# Call bubblesort function

bubblesort(marks)