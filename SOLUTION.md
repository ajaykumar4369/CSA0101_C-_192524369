# Assignment 1 — Tasks 1–12: written solutions

Student: Mohamed Haarun M H (verify before submission)  
Register number: 192524430

## Task 1 — Objects and invariants
- **SmartCard:** private balance in integer paise; canTravel/deduct protect the minimum balance.
- **Passenger:** category and concession eligibility; the brief does not specify student/senior rates, so do not invent a rate.
- **Journey:** zone, departure time, date/day type and fare.
- **Zone/FareTable:** scoped zone values and one authoritative base-fare table.
- Encapsulation protects balance; abstraction exposes fare/deduct operations; inheritance may represent passenger types; polymorphism can select fare policies. Procedural and OOP implementations both take O(1) time per journey and O(1) state per card, but OOP centralizes rule changes.
- Invariants: valid zone/hour; money in paise; peak intervals [08:00,10:00) and [17:00,20:00); successful trip leaves at least 5000 paise; invalid/negative inputs are rejected.

## Task 2 — Tokens and constants
Examples: keyword `constexpr`; identifier `MIN_BALANCE_PAISE`; literal `5000`; operator `>=`; punctuator `{}`. `#define` is textual substitution without type checking; `const` prevents mutation; `constexpr` enables compile-time evaluation. Prefer `constexpr` arrays and `enum class Zone` for typed, scoped zone values. Macros do not materially improve runtime and usually offer less safety.

## Task 3 — Data types
Use `bool` for peak/eligibility, `enum class` for zones, `int` for hours, and `long long` for paise totals. Use `std::size_t` for container sizes. Floating point is unsuitable for authoritative money because decimal fractions may not be exactly representable. Typical sizes are bool 1, char 1, int 4, long long 8, float 4, double 8 bytes (verify with sizeof). At ₹36 per trip, 3,000,000 trips total ₹108,000,000 = 10,800,000,000 paise, beyond a typical 32-bit signed int in paise.

## Task 4 — Conversions and predicted output
Expected output:
```
3 3.5
C 68
1 true
s >= u
```
`a / b` is integer division before assignment to double; casting before division gives 3.5. Character arithmetic promotes char to int. Nonzero int converts to true. In comparison with unsigned, -1 converts to unsigned, so `s < u` is false. Use explicit casts and brace initialization to catch narrowing.

## Task 5 — Precedence and predicted output
Expected output:
```
11 16
9 6 4
6 4
3 1 -3 -1
18
```
Multiplication precedes addition; parentheses override grouping. Post-increment yields the old value, pre-increment yields the new value. Modulo and multiplication associate left-to-right. Integer division truncates toward zero; remainder follows the dividend's sign. Loop sum is 0+3+6+9=18. Avoid confusing increment expressions such as `i = i++`.

## Task 6 — Control structures and pseudocode
1. Validate zone and hour.
2. Switch on zone to select 1000/2000/3000 paise.
3. Peak is `(hour >= 8 && hour < 10) || (hour >= 17 && hour < 20)`.
4. If peak, fare = base + base*20/100; otherwise fare = base.
5. Allow journey only if balance - fare >= 5000; deduct only after checking.
The provided `Task06/task06_switch.cpp` sample should print ₹10.00 (balance ₹90), ₹36.00 (balance ₹54), then deny the next trip.

## Task 7 — Procedural vs OOP
Procedural code uses separate balance variables and free functions; every caller must obey the contract. A `SmartCard` class with private balance and `deduct`/ `canTravel` prevents unauthorized negative/too-low balance updates. Both are O(1) per trip and O(1) per card; public balance would let any caller violate the invariant.

## Task 8 — Safe input/output
Check stream extraction and the hour range. On invalid input, use `cin.clear()` then `cin.ignore(numeric_limits<streamsize>::max(), '\\n')`. Use `setw`/`setfill` for integer paise formatting; `fixed`/`setprecision(2)` is for display only. `getline` plus `stoi` is O(L) time and O(L) buffer space for a line of length L; catch parsing exceptions.

## Task 9 — Testing
Peak boundary expected cases: 07 off-peak; 08 peak; 09 peak; 10 off-peak; 17 peak; 20 off-peak. Add integration tests for all zones, invalid zone, negative recharge, letters in hour input and a balance ending at exactly 5000 paise. A test table of t cases takes O(t) time and O(t) storage.

## Task 10 — Expectations versus execution
At ₹36 per journey: 20,000 => ₹720,000 (72,000,000 paise); 500,000 => ₹18,000,000 (1,800,000,000 paise); 3,000,000 => ₹108,000,000 (10,800,000,000 paise). The last paise total exceeds typical INT_MAX 2,147,483,647. Use long long; every addition is O(1), and each accumulator uses constant space. Double has a wider range but can introduce rounding differences.

## Task 11 — Recommendation
Use `enum class Zone`, `constexpr` fare constants/table, integer paise, long long aggregate totals, private card balance and independently testable fare-policy logic. Validate every external input. Fare calculation is O(1), processing N journeys O(N). A configuration file allows fare changes without recompilation but requires startup parsing, validation and malformed-file handling (O(z) for z fares).

## Task 12 — Design challenge
Modify the design: add Airport at 6000 paise, use a four-entry fare table, and separate day-type policy from peak policy. Weekend discount is 10% and does not combine with peak surcharge. A monthly pass covers two chosen zones and yields zero fare for covered trips. Worked examples: Airport weekday peak = ₹72; Airport weekend peak = ₹54; covered Outer trip = ₹0. Validate zone indexes and pass choices; the brief does not specify expiry or transfer rules.
