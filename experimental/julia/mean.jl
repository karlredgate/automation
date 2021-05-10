#!/opt/local/bin/julia
#
# std() does not understand Array{Any}() - which is what you get
# from the range operator by default
#
# * how to get a range from a CSV with the correct type?
# µ

using DelimitedFiles

sample = readdlm("sample.log",' ')
m = mean( sample[:,5] )
a = Array{Float64}( sample[:,5] )
s = std( a )
println( "sample mean $m  std $s" )

all = readdlm("all.log",' ')
m = mean( all[:,5] )
aa = Array{Float64}( all[:,5] )
s = std( aa )
println( "all mean $m  std $s" )
