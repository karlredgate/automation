

def nothing():
    return "NOTHING"

def front(x):
    print( "before..." )
    y = underlay()
    assert y == 3
    print( "after..." )

def underlay():
    print( "Underlay " )
    return 3

def bad_thing(arg):
    print( "FOO"+arg )

def myprint(x):
    print( "NOBODY: " + str(x) )
