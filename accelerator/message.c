#include "message.h"
#include "stdio.h"

void ta_usage() {
  printf("tangle-accelerator usage:\n");
  for (int i = 0; i < cli_cmd_num; i++) {
    printf("--%-34s ", ta_cli_arguments_g[i].name);
    printf("     ");
    if (ta_cli_arguments_g[i].has_arg == REQUIRED_ARG) {
      printf(" arg ");
    } else if (ta_cli_arguments_g[i].has_arg == OPTIONAL_ARG) {
      printf("[arg]");
    } else {
      printf("     ");
    }
    printf(" %s \n", ta_cli_arguments_g[i].desc);
  }
}
