
# python3 -m pytest example_pytest.py

import unittest
from unittest import mock
from ddt import data, ddt

import nobody

SOME_TEST_CASES = (
    {
        "description": "Some text"
    },{
        "description": "Some other text"
    }
)

# ddt provides the @ddt decorator for the unittest class
# and the @data decorator for the methods - just calling
# the test function once for each member of the array passed

@ddt
class SomeTestCase(unittest.TestCase):

    def test_nobody(self):
        nobody.nothing()

    @data( 9,7,5,3 )
    def test_data( self, value ):
        nobody.myprint( "Value:"+str(value) )

    # Don't forget the "*" - or you get the "tuple" err mesg
    @data(*SOME_TEST_CASES)
    def test_casedata( self, testdata ):
        nobody.myprint( testdata.get("description") )

    def test_nobody_fail(self):
        nobody.bad_thing( "string" )
        self.assertRaises( TypeError, nobody.bad_thing, 3 )

    def test_underlay_A(self):
        nobody.front("hello")

    # This should trigger the assertion in "front" since
    # the return value of its called function is asserted
    # to be 3
    @mock.patch('nobody.underlay')
    def test_underlay_B(self, mock_underlay):
        mock_underlay.return_value = 4
        mock_underlay.side_effect = lambda : print("sideEffect")
        self.assertRaises( AssertionError, nobody.front, "hello" )

    @mock.patch('nobody.underlay')
    def test_underlay_C(self, mock_underlay):
        # This would cause nobody.underlay to return 4...but
        mock_underlay.return_value = 4
        # Closure instead of lambda
        def inner():
            print( "INNER" )
            # this changes the return value
            # so it will not throw an exception
            return 3
        mock_underlay.side_effect = inner
        # self.assertRaises( AssertionError, nobody.front, "hello" )
        nobody.front( "goodbye" )

    @mock.patch('nobody.underlay')
    def test_underlay_D(self, mock_underlay):
        # This would cause nobody.underlay to return 4...but
        mock_underlay.return_value = 4
        # Closure instead of lambda
        def inner():
            print( "INNER" )
            # this causes the original return value to
            # be used - NOT the side_effect value
            # so the exception WILL occur
            return mock.DEFAULT
        mock_underlay.side_effect = inner
        self.assertRaises( AssertionError, nobody.front, "hello" )

# vim: autoindent expandtab sw=4
