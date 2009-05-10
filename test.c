#include <errno.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include <scrypt.h>
/*
  int scrypt(const uint8_t * passwd, size_t passwdlen,
        const uint8_t * salt, size_t saltlen, uint64_t N, uint32_t r, uint32_t p,
            uint8_t * buf, size_t buflen);
            */

main() {
  char buf[1024];
  int ret = scrypt("abcdefg", 7, "..", 2, 128, 2, 2, buf, sizeof(buf));
  if (ret != 0) {
    perror("scrypt");
    exit(ret);
  }
  printf("%s\n", buf);
}
