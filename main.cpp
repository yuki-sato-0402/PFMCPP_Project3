/*
 Project 3 - Part 3 / 5
 video: Chapter 2 - Part 8
 Constructors tasks

 Create a branch named Part3

 On this new branch:

 0) if you opted to not fill in any of your member functions in part2, 
    fill in ALL of your member functions
    
 1) Add a constructor for each User-Defined-Type.
    The constructor should be the first declaration in your UDT, before all member variables and member functions.
    add a std::cout message in the constructor that prints out the name of the class being constructed.  
    When you run your code, you'll see the order that your objects are created in the program output. 
 
 2) For each User-Defined-Type:
        amend some of the member functions to print out something interesting via std::cout
 
 3) Instantiate 1 or 2 instances of EACH of your user-defined types in the main() function.  
    You should have at least 12 different variables declared in main(), because you have written 12 different types (including the nested types)

 4) For each instantiated UDT: 
        call each of that instance's member functions.
        You're doing this to show that your code doesn't produce warnings when you call the functions that take arguments.
 
 5) add some std::cout statements in main() that print out your UDT's member variable values or values returned from your UDT member functions (if they return values)
 
 After you finish defining each type/function:
 click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 
 example:
 */

#include <iostream>
namespace Example 
{
struct UDT  // my user defined type named 'UDT'
{
    int thing = 0; //a member variable
    UDT();              //1) the constructor
    void printThing();  //the member function
};

//the function definitions are outside of the class
UDT::UDT()
{
    std::cout << "UDT being constructed!" << std::endl; //1) 
}

void UDT::printThing()
{
    std::cout << "UDT::printThing() " << thing << std::endl;  //2) printing out something interesting
}

int main()
{
    UDT foo;              //3) instantiating a UDT named 'foo' in main()
    foo.printThing();     //4) calling a member function of the UDT instance.
    
    //5) a std::cout statement accessing foo's member variable.
    //It also demonstrates a 'ternary expression', which is syntactic shorthand for an 'if/else' expression
    std::cout << "Is foo's member var 'thing' equal to 0? " << (foo.thing == 0 ? "Yes" : "No") << "\n";
    
    return 0;
}
} //end namespace Example

//insert Example::main() into main() of user's repo.




struct Recipe
{
    int amountOfSeasoning = 4;
    int costOfNecessaryFoodstuff = 3000;
    int numberOfGasBillsRequired = 2;
    float timeItTakes = 45.5f;
    int numberOfDishes = 8;

    struct RecipeWebsite 
    {    
        int numberOfPage = 4;
        int videoTime = 7;
        int numberOfCharacters = 2000;
        bool nutritionFactsLabel = false;
        std::string theNameOfWebsite = "CookMaster";

        void displaySeasonings(int seasoning, std::string nameOfSeasonings);
        int displayQuantitiesInLineWithTheNumberOfPeople(int seasoning, int numberOfPeople);
        void videoSpeaksHowToMakeIt();
    };
    void seasoningForFood();
    void selectfoodstuffs();
    bool heatSeveralPansAtTheSameTime(int gasBills); 
};

void Recipe::RecipeWebsite::displaySeasonings(int seasoning, std::string nameOfSeasonings)
{
    std::string str = nameOfSeasonings;
    std::cout << seasoning << " " << str << " " "is required." << std::endl;
}

int Recipe::RecipeWebsite::displayQuantitiesInLineWithTheNumberOfPeople(int seasoning, int numberOfPeople)
{
    int num = numberOfPeople;
    return seasoning * num;
}

void Recipe::RecipeWebsite::videoSpeaksHowToMakeIt()
{
}

void Recipe::seasoningForFood()
{
}

void Recipe::selectfoodstuffs()
{
}

bool Recipe::heatSeveralPansAtTheSameTime(int gasBills) 
{
    if(gasBills >= 2)
    {
        return true;
    }
    
    return false;
}


struct LivePerformance
{
    int feesForPerformers = 20000;
    int daysOfPractice = 10;
    int facilityRentalFees = 40000;
    int numberOfSongs = 5;
    int numberOfPerformers = 5;
    
    int bringTheMoney(int guarantee, int rentalFees, int otherExpenses); 
    void doPerformancePractice();
    int reserveAFacility(char room, int rentalPeriod, int rentalFees); 
};

