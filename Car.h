#include <string>
using namespace std;

class Car{
private:
    int car_id;
    bool active;
    string lincensePlate;
    string model;
    string brand;
    int registrationYear;
    int mileage;
    int dailyPrice;
    string fuelType;
    string gearbox;
    string color;
    string remark;

public:
    Car(int car_id, string lincensePlate, string model, string brand, int registrationYear, int mileage, int dailyPrice, string fuelType, string gearbox, string color, string remark);
    void inline set_licensePlate(string new_licensePlate){lincensePlate = new_licensePlate;}
    void inline set_model(string new_model){ model = new_model;}
    void inline set_brand(string new_brand){brand = new_brand;}
    void inline set_registrationYear(int new_registrationYear){registrationYear = new_registrationYear;}
    void inline set_mileage(int new_mileage){mileage = new_mileage;}
    void inline set_dailyPrice(int new_dailyPrice){dailyPrice = new_dailyPrice;}
    void inline set_fuelType(string new_fuelType){fuelType = new_fuelType;}
    void inline set_gearbox(string new_gearbox){gearbox = new_gearbox;}
    void inline set_color(string new_color){color = new_color;}
    void inline set_remark(string new_remark){remark = new_remark;}

    string inline get_lincensePlate(){return lincensePlate;}
    string inline get_model(){return model;}
    string inline get_brand(){return brand;}
    int inline get_registrationYear(){return registrationYear;}
    int inline get_mileage(){return mileage;}
    int inline get_dailyPrice(){return dailyPrice;}
    string inline get_fuelType(){return fuelType;}
    string inline get_gearbox(){return gearbox;}
    string inline get_color(){return color;}
    string inline get_remark(){return remark;}

    void add();
    void del(int car_id);
    void update(int car_id);
    void inline deactivate(int car_id){active = false;}
    bool valid(int car_id);
};