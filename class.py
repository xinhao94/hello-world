class Employee:

	num_of_emps = 0
	raise_amt = 1.04

	# Default constructor
	# Special methods are surrounded by double underscore
	# or "dunder"
	def __init__(self, first, last, pay):
		self.first = first
		self.last = last
		self.email = first + '.' + last +'@email.com'
		self.pay = pay

		Employee.num_of_emps += 1

	def fullname(self):
		return '{} {}'.format(self.first, self.last)

	def apply_raise(self):
		self.pay = int(self.pay * self.raise_amt)

	@classmethod
	def set_raise_amt(cls, amount):
		cls.raise_amt = amount

	# Alternative constructor
	@classmethod
	def from_string(cls, emp_str):
		first, last, pay = emp_str.split('-')
		return cls(first, last, pay)

	# Static methods don't operate on the class or
	# its instances
	@staticmethod
	def is_workday(day):
		if day.weekday() == 5 or day.weekday() == 6:
			return False
		else:
			return True

	# Common special/magic/dunder methods
	# __repr__() is an unambiguous representation of the 
	# object, used for debugging for developers
	# Return a string that can be used to recreate the object
	def __repr__(self):
		return "Employee('{}', '{}', {})".format(self.first, self.last, self.pay)

	# __str__() is a more readable representation of the 
	# object, used as a display for end users
	# __str__() overrides the print() function
	def __str__(self):
		return "{} - {}".format(self.fullname(), self.email)

	# Use __add__() to overload the '+' operator
	def __add__(self, other):
		return self.pay + other.pay

	# Overload the dunder method __len__()
	def __len__(self):
		return len(self.fullname()) 

# Class Developer is inherited from class Employee
class Developer(Employee):
	# Override the attribute in parent class
	raise_amt = 1.10
	# Override the constructor for more attributes
	def __init__(self, first, last, pay, prog_lang):
		# Call the parent constructor to handle some arguments
		super().__init__(first, last, pay)
		# Handle the new attribute
		self.prog_lang = prog_lang

class Manager(Employee):
	# Override the constructor for more attributes
	# Avoid using mutable data type as the default value
	def __init__(self, first, last, pay, employees=None):
		super().__init__(first, last, pay)
		# Initiate the employees that the manager supervises
		if employees is None:
			self.employees = []
		else:
			self.employees = employees
	# Add an employee to the supervision list
	def add_emp(self, emp):
		if emp not in self.employees:
			self.employees.append(emp)
	# Remove an employee from the supervision list
	def remove_emp(self, emp):
		if emp in self.employees:
			self.employees.remove(emp)
	# Print all employees in the supervision list
	def print_emps(self):
		for emp in self.employees:
			print('-->', emp.fullname())

import datetime

# Instantiation by calling the constructor
emp_1 = Employee('Corey', 'Schafer', 50000)
print(emp_1.fullname())
print(emp_1.email)

# Calling a class method
print(Employee.raise_amt)
Employee.set_raise_amt(1.05)
print(Employee.raise_amt)

# Using a class method as an alternative constructor
new_emp_str = 'John-Doe-70000'
new_emp = Employee.from_string(new_emp_str)
print(new_emp.email)

# Calling a static method 
my_date = datetime.date(2020, 1, 27)
print(Employee.is_workday(my_date))


# Instantiate one inherited class
dev_1 = Developer('Test', 'Employee', 60000, 'Java')
print(dev_1.email)
print(dev_1.prog_lang)

#Instantiate another inherited class
mgr_1 = Manager('Sue', 'Smith', 90000, [dev_1])
print(mgr_1.email)
mgr_1.add_emp(emp_1)
mgr_1.remove_emp(dev_1)
mgr_1.print_emps()

# Visualize the inheritance by calling function help()
# print(help(Developer))

# Useful built-in functions 
print(isinstance(mgr_1, Manager))
print(isinstance(mgr_1, Employee))
print(isinstance(mgr_1, Developer))
print(issubclass(Developer, Employee))
print(issubclass(Manager, Employee))
print(issubclass(Manager, Developer))

# Use of magical methods!
print(emp_1.__repr__())
print(emp_1.__str__())
print(emp_1)
print(emp_1 + dev_1)
print(len(emp_1))
