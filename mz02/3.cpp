class C
{
    double arg_{};
public:
    C() {}
    C(double a) : arg_(a) {}
    C(C a, C b) : arg_(a.arg_ + b.arg_) {}
    C(C* a) : arg_(a->arg_) {}
    C operator[](int a) {
        return *this;
    }
    friend C operator+(const C& a, const C& b); 
    int operator*(const C& a) {
        return (int) (a.arg_ * arg_);
    }
    C operator++() {
        arg_ += 1;
        return *this;
    }
    C operator~() const {
        return *this;
    }
    C operator&() const {
        return *this;
    }
    operator int() {
        return (int) arg_;
    }
};


C operator+(const C & a, const C & b){
    C res = C(a.arg_ + b.arg_);
    return res;
}
