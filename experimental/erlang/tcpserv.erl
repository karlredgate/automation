
-module(tcpserv).
-export( [start/0] ).

start() ->
    Options = [binary, {reuseaddr, true}, {active,true}],
    {ok, Listener} = gen_tcp:listen( 8080, Options ),
    connection( Listener ) .

connection(Listener) ->
    {ok, Socket} = gen_tcp:accept(Listener),
    inet:setopts( Socket, [binary, {packet,0}, {nodelay,true}, {active,true}] ),
    % spawn( fun () -> loop(Socket) end ),
    loop(Socket),
    io:format( "got connection~n" ),
    connection(Listener) .

loop(Socket) ->
    io:format( "receive loop~n" ),
    receive
    {tcp, Socket, Bin} ->
        io:format( "got data~n" ),
	io:format( "data ~p~n", [Bin] ),
       loop(Socket);
    {tcp_closed, Socket} -> io:format( "closed" );
    {_} -> io:format( "unknown msg~n" )
    end .
