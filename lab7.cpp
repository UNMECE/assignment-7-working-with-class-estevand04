#include <iostream>
#include <cmath>

class Electric_Field {
  private:
    double *E; 

  public: 
  //default constructor
  Electric_Field() {
      E = new double[3]{0.0, 0.0, 0.0};
      
  }
  //parameterized constructor
  Electric_Field(double Ex, double Ey, double Ez){
      E = new double[3]{Ex, Ey, Ez};
  }
  //destructor
 ~Electric_Field(){
     delete[] E;
 }
 //function used to find the magnitude of the Electric_Field
 double calculateMagnitude() const {
     return std::sqrt(E[0] + E[1] + E[2] * E[2]);
 }
 //function used to find the innter product
 double innerProduct(const Electric_Field &other) const{
     return E[0] * other.E[0] + E[1] * other.E[1] + E[2] * other.E[2];
 }
 //getters
 double getX() const { return E[0]; }
 double getY() const { return E[1]; }
 double getZ() const { return E[2]; }
 //setters
 void setX(double Ex) { E[0] = Ex; }
 void setY(double Ey) { E[1] = Ey; }
 void setZ(double Ez) { E[2] = Ez; }
 
};

class Magnetic_Field {
    private: 
    double *B;
    
    public:
    Magnetic_Field() {
        B = new double[3]{0.0, 0.0, 0.0};
    }
    
    Magnetic_Field(double Bx, double By, double Bz) {
        B = new double[3]{Bx, By, Bz};
    }
    
    ~Magnetic_Field(){
        delete[] B;
    }
    
    double calculateMagnitude() const {
        return std::sqrt(B[0] * B[0] + B[1] * B[1] + B[2] * B[2]);
    }
    //function used to find the unit vector of the Magnetic_Field
    void calculateUnitVector(double &ux, double &uy, double &uz) const {
        double mag = calculateMagnitude();
        if (mag == 0) {
            ux = uy = uz = 0;
        } else {
            ux = B[0] / mag;
            uy = B[1] / mag;
            uz = B[2] / mag;
        }
    }
    
    double getX() const {return B[0]; }
    double getY() const { return B[1]; }
    double getZ() const { return B[2]; }
    
    void setX(double Bx) { B[0] = Bx; }
    void setY(double By) { B[1] = By; }
    void setZ(double Bz) { B[2] = Bz; }
    
};


int main() {
    //creating a default and parameterized Electric_field object
    Electric_Field E_default;
    Electric_Field E_componets(1e5, 10.9, 1.7e2);
    
    //modify the Electric_field using setters
    E_default.setX(5.0);
    E_default.setY(3.0);
    E_default.setZ(4.0);
    
    
    //display the magnitudes 
    std::cout << "magnitude of E_default: " << E_default.calculateMagnitude() << std::endl;
    std::cout << "magnitude of E_componets: " << E_componets.calculateMagnitude() << std::endl;
    
    //calculate the inner product 
    double inner_product = E_default.innerProduct(E_componets);
    std::cout << "inner product of E_default and E_componets: " << inner_product << std::endl;
    
    //now creating default and parameterized Magnetic_Field objects
    Magnetic_Field B_default;
    Magnetic_Field B_components(2.5, -1.2, 3.7);
    
    //modify the Magnetic_Field using setters again
    B_default.setX(1.0);
    B_default.setY(2.0);
    B_default.setZ(2.0);
    
    //now displaying the magnitudes
    std::cout << "magnitude of B_default: " << B_default.calculateMagnitude() << std::endl;
    std::cout << "magnitude of B_components: " << B_components.calculateMagnitude() << std::endl;
    
    //find the unit vector of the Magnetic_Field
    double ux, uy, uz;
    B_components.calculateUnitVector(ux, uy, uz);
    std::cout << "unit vector of B_components: (" << ux << ", " << uy << ", " << uz << ")" << std::endl;
    
    return 0;
}
