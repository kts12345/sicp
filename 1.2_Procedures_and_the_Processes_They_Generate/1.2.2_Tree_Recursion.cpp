//sicp.1.2.2 Tree Recursion

#include <iostream>   // cout, endl, <<

/* ----------------------------------------
(define (fib n)
    (cond ((= n 0) 0)
          ((= n 1) 1)
          (else (+ (fib (- n 1))
                   (fib (- n 2))))))
*/

template < typename N >
N fib(N n) 
{
    return  n == N(0) ? N(0) :
            n == N(1) ? 1 :
                        fib(n-1) + fib(n-2);
}

/* ----------------------------------------
(define (fib n)
    (fib-iter 1 0 n))

(define (fib-iter a b count)
    (if (= count 0)
        b
        (fib-iter (+ a b) a (- count 1))))
*/
template < typename T >
T fib_iter (T a, T b, T count)
{
    if (count == T(0)) return b;
    return fib_iter(a+b, a, count-1);
}
auto fib2 = [](auto n) { return fib_iter<decltype(n)>(1,0,n);};

/* ----------------------------------------
(define (count-change amount)
        (cc amount 5))
*/
template < typename T > T cc (T amount, T kinds_of_coins); // forward-declare
template < typename T >
T count_change  (T amount)
{ 
    return cc(amount, 5); 
};

/* ----------------------------------------
(define (cc amount kinds-of-coins)
        (cond ((= amount 0) 1)
              ((or (< amount 0) (= kinds-of-coins 0)) 0)
              (else (+ (cc amount
                           (- kinds-of-coins 1))
                       (cc (- amount
                              (first-denomination kinds-of-coins))
                           kinds-of-coins)))))
*/
template < typename T >T first_denomination (T kinds_of_coins);  // forward-declare
template < typename T >
T cc (T amount, T kinds_of_coins)
{
    return
     (amount == 0) ? T(1) :
     (amount < 0 || kinds_of_coins == 0) ? T(0) :
     cc(amount, kinds_of_coins - 1) + 
     cc(amount - first_denomination(kinds_of_coins), kinds_of_coins);
};

/* ----------------------------------------
(define (first-denomination kinds-of-coins)
    (cond ((= kinds-of-coins 1) 1)
          ((= kinds-of-coins 2) 5)
          ((= kinds-of-coins 3) 10)
          ((= kinds-of-coins 4) 25)
          ((= kinds-of-coins 5) 50)))
*/
template < typename T >
T first_denomination (T kinds_of_coins)
{
    return
        kinds_of_coins == 1 ? T(1) :
        kinds_of_coins == 2 ? T(5) :
        kinds_of_coins == 3 ? T(10) :
        kinds_of_coins == 4 ? T(25) :
        kinds_of_coins == 5 ? T(50) :
        T(-1);        
};


int main ()
{
    auto print = [](auto v) {  std::cout << v << std::endl; };
    
    print (fib(5));
    print (fib2(5));
    
    print (count_change(100));
}
/*===================================
 * output
 *-----------------------------------
 5
 5
 7750
*/