typedef enum {
  api_ok,
  api_fail,
  api_invalid_arg
} api_status;

typedef struct {
  const char *err_msg;
  api_status err_code;
} api_error_info;
