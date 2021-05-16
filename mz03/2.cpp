namespace numbers {
    class complex_stack
    {
        complex *stack_;
        size_t size_{};
    public:
        complex_stack() : stack_{nullptr}, size_{0} {}
        complex_stack(int size)
        {
            stack_ = new complex[size];
            size_ = size;
        }
        complex_stack(const complex_stack &other) : size_{other.size_}
        {
            stack_ = new complex[size_];
            for (size_t i = 0; i < size_; ++i) {
                stack_[i] = other[i];
            }
        }
        void swap(complex_stack &other) noexcept
        {
            std::swap(stack_, other.stack_);
            std::swap(size_, other.size_);
        }
        complex_stack & operator= (complex_stack other)
        {
            swap(other);
            return *this;
        }
        complex & operator[] (size_t index) const
        {
            return stack_[index];
        }
        size_t size() const
        {
            return size_;
        }
        complex_stack operator<< (complex number) const
        {
            complex_stack new_stack(size_ + 1);
            for (size_t i = 0; i < size_; ++i) {
                new_stack[i] = stack_[i];
            }
            new_stack[new_stack.size() - 1] = number;
            return new_stack;
        }
        complex operator+ () const
        {
            return stack_[size_ - 1];
        }
        complex_stack operator~ () const
        {
            complex_stack new_stack(size_ - 1);
            for (size_t i = 0; i < size_ - 1; ++i) {
                new_stack[i] = stack_[i];
            }
            return new_stack;
        }
        ~complex_stack()
        {
            delete[] stack_;
        }
    };
}