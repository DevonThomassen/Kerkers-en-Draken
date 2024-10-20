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
         * @param size The reserved size of the array. Default is 4.
         */
        explicit Array(const int size = 4)
                : size_(size),
                  data_(nullptr) {}

        ~Array() {
            delete[] data_;
        }

        /**
         * @brief Copy constructor for the Array class.
         * @param other The Array object to copy.
         */
        [[nodiscard]] T& operator[](const int index) {
            return data_[index];
        }

        /**
         * @brief Copy assignment operator for the Array class.
         * @param other The Array object to copy.
         */
        [[nodiscard]] const T& operator[](const int index) const {
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
        [[nodiscard]] T* data() {
            return data_;
        }

        /**
         * @brief Resizes the array to the given size.
         * @param new_size The new size of the array.
         */
        void resize(const int new_size) {
            T* new_data = new T[new_size];
            for (int i = 0; i < size_; ++i) {
                new_data[i] = data_[i];
            }
            delete[] data_;
            data_ = new_data;
            size_ = new_size;
        }

        /**
         * @brief Adds an element to the end of the array.
         * @param element The element to add.
         * @note If the array is full, the array will be resized.
         * @note If the array is empty, the array will be resized to 1.
         */
        void push_back(const T& element) {
            if (size_ == 0) {
                resize(1);
            } else if (size_ == 1) {
                resize(2);
            } else if (size_ == 2) {
                resize(4);
            } else {
                resize(size_ * 2);
            }
            data_[size_ - 1] = element;
        }

    private:
        int size_;
        T* data_;
    };

} // domain

#endif //ARRAY_HPP
