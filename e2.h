//
// Created by Brian Swenson on 2/8/18.
//

#ifndef E2_E2_H
#define E2_E2_H

#endif //E2_E2_H


template <typename Iterator>
typename std::iterator_traits<Iterator>::value_type
adder(Iterator begin, Iterator end)
{
    using T = typename std::iterator_traits<Iterator>::value_type;
    return std::accumulate(begin, end, T());
}

template <typename Iterator>
typename std::iterator_traits<Iterator>::value_type
minimum(Iterator begin, Iterator end)
{
    using T = typename std::iterator_traits<Iterator>::value_type;
    return *std::min_element(begin, end);
}


template <typename Iterator>
typename std::iterator_traits<Iterator>::value_type
maximum(Iterator begin, Iterator end)
{
    using T = typename std::iterator_traits<Iterator>::value_type;
    return *std::max_element(begin, end);
}



template <typename Iterator>
typename std::iterator_traits<Iterator>::value_type
parallel_sum(Iterator begin, Iterator end)
{

    using T = typename std::iterator_traits<Iterator>::value_type;
    auto mid = begin + std::distance(begin, end) / 2;
    std::future<T> f1 = std::async(std::launch::async, adder<Iterator>, begin, mid);
    std::future<T> f2 = std::async(std::launch::async, adder<Iterator>, mid, end);
    return f1.get()+f2.get();
}


template <typename Iterator>
typename std::iterator_traits<Iterator>::value_type
minimum_value(Iterator begin, Iterator end){

    using T = typename std::iterator_traits<Iterator>::value_type;
    std::future<T> f3 = std::async(std::launch::async, minimum<Iterator>, begin, end);
    return f3.get();
}

template <typename Iterator>
typename std::iterator_traits<Iterator>::value_type
maximum_value(Iterator begin, Iterator end){

    using T = typename std::iterator_traits<Iterator>::value_type;
    std::future<T> f4 = std::async(std::launch::async, maximum<Iterator>, begin, end);
    return f4.get();
}