# Task 10 - Expected versus actual execution

For a reproducible comparison assume each trip costs Rs 36 (Outer peak). Exact integer-paise totals: 20,000 trips = Rs 720,000 / 72,000,000 paise; 500,000 = Rs 18,000,000 / 1,800,000,000 paise; 3,000,000 = Rs 108,000,000 / 10,800,000,000,000 paise. These whole-rupee totals are exactly representable as doubles, but arbitrary fractional rupee fares can accumulate binary rounding differences.

A 32-bit signed int cannot hold the network total in paise; long long is sufficient. On common targets int is 4 bytes and long long/double are 8 bytes. Addition is O(1) in all three. `-Wall -Wextra -pedantic` enables warnings; signed/unsigned comparison can trigger `-Wsign-compare` and should be corrected. Actual timing and sizeof depend on the user's compiler and hardware, so record those after running locally rather than inventing measurements.
