
# https://stackoverflow.com/questions/338101/python-function-attributes-uses-and-abuses
# http://www.python.org/dev/peps/pep-0232/

def foo(x):
    pass

# attribute for function foo
foo.score = 10
print( dir(foo) )
