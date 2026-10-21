#include <array>
#include <iostream>
#include <iomanip>
#include <limits>

enum class Zone { Inner, Middle, Outer, Airport };
enum class DayType { Weekday, Weekend };
constexpr std::array<long long, 4> BASE_PAISE{1000, 2000, 3000, 6000};
constexpr int PEAK_SURCHARGE_PERCENT = 20;
constexpr long long MIN_BALANCE_PAISE = 5000;

constexpr bool isPeak(int hour) {
    return (hour >= 8 && hour < 10) || (hour >= 17 && hour < 20);
}
long long calculateFare(Zone zone, int hour, DayType day) {
    const auto index = static_cast<std::size_t>(zone);
    if (index >= BASE_PAISE.size() || hour < 0 || hour > 23) return -1;
    const long long base = BASE_PAISE[index];
    if (day == DayType::Weekend) return base * 90 / 100; // no peak surcharge
    return isPeak(hour) ? base + base * PEAK_SURCHARGE_PERCENT / 100 : base;
}
class SmartCard {
    long long balance_;
public:
    explicit SmartCard(long long initial) : balance_(initial < 0 ? 0 : initial) {}
    bool canTravel(long long fare) const {
        return fare >= 0 && balance_ - fare >= MIN_BALANCE_PAISE;
    }
    bool deduct(long long fare) {
        if (!canTravel(fare)) return false;
        balance_ -= fare;
        return true;
    }
    long long balance() const { return balance_; }
};
int main() {
    SmartCard card(10000);
    struct Trip { Zone zone; int hour; DayType day; };
    const Trip trips[] = {
        {Zone::Inner, 7, DayType::Weekday},
        {Zone::Outer, 18, DayType::Weekday},
        {Zone::Middle, 10, DayType::Weekday},
        {Zone::Airport, 18, DayType::Weekend}
    };
    for (const auto& trip : trips) {
        const long long fare = calculateFare(trip.zone, trip.hour, trip.day);
        if (card.deduct(fare)) {
            std::cout << "Accepted fare Rs " << fare / 100 << '.'
                      << std::setw(2) << std::setfill('0') << fare % 100
                      << std::setfill(' ') << "; balance paise=" << card.balance() << '\n';
        } else {
            std::cout << "Denied; balance paise=" << card.balance() << '\n';
        }
    }
}
