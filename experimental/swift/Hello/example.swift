var foo = 33  // variable
let bar = 42  // constant

let f: Double = 70

let label = "Hello"
let blabel = label + String(bar)

let another = "another \(label) string"

print( "about to list" )

// let big = """
// lines of text
// """

var sh = ["apple","berry","cherry"]
// sh[4] = "mango"
sh[2] = "mango"

for fruit in sh {
    print( "Fruit \(fruit)" )
}

var occ = [
    "first": 3,
    "second": 4,
]
print( "first is \(occ["first"]) " )
for (key, value) in occ {
    print( "Dict: \(key) is \(value)" )
}

let emp = [String]()
var dict = [String:Float]()

dict = [:]

var a_name: String? = "Drexl Spivey"

if let name = a_name {
    print( "Name \(name)" )
}

let b_name: String? = nil
let check = b_name ?? a_name
print( "check \(check)" )

var fruit = "tree"
switch fruit {
    case "cherry": print( " a cherry " )
    default: print( " \(fruit) is not a fruit " )
}

for i in 0..<4 {
    print( "i is \(i)" )
}

for i in 0...4 {
    print( "i is \(i)" )
}

func greet( p:String, day:String) -> String {
    return "Hello \(p) says \(day)"
}
let gr = greet( p:"Joe", day:"Fri" )
print( " Greet: \(gr) " )

func greet( _ p:String, on day:String) -> String {
    return "Hello \(p) says on \(day)"
}
let gr2 = greet( "Joe", on:"Fri" )
print( " Greet: \(gr2) " )

