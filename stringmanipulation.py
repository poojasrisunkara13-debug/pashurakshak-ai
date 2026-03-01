student_info = " Name: Sara | Roll: 101 | Course: Python Programming "

clean_info = student_info.strip()
print("Cleaned String:", clean_info)

print("Uppercase:", clean_info.upper())
print("Lowercase:", clean_info.lower())

print("Starts with 'Name':", clean_info.startswith("Name"))
print("Ends with 'ing':", clean_info.endswith("ing"))

new_info = clean_info.replace("Python", "Data Science")
print("After Replace:", new_info)

parts = clean_info.split("|")
print("Split Parts:", parts)

joined = ", ".join(parts)
print("Joined with commas:", joined)

print("Position of 'Roll':", clean_info.find("Roll"))
print("Count of 'a':", clean_info.count("a"))

name = "Sara"
marks = 433
print(f"\nStudent {name} has scored {marks} marks successfully.")

print("Line1\nLine2\tTabbed Example")