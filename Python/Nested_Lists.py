N = int(raw_input())

students = list()
for i in range(N):
    students.append([raw_input(), float(raw_input())])

students.sort()
min_grade = 100
second_min = 100

# Define min grade
for i in range(0, len(students)):
    if students[i][1] < min_grade:
        min_grade = students[i][1]

# Define second min grade
for i in range (0,len(students)):
    if students[i][1] < second_min and students[i][1] != min_grade:
        second_min = students[i][1]

# Find students with second min grade
for i in range (0,len(students)):
    if second_min == students[i][1]:
        print(students[i][0])
