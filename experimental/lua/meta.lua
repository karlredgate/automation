
mt = getmetatable("")
for name,method in pairs(mt) do
    print( name, method )
end
if ( mt.__index == string ) then
    print "index is string"
end

mt.__add = function (x,y)
    return x .. y
end

print( "this should " + "be" + " one string" )

do
    -- local scope
    meta = {
	__concat = function (left, right)
	    assert( type(left) == "table" and type(right) == "table" )
	    -- do more
	end
    }
    function Splice( that )
	return setmetatable( that, meta )
    end
end

a = Splice( {} )

