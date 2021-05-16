#include <iostream>
template<typename It1st, typename It1fin, typename It2, 
        class Multiply = std::multiplies<typename std::iterator_traits<It1st>::value_type>,
        class Addition = std::plus<typename std::iterator_traits<It1st>::value_type> >
typename std::iterator_traits<It1st>::value_type scalar_mul(
        It1st Ibeg,
        It1fin Iend, 
        It2 I2, 
        typename std::iterator_traits<It1st>::value_type Init = 
                    typename std::iterator_traits<It1st>::value_type(),
        Multiply MulF = std::multiplies<typename std::iterator_traits<It1st>::value_type>(),
        Addition AddF = std::plus<typename std::iterator_traits<It1st>::value_type>()
        )
{
    for (auto it = Ibeg; it != Iend; ++it, ++I2) {
        Init = AddF(Init, MulF(*it, *I2));
    }
    return Init;
}