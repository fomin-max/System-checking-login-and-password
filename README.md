# System-checking-login-and-password
The program is written for the Linux.
The login and password are requested from the keyboard, then the entered password is checked (the password can consist of an arbitrary string of characters) for the specified user (the database can contain several users).
If the correct password is entered, then you are logged in and you can change your password.
If the password is entered incorrectly three times, the program is exited.

The user database is contained in the passwd file (the fields are separated by a colon):
Arnold: 232uywejrkh: Arnold Robbins
Helga: sdfsfwerw333: Helga Robbins
Homer: 123: Homer Simpson

The password is stored in encrypted form: XOR-encryption (the key is inside the program).

To work with the user base, the function looks like this: struct passwd * getpw (void) - returns a pointer to the struct passwd structure that contains information about the current user.

Secure operation of the program is ensured - control and check for overflow of the arrays.
The program source code is divided into several files (the header file), the make utility was used to build the files.
