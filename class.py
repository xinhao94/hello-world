class Employee:

	num_of_emps = 0
	raise_amt = 1.04

	# Default constructor
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

import datetime

emp_1 = Employee('Corey', 'Schafer', 50000)
emp_2 = Employee('Test', 'Employee', 60000)
print(emp_1.fullname())
print(emp_1.email)
print(Employee.raise_amt)
Employee.set_raise_amt(1.05)
print(Employee.raise_amt)
new_emp_str = 'John-Doe-70000'
new_emp = Employee.from_string(new_emp_str)
print(new_emp.email)

my_date = datetime.date(2020, 1, 27)
print(Employee.is_workday(my_date))
