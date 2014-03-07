//  sicp.exercise.1.12
/* -------------------------------------------------------
 * Problem
  The following pattern of numbers is called Pascal's triangle. 
          1
         1 1
        1 2 1
       1 3 3 1
      1 4 6 4 1
     1...   ...1
  The numbers at the edge of the triangle are all 1, and each number inside the triangle is the sum of the
  two numbers above it. Write a procedure that computes elements of Pascal's triangle by means of a
  recursive process.
*/

#include <iostream>    // cout, endl, <<
#include <string>

/*------------------------------------------------------------
(define (pascal n m)
   (cond ((= n m) 1)
         ((= 1 m) 1)
         (else (+ (pascal (- n 1) (- m 1)) 
                  (pascal (- n 1) m))))) 
*/
template < typename N >
N pascal (N n, N m)
{
    return n == m ? 1 :
           1 == m ? 1 :
           pascal(n-1, m-1) + pascal(n-1, m);
}

 /*
(define (pascal-row n)
     (pascal-row-iter n 1 ""))
  
(define (pascal-row-iter n m row)
    (define new-row (string-append row " " (number->string (pascal n m))))
    (cond ((> n m) (pascal-row-iter n (+ m 1) new-row))
          (else new-row)))
*/
template < typename N >
std::string pascal_row_iter (N n, N m, std::string row)
{
    auto const new_row = row + " " + std::to_string(pascal(n,m));
    return n > m ? pascal_row_iter(n, m+1, new_row) :
                   new_row;
} 
template < typename N >
auto pascal_row (N n) { return pascal_row_iter(n, 1, ""); };
// ------------------------------------------------------
// test
int main()
{
  auto print = [](auto v) {  std::cout << v << std::endl; };

  print (pascal_row(1)); // (pascal-row 1)
  print (pascal_row(2)); // (pascal-row 2)
  print (pascal_row(3)); // (pascal-row 3)
  print (pascal_row(4)); // (pascal-row 4)
  print (pascal_row(5)); // (pascal-row 5) 
  
}

/*
 ========================================================
  * Output
 --------------------------------------------------------
 1
 1 1
 1 2 1
 1 3 3 1
 1 4 6 4 1

 */
