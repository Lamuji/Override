Here, you either rack your brain and learn some stuff, or you go with the dumb and easy method.
Obviously, **no-brainer**.

The program asks us for a password.
Looking at the decompiled code, we see that the input is passed to a "test" function along with a second argument (322424845).

In the switch-case, our password is sent to the decrypt function IF the difference between the second argument and our password is equal to 1, 2, 3… 9, 16, 17, 18… 21.

The decrypt function performs a comparison using XOR (exclusive OR, meaning a bit comparison where the result is 1 only if the two bits are different). If the result of this XOR operation between our password and the encrypted string "Q}|u`sfg~sf{}|a3" decrypts to "Congratulations!", then bingo.

You get it—there are only about 15 numbers to test, so we’re not going to overthink it.