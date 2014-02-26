// sicp.1.1.6 Conditional Expressions and Predicates

#include <iostream>
#include <functional>

#include <boost/phoenix.hpp>


template <typename V>
void print( V v )
{
  using std::cout;
  using std::endl;
  cout << v << endl;
}

int main()
{
  using boost::phoenix::arg_names::arg1;
  using boost::phoenix::arg_names::arg2;
  
  //---------------------------------------

  // (cond (<p1> <e1>)
  //       (<p2> <e2>)
  //       (<pn> <en>))

  // (define (abs x)
  //   (cond ((> x 0) x)
  //         ((= x 0) 0)
  //         ((< x 0) (- x))))
  
  auto undefined = arg1;
  auto abs = 
        if_else(arg1 > 0  , arg1,
        if_else(arg1 == 0 , 0,
        if_else(arg1 < 0  , -arg1,
        undefined)));
  
  // ---------------------------------------

  // (cond (<p1> <e1>)
  //       (<p2> <e2>)
  //       (else <e>))

  // define (abs x)
  //    (cond ((< x 0) (- x))
  //           (else x)))

  auto abs2 = 
        if_else(arg1 < 0  , -arg1,
                arg1);
   
  // ---------------------------------------

  // (if <predicate> <consequent> <alternative>)
  
  // (define (abs x)
  //     (if (< x 0)
  //         (- x)
  //          x
  auto abs3 = 
        if_else(arg1 < 0 ,
                -arg1,
                arg1);
                
  print (abs(-544));
  print (abs2(-54));
  print (abs2(-5));

}
