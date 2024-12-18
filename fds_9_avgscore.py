def avg_score(Marks):
    total = 0
    count = 0
    for Mark in Marks:
        if Mark != -1:
            total += Mark
            count += 1
    if count == 0:
        return 0
    return total / count


def highest_score(Marks):
    highest_score = None
    for Mark in Marks:
        if Mark != -1:
            if highest_score == None or Mark > highest_score:
                highest_score = Mark
    return highest_score

        
def lowest_score(Marks):
    lowest_score = None
    for Mark in Marks:
        if Mark != -1:
            if lowest_score == None or Mark < lowest_score:
                lowest_score = Mark
    return lowest_score


def absent_students(Marks):
    count = 0
    for Mark in Marks:
        if Mark == -1:
            count += 1
    return count


def highest_frequency_score(Marks):
    frequency = {}
    
    for Mark in Marks:
        if Mark != -1:
            if Mark in frequency:
                frequency[Mark] += 1
            else:
                frequency[Mark] = 1
    most_frequent = None
    count = 0
    
    for Mark in frequency:
        if frequency[Mark] > count:
            count = frequency[Mark]
            most_frequent = Mark
    return most_frequent

Num = int(input("Enter the number of student : "))
Marks = []
    
for i in range(Num):
    Marks.append(int(input(f"Enter the marks of FDS of student {i+1} (Enter -1 if student was absent) : ")))
        
    print("Average Score of the class : ", avg_score(Marks))
        
    highest = highest_score(Marks)
    lowest = lowest_score(Marks)
    print("Highest Score of the class : ", highest)
    print("Lowest Score of the class : ", lowest)
        
    print("Number of students who were absent : ", absent_students(Marks))
        
    print("The most frequent marks : ", highest_frequency_score(Marks))
