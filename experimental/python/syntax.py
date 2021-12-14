
def foo(n):
    if n == 3: return print("three")
    print("still")
    if n == 6: print("six")


foo( 4 )
foo(3)

print( "default value" )
print( "In this ... the def value is evaluated ONLY once" )
print( "   so this will create a longer list" )
def foo( n, l=[] ):
    l.append( n )
    return l

print( foo(4) )
print( foo(8) )
print( foo(15) )
print( foo(16) )
print( foo(23) )
print( foo(42) )

def some_flags2(t):
    return ['-6', True]  if t == 'IPv6' else ['-4', False]

def some_flags(t):
    if t == 'IPv6': return '-6', True
    return '-4', False

a,b = some_flags('IPv4')
print( "flag:" + a + " v6p:" + str(b) )
a,b = some_flags('IPv6')
print( "flag:" + a + " v6p:" + str(b) )

a,b = some_flags2('IPv4')
print( "flag:" + a + " v6p:" + str(b) )
a,b = some_flags2('IPv6')
print( "flag:" + a + " v6p:" + str(b) )

def rv1(): "foo"
def rv2(): return "foo"

print( "rv1" + str(rv1()) )
print( "rv2" + str(rv2()) )
