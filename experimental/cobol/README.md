
[https://stackoverflow.com/questions/47246110/gnucobol-entry-point-not-found]

According to the
[official manual of GNUCOBOL](https://open-cobol.sourceforge.io/doc/gnucobol.html#Hello-world_0021),
you should compile your code with:

```
cobc -x HelloWorld.cbl
```

then run it with

```
./HelloWorld
```

You can also read GNUCOBOL wiki page which contains some exmaples
for further information.

P.S. As Simon Sobisch said, If you change your file name to
`HELLO-WORLD.cbl` to match the program ID, the same commands that you
have used will be ok:

```
cobc HELLO-WORLD.cbl
cobcrun HELLO-WORLD
```

> Note: this answer is not completely correct - the `-x` will work
> but it isn't the "way to compile according to the official docs",
> see provided answer.
> Nonetheless: thanks for digging into the documentation and
> providing an answer,

An entry point is a point where you may enter a shared object (this
is actually more C then COBOL).
GnuCOBOL generates entry points for each `PROGRAM-ID`, `FUNCTION-ID`
and `ENTRY`.
Therefore your entry point is `HELLO-WORLD` (which likely gets a
conversion as - is no valid identifier in ANSI C - you won't have
to think about this when `CALL`ing a program as the conversion will
be done internal).

Using cobcrun internally does:

 1. search for a shared object (in your case `HelloWord`),
    as this is found (because you've generated it) it will be loaded
 2. search for an entry point in all loaded modules - which isn't found

There are three possible options to get this working:

 * As mentioned in Ho1's answer: use `cobc -x`,
   the reason that this works is because you don't generate
   a shared object at all but a C main which is called directly
   (= the entry point doesn't apply at all)
 * preload the shared object and calling the program by its `PROGRAM-ID`
   (entry point), either manually with
   `COB_PRE_LOAD=HelloWorld cobcrun HELLO-WORLD` or through
   `cobcrun` (option available since GnuCOBOL 2.x)
   `cobcrun -M HelloWorld HELLO-WORLD`
 * change the `PROGRAM-ID` to match the source name
   (either rename or change the source, I'd do the second:
    `PROGRAM-ID. HelloWorld`.)

I'm trying to use SQLite3 natively with GnuCOBOL.

The reason for not using a C wrapper is:

 1. I don't write C.
 2. All the examples I've seen only send their SELECT output to stdout, which I find very unuseful, instead of allowing you to read it one row at a time into your program.
 3. I still don't write C `<G>`.

My plan is to create a library of GnuCOBOL callable routines. More than likely they will have a macro wrapper to make them easier to use.

It looks as if my open routine works OK. It creates a new file that the SQLite3 command is happy with (the `sqlite_master` table exists and you can access it; you can create tables and insert/select/update rows).

All of my other routines, even close, return a status 21 which is "Attempting to use an SQLite interface in an undefined/unsupported way.".

I think that the error might be caused by the way I have defined (s9(4) comp) the variable to hold the 'handle' to the database which is returned by the open and used by most of the other routines.

I have attached a copy of my test program source and request that somebody who is conversant with calling C routines from GnuCOBOL have a look at it and give me a hint on what my mistake is.

Note: I am developing this on a 32-bit system.

Links

 * https://sourceforge.net/p/open-cobol/discussion/help/thread/cc255167/
 * https://stackoverflow.com/questions/34356757/how-to-write-sqlite-callback-in-cobol
 * https://www.tutorialspoint.com/sqlite/sqlite_c_cpp.htm
 * Examples:
 * https://www.ibm.com/support/knowledgecenter/en/SSEPEK_11.0.0/apsg/src/tpc/db2z_programexpcobol.html
 * https://www.ibm.com/support/knowledgecenter/SSEPEK_11.0.0/apsg/src/tpc/db2z_samplecoboldynamicsql.html

