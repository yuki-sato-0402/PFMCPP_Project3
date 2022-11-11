/*
Project 3 - Part 1e / 5
Video:  Chapter 2 Part 5
User-Defined Types

Continue your work on branch Part1

Purpose: The entire purpose of this 5-part project is to get you writing C++ code that compiles and to 
reinforce the syntax habits that C++ requires.  
What you create in this project will be used as the basis of Project 5 in the course.   

************************
Part1 purpose:  Learn to write UDTs

You are going to write 10 UDTs in project3.  
Part1 will be broken up into 5 separate steps
    Part 1a: you will learn to think about an object in terms of its sub-objects.
    Part 1b: you will write 4 un-related UDTs in plain english
    Part 1c: you will write 1 UDT in plain english that will be made of 5 related sub-objects
    Part 1d: you will write plain-english UDTs for the 5 sub-objects that form the UDT defined in Part 1c
    Part 1e: you will convert those 10 plain-english UDTs into code that runs.
************************

Convert your 10 Plain-english UDTs into code.

I recommend compiling after finishing each one and making sure it compiles 
without errors or warnings before moving on to writing the next UDT. 

1) define an empty struct below your plain-english UDT. i.e.:

Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#if false //ignore these #if #endif lines. they're just here to prevent compiler errors.
struct CarWash
{

};
#endif
/*
    - Do this for all 10 UDTs

2) Below your plain-english UDT, Copy your 5 properties & 3 actions into the empty struct body.
    - comment them out.
    - Do this for all 10 UDTs
    
3) declare your member variables and member functions underneath each plain-english comment in your struct's body.
    - give the member variables relevant data types
    - Do this for all 10 UDTs
    - if your functions return something other than 'void', add a comment explaining what is being returned.  see the example code below.
 
4) make the function parameter list for those member functions use some of your User-Defined Types
    - You'll write definitions/implementations for these functions in Project3 Part2
    - you'll call each of these functions in Project3 part3
    - Do this for all 10 UDTs
 
5) make 2 of the 10 user-defined types have a nested class.  
    - this nested class also needs 5 properties and 3 actions.
    - these nested classes are not considered one of your 10 UDTs.
    - this nested class must be related to the class it is nested inside
 
6) your 10th UDT's properties should be instances of your #5-#9 UDTs.   
    - No primitives allowed!
 
7) After you finish defining each type, click the [run] button.  
    Clear up any errors or warnings as best you can. 
    if your code produces a [-Wpadded] warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

/*
 example:  

Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#include <iostream>
#include <string>

struct CarWash //                                   1) define an empty struct for each of your 10 types.       
{
    //number of vacuum cleaners                     2) copied and commented-out plain-english property
    int numVacuumCleaners = 3; //                   3) member variables with relevant data types.
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car //5)                                 Note that the nested type 'Car' is related to the 'CarWash' 
    {
        //2) member variables with relevant data types.  the names are appropriate for the U.D.T.'s purpose.
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        //3) a member function.  it has multiple arguments, some with default values.
        //the parameter names are related to the work the function will perform.
        void fillTank(float costPerGallon, double fuelAmountInGallons = 2.0, bool requiresDiesel = false);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips); //3) returns the number of miles traveled
    };

    //wash and wax car
    void washAndWaxCar(Car carA); //4) a member function whose parameter is a UDT.
    //charge customer
    float chargeCustomer(float discountPercentage); //3) returns the total amount charged.
    //detail the car interior
    void detailInterior(Car carB);
    
    //5) a member variable whose type is a UDT.
    Car carBeingServiced;  

    /*
    Pay attention to the member functions that take an instance of 'Car'
    Notice that there is a member variable of the same type.

    It makes sense to pass a Car to the function 'washAndWaxCar' because car washes service MANY cars
    However, they only service ONE car at a time.
    the carBeingServiced's value would change every time you wash and wax the car. 

    I see many students who write code emulating this format, but their usage does not make logical sense.  
    Consider the following snippet:

    struct SoccerTeam
    {
        struct Manager
        {
            ...
        };

        // train their skills
        void trainPlayerSkills(Manager managerA);
    
        Manager teamManager;
    };

    It does not make sense to pass in a new Manager whenever you are going to train your team players.
    Soccer teams have ONE manager.

    a much more relevant usage would be adding a member function that hires a new manager:

    struct SoccerTeam
    {
        struct Manager
        {
            ...
        };

        void hireNewManager(Manager newManager);
    
        Manager teamManager;
    };

    We can safely assume that the 'Manager' instance that is being passed in will be replacing the current 'teamManager' variable without looking at any other code.
    This is because the function name and function argument clearly indicate what they are/what they do.

    Your function names and parameter names should make LOGICAL SENSE.
    Readers of your code should be able to INTUITIVELY understand what your function implementations will do without actually seeing the implementations.

    Keep this in mind when you define your UDTs in this project part.
    */
};

