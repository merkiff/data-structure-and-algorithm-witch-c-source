//#include <boost/functional/hash.hpp>
// Boost 라이브러리에서 제공하는 hash_combine() 함수로 원하는 해시 함수 구성하기
/*
struct Car
{
    std::string model;
    std::string brand;
    int buildYear;
};

struct CarHasher
{
    std::size_t operator()(const Car& car) const
    {
        std::size_t seed = 0;
        boost::hash_combine(seed, car.model);
        boost::hash_combine(seed, car.brand);
        return seed;
    }
};

struct CarComparator
{
    bool operator()(const Car& car1, const Car& car2) const
    {
        return (car1.model == car2.model) && (car1.brand == car2.brand);
    }
};
*/