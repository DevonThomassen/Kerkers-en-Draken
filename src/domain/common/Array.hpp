#ifndef ARRAY_HPP
#define ARRAY_HPP

namespace domain {

    /**
     * @class Array
     * @brief A RAII class for creating dynamic arrays.
     */
    template<typename T>
    class Array {
    public:
        /**
         * @brief Constructor for the Array class.
         * @param capacity The reserved size of the array. Default is 4.
         */
        explicit Array(int capacity = 4)
                : size_(0),
                  capacity_(capacity),
                  data_(new T* [capacity]) {}

        /**
         * @brief Copy constructor.
         * @param other The Array to copy.
         */
        Array(const Array& other)
                : size_(other.size_),
                  capacity_(other.capacity_),
                  data_(new T* [other.capacity_]) {
            for (int i = 0; i < size_; ++i) {
                data_[i] = other.data_[i];
            }
        }

        /**
         * @brief Copy assignment operator.
         * @param other The Array to copy.
         * @return The copied Array.
         */
        Array& operator=(const Array& other) {
            if (this != &other) {
                delete[] data_;
                size_ = other.size_;
                capacity_ = other.capacity_;
                data_ = new T* [other.capacity_];
                for (int i = 0; i < size_; ++i) {
                    data_[i] = other.data_[i];
                }
            }
            return *this;
        }

        /**
         * @brief Move constructor.
         * @param other The Array to move.
         */
        Array(Array&& other) noexcept
                : size_(other.size_),
                  capacity_(other.capacity_),
                  data_(other.data_) {
            other.size_ = 0;
            other.capacity_ = 0;
            other.data_ = nullptr;
        }

        /**
         * @brief Move assignment operator.
         * @param other The Array to move.
         * @return The moved Array.
         */
        Array& operator=(Array&& other) noexcept {
            if (this != &other) {
                delete[] data_;
                size_ = other.size_;
                capacity_ = other.capacity_;
                data_ = other.data_;
                other.size_ = 0;
                other.capacity_ = 0;
                other.data_ = nullptr;
            }
            return *this;
        }

        /**
         * @brief Destructor for the Array class.
         */
        ~Array() {
            delete[] data_;
        }

        /**
         * @brief Overloaded subscript operator.
         * @param index The index of the element to access.
         * @return The element at the specified index.
         */
        T* operator[](const int index) {
            return data_[index];
        }

        /**
         * @brief Overloaded subscript operator.
         * @param index The index of the element to access.
         * @return The element at the specified index.
         */
        const T& operator[](const int index) const {
            return data_[index];
        }

        /**
         * @brief Returns the size of the array.
         * @return The size of the array.
         */
        [[nodiscard]] int size() const {
            return size_;
        }

        /**
         * @brief Returns the data of the array.
         * @return The data of the array.
         */
        [[nodiscard]] const T** data() const {
            return data_;
        }

        /**
         * @brief Reserves memory for the array.
         * @param new_capacity The new capacity of the array.
         */
        void reserve(const int new_capacity) {
            T** new_data = new T* [new_capacity]{nullptr};
            for (int i = 0; i < size_; ++i) {
                new_data[i] = data_[i];
            }
            delete[] data_;
            data_ = new_data;
            capacity_ = new_capacity;
        }

        /**
         * @brief Adds an element to the array.
         * @param element The element to add.
         */
        void push_back(T* element) {
            if (size_ == capacity_) {
                reserve(capacity_ * 2);
            }
            data_[size_++] = element;
        }

        /**
         * @brief Removes the last element from the array.
         */
        void pop_back() {
            if (size_ > 0) {
                data_[size_--] = nullptr;
            }
        }

    private:
        int size_;
        int capacity_;
        T** data_;
    };

} // domain

#endif //ARRAY_HPP