/*
Thing 1) Recipe
5 properties:
    1)number of seasonings (int)
    2)cost of necessary foodstuffs (yen) (int)
    3)number of gas bills required (int)
    4)time it takes (minutes) (float)
    5)number of dishes (int)
3 things it can do:
    1)seasoning for food
    2)select foodstuffs
    3)heat several pans at the same time
*/

/*
Thing 2) Live Performance
5 properties:
    1)fees for performers (yen) (int)
    2)days of practice (int)
    3)facility rental fees (yen) (int)
    4)number of songs (int)
    5)number of performers(int)
3 things it can do:
    1)bring the money 
    2)do performance practice
    3)reserve a facility
 */

/*
Thing 3) storefront business
5 properties:
    1)business funds (yen) (int)
    2)store area (㎡)　(float)
    3)number of employees (int)
    4)number of computers (int)
    5)number of business cards (int)
3 things it can do:
    1)produce products
    2)pay rent
    3)hire an employee
 */

/*
Thing 4) Camera
5 properties:
    1)f-value (float)
    2)number of pixels (int)
    3)iso sensitivity (int)
    4)shutter speed (second) (float)
    5)zoom magnification (float)
3 things it can do:
    1)capture the light
    2)resolve image
    3)brighten the image
 */
    
/*
Thing 5)Wheel
5 properties:
    1)diameter (float)
    2)umber of bolt holes (int)
    3)rim width (float)
    4)flange shape (char)
    5)pitch circle diameter (float)
3 things it can do:
    1)support the body
    2)transmits engine power to tires and road surface
    3)allows brake heat to escape
*/

/*
Thing 6)Engine
5 properties:
    1)nunber of cylinder (int)
    2)horsepower (ps) (int)
    3)engine displacement (cc)　(int)
    4)maximum torque (Nm) (int)
    5)turbo (bool)
3 things it can do:
    1)generate motive power
    2)generate heat
    3)pushing the piston down
 */

/*
Thing 7)Transmission
5 properties:
    1)AT (bool)
    2)number of gears(int)
    3)driven type (std::string)
    4)number of clutch plates (int)
    5)frequency of maintenance (days) (int)
3 things it can do:
    1)create driving force
    2)increase acceleration
    3)increase fuel efficiency
 */

/*
Thing 8)Body 
5 properties:
    1)type of body shape (std::string)
    2)over-all length (m) (float)
    3)over-all height (m) (float)
    4)capacity (int)
    5)weight (kg) (float)
3 things it can do:
    1)carry luggage
    2)covering the engine
    3)protects people from impact
 */

/*
Thing 9)Gasoline
5 properties:
    1)type (std::string)
    2)fuel consumption (km/L) (float)
    3)capacity (liter)　(float)
    4)boiling point (degree) (int)
    5)price per liter (yen) (int)
3 things it can do:
    1)fruel your car
    2)inhale into the cylinder
    3)burn
 */

/*
Thing 10)Car 
5 properties:
    1)wheel (diameter) (float)
    2)engine (horsepower) (int)
    3)transmission (number of gears) (int)
    4)body (vehicle weight) (float)
    5)gasoline (type) (std::string)
3 things it can do:
    1)putting people 
    2)turn the car around
    3)change the speed
 */
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    std::cout << "good to go!" << std::endl;
}
