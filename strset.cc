#include "strset.h"
#include <unordered_map>
#include <set>
#include <iostream>
#include <string.h>
using namespace std;

unsigned long ID = 0;
unordered_map<int, set<string> > tab;

bool istnieje(unsigned long id)
{
    return (tab.find(id) != tab.end());
}

unsigned long strset_new()
{
    tab[ID] = set<string>();
//    cout<<tab.size()<<" "<<ID<<"\n";
    return ID++;
}

void strset_delete(unsigned long id)
{
    tab.erase(id);
}

size_t strset_size(unsigned long id)
{
    if(!istnieje(id))
        return 0;
    return tab[id].size();
}

void strset_insert(unsigned long id, const char* value)
{
    string pom(value);

    if(istnieje(id))
        tab[id].insert(pom);
}

void strset_remove(unsigned long id, const char* value)
{
    string pom(value);
    if(istnieje(id))
        tab[id].erase(value);
}

int strset_test(unsigned long id, const char* value)
{
    string pom(value);
    if(istnieje(id))
        return tab[id].find(value) != tab[id].end();
    return 0;
}

void strset_clear(unsigned long id)
{
    if(istnieje(id))
        tab[id].clear();
}

int strset_comp(unsigned long id1, unsigned long id2)
{
    if(istnieje(id1)||istnieje(id2))
    {
        if(istnieje(id1) && istnieje(id2))
        {
            if(tab[id1]<tab[id2])
                return -1;
            if(tab[id2]<tab[id1])
                return 1;
            return 0;
        }
        else if(istnieje(id1))
                return 1;
            else
                return -1;
    }
    else
        return 0;
}
