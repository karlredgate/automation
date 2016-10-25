
class Foo:
	def __init__( self, arg ):
		self.arg = arg

	def train( self, data ):
		for item in data:
			print( "item %s %s" % (item,item) )

if __name__ == '__main__':
	foo = Foo( 0xDEAF )
	foo.train( [3,4,5] )
