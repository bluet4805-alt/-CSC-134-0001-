// CSC 134
// M7T1 - Restaurant Rating
// Blue 
// 4/29/24
// Use Restaurant class to store user ratings

#include <iostream>
using namespace std;


// Next time we'll put the class in a separate file
class Restaurant {
  private:
    string name;    // Resturant Name 
    double rating;  // 1-5 stars, including half stars

  public:
	Restaurant(string n, double r) {
        //Constructor -- make new object 
		name = n;
		rating = r;
	}
	// getters and setters
    void setName(string n) {
        name = n; 
    }
    void setRating(double r) {
        rating = r;
    }
    string getName() const {
        return name;
    }
    double getRating() const {
        return rating;
    }
  
};

int main() {
    cout << "M7T1 - Restaurant Reviews" << endl;

    return 0;

}