int LivePerformance::bringTheMoney(int guarantee, int rentalFees, int otherExpenses)
{
    return guarantee + rentalFees + otherExpenses;
}

void LivePerformance::doPerformancePractice()
{  
}

 int LivePerformance::reserveAFacility(char room, int rentalPeriod, int rentalFees)
{ 
    if(room == 'a' || room == 'b' || room == 'c')
    {
        rentalFees = 40000;
    }
    else
    {
        rentalFees = 20000;
    }

    return rentalFees * rentalPeriod;
}

struct StorefrontBusiness
{
    int businessFunds = 500000;
    int storeArea = 1000;
    int numberOfItems = 300;
    int numberOfCashRegisters = 5;
    bool securityEquipment = true;

    struct Company
    {
        std::string requiredSkills = "customer_service";
        std::string promotionMethod = "internet";
        std::string brandName = "Tokyo_Blue";
        int distanceFromStation = 8;
        bool necessityOfQualification = false;
    
        void provideProducts(std::string kindOfProducts = "cloth");
        void provideServices(std::string kindOfServices = "tryingOn");
        double holdAnOpenSale(int itemNumber, double price); 
    };
    
    void produceProducts();
    double payRent(double distanceFromStation);
    double hireAnEmployee(int area, double ans); 
};

void StorefrontBusiness::Company::provideProducts(std::string kindOfProducts)
{
    std::string str = kindOfProducts;
    std::cout << " " << str << "We sell" " " << std::endl;
}

void StorefrontBusiness::Company::provideServices(std::string kindOfServices)
{
    std::string str = kindOfServices;
    std::cout << " " << str << "Free Service :" " " << std::endl;
}

double StorefrontBusiness::Company::holdAnOpenSale(int itemNumber, double price)
{
    if(itemNumber >= 0 && itemNumber < 1000)
    {
        return price * 0.75;
    }  
    
    return price * 0.9;
}

void StorefrontBusiness::produceProducts()
{
}

double StorefrontBusiness::payRent(double distanceFromStation)
{
    return distanceFromStation * 1.5;
}


double StorefrontBusiness::hireAnEmployee(int area, double ans)
{
    ans = round(area / 25);
    return ans;
}


struct Camera
{
    float rangeOfFvalue = 25.0f;
    int maximumNumberOfPixels = 24; 
    int rangeOfIsoSensitivity = 12800;
    float rangeShutterSpeed = 8.000f;
    float maximumZoomMagnification = 6.0f;
    
    void captureTheLight(double fValue, int isoSensitivity, double shutterSpeed);
    void resolveImage(int pixels);
    void brightenTheImage(int isoSensitivity, int num);
};

void Camera::captureTheLight(double fValue, int isoSensitivity, double shutterSpeed)
{
    if(fValue >= 5.6 || isoSensitivity >= 800 || shutterSpeed >= 0.02)
    {
        std::cout << "bright" << std::endl;
    }
    else 
    {
        std::cout << "dark" << std::endl;
    }
}

void Camera::resolveImage(int pixels)
{
    if(pixels >= 20000000)
    {
        std::cout << "High_Resolution" << std::endl;
    }        
}

void Camera::brightenTheImage(int isoSensitivity,int num)
{
    num = isoSensitivity;
    std::cout << " " << num << "isoSensitivity :" " " << std::endl;
}

struct Wheel
{
    float diameter = 20.0f;
    int umberOfBoltHoles = 5;
    float rimWidth = 7.5f;
    char flangeShape = 'j';
    float pitchCircleDiameter = 114.3f;
    
    void supportTheBody(float weightCapacity);
    void transmitsEnginePowerToTiresAndRoadSurface();
    void allowsBrakeHeatToEscape();
};

void Wheel::supportTheBody(float weightCapacity)
{
    if(weightCapacity >= 2000)
    {
        std::cout << "classB" << std::endl;
    }
    else
    {
        std::cout << "classA" << std::endl;
    }
}

void Wheel::transmitsEnginePowerToTiresAndRoadSurface()
{
}

void Wheel::allowsBrakeHeatToEscape()
{
}

struct Engine
{ 
    int nunberOfCylinder = 8;
    int horsepower = 250;
    int engineDisplacement = 2000;
    int maximumTorque = 200;
    bool turbo = false;
    
    double generateMotivePower(int power, double weight, double ans); 
    void generateHeat();
    void pushingThePistonDown(int cylinderVolume);
};

