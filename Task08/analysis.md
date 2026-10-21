# Task 8 - Safe input and output

For formatted extraction with `cin >>`, check `cin.fail()` after every read; on failure call `cin.clear()` and discard the bad line with `cin.ignore(numeric_limits<streamsize>::max(), '\n')` before retrying. Otherwise the stream remains failed. The supplied input program reads complete lines, validates numeric conversion and bounds, then reprompts.

Store money in integer paise. For output, split rupees and paise and use `setw(2)` and `setfill('0')`; `fixed` and `setprecision(2)` are display-only. `getline` plus `stoi` costs O(L) for a line of length L and O(L) buffer space; it permits explicit exception handling and trailing-junk rejection. Stream extraction is convenient for tokens but requires careful state recovery.
