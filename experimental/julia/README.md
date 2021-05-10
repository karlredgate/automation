
 * https://en.wikibooks.org/wiki/Introducing_Julia/Arrays_and_tuples
 * https://julialang.org/benchmarks/
 * https://en.wikibooks.org/wiki/Introducing_Julia/Working_with_text_files
 * https://github.com/JuliaIO/JSON.jl

 * https://discourse.julialang.org/t/psa-use-julia-0-7-if-you-are-upgrading/13321

PSA = Public Service Announcement A lot of people are posting issues where their old code doesn’t work anymore on 1.0 because some function has been renamed or removed. The 0.7 release exists exactly for this reason: your old code will work on 0.7 and give you a specific warning about how to fix your code. If you have any old code, you should use 0.7 to get these warnings before switching to 1.0; even if you just have work habits that may need changing, you should probably use 0.7 for a while. …

https://docs.julialang.org/en/v1/stdlib/DelimitedFiles/index.html


```
julia> linspace(1,2)
┌ Warning: `linspace(start, stop)` is deprecated, use `range(start, stop=stop, length=50)` instead.
│   caller = top-level scope at none:0
└ @ Core none:0
1.0:0.02040816326530612:2.0
```



```
julia> readdlm
WARNING: Base.readdlm is deprecated: it has been moved to the standard library package `DelimitedFiles`.
Add `using DelimitedFiles` to your imports.
 in module Main
 readdlm (generic function with 6 methods)
julia> 
```

```
julia> airline_array = readdlm("/Users/randyzwitch/airline/1987.csv", ',');
julia> size(airline_array)
(1311827,29)
julia> typeof(airline_array)
Array{Any,2}
```

DataFrame
--------

 * <https://int8.io/reading-csv-file-into-julia/>
 * <https://juliadata.github.io/DataFrames.jl/release-0.10/man/io/>

```
Pkg.add("DataFrames")
using DataFrames;
iris = readtable("iris.csv")
size(iris)
names(iris)
sepal_length_column = iris[:Sepal_Length]
typeof(iris[:Sepal_Length])
sepal_length_column = iris[1]
```

Can we select a region of data frame as it is possible in R?
Julia gives you that too.
Accessing 2th and 3rd column of last 10 rows is as easy as:

```
iris_sub = iris[end-10:end,2:3]
```

What about writing to DataFrame.
Can you replace whole column?
Yes, to replace it with randomly generated vector try:

```
iris[1] = randn(nrow(iris))
```

What about replacing a row?
Lets try to copy first row and write it as the last one.

```
iris[end,:] = iris[1,:]
```

Are they equal now?

```
iris[end,:] == iris[1,:]
true
```

It is also easy to convert DataFrame to matrix using convert function

```
iris_matrix = convert(DataFrame, iris)
```

The type of iris_matrix is then square Array of Any.
Julia will specify resulting type as much as possible.
So if your input DataFrame consists of Floats only it will convert
it to square Array of Float64.

```
iris_matrix = convert(DataFrame, iris[1:2])
```


```
using DataFrames, Requests

resp = get("https://data.cityofnewyork.us/api/views/kku6-nxdu/rows.csv?accessType=DOWNLOAD")
>> Response(200 OK, 17 headers, 27350 bytes in body)
tbl = readtable(IOBuffer(resp.data));
names(tbl)
>> 46-element Array{Symbol,1}:
>> :JURISDICTION_NAME
>> ...
eltypes(tbl)
>> 46-element Array{Type,1}:
>> ...
```

### Another

With the deprecation of Requests in favor of HTTP here is an example
on how to use `HTTP.request` and the body of the resulting call to
request.

```
julia> using CSV, HTTP

julia> res = HTTP.request("GET", "http://users.csc.calpoly.edu/~dekhtyar/365-Winter2015/data/CARS/cars-data.csv")
HTTP.Messages.Response:
"""
HTTP/1.1 200 OK
Date: Wed, 16 May 2018 12:46:39 GMT
Server: Apache/2.4.18 (Ubuntu)
Last-Modified: Mon, 05 Jan 2015 23:29:09 GMT
ETag: "330f-50bf00ea05b40"
Accept-Ranges: bytes
Content-Length: 13071
Content-Type: text/csv

Id,MPG,Cylinders,Edispl,Horsepower,Weight,Accelerate,Year
1,18,8,307,130,3504,12,1970
2,15,8,350,165,3693,11.5,1970
3,18,8,318,150,3436,11,1970    
⋮
13071-byte body
"""

julia> res_buffer = IOBuffer(res.body)
IOBuffer(data=UInt8[...], readable=true, writable=false, seekable=true,     append=false, size=13071, maxsize=Inf, ptr=1, mark=-1)

julia> using DataFrames, DataStreams
julia> df = CSV.read(res_buffer)
406×8 DataFrames.DataFrame
│ Row │ Id  │ MPG │ Cylinders │ Edispl │ Horsepower │ Weight │ Accelerate │     Year │
        ├─────┼─────┼─────┼───────────┼────────┼────────────┼────────┼────────────┼──────┤
	│ 1   │ 1   │ 18  │ 8         │ 307.0  │ 130        │ 3504   │ 12.0       │     1970 │
	│ 2   │ 2   │ 15  │ 8         │ 350.0  │ 165        │ 3693   │ 11.5       │     1970 │
	│ 3   │ 3   │ 18  │ 8         │ 318.0  │ 150        │ 3436   │ 11.0       │ 1970 │
	⋮    
	│ 405 │ 405 │ 28  │ 4         │ 120.0  │ 79         │ 2625   │ 18.6       │ 1982 │
	│ 406 │ 406 │ 31  │ 4         │ 119.0  │ 82         │ 2720   │ 19.4       │ 1982 │
```


```
julia> csv"""
1,2,3
3,4,5
"""
┌ Warning: @csv_str and the csv""" syntax are deprecated. Use CSV.read(IOBuffer(...)) from the CSV package instead.
│   caller = ip:0x0
└ @ Core :-1
1×3 DataFrame
│ Row │ x1     │ x2     │ x3     │
│     │ Int64⍰ │ Int64⍰ │ Int64⍰ │
├─────┼────────┼────────┼────────┤
│ 1   │ 3      │ 4      │ 5      │
julia>
```


Round
-----

You must be looking at the documentation from an older version of
Julia: in 0.7 and later round takes a keyword digits or sigdigits
keyword 4:

```
julia> round(pi, digits=3)
3.142
julia> round(pi, sigdigits=3)
3.14
```

However this is probably not a good way to check for approximate
equality since it can be very brittle (e.g. very close numbers can
round in opposite directions). I would suggest you use isapprox 3
(or its infix form ≈) instead

```
julia> h = StatsBase.fit(Histogram, y )
Histogram{Int64,1,Tuple{StepRangeLen{Float64,Base.TwicePrecision{Float64},Base.TwicePrecision{Float64}}}}
edges:
  -2.0:2.0:30.0
  weights: [64369, 8456, 4592, 326, 254, 41, 11, 7, 3, 1, 0, 1, 0, 1, 2, 2]
  closed: left
  isdensity: false
```

