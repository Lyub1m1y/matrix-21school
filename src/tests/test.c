#include <check.h>

#include "list.h"

int main() {
  Suite *suite = suite_create("s21_matrix");
#ifdef suite_add_tcase_list
  suite_add_tcase_list(suite);
#endif

  SRunner *suite_runner = srunner_create(suite);
#ifdef srunner_add_suite_list
  srunner_add_suite_list(suite_runner);
#endif

  srunner_run_all(suite_runner, CK_NORMAL);
  int failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
  return (failed_count != 0);
}
