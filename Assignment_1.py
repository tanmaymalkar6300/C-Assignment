Assignment 1


CODE


marklist = [20, 50, 40, 50, 90, 50, 90, 90, None, 89, None]


print(marklist)


total = 0

absent_students = 0

freq = {}

max_val = marklist[0]

min_val = marklist[0]


for mark in marklist:

    if mark is None:

        absent_students += 1

    else:

        total += mark

        if mark > max_val:

            max_val = mark

        if mark < min_val:

            min_val = mark

        if mark is not None:

            if freq.get(mark) is None:

                freq[mark] = 1

            else:

                freq[mark] += 1


print("a. Average Score of the class =", total / (len(marklist) - absent_students))

print("b. Highest Score =", max_val, "and Lowest Score =", min_val)

print("c. Number of absent students =", absent_students)


highest_freq = 0

highest_freq_mark = 0


for mark in freq:

    if freq[mark] > highest_freq:

        highest_freq = freq[mark]

        highest_freq_mark = mark


print("d. Mark with the highest frequency:", highest_freq_mark)


