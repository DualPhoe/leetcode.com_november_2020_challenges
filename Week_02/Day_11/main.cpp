#include <iostream>
#include <vector>
using namespace std;

struct my_point
{
    float _x;
    float _y;
    my_point()
    {}

    bool overlap(const my_point & b)
    {
        if((_x == b._x ) && (_y == b._y))
        {
            return true;
        }
        return false;
    }

    my_point middlePoint(const my_point & b)
    {
        my_point res;
        res._x = (_x + b._x)/2;
        res._y = (_y + b._y)/2;
        return res;
    }
};

int distance_Square( const my_point & p1, const my_point & p2)
{
    return pow( p1._x - p2._x , 2) + pow( p1._y - p2._y  , 2);
}

struct my_triangle 
{
    my_point P1,P2,P3;
    my_triangle()
    {
    }

    void set_point(const int & x1, const int & y1,
                   const int & x2, const int & y2,
                   const int & x3, const int & y3)
    {
        P1._x = x1;
        P1._y = y1;
        
        P2._x = x2;
        P2._y = y2;
        
        P3._x = x3;
        P3._y = y3;
    }

    

    bool isIsoscelesRightTriangle(my_point & oFocal)
    {
        if(P1.overlap(P2) || P1.overlap(P3) || P2.overlap(P3))
        {
            return false;
        }

        int D12 = distance_Square(P1,P2);
        int D13 = distance_Square(P1,P3);
        int D23 = distance_Square(P2,P3);

        if(D12 + D13 == D23)
        {
            oFocal = P2.middlePoint(P3);
            return true;
        }

        if(D12 + D23 == D13)
        {
            oFocal = P1.middlePoint(P3);
            return true;
        }

        if(D23 + D13 == D12)
        {
            oFocal = P1.middlePoint(P2);
            return true;
        }

        return false;
        
    }

};

class Solution {
public:
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) 
    {
        my_triangle triangle_one;
        triangle_one.set_point(p1[0], p1[1],
                              p2[0], p2[1],
                              p3[0], p3[1]);
        my_point focal_one;
        if(!triangle_one.isIsoscelesRightTriangle(focal_one))
        {
            return false;
        }
        
        my_triangle triangle_two;
        triangle_two.set_point(p4[0], p4[1],
                              p2[0], p2[1],
                              p3[0], p3[1]);
        my_point focal_two;
        if(!triangle_two.isIsoscelesRightTriangle(focal_two))
        {
            return false;
        }

        if(focal_one.overlap(focal_two))
        {
            return true;
        }

        
        
        
        return false;
        
    }
};


int main()
{
    return 0;
}