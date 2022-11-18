 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 0) delete all of the plain english pseudo-code you added in Part1.
   don't forget to remove the blank lines left behind after you remove your comments
   - you should be left with only your UDTs.
*/
// example:
// if you had something like this at the end of Part1e:
/*
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
namespace Part1eVersion 
{
struct CarWash        
{
    //number of vacuum cleaners                     
    int numVacuumCleaners = 3; 
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(float costPerGallon, double fuelAmountInGallons = 2.0, bool requiresDiesel = false);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar( Car car ); 
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}

//this is what I want to see after the code is cleaned up: 
namespace Part2Version
{
struct CarWash        
{
    int numVacuumCleaners = 3; 
    int numEcoFriendlyCleaningSupplies = 20;     
    float waterUsedPerWeek = 200.f;            
    float profitPerWeek = 495.95f;               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    void washAndWaxCar( Car car ); 
    float chargeCustomer(float discountPercentage);
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}
  /*
    The above snippet is just an example showing you how to clean up your code.  
    Do not put your cleaned up code into a namespace like I have done here.

 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */





 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
    If you have 'unused parameter' warnings, you aren't using one of your function parameters in your implementation.
    Solution: use the parameter in your implementation.

    If you have 'shadows a field of <classname>' warnings, a local variable in the function has the same name as a class member.  
    This local variable could also be a function parameter with the same name as the class member.
    Solution: change the local variable's name so it is different from the class member variable's name.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */


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

struct Recipe
{
    //number of seasonings (int)
    int numberOfSeasonings = 4;
    //cost of necessary foodstuffs (yen) (int)
    int costOfNecessaryFoodstuff = 3000;
    //number of gas bills required (int)
    int numberOfGasBillsRequired = 2;
    //time it takes (minutes) (float)
    float timeItTakes = 45.5f;
    //number of dishes (int)
    int numberOfDishes = 8;

    struct RecipeWebsite 
    {
        //numberOfPage (int)
        int numberOfPage = 4;
        //video time (minutes) (int)
        int videoTime = 7;
        //number of characters 
        int numberOfCharacters = 2000;
        //nutrition facts label (bool)
        bool nutritionFactsLabel = false;
        //the mame of website
        std::string theNameOfWebsite = "CookMaster";

        void displaySeasonings(int numberOfSeasonings, std::string nameOfSeasonings);
        void displayQuantitiesInLineWithTheNumberOfPeople(int numberOfPeople);
        void dideoSpeaksHowToMakeIt();
    };
    
    //seasoning for food 
    void seasoningForFood();
    //select foodstuffs
    void selectfoodstuffs(RecipeWebsite omelet);
    //heat several pans at the same time
    bool heatSeveralPansAtTheSameTime(int gasBills, RecipeWebsite steak); //returns true if it is more than 2

};



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

struct LivePerformance
{
    //fees for performers (yen) (int)
    int feesForPerformers = 20000;
    //days of practice (int)
    int daysOfPractice = 10;
    //facility rental fees (yen) (int) 
    int facilityRentalFees = 40000;
    //number of songs (int)
    int numberOfSongs = 5;
    //number of performers(int)
    int numberOfPerformers = 5;
    
    //bring the money 
    int bringTheMoney(int guarantee, int rentalFees, int otherExpenses); //returns the total cost
    //do performance practice
    void doPerformancePractice();
    //reserve a facility
    int reserveAFacility(char room, int rentalPeriod); //return the rental information details
};

/*
Thing 3) storefront business
5 properties:
    1)business funds (yen) (int)
    2)store area (㎡)　(float)
    3)number of items (int)
    4)number of cash registers (int)
    5)security equipment (bool)
3 things it can do:
    1)produce products
    2)pay rent
    3)hire an employee
 */

struct StorefrontBusiness
{
    //business funds (yen) (int)
    int businessFunds = 500000;
    //store area (㎡)　(float)
    int storeArea = 1000;
    //number of items (int)
    int numberOfItems = 300;
    //number of cash registers (int)
    int numberOfCashRegisters = 5;
    //security equipment (bool) 
    bool securityEquipment = true;

    struct Apparel
    {
        //required skills (std::string)
        std::string requiredSkills = "customer_service";
        //promotion method (std::string)
        std::string promotionMethod = "internet";
        //branf name (std:string)
        std::string brandName = "Tokyo_Blue";
        //distance from station (minutes) (int)
        int distanceFromStation = 8;
        //necessity of qualification (bool)
        bool necessityOfQualification = false;
    
        //provide products 
        void provideProducts(std::string kindOfProducts = "cloth");
        //provide services
        void provideServices(std::string kindOfServices = "tryingOn");
        //Hold an open sale
        int holdAnOpenSale(int itemNumber); //return the reduced price
    };
    
    //produce products
    void produceProducts();
    //pay rent
    int payRent(float distanceFromStation); //return the rental fee
    //hire an employee
    int hireAnEmployee(int storeArea); //return the number of employees
};

