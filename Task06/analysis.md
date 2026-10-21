# Task 6 - Control structures

**Algorithm:** validate the zone; use a switch to select the base paise fare; compute peak as `(hour >= 8 && hour < 10) || (hour >= 17 && hour < 20)`; if peak, add 20% using integer arithmetic; return fare. Reject unknown zones and invalid hours. A counted for loop handles a known journey list; range-for is concise for existing trips; while suits input until EOF. `continue` skips invalid journeys; `break` exits on a fatal condition. Always include switch `default`.

Use if/else for time intervals, switch for the closed zone enum, and avoid nested conditional operators when they reduce clarity. The completed starter uses switch and integer paise. Expected output: Fare Rs 10.00 balance Rs 90; Fare Rs 36.00 balance Rs 54; Denied (low balance) balance Rs 54.

Alternative: a bounds-checked fare array indexed by zone remains O(1), uses space for the fares, and makes adding a fourth zone a new entry. A switch needs another case; compilers may implement it as a jump table.
