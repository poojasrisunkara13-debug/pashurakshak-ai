def welcome():
    print("----- Welcome to Student Result System -----")

def display_student(name, rollno):
    print(f"Student Name : {name}")
    print(f"Roll Number  : {rollno}")

def calculate_total(marks):
    total = sum(marks)
    return total

def calculate_grade(average):
    if average >= 90:
        return "A+"
    elif average >= 75:
        return "A"
    elif average >= 60:
        return "B"
    elif average >= 35:
        return "C"
    else:
        return "Fail"
welcome()

name = "Sara"
rollno = 101
marks = [85, 90, 78, 88, 92]  

display_student(name, rollno)

total = calculate_total(marks)
average = total / len(marks)   
grade = calculate_grade(average)

print("\nTotal Marks :", total)
print("Average     :", average)
print("Grade       :", grade)
