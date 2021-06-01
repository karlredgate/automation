#
# create new tclsh - new comment character ...
#

proc // { args } {
}

proc syntax {args} {
    puts "SYNTAX"
}

proc package {name} {
    # Need to remove ; at end
    puts "package $name;"
}

proc option {name _ value} {
}

proc import {args} {
    puts "import $args"
}

proc message {name block} {
    puts "message $name"
}

# optional string foo = number
proc optional {args} {
}
proc repeated {args} {
}

proc enum {name block} {
}

source foo.proto
