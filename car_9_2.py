class Dog:
	"""a dog class"""

	def __init__(self, name, age):
		"""nintial"""
		self.name = name
		self.age = age

	def sit(self):
		"""sit"""
		print (self.name.title()+" is now sitting.")

	def roll_over(self):
		"""roll_over"""
		print (self.name.title()+" rolled over!")

my_dog = Dog("Rex", 6)

print ("My dog's name is "+my_dog.name.title()+".")
print ("Its age is "+str(my_dog.age))

my_dog.sit
my_dog.roll_over

