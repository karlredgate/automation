
-module(tcpserv).
-export( [start/0] ).

start() ->
    Options = [binary, {reuseaddr, true}, {active,true}],
    {ok, Listener} = gen_tcp:listen( 8080, Options ),
    acceptor(Listener) .

acceptor(Listener) ->
    % {Child} = spawn( tcpserv, connection, [Listener, self()] ),
    % spawn( tcpserv, connection, [Listener, self()] ),
    Parent = self(),
    spawn( fun () -> connection(Listener, Parent) end ),
    receive
    {accepted} -> io:format("child accepted~n"), acceptor(Listener)
    end .

connection(Listener, Parent) ->
    {ok, Socket} = gen_tcp:accept(Listener),
    io:format( "got connection~n" ),
    inet:setopts( Socket, [binary, {packet,0}, {nodelay,true}, {active,true}] ),
    Parent ! {accepted},
    % spawn( fun () -> loop(Socket) end ),
    loop(Socket) .

loop(Socket) ->
    io:format( "receive loop~n" ),
    receive
    {tcp, Socket, Data} ->
        io:format( "got data~n" ),
	io:format( "data ~p~n", [Data] ),
	<<"GET ",URI/binary>> = Data,
	io:format( "URI is ~p~n", [URI] ),
       loop(Socket);
    {tcp_closed, Socket} -> io:format( "closed" );
    {_} -> io:format( "unknown msg~n" )
    end .
