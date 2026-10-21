# Task 5 - Expressions and precedence

Prediction:
```text
11 16
9 6 4
6 4
3 1 -3 -1
18
```

In `x + y * 2`, multiplication precedes addition (11); parentheses force `(x+y)*2` (16). In `x++ + ++y`, postfix yields old x=5 and increments x; prefix increments y to 4 and yields 4. The sum is 9 and state becomes x=6,y=4. The conditional chooses 6. `%` and `*` associate left-to-right: `(6%4)*2=4`. Integer division truncates toward zero: 10/3=3 and -10/3=-3; remainder has dividend's sign, so -10%3=-1. The loop sums 0+3+6+9=18. `i=i++` is an unsafe, misleading update; avoid it. `++i` yields the new value; `i++` yields the prior value.

Peak expression: `(hour >= 8 && hour < 10) || (hour >= 17 && hour < 20)`. `&&` binds tighter than `||`; parentheses clarify the half-open intervals. Surcharge: `fare += fare * 20 / 100`; concession: `fare = fare * (100 - discountPercent) / 100`, with bounds and rounding policy validated. A 24-entry `bool peak[24]` lookup remains O(1), costs 24 bytes, and requires initialization.
