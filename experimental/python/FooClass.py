
class Foo:
    # Class variable
    id = 3

    def __init__( self, arg ):
        self.arg = arg

    def train( self, data ):
        print( "arg 0x%x" % self.arg )
        for item in data:
            print( "item %s %s" % (item,item) )


if __name__ == '__main__':
    foo = Foo( 0xDEAF )
    foo.train( [3,4,5,[9,7,8]] )
