-module(dlibusb).
-author("goertzen").

-on_load(init/0).
-include_lib("eunit/include/eunit.hrl").

-export([mytest_io/0, mytest_cpu/0, mytest_none/0]).

mytest_io() ->
    erlang:nif_error(nif_library_not_loaded).
mytest_cpu() ->
    erlang:nif_error(nif_library_not_loaded).
mytest_none() ->
    erlang:nif_error(nif_library_not_loaded).

init() ->
    PrivDir = code:priv_dir(dlibusb),
    Lib = filename:join([PrivDir, "dlibusb"]),
    ok = erlang:load_nif(Lib, 0).

