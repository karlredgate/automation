
Sobject = {}

function Sobject:new( uuid )
    local t = setmetatable( {}, {__index = Sobject} )
    t.uuid = (uuid or "DEADBEEF")
    return t
end


function Sobject:

o = Sobject:new( "FEEDFACE" )

print( "Sobject:", o )