/*
Thing 4) Camera
5 properties:
    1)range of f-value (float)
    2)maximum number of pixels (int)
    3)range of iso sensitivity (int)
    4)range shutter speed (second) (float)
    5)maximum zoom magnification (float)
3 things it can do:
    1)capture the light
    2)resolve image
    3)brighten the image
 */

struct Camera
{
    //range of f-value (float)
    float rangeOfFvalue = 25.0f;
    //maximum number of pixels (int)
    int maximumNumberOfPixels = 24; //(million)
    //range of iso sensitivity (int)
    int rangeOfIsoSensitivity = 12800;
    //range shutter speed (second) (float)
    float rangeShutterSpeed = 8.000f;
    //maximum zoom magnification (float)
    float maximumZoomMagnification = 6.0f;
    
    //capture the light
    void captureTheLight(float fValue, int isoSensitivity, float shutterSpeed);
    //resolve image
    void resolveImage(int pixels);
    //brighten the image
    void brightenTheImage(int isoSensitivity);
};

/*
Thing 5)Wheel
5 properties:
    1)diameter (inch) (float)
    2)number of bolt holes (int)
    3)rim width (inch) (float)
    4)flange shape (char)
    5)pitch circle diameter (mm) (float)
3 things it can do:
    1)support the body
    2)transmits engine power to tires and road surface
    3)allows brake heat to escape
*/

struct Wheel
{
    //diameter (inch) (float)
    float diameter = 20.0f;
    //number of bolt holes (int) 
    int umberOfBoltHoles = 5;
    //rim width (inch) (float)
    float rimWidth = 7.5f;
    //flange shape (char) 
    char flangeShape = 'j';
    //pitch circle diameter (mm) (float)
    float pitchCircleDiameter = 114.3f;
    
    //support the body
    void supportTheBody(float weightCapacity);
    //transmits engine power to tires and road surface
    void transmitsEnginePowerToTiresAndRoadSurface();
    //allows brake heat to escape
    void allowsBrakeHeatToEscape();
};

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
struct Engine
{ 
    //nunber of cylinder (int)
    int nunberOfCylinder = 8;
    //horsepower (ps) (int)
    int horsepower = 250;
    //engine displacement (cc)　(int)
    int engineDisplacement = 2000;
    //maximum torque (Nm) (int)
    int maximumTorque = 200;
    //turbo (bool)
    bool turbo = false;
    
    //generate motive power
    float generateMotivePower(int power, float weight); //return the weight-to-power ratio
    //generate heat
    void generateHeat();
    //pushing the piston down
    void pushingThePistonDown(int cylinderVolume);
};

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

struct Transmission
{
    //AT (bool) 
    bool AT = true;
    //number of gears(int)
    int numberOfGears = 7;
    //driven type (std::string) 
    std::string drivenType = "AWD";
    //number of clutch plates (int)
    int numberOfClutchPlates = 1;
    //frequency of maintenance (days) (int)
    int frequencyOfMaintenance = 180;
    
    //create driving force
    void createDrivingForce();
    //increase acceleration
    void increaseAcceleration(float zero_100kmh);
    //increase fuel efficiency
    bool increaseFuelEfficiency(bool MT); //returns false if the AT is true
};

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

struct Body
{
    //type of body shape (std::string)
    std::string typeOfBodyShape = "SUV";
    //over-all length (m) (float)
    float overAllLength = 4825.0f;
    //over-all height (m) (float)
    float overAllHeight = 1885.0f;
    //capacity (int)
    int capacity = 7;
    //weight (kg) (float)
    float weight = 2050;
    
    //carry luggage
    void carryLuggage(int maximumCarryingCapacity);
    //covering the engine
    void coveringTheEngine();
    //protects people from impact
    float protectsPeopleFromImpact(bool airbag, int speed); //return probability of protecting people
};

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

struct Gasoline
{
    //type (std::string)
    std::string type = "regular";
    //fuel consumption (km/L) (float) 
    float fuelConsumption = 10.5f;
    //capacity (liter)　(float)
    float capacity = 93.0f;
    //boiling point (degree) (int)
    int boilingPoint = 40.0f;
    //price per liter (yen) (int)
    int pricePerLiter = 160;

    //fuel your car 
    int fuelYourCar(float fuelEfficient, float capascityOfGasoline); //mileage
    //inhale into the cylinder 
    void inhaleIntoTheCylinder(float cpacityOfInjector);
    //burn
    void burn();
};

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

struct Car
{
    //wheel (diameter) (float)
    Wheel bridgestone_model1;
    //engine (horsepower) (int)
    Engine toyota_model1;
    //transmission (number of gears) (int)
    Transmission aisin_aw_model1;
    //body (vehicle weight) (float)
    Body nissan_model1;
    //gasoline (type) (std::string)
    Gasoline mobil1_model1;
    
    //putting people 
    void puttingPeople(bool childSeat);   
    //turn the car around
    void turnTheCarAround(float minimumTurningRadius);
    //change the speed
    void changeTheSpeed(float acceleration, float topspeed);
};




//
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
