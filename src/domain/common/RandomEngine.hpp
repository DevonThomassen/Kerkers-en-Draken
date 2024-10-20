#ifndef RANDOMENGINE_HPP
#define RANDOMENGINE_HPP

#include <random>

/**
 * @class RandomEngine
 * @brief A class that represents a random engine.
 */
class RandomEngine {
public:
    /**
     * @brief Get the instance of the RandomEngine.
     * @return The instance of the RandomEngine.
     */
    static RandomEngine& get_instance() {
        static RandomEngine instance;
        return instance;
    }

    // Delete copy and move constructors and assign operators
    RandomEngine(RandomEngine const&) = delete;
    void operator=(RandomEngine const&) = delete;

    /**
     * @brief Generates a random number.
     * @param min The minimum value.
     * @param max The maximum value.
     * @return The random number.
     */
    int generate_random_number(int min, int max) {
        std::uniform_int_distribution<int> distribution(min, max);
        return distribution(engine_);
    }

    /**
     * @brief Generates a random number.
     * @tparam T The type of the number.
     * @param min The minimum value.
     * @param max The maximum value.
     * @return Optional containing the random number.
     */
    template<typename T>
    std::optional<T> generate_random(T min, T max) {
        if constexpr (std::is_integral<T>::value) {
            std::uniform_int_distribution<T> distribution(min, max);
            return distribution(engine_);
        }
        if constexpr (std::is_floating_point<T>::value) {
            std::uniform_real_distribution<T> distribution(min, max);
            return distribution(engine_);
        }
        return std::nullopt;
    }

    /**
     * @brief Generates a random boolean.
     * @return The random boolean.
     */
    std::optional<bool> hit_percentage(const int percentage) {
        if (percentage < 0 || percentage > 100) {
            return std::nullopt;
        }
        std::uniform_int_distribution<int> distribution(1, percentage);
        return distribution(engine_) <= percentage;
    }

private:
    std::random_device device_;
    std::default_random_engine engine_;

    explicit RandomEngine()
            : device_(),
              engine_(device_()) {}
    ~RandomEngine() = default;
};

#endif //RANDOMENGINE_HPP
