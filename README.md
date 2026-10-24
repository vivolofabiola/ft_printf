# ft_printf

### step 1: ft_putstr_fd with NULL

FUNCTION put_str(s, fd) -> int
    IF s is NULL
        write "(null)"
        RETURN how many characters that is
    count = 0
    WHILE s[count] is not end-of-string
        write s[count]
        count = count + 1
    RETURN count

Done when: "hi" returns 2, "" returns 0, and NULL prints (null) and returns 6.


### Step 2: simple handlers (take the va_list, return a count)
```
FUNCTION print_char(list) -> int
    c = next argument from list, read as an int    (chars are promoted to int)
    RETURN put_char(c)
```
```
FUNCTION print_str(list) -> int
    s = next argument from list, read as a char pointer
    RETURN put_str(s)
```
```
FUNCTION print_percent() -> int
    RETURN put_char('%')
```
Done when: %c with 'A' returns 1, %s with "abc" returns 3, and %% returns 1.

### Step 3: number handlers
```
FUNCTION print_int(list) -> int          (%d and %i share this)
    n = next argument, read as an int
    RETURN putnbr(n)                      (your finished function)
```
```
FUNCTION print_unsigned(list) -> int      (%u)
    n = next argument, read as an unsigned int
    RETURN put_unsigned(n)
```
Done when: %u with 4294967295 prints it and returns 10. Reusing put_unsigned for %u is what makes it cheap.

put_unsigned is static right now. To use it from another file you need to remove static and add its prototype to your header.

### Step 4: hex
```
FUNCTION put_hex(n, uppercase_flag) -> int
    digits = "0123456789abcdef"   (or "0123456789ABCDEF" if uppercase_flag)
    count = 0
    IF n >= 16
        count = put_hex(n / 16, uppercase_flag)
    write digits[n % 16]
    RETURN count + 1
```
```
FUNCTION print_hex(list, uppercase_flag) -> int
    n = next argument, read as an unsigned int
    RETURN put_hex(n, uppercase_flag)
```
This is the same shape as put_unsigned, with 16 in place of 10 and a lookup string in place of + '0'. Think about why a lookup string works for hex.

Done when: 255 gives ff and returns 2, 255 with %X gives FF, and 0 gives 0 and returns 1.

### Step 5: %p
```
FUNCTION print_pointer(list) -> int
    p = next argument, read as a pointer, stored as an unsigned long
    IF p is 0
        write the text real printf gives for a null pointer
        RETURN its length
    count = write "0x"
    RETURN count + put_hex_long(p)

Two things to decide:

put_hex takes an unsigned int, but a pointer is 64 bits. You need a version that takes an unsigned long. Could you make put_hex do both with one parameter type, rather than writing it twice?
A null pointer prints (nil) on Linux but 0x0 on macOS. Your evaluation is on Linux, so match Linux.
```
### Step 6: the dispatcher

```
FUNCTION handle_conversion(c, list) -> int
    SWITCH on c
        'c'      -> RETURN print_char(list)
        's'      -> RETURN print_str(list)
        'p'      -> RETURN print_pointer(list)
        'd','i'  -> RETURN print_int(list)
        'u'      -> RETURN print_unsigned(list)
        'x'      -> RETURN print_hex(list, lowercase)
        'X'      -> RETURN print_hex(list, uppercase)
        '%'      -> RETURN print_percent()
        default  -> RETURN 0

Because each case returns, you don’t need break.
```

### Step 7: the main loop
```
FUNCTION ft_printf(format, ...) -> int
    i = 0
    total = 0
    va_start(list, format)           once, here
    WHILE format[i] is not end-of-string
        IF format[i] is '%'
            total = total + handle_conversion(format[i + 1], list)
            i = i + 2                skip '%' AND the letter
        ELSE
            total = total + put_char(format[i])
            i = i + 1
    va_end(list)                     once, here
    RETURN total
```
Trace "Age: %d\n" with the argument 7, writing i and total after each step:

step   i   format[i]   action          total
1      0   A           print literal   1
2      1   g           ...
...

Finish the table yourself. The final total should be 7 (Age: 7\n).

### Step 8: edge cases
```
A % at the very end of the format string: what is format[i + 1] there? Make sure the function doesn’t read past '\0'.
"%" alone, and "100%%".
Compare against real printf for every conversion, checking both the printed text and the return value:
  int a = printf("...", x);
  int b = ft_printf("...", x);
  compare a and b
```
File layout reminder

Keep each file at 5 functions or fewer. For example:

ft_printf.c: ft_printf, handle_conversion

chars and strings: put_char, put_str, print_char, print_str, print_percent

numbers: putnbr, put_unsigned, print_int, print_unsigned

hex: put_hex, print_hex, print_pointer

My suggestion for today: do Steps 1 to 3 first and test each handler with a tiny main before moving on. When you get stuck, paste the function and your trace and I’ll look at it.