double Engine::generateMotivePower(int power, double weight, double ans)
{
    ans = round(weight / power);
    return ans;
}

void Engine::generateHeat()
{
}

void Engine::pushingThePistonDown(int cylinderVolume)
{    
    if(cylinderVolume >= 2000)
    {
        std::cout << "Nomal_Car" << std::endl;
    }
    else if(cylinderVolume >= 660)
    {
        std::cout << "Small_Car" << std::endl;
    }
    else
    {
        std::cout << "Light_Car" << std::endl;
    }
}


struct Transmission
{
    bool AT = true;
    int numberOfGears = 7;
    std::string drivenType = "AWD";
    int numberOfClutchPlates = 1;
    int frequencyOfMaintenance = 180;
    
    void createDrivingForce();
    void increaseAcceleration(float zero_100kmh);
    void increaseFuelEfficiency(bool MT); 
};

void Transmission::createDrivingForce()
{
}

void Transmission::increaseAcceleration(float zero_100kmh)
{
    if(zero_100kmh <= 5.0f)
    {
        std::cout << "fast" << std::endl;
    }
    else
    {
        std::cout << "nomal" << std::endl;
    }
}

void Transmission::increaseFuelEfficiency(bool MT)
{
    if(MT == true)
    {
        std::cout << "Good_Fuel_Economy" << std::endl;
    }
    else
    {
        std::cout << "Bad_Fuel_Economy" << std::endl;
    }
}

struct Body
{
    std::string typeOfBodyShape = "SUV";
    float overAllLength = 4825.0f;
    float overAllHeight = 1885.0f;
    int capacity = 7;
    float weight = 2050;
    
    void carryLuggage();
    void coveringTheEngine();
    float protectsPeopleFromImpact(bool airbag, int speed); 
};

void Body::carryLuggage()
{    
}

void  Body::coveringTheEngine()
{
}

float Body::protectsPeopleFromImpact(bool airbag, int speed)
{
    if(airbag == true || speed <= 70)
    {
        return 50.0f;
    }
    else if(airbag == true || speed <= 90)
    {
        return 35.0f;
    }
    else if(airbag == false || speed <= 90)
    {
        return 10.0f;
    }
    
    return 5.0f;
}

struct Gasoline
{
    std::string type = "regular";
    float fuelConsumption = 10.5f;
    float capacity = 93.0f;
    int boilingPoint = 40.0f;
    int pricePerLiter = 160;

    float fuelYourCar(float fuelEfficient, float capascityOfGasoline); 
    double inhaleIntoTheCylinder(double cpacityOfInjector, double maximumOutput);
    void burn();
};

float Gasoline::fuelYourCar(float fuelEfficient, float capascityOfGasoline)
{
    return fuelEfficient * capascityOfGasoline;
}

double Gasoline::inhaleIntoTheCylinder(double cpacityOfInjector, double maximumOutput)
{
    maximumOutput = cpacityOfInjector / 370;
    return maximumOutput;
}

void Gasoline::burn()
{
}

struct Car
{
    Wheel bridgestone_model1;
    Engine toyota_model1;
    Transmission aisin_aw_model1;
    Body nissan_model1;
    Gasoline mobil1_model1;
    
    void puttingPeople(bool childSeat);   
    void turnTheCarAround(float minimumTurningRadius);
    std::string changeTheSpeed(float acceleration, float topspeed);
};

void Car::puttingPeople(bool childSeat)
{
    if(childSeat == true)
    {
        std::cout << "Suitable for children" << std::endl;
    }
}

void Car::turnTheCarAround(float minimumTurningRadius)
{  
    if(minimumTurningRadius >= 5.0f)
    {
        std::cout << "Large_Car" << std::endl;
    }
    else
    {
        std::cout << "Nomal_Car" << std::endl;
    }
}

std::string Car::changeTheSpeed(float acceleration, float topspeed)
{
    if(acceleration >= 5.0f && topspeed <= 200)
    {
        return "AWD";
    }
    else if(acceleration <= 5.0f && topspeed <= 200)
    {
        return "FF";
    }
    else if(acceleration <= 5.0f && topspeed >= 200)
    {
        return "FR";
    }
    else if(acceleration >= 5.0f && topspeed >= 200)
    {
        return "MR";
    }
    
    return "Others";
}

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
    Example::main();
    
    std::cout << "good to go!" << std::endl;
}
