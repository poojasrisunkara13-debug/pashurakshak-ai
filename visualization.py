import matplotlib.pyplot as plt
import seaborn as sns

employees = ["John", "Sara", "Mike", "Emma", "David", "Sophia"]
salaries = [50000, 60000, 75000, 80000, 55000, 70000]  
experience = [2, 4, 6, 8, 3, 5]  
departments = ["HR", "IT", "Finance", "IT", "HR", "Finance"]
performance = [70, 85, 90, 88, 65, 80]  

# Line Chart
print("\n[Line Chart Significance] Useful for showing trends and comparisons over categories or time.")
plt.figure(figsize=(7,5))
plt.plot(employees, salaries, marker='o', label="Salary ($)")
plt.plot(employees, performance, marker='s', label="Performance Score")
plt.title("Line Chart - Employee Salary vs Performance")
plt.xlabel("Employees")
plt.ylabel("Values")
plt.legend()
plt.tight_layout()
plt.show()

# Bar Chart
print("\n[Bar Chart Significance] Helps compare values between different categories easily.")
plt.figure(figsize=(7,5))
plt.bar(employees, salaries, color='skyblue')
plt.title("Bar Chart - Employee Salaries")
plt.xlabel("Employees")
plt.ylabel("Salary ($)")
plt.tight_layout()
plt.show()

# Histogram
print("\n[Histogram Significance] Displays frequency distribution of continuous data.")
plt.figure(figsize=(7,5))
plt.hist(performance, bins=5, color='green', edgecolor='black')
plt.title("Histogram - Distribution of Performance Scores")
plt.xlabel("Performance Range")
plt.ylabel("Number of Employees")
plt.tight_layout()
plt.show()

# Pie Chart
print("\n[Pie Chart Significance] Shows proportion of categories as percentages of a whole.")
plt.figure(figsize=(6,6))
dept_counts = [
    departments.count("HR"),
    departments.count("IT"),
    departments.count("Finance")
]
plt.pie(dept_counts, labels=["HR", "IT", "Finance"], autopct="%1.1f%%", startangle=90)
plt.title("Pie Chart - Department Distribution")
plt.tight_layout()
plt.show()

# Box Plot
print("\n[Box Plot Significance] Summarizes data spread, median, and identifies outliers.")
plt.figure(figsize=(7,5))
sns.boxplot(x=salaries)
plt.title("Box Plot - Salary Distribution")
plt.xlabel("Salary ($)")
plt.tight_layout()
plt.show()
