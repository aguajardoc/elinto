// Usage: rng();
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
// Get random integer in range
const int B = uniform_int_distribution<int>(lb, ub)(rng);
// Shuffle an array
shuffle(a.begin(), a.end(), rng);
