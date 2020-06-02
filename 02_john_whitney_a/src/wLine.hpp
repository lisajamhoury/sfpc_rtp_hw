//
//  wLine.hpp
//  02_john_whitney_a
//
//  Created by Lisa Jamhoury on 5/31/20.
//

#ifndef wLine_hpp
#define wLine_hpp

#include <stdio.h>
#include "ofMain.h"

class WLine {

    public: // place public functions or variables declarations here

    // methods, equivalent to specific functions of your class objects
    void setup(float _xO1, float _yO1, float _xO2, float _yO2, float _x1, float _y1, float _x2, float _y2, float _rad1, float _rad2, float _angle, ofColor _clr, int _group);
    // setup method, use this to setup your object's initial state
    void updateState(int _state);
    void update();  // update method, used to refresh your objects properties
    void draw();    // draw method, this where you'll do the object's drawing

    // variables
    
    float x1Start;
    float y1Start;
    float x2Start;
    float y2Start;
    
    float rad1Start;
    float rad2Start;
    float angleStart;
    
    float xO1;
    float yO1;
    float xO2;
    float yO2;
    
    float x1;
    float y1;
    
    float x2;
    float y2;
    
    float rad1;
    float rad2;
    float angle1;
    float angle2;
    
    ofColor clr;
    int group; 
    int state;

    float pathAngle;
    
    WLine();  // constructor - used to initialize an object, if no properties are passed the program sets them to the default value
    private: // place private functions or variables declarations here
    
    
}; // don't forget the semicolon!

#endif /* wLine_hpp */
