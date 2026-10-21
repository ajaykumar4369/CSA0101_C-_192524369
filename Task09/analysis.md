# Task 9 - Implement and test fare logic

Use a table-driven suite: ordinary Inner/Middle/Outer fares are 1000/2000/3000 paise off-peak. Peak boundaries are half-open: 08:00 and 17:00 peak; 10:00 and 20:00 off-peak. Expected fares: Inner at 08:00 = 1200; Inner at 10:00 = 1000; Middle at 17:00 = 2400; Outer at 20:00 = 3000.

Reserve tests: balance 6000 paise with a 1000 fare succeeds and leaves exactly 5000; balance 5999 is denied. Reject unknown zones, negative recharges and letters for the hour before changing state. Five hand-calculated trips (Inner 1000, Middle 2000, Outer 3000, Inner peak 1200, Middle peak 2400) sum to 9600 paise (Rs 96).

A table with t cases takes O(t) time and O(t) storage, and new boundary cases are added as rows. Test source is available in the repository's integrated C++ program; verify each expected/actual row with the compiler on the submission machine.
