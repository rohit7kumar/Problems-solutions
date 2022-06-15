#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<math.h>

 using namespace std;

 
   const int NumberOfRows = 6;
   const int NumberOfColumns = 3;
   const int origin=(0,0);

   float distance(int x1, int y1, int x2, int y2)
{
    // Calculating distance
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) * 1.0);
    
};


int main() {

    // Open the sourcefile
    ifstream FileStream{ "points.txt" };

    // And check, if it could be opened
    if (FileStream) {

        // Define 2D array to hold all data and initialize it with all 0
        char array2D[NumberOfRows][NumberOfColumns]{};

        // Read the rows and columns from the source file
        for (int row = 0; row < NumberOfRows; ++row)
            for (int col = 0; col < NumberOfColumns; ++col)
                FileStream >> array2D[row][col];


        // Debug output
        for (int row = 0; row < NumberOfRows; ++row) {
            for (int col = 0; col < NumberOfColumns; ++col)  std::cout << array2D[row][col] << ' ';
            std::cout << '\n';
        }
    }
    else cerr << "\nError: Could not open source file\n\n";

 ofstream outfile;
 outfile.open("output.txt");
 if(outfile.is_open())
 {
    
   outfile << distance(0, 0, 2, 4)<<endl;
     outfile << distance(0, 0, 5, 7) <<endl;
      outfile << distance(0, 0, 8, 2) <<endl;
       outfile << distance(0, 0, 3, 6) <<endl;
        outfile << distance(0, 0, 3, 2) <<endl;
       
        outfile.close();
 }
 else
 cout<<"Error\n";
    return 0;
}
