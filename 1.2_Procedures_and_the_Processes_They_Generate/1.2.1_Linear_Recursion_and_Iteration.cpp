//sicp.1.2.1 Linear Recursion and Iteration

#include <iostream>                        // cout, endl, <<

//(define (factorial_r n)
//  (if (= n 1)
//       1
//      (* n (factorial_r (- n 1)))))
template < typename N >
N factorial_r(N n) 
{
    return (n == N(1)) ?
            N(1):
            n * factorial_r (n-1);
}

// (define (fact-iter product counter max-count)
//    (if (> counter max-count)
//         product
//        (fact-iter (* counter product)
//                   (+ counter 1)
//                   max-count)))
template < typename N >
N fact_iter(N product, N counter, N max_count)
{
    return  counter > max_count ?
            product :
            fact_iter (counter * product,
                       counter + 1,
                       max_count);
}


// (define (factorial n)
//    (fact-iter 1 1 n))
template < typename N >
N factorial(N n)
{
    return fact_iter (1, 1, n);
}

int main ()
{
    auto print = [](auto v) {  std::cout << v << std::endl; };
    
    print (factorial_r (6));
    print (factorial   (6));
}