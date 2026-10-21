# Task 7 - Procedural and object-oriented versions

**Procedural version:** keep `balance` in a variable; call `can_travel(balance, fare)`; if permitted, subtract fare. It is O(1) time and O(1) storage, but any caller can bypass the check.

**OOP version:** `SmartCard` holds a private balance and exposes `canTravel(fare)` and `deduct(fare)`. `deduct` changes state only after checking the reserve. Invalid or insufficient deductions leave the state unchanged. This prevents a negative balance or balance below Rs 50.

Both versions have identical time and space complexity. Changing the reserve is one constant edit in either design, but the class makes it harder for unrelated code to break the invariant. A private member costs no additional per-journey time or storage compared with a public member. The runnable class is in the integrated C++ source at the repository root.
