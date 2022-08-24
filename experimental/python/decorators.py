
# Decorators are somewhat like a "curry", take a
# function as an argument, return a new function
# derived from the old function.
#
# This would be a good way to add aspect oriented
# programming...

# https://www.geeksforgeeks.org/decorators-in-python/
# https://www.geeksforgeeks.org/function-decorators-in-python-set-1-introduction/

# Adds a welcome message to the string
# returned by fun(). Takes fun() as
# parameter and returns welcome().
def decorate_message(fun):
    # Nested function
    def addWelcome(site_name):
        return "Welcome to " + fun(site_name)
                      
    # Decorator returns a function
    return addWelcome

@decorate_message
def site(site_name):
    return site_name;

# Driver code
# This call is equivalent to call to
# decorate_message() with function
# site("GeeksforGeeks") as parameter

# print site("GeeksforGeeks")
print( site("GeeksforGeeks") )


# A Python example to demonstrate that
# decorators can be useful attach data

# A decorator function to attach
# data to func
def attach_data(func):
    func.data = 3
    return func

@attach_data
def add (x, y):
    return x + y

# Driver code

# This call is equivalent to attach_data()
# with add() as parameter
print(add(2, 3))
print(add.data)

