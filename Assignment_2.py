Assignment 2

Code



def intersection(l1, l2):

    res = []

    for student in l1:

        if student in l2:

            res.append(student)

    return res


def union(l1, l2):

    res = l2.copy()

    for student in l1:

        if student not in l2:

            res.append(student)

    return res


def diff(l1, l2):

    res = []

    for student in l1:

        if student not in l2:

            res.append(student)

    return res


a = [1, 2, 3, 4, 5, 6, 7]

b = [2, 3, 5, 7, 9, 10]

c = [2, 4, 6, 8, 10, 12]


print(f"A = {a} \nB = {b}\nC = {c}\n")

print(f"a. {intersection(a, b)}")

print(f"b. {diff(union(a, b), intersection(a, b))}")

print(f"c. {diff(diff(c, b), a)}")

print(f"d. {diff(union(a, c), b)}")