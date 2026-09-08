#include <iostream>
#include <string>

using namespace std;


class Engine
{
    string type;
    int power;

public:

    Engine() : type("none"), power(0)
    {
    }

    Engine(string type, int power)
        : type(type), power(power)
    {
    }

    void Print() const
    {
        cout << "Engine type : " << type << endl;
        cout << "Engine power : " << power << " hp" << endl;
    }
};

class Wheel
{
    int diameter;
    string type;

public:

    Wheel() : diameter(0), type("none")
    {
    }

    Wheel(int diameter, string type)
        : diameter(diameter), type(type)
    {
    }

    void Print() const
    {
        cout << "Wheel diameter : " << diameter << endl;
        cout << "Wheel type : " << type << endl;
    }
};

class Door
{
    string type;

public:

    Door() : type("none")
    {
    }

    Door(string type) : type(type)
    {
    }

    void Print() const
    {
        cout << "Door type : " << type << endl;
    }
};

class Body
{
    string type;

public:

    Body() : type("none")
    {
    }

    Body(string type) : type(type)
    {
    }

    void Print() const
    {
        cout << "Body type : " << type << endl;
    }
};

class Headlight
{
    string type;

public:

    Headlight() : type("none")
    {
    }

    Headlight(string type) : type(type)
    {
    }

    void Print() const
    {
        cout << "Headlight type : " << type << endl;
    }
};

class Driver
{
    string name;
    string surname;
    int age;
    int experience;

public:

    Driver()
        : name("none"),
        surname("none"),
        age(0),
        experience(0)
    {
    }

    Driver(string name, string surname, int age, int experience)
        : name(name),
        surname(surname),
        age(age),
        experience(experience)
    {
    }

    void Print() const
    {
        cout << "Driver name : " << name << endl;
        cout << "Driver surname : " << surname << endl;
        cout << "Driver age : " << age << endl;
        cout << "Driving experience : " << experience << " years" << endl;
    }
};

class Car
{
    string model;

    Engine engine;
    Body body;
    Wheel* wheels;
    Door* doors;
    Headlight* headlights;

    int countWheels;
    int countDoors;
    int countHeadlights;

    Driver* driver;

public:

    Car()
        : model("none"),
        engine(),
        body(),
        wheels(nullptr),
        doors(nullptr),
        headlights(nullptr),
        countWheels(0),
        countDoors(0),
        countHeadlights(0),
        driver(nullptr)
    {
    }

    Car(
        string model,
        string engineType,
        int enginePower,
        string bodyType
    )
        : driver(nullptr)
    {
        this->model = model;

        engine = Engine(engineType, enginePower);
        body = Body(bodyType);

        countWheels = 4;
        wheels = new Wheel[countWheels];

        for (int i = 0; i < countWheels; i++)
        {
            wheels[i] = Wheel(18, "Alloy");
        }

        countDoors = 4;
        doors = new Door[countDoors];

        for (int i = 0; i < countDoors; i++)
        {
            doors[i] = Door("Standard");
        }

        countHeadlights = 2;
        headlights = new Headlight[countHeadlights];

        for (int i = 0; i < countHeadlights; i++)
        {
            headlights[i] = Headlight("LED");
        }
    }

    Car(
        string model,
        string engineType,
        int enginePower,
        string bodyType,
        Driver* driver
    )
        : Car(model, engineType, enginePower, bodyType)
    {
        this->driver = driver;
    }

    void AddDriver(Driver* driver)
    {
        this->driver = driver;
    }

    void Show() const
    {
        cout << "============================" << endl;
        cout << "Car information" << endl;

        cout << "Model : " << model << endl;

        cout << endl << "--- Engine ---" << endl;
        engine.Print();

        cout << endl << "--- Body ---" << endl;
        body.Print();

        cout << endl << "--- Wheels ---" << endl;

        for (int i = 0; i < countWheels; i++)
        {
            cout << "Wheel " << i + 1 << endl;
            wheels[i].Print();
        }

        cout << endl << "--- Doors ---" << endl;

        for (int i = 0; i < countDoors; i++)
        {
            cout << "Door " << i + 1 << endl;
            doors[i].Print();
        }

        cout << endl << "--- Headlights ---" << endl;

        for (int i = 0; i < countHeadlights; i++)
        {
            cout << "Headlight " << i + 1 << endl;
            headlights[i].Print();
        }

        cout << endl << "--- Driver ---" << endl;

        if (driver != nullptr)
        {
            driver->Print();
        }
        else
        {
            cout << "Driver is not assigned!" << endl;
        }

        cout << "============================" << endl;
        cout << endl;
    }

    ~Car()
    {
        if (wheels != nullptr)
            delete[] wheels;

        if (doors != nullptr)
            delete[] doors;

        if (headlights != nullptr)
            delete[] headlights;
    }
};



int main()
{
    Driver driver1(
        "John",
        "Smith",
        35,
        12
    );

    Car car1(
        "BMW X5",
        "Diesel",
        286,
        "SUV"
    );

    cout << "Car before adding driver:" << endl;
    car1.Show();

    car1.AddDriver(&driver1);

    cout << "Car after adding driver:" << endl;
    car1.Show();

    Driver driver2(
        "Michael",
        "Johnson",
        42,
        20
    );

    Car car2(
        "Mercedes-Benz",
        "Petrol",
        300,
        "Sedan",
        &driver2
    );

    cout << "Second car:" << endl;
    car2.Show();

    car2.AddDriver(&driver1);

    cout << "Second car after changing driver:" << endl;
    car2.Show();
}