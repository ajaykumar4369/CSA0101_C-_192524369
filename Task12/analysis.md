# Task 12 - Re-evaluate and adapt the design

## Impact analysis
Add `Zone::Airport` at Rs 60.00, a weekend discount constant and a monthly pass holding two selected zones. Update the fare table, zone validation, display and tests. The SmartCard balance invariant remains unchanged.

## Evaluation and decision
Modify the existing design rather than replace it: keep SmartCard encapsulation, replace the small switch with a bounds-checked fare table, and add distinct weekend and pass policies. The switch can absorb Airport with another case, but a table scales more clearly as zones grow. Weekend discount takes precedence and does not combine with peak surcharge.

## Adapted policy and examples
Airport weekday peak = Rs 72.00 (6000 + 20%); Airport weekend, even during peak = Rs 54.00 (6000 - 10%). A pass covering Inner and Outer allows unlimited journeys in those two zones during its active month; Middle and Airport remain chargeable. A fare table lookup and two-zone membership check are O(1); storage is O(z) fares plus two zones per pass.

The revised implementation is in the repository's integrated C++ source. Tests should cover all four base fares, weekend/peak exclusivity, covered and uncovered zones, invalid zone rejection, and card reserve. Retaining the tested card class limits change risk while the fare policy adapts to the new products.
