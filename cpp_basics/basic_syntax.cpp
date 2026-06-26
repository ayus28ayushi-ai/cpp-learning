#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include<cstdlib>
 

namespace first{
    int x=1;
}

namespace second{
    int x=2;
}

typedef std::vector<std::pair<std::string, int>> pairlist_t;   // underscore t is a naming convention for type
using type = std::vector<std::pair<std::string, int>>;

int main(){
    //----------------BASIC  ------------------------
    std::cout << "I like coffee!" << std::endl;  //one way to go to next line
    std::cout << "I like coffee!" << '\n';  // significantly faster 

    /*Using \n (Buffered): You finish writing a letter, drop it in your outgoing mailbox,
                           and start writing the next one. When the mail carrier comes by later,
                           they take all your letters at once. This is highly efficient.

    Using std::endl (Flushing): You finish writing a single sentence, put it in an envelope, 
                                run all the way down to the post office to mail it, walk back home,
                                 write the next sentence, and run back to the post office again.*/
    std::cout << "I like reading novels:)" <<std::endl;


    //-----------------------DATA TYPES AND VARIABLES----------------------
    int integer=1;
    double y=1.2;
    char letter = 'A';
    bool isTrue = false;

    std::string name = "Ayu\nAyushi\n";   //initialising string

    std::cout << "Hello " << name;

    //---------------------const keyword -----------------------------------
    //if you add 'const while initialising the variable, its unmodifiable then
    const double pi =  3.14;
    int rad = 2;
    std::cout << "Circumference: " << 2*pi*rad;
   

    //------------------------namespace---------------------------
     int x=0;

     std::cout << "\nprinting using namespace: first:" <<  x;
     std::cout << "\nprinting using namespace: first:" << first::x;
     std::cout << "\nprinting using namespace: first:" << second::x;

     //--------------------------typedef and using----------------------------
      
     std::vector<std::pair<std::string, int >> somename;
     pairlist_t pairlist;  // from this keyword we created a alias for existing data type
     type somegivenname; // 'using' is a modern alternative for typedef and it works better with templates

     //-----------------------------TYPE CONVERSION----------------------------
     //implicit = automatic
     int lives = 3;
    double bonus = 0.5;

    // 'lives' is implicitly converted to a double (3.0) before addition
    double total = lives + bonus; // 3.0 + 0.5 = 3.5

    std::cout << total; // Prints 3.5

    char ch = 100;
    std::cout <<'\n' << ch;  //implicit

    //explicit = precede value with new data type (int)
    std::cout << "\nExplicit example: " << (char)100 << '\n';

    //----------------------------USER INPUT---------------------------------------------
    std::string nickname;
    std::cout<<"Whats your name?: ";   // << insertion operator
    std::cin >> nickname;              // >> extraction operator
    std::cout << nickname;  

    std::string fullname;
    std::cout << "\nEnter your full name: ";
    // 💡 ADD std::ws HERE to clear the leftover '\n' from the buffer
    std::getline(std::cin >> std::ws, fullname);    //since we used cin earlier, we have newline in the buffer   
    std::cout << "\nHello: " << fullname << '\n';
    
    //----------------------------SOME MATH FUNCTIONS----------------------------------------
    double a = 3.24;
    double b = 647.73;

    //max and min
    int z;
    z = std::max(a,b);
    z = std::min(a,b);

    //add "#include <cmath>" for the following 
   int val;
   //val = pow(2,3);
   //val = sqrt(9);
   //val = abs(-302);
   //val = round(a);
   //val = ceil(a);
   //val = floor(a);

    //----------------------------------if statements---------------------------
    //SAME AS C lang

    //----------------------------------switch and while---------------------------
    //SAME AS C lang

    //----------------------------------ternary operator---------------------------
    //SAME AS C lang

    
    //----------------------------------SOME STRING METHODS----------------------------------
    
    std::string temp;
    std::cout << "\nEnter some string: ";
    std::cin >> temp;
    
    temp.length();    //returns the number of characters
    temp.empty();     //returns boolean value
    temp.clear();     //you clear the string
    temp.append("something to append");
    temp.at(2);
    temp.insert(1, "@");
    temp.find(' ');    //return the index
    temp.erase(0, 3);  //it erases 3 characters starting from index 0

    //C++'s standard output stream (std::cout) forces boolean values into integers during printing
    //use std::boolalpha stream manipulator to force it to print bool values 
    std::cout << std::boolalpha <<temp.empty() << '\n';


    //--------------------------------------random number generation---------------------------------------
    //pseudo-random

    //seed the random number generator with the current time
    srand(time(NULL));  // this time gives random number till the number of sec that have passed since, jan 1970
    int rannum = (rand() % 6)+1;  //numbers between 1-6
    std::cout << '\n' << rannum;
    


    //---------------------------------------USER GENERATED FUNCTION-------------------------------------------
    //same as C lang



    //---------------------------------------ARRAYS ----------------------------------------------------------
    //STATIC ALLOCATION
    // * memory allocated at the compile time
    // * allocation in stack memory

    //No. of SUBARRAYS = n*(n+1)/2
    int marks[5];
    //finding size of array
    std::cout << sizeof(marks)/sizeof(int);  //prints 5

    //std::min(value1, value2);   //ternary operator-based function.
    //std::swap(value1,value2);   

    //---------------------------------------VECTORS(STL container)---------------------------------------------------------
    //DYNAMIC ALLOCATION
    // *memory allocated at the run time, thats why we can resize
    // * allocated in the heap memory

    //#include <vector>
    std::vector<int> vec; //empty rn, if we try to print vec[0] we will get a segmentation fault
    std::vector<int> vec1 = {1,2,3};
    std::vector<int> vec2(3, 0);  //3 is the size of the vector, 0 is the value at each index
    
    //for each loop
    //iterator is the  value in vector not the index
    std::vector<char> char_vec = {'a', 'b', 'c'};

    for (char i : char_vec){
        std::cout << i <<"\n";
    }

    //vector functions
    //1. .size()
    //2. .push_back()   element pushed at the end
    //3. .pop_back()    element popped from the end
    //4. .front()       gives the front value
    //5. .back()       gives the last value
    //6. .at(index)    gives value at the index
    //7. .capacity()   gives the vector's capacity
    //8. .begin()      gives pointer-like object pointing to the first element
    //9. .end()        gives pointer-like object pointing to the last element

    /*When you try to push and vector reaches its capacity:
       1. Allocate: It requests a new, larger memory block (typically double the current size).
       2. Move: It copies/moves all existing elements into the new block.
       3. Insert: It adds your new element into the new, larger array.
       4. Delete: It frees the old memory to prevent leaks.
    */

    //when we pass them in a function, the container is "PASS BY VALUE".
    // use vector<int>& nums while passing the parameter in the function for "PASS BY REFERENCE"

    
    return 0;

}    