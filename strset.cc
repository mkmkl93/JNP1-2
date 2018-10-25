#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include "strset.h"

namespace jnp1{
    std::set<unsigned long> unusedInts;
    std::unordered_map<unsigned long, std::set<std::string>> strSets;
    unsigned long id;

    bool istnieje(unsigned long id)
    {
        return (strSets.find(id) != strSets.end());
    }

    unsigned long strset_new(){
        strSets[id] = std::set<std::string>();
        return id++;
    }
    void strset_delete(unsigned long id) {
        strSets.erase(id);
    }

    size_t strset_size(unsigned long id) {
        if(!istnieje(id))
            return 0;
        return strSets[id].size();
    }

    void strset_insert(unsigned long id, const char *value) {
        std::string pom(value);

        if(istnieje(id))
            strSets[id].insert(pom);
    }

    void strset_remove(unsigned long id, const char *value) {
        std::string pom(value);

        if(istnieje(id))
            strSets[id].erase(value);
    }

    int strset_test(unsigned long id, const char *value) {
        std::string pom(value);

        if(istnieje(id))
            return strSets[id].find(value) != strSets[id].end();
        return 0;
    }

    void strset_clear(unsigned long id) {
        if(istnieje(id))
            strSets[id].clear();
    }

    int strset_comp(unsigned long id1, unsigned long id2) {
        if(istnieje(id1)||istnieje(id2)) {
            if(istnieje(id1) && istnieje(id2)){
                if(strSets[id1]<strSets[id2])
                    return -1;
                if(strSets[id2]<strSets[id1])
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

}

unsigned long strset_new(){
    return jnp1::strset_new();
}

void strset_delete(unsigned long id) {
    return jnp1::strset_delete(id);
}

size_t strset_size(unsigned long id) {
    return jnp1::strset_size(id);
}

void strset_insert(unsigned long id, const char *value) {
    return jnp1::strset_insert(id, value);
}

void strset_remove(unsigned long id, const char *value) {
    return jnp1::strset_remove(id, value);
}

int strset_test(unsigned long id, const char *value) {
    return jnp1::strset_test(id, value);
}

void strset_clear(unsigned long id) {
    return jnp1::strset_clear(id);
}

int strset_comp(unsigned long str1, unsigned long str2) {
    return jnp1::strset_comp(str1, str2);
}
