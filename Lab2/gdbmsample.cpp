#include <boost/lexical_cast.hpp>
#include <gdbm.h>
#include <iostream>
#include <string>
#include <string.h>

struct record
{
    int a;
    int b;
};

int main(int argc, char* argv[])
{
    GDBM_FILE db;

    db = gdbm_open("gdbm.db", 512, GDBM_WRCREAT | GDBM_NOLOCK | GDBM_SYNC, 0664, NULL);

    datum lekey;
    datum levalue;
    for (int i = 0; i < 10; ++i) {
        record r;
        r.a = i;
        r.b = i + 1;
        lekey.dptr = (char*) boost::lexical_cast<std::string>(i).c_str();
        lekey.dsize = strlen(lekey.dptr) + 1;
        levalue.dptr = (char*) &r;
        levalue.dsize = sizeof(record);
        gdbm_store(db, lekey, levalue, GDBM_INSERT);
    }
    gdbm_sync(db);

    for(lekey = gdbm_firstkey(db);
        lekey.dptr != NULL;
        lekey = gdbm_nextkey(db, lekey)) {
        levalue = gdbm_fetch(db, lekey);
        record* r = (record*) levalue.dptr;
        if (r) {
            std::cout << lekey.dptr << " " << r->a << " " << r->b << std::endl;
            free(levalue.dptr);
        }
    }

    gdbm_close(db);

    return 0;
}
