# Task 2 - Tokens, constants, and identifiers

A declaration such as `constexpr long long MIN_BALANCE_PAISE = 5000;` contains keywords (`constexpr`, `long`), an identifier (`MIN_BALANCE_PAISE`), a literal (`5000`), an operator (`=`), and punctuator (`;`). Use `constexpr` for compile-time fares and limits because it is typed, scoped, and usable in constant expressions. `const` suits read-only runtime values. `#define` is textual substitution with no type or scope and can duplicate side effects.

`enum class Zone { Inner, Middle, Outer }` scopes enumerators and prevents accidental integer mixing; a plain enum converts more freely. Identifiers begin with a letter or underscore and contain letters, digits, or underscores; avoid reserved underscore patterns. Use PascalCase for types, UPPER_SNAKE_CASE for constants, and descriptive lower camel case for functions and variables.

**Alternative and complexity.** `#define OUTER_FARE 3000` uses no storage, as an optimized constexpr generally does. Both have O(1) runtime impact and no meaningful per-journey memory. A macro lacks type checking and scope; constexpr is compiler checked. A fourth zone adds an enum value and a fare-table entry; a size check can keep the table aligned with the enum.
