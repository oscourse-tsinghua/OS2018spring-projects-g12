#define __str_1(x...)     #x
#define __str(x...)       __str_1(x)

#define include_bin(__file, name) \
  .globl _##name##_start; \
  _##name##_start:; \
  .incbin __str(/home/liupan15/Desktop/OS2018spring-projects-g12/ucore_plus/ucore/out/kernel/arch/amd64/__file); \
  _##name##_end:; \
  .globl _##name##_size; \
  _##name##_size:; \
    .quad _##name##_end - _##name##_start

.section .piggydata, "a", @progbits
include_bin(init/bootother, bootother)
