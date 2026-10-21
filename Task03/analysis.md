# Task 3 - Data types and compatibility

| Value | Type | Reason |
|---|---|---|
| Fare, balance, total | `long long` paise | Exact currency and aggregate capacity |
| Zone | `enum class Zone` | Closed, type-safe categories |
| Hour, minute, percent | `int` | Small signed values with validation |
| Peak, validity, pass result | `bool` | Two-state facts |
| Journey count | `long long` | Scales to network use |
| Displayed rupees | `long long` and remainder | Exact formatting |
| Input token | `std::string` | Validate before conversion |

Common g++ sizes are bool 1, char 1, int 4, long long 8, float 4 and double 8 bytes; verify `sizeof` on the target system. `<climits>` supplies `INT_MAX` (typically 2,147,483,647) and `LLONG_MAX` (typically 9,223,372,036,854,775,807). Three million Rs 36 trips total Rs 108,000,000,000 or 10,800,000,000,000 paise, beyond `int` but safe in `long long`.

Integer paise avoids binary floating representation errors. Both double and long long addition are O(1) and typically 8 bytes. Integer paise has no rounding accumulation provided overflow is prevented. Usual arithmetic conversions can promote int to double; bool promotes to int in arithmetic. Use explicit casts at intentional conversion boundaries.
