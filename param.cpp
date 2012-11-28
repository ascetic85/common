// file: param.cpp
// cc: g++ param.cpp -std=c++11
// link: http://cpp.ezbty.org/content/science_doc/c%E5%AF%B9%E8%B1%A1%E6%9E%84%E9%80%A0%E5%B7%A5%E5%8E%82%E7%9A%84%E5%AE%9E%E7%8E%B0

#include <iostream>
#include <vector>
#include <map>

using namespace std;

std::vector<double> v = {1,2,4.123,99,.99};
std::map<vector<string>, vector<int> > years =
{
    { {"Maurice", "Vincent", "Wilkes"}, {1913, 1945, 1951, 1967, 2000} },
    { {"Martin", "Ritchards"},  {1982, 2003, 2007} },
    { {"David", "John", "Wheeler"}, {1927, 1947, 1951, 2004} }
};

//这个实现可以适应所有情况，包括没有参数的情况
//需要注意参数的类型的声明，这里涉及参数转发(值和完全相同的类型都需要保留)，不了解的话可能无法理解；或者无法实现功能
template<typename Obj, typename... Param>
Obj* construct(Param&&... params)
{
    //调用std::forward实现参数转发
    return new Obj(std::forward<Param>(params)...);
}

class Object
{
public:
    Object(int a, int b, int c)
        :a_(a), b_(b), c_(c)
    {
        std::cout << "Object Construct" << std::endl;
    }

private:
    int a_;
    int b_;
    int c_;
};

void f(initializer_list<int> args)
{
    for (auto p=args.begin(); p!=args.end(); ++p) cout << *p << "\n";
}

#if 0
// http://stackoverflow.com/questions/1350657/variable-parameter-function-how-to-make-it-type-safe-and-more-meaningful
// wrapper to abstract away the difference between pointer types and value types.    
template< typename T > struct TCont {
  T value;
  TCont( const T& t ):value(t){}
};

template<typename T, size_t N> struct TCont< T[N] > {
  const T* value;
  TCont( const T* const t ) : value( t ) { }
};

template<typename T> struct TCont<T*> {
  const T* value;
  TCont( const T* t ): value(t){}
};


// forward definition of type argument list
template< typename aT, typename aRest >
struct TArgList ;

// this structure is the starting point 
// of the type safe variadic argument list
struct VoidArg {

  template< typename A >
  struct Append {
    typedef TArgList< A, VoidArg > result;
  };

  template< typename A >
  typename Append<A>::result append( const A& a ) const {
    Append<A>::result ret( a, *this );
    return ret;
  }

  //syntactic sugar
  template< typename A > typename Append<A>::result operator=( const A& a ) const { return append(a); }

} const arglist;


// typelist containing an argument 
// and the rest of the arguments (again a typelist)
//
template< typename aT, typename aRest >
struct TArgList {
  typedef aT T;
  typedef aRest Rest;
  typedef TArgList< aT, aRest > Self;

  TArgList( const TCont<T>& head, const Rest& rest ): head( head ), rest( rest ){}

  TCont<T> head;
  Rest rest;

  template< typename A > struct Append {
    typedef TArgList< T, typename Rest::Append<A>::result > result;
  };

  template< typename A >
  typename Append< A >::result append( const A& a ) const {
    Append< A >::result ret ( head.value, (rest.append( a ) ) );
    return ret;
  }

  template< typename A > typename Append<A>::result operator,( const A& a ) const { return append(a); }
};
#endif

int main()
{
    //调用示例
    Object* ptr=construct<Object>(0, 0, 0);

    f({3,2,3,4,3});
    if(ptr==NULL)
        return -1;
    return 0;
}