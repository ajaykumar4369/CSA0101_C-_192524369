# Task 1 - Problem and object analysis

**Objects.** A SmartCard owns its id and private integer-paise balance; canTravel and deduct enforce the reserve. Passenger holds category and eligibility. Journey records origin/destination zones, time, day type and fare. Zone is the closed network set; FareTable maps zones to base fares. This separation prevents fare constants and balance checks from being duplicated.

**Procedural versus OOP.** Procedural functions pass balance, zone, time and passenger category, updating balance by reference. OOP binds state and valid operations together. Both are O(1) time per journey and O(1) state per card. Encapsulation confines rule updates and prevents callers from bypassing validation.

**OOP principles.** Encapsulation: private card balance. Abstraction: charge(journey) hides calculation details. Inheritance could model concessions, but an enum or strategy is simpler for two categories. Polymorphism could use a DiscountPolicy interface for student, senior and future pass policies.

**Invariants and assumptions.** Zone is valid; hour is 0-23; fares are nonnegative; peak intervals are [08:00,10:00) and [17:00,20:00); surcharge is 20%, rounded to nearest paise. Concession rates are unspecified in the brief and must be set by policy. Every accepted journey leaves at least 5000 paise. Invalid input never changes the card.

**Complexity.** Procedural fare(zone,time,kind) plus try_deduct(balance,fare) and OOP FareTable::fare(journey) plus SmartCard::charge(fare) both use O(1) time and O(1) extra memory per card. OOP centralizes rule changes and protects invariants.
