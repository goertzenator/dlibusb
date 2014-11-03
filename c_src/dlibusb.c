#include <erl_nif.h>

static ERL_NIF_TERM mytest(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    const int cnt=11;  // doesn't segfault if cnt=10
    ERL_NIF_TERM arr[cnt];
    ERL_NIF_TERM atom_ok;
    atom_ok = enif_make_atom(env, "ok");
    for(int i=0; i<cnt; i++)
    {
        arr[i] = atom_ok;
    }

    return enif_make_list_from_array(env, arr, cnt);
}

static ErlNifFunc nif_funcs[] = {
    {"mytest_io",      0, mytest, ERL_NIF_DIRTY_JOB_IO_BOUND},
    {"mytest_cpu",     0, mytest, ERL_NIF_DIRTY_JOB_CPU_BOUND},
    {"mytest_none",    0, mytest}
};

ERL_NIF_INIT(dlibusb, nif_funcs, 0, 0, 0, 0)
