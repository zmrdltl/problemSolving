class ParkingSystem {
public:
    vector <int> carPerSize;
    ParkingSystem(int big, int medium, int small) {
        carPerSize.resize(4, 0);
        carPerSize[1] = big;
        carPerSize[2] = medium;
        carPerSize[3] = small;
    }
    
    bool addCar(int carType) {
        if (carPerSize[carType] - 1 < 0) return false;
        carPerSize[carType]--;
        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */