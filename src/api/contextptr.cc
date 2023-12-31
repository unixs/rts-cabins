#include <contextptr.hpp>

#define NAN_PLACEHOLDER_SIZE 5

static inline void
save_ptr_to_float_arr(const float *dst, void **ptr_to_data_ptr)
{
  memcpy((void *) dst, ptr_to_data_ptr, sizeof(void *));
}

static inline void
restore_ptr_from_float_arr(const float *src, void **ptr_to_data_ptr)
{
  memcpy(ptr_to_data_ptr, src, sizeof(void *));
}

static api_status
prepare_float_arr(float dst[], const size_t arr_size)
{
  if (arr_size < NAN_PLACEHOLDER_SIZE) {
    return api_fail;
  }

  for (short i = 0; i < NAN_PLACEHOLDER_SIZE; i++) {
    dst[i] = NAN;
  }

  return api_ok;
}

api_status
save_context_ptr(Context **ctxt_ptr, float dst[], const size_t arr_size)
{
  api_status fail = prepare_float_arr(dst, arr_size);

  if (fail) {
    return api_invalid_arg;
  }

  save_ptr_to_float_arr(dst, reinterpret_cast<void **>(ctxt_ptr));

  return api_ok;
}

Context *
restore_context_ptr(const float src[])
{
  void *ctxt = NULL;
  // TODO: check NaN's around pointer here

  restore_ptr_from_float_arr(src, &ctxt);

  return reinterpret_cast<Context *>(ctxt);
}
