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
#include <math.h>
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

struct Person
{
    int age; 
    int height;
    float hairLenght;
    float GPA;
    unsigned int SATscore;
    int distanceTraveled;
    int runningTime;

    struct Foot
    {
    void stepForward();
    int stepSize();
    };

    Foot leftFoot;
    Foot rightFoot;

    void run(int howFast, bool startWithLeftFoot);
};


void Person::run(int howFast, bool startWithLeftFoot)
{
     if(startWithLeftFoot == true )
    {
        leftFoot.stepForward();
        rightFoot.stepForward();
    }
    else
    {
        rightFoot.stepForward();
        leftFoot.stepForward();
    }
    distanceTraveled += leftFoot.stepSize() + rightFoot.stepSize();
    howFast = distanceTraveled / runningTime;
}





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
    printf("%d %s are required \n", seasoning, str.c_str());
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

void doPerformancePractice()
{  
}

 int reserveAFacility(char room, int rentalPeriod, int rentalFees)
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
    printf ("We sell %s \n", str.c_str());
}

void StorefrontBusiness::Company::provideServices(std::string kindOfServices)
{
    std::string str = kindOfServices;
    printf ("Free Service : %s \n", str.c_str());
}

double StorefrontBusiness::Company::holdAnOpenSale(int itemNumber, double price)
{
    double floor(double);
    if(itemNumber >= 0 && itemNumber < 1000)
    {
        return price * 0.75;
    }  
    else
    {
        return price * 0.9;
    }
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
    ans = round((double)area / 25);
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
    void brightenTheImage(int isoSensitivity);
};

void Camera::captureTheLight(double fValue, int isoSensitivity, double shutterSpeed)
{
    if(fValue >= 5.6 || isoSensitivity >= 800 || shutterSpeed >= 0.02)
    {
        printf("bright");
    }
    else 
    {
        printf("dark");
    }
}

void resolveImage(int pixels)
{
    if(pixels >= 20000000)
    {
        printf("High_Resolution");
    }
        
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
        printf("classB");
    }
    else
    {
        printf("classA");
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
    
    float generateMotivePower(int power, float weight); 
    void generateHeat();
    void pushingThePistonDown(int cylinderVolume);
};

float Engine::generateMotivePower(int power, float weight)
{
    return weight / (float)power;
}

void Engine::generateHeat()
{
}

void Engine::pushingThePistonDown(int cylinderVolume)
{    
    if(cylinderVolume >= 2000)
    {
        printf("Nomal_Car");
    }
    else if(cylinderVolume >= 660)
    {
        printf("Small_Car");
    }
    else
    {
        printf("Light_Car");
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
        printf("fast");
    }
    else
    {
        printf("nomal");
    }
}

void Transmission::increaseFuelEfficiency(bool MT)
{
    if(MT == true)
    {
        printf("Good_Fuel_Economy");
    }
    else
    {
        printf("Bad_Fuel_Economy");
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
        else
        {
            return 5.0;
        }
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
    if (childSeat == true)
    {
        printf("Suitable for children");
    }
}

void Car::turnTheCarAround(float minimumTurningRadius)
{  
    if(minimumTurningRadius >= 5.0f)
    {
        printf("Large_Car");
    }
    else
    {
        printf("Nomal_Car");
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
    else
    {
        return "Others";
    }
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
    std::cout << "good to go!" << std::endl;
}
