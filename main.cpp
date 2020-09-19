/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert all of the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.
 
 2) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */


#include <iostream>
#include <string>
struct T
{
    T(int v, const char* var) :  //1
            value(v),//2
            name(var)//3
    {}
    
    int value;
    std::string name;
    
};

struct A                                //4
{
    T* compare(T& a, T& b) //5
    {
        
            if( a.value < b.value ) return &a;
            if( a.value > b.value ) return &b;
    
        return nullptr;
    }
};

struct U
{
    float varU1 { 7.1f }, varU2 { 0.2f };
    float function(float& updatedVal)      //12
    {
        std::cout << "U's varU1 value: " << this->varU1 << std::endl;
        this->varU1 = updatedVal;
        std::cout << "U's varU1 updated value: " << this->varU1 << std::endl;
        while( std::abs(this->varU2 - this->varU1) > 0.001f )
        {
            /*
             write something that makes the distance between that->varU2 and that->VarU1 get smaller
             */
            this->varU2 += 0.01f;
        }
        std::cout << "U's varU2 updated value: " << this->varU2 << std::endl;
        return this->varU2 * this->varU1;

    }
};

struct B
{
    static float function(U& that, float& updatedVal )        //10
    {

        std::cout << "U's varU1 value: " << that.varU1 << std::endl;
        that.varU1 = updatedVal;
        std::cout << "U's varU1 updated value: " << that.varU1 << std::endl;
        
        while( std::abs(that.varU2 - that.varU1) > 0.001f )
        {
            /*
             write something that makes the distance between that->varU2 and that->VarU1 get smaller
             */
            that.varU2 += 0.01f;
        }
        std::cout << "U's varU2 updated value: " << that.varU2 << std::endl;
        return that.varU2 * that.varU1;

    }
};
        
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already:
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    T n1(8 , "stringN1" );                                             //6
    T n2(4 , "stringN2");                                             //6
    
    A f;                                            //7
    auto* smaller = f.compare(n1 ,n2 );                              //8
        
    if (smaller != nullptr)
    {
        std::cout << "the smaller one is << " << smaller->name << std::endl; //9
    }
    else
    {
        std::cout << "the values of " << n1.name << " and " << n2.name << " are equal!" << std::endl;
    }
    
    U n3;
    float updatedValue = 5.f;
    std::cout << "[static func] n3's multiplied values: " << B::function( n3, updatedValue ) << std::endl;                  //11
    
    U n4;
   std::cout << "[member func] n4's multiplied values: " << n4.function( updatedValue ) << std::endl;
}

        
        
        
        
        
        
        
