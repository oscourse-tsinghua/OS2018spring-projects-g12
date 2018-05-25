#define __str_1(x...)     #x
#define __str(x...)       __str_1(x)

#define include_bin(__file, name) \
  .globl _##name##_start; \
  _##name##_start:; \
  .incbin __str(/dockershare/ucore/out/kernel/arch/amd64/__file); \
  _##name##_end:; \
  .globl _##name##_size; \
  _##name##_size:; \
    .quad _##name##_end - _##name##_start

.section .piggydata, "a", @progbits
include_bin(init/bootother, bootother)
