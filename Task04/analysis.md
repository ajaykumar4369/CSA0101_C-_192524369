# Task 4 - Implicit conversions

Prediction made from the rules before execution:

```text
3.5 3.5
C 68
1 true
s >= u
```

`a / b` performs integer division (both operands int), yielding 3 before conversion to double; an explicit cast makes the second division floating point. `'A' + 2` promotes char to int and assignment converts 67 to char 'C'; printing `ch + 1` promotes char to int and yields 68. Integer 5 converts to bool true; default output is 1, then `boolalpha` prints true. For `s < u`, usual arithmetic conversions convert -1 to unsigned, so `s >= u` is printed. `-Wsign-compare` warns about this comparison.

Safer code uses `static_cast<double>(a) / b` and brace initialization (`int n{3};`). `int n{3.7};` is ill-formed due to narrowing, caught during compilation. Explicit casts do not materially change time or storage; they make intent visible.
