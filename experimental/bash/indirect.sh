
# https://stackoverflow.com/questions/8515411/what-is-indirect-expansion-what-does-var-mean

set -x

foo=dead
bar=beef
junk=foo
jank=bar

echo junk is ${junk}
echo \!junk is ${!junk}
echo '!j*' is ${!j*}

echo Test this - '${!name[@]}'


something='the data'
declare -n ref=something
echo $ref should be "'the data'"

function try() {
    local -n var=$1
    echo "var should dereference another variable - $var"
    echo "what is ${var@a}  and ${#var}"
}

try bar
declare -r PI=3.1415
try PI
