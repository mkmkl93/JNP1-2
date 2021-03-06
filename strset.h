

#ifdef __cplusplus

namespace jnp1 {
    extern "C" {
#endif

        #include "stdio.h"

        unsigned long strset_new();

        void strset_delete(unsigned long id);

        size_t strset_size(unsigned long id);

        void strset_insert(unsigned long id, const char *value);

        void strset_remove(unsigned long id, const char *value);

        int strset_test(unsigned long id, const char *value);

        void strset_clear(unsigned long id);

        int strset_comp(unsigned long str1, unsigned long str2);

#ifdef __cplusplus
    }
}
#endif
