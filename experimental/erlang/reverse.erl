
-module(reverse).
-export( [start/0] ).
-export( [parse/1] ).

% RequestLine1 = <<"GET /foo/bar.html HTTP/1.1\r\n">>.
% RequestLine2 = <<"POST /foo/bar.html HTTP/1.1\r\n">>.
% RequestLine3 = <<"PUT /foo/bar.html HTTP/1.1\r\n">>.

-define(RequestLine1, <<"GET /foo/bar.html HTTP/1.1\r\n">>).
-define(RequestLine2, <<"POST /foo/bar.html HTTP/1.1\r\n">>).
-define(RequestLine3, <<"PUT /foo/bar.html HTTP/1.1\r\n">>).

match_method(<<"PUT ",Line/binary>>) ->
	{put, Line};
match_method(<<"POST ",Line/binary>>) ->
	{post, Line};
match_method(<<"GET ",Line/binary>>) ->
	{get, Line}.

find_space( <<>>, Word ) -> {lists:reverse(Word),"HTTP/0.9"};
find_space( <<$\ ,Version/binary>>, Word ) -> {lists:reverse(Word),Version};
find_space( <<$\r,Version/binary>>, Word ) -> {lists:reverse(Word),Version};
find_space( <<$\n,Version/binary>>, Word ) -> {lists:reverse(Word),Version};
find_space( <<C,Rest/binary>>, Word ) -> find_space( Rest, [C|Word] ).

parse( Line ) ->
	{Method, Rest} = match_method( Line ),
	{URL,End} = find_space( Rest, [] ),
	{Version,Junk} = find_space( End, [] ),
	io:format( "method ~p~n", [Method] ),
	io:format( "URL ~p~n", [URL] ),
	io:format( "V ~p~n", [Version] ),
	io:format( "REST ~p~n", [Rest] ).

% start() -> parse( RequestLine1 ).
start() -> parse( <<"GET /foo/bar.html HTTP/1.1\r\n">> ),
parse( <<"POST /foo/bar.html\r\n">> ).
