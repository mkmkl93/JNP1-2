#ifdef __cplusplus
namespace jnp1 {
    unsigned long strset42();
}

extern "C" unsigned long strset42();
#else
unsigned long strset42();
#endif
