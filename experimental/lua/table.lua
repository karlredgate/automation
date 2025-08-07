
t = {} -- a new table
print( t )

t = { a = 0xdead, b = 0xbeef }
print(t)

t.a = function()
    print("a function")
end

t.a()

u = { ["foo"] = 200 }
-- u.foo

a = { "one", "two", "three" }
print( "Array(really table):", a )
print( "second item in array:", a[1] )
print( "Count:", #a )
