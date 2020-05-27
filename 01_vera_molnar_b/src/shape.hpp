//
//  shape.hpp
//  01_vera_molnar_b
//
//  Created by Lisa Jamhoury on 5/26/20.
//

#ifndef shape_hpp
#define shape_hpp

#include "ofMain.h"
#include "ofApp.h"
#include <stdio.h>


class Shape {

    public: // place public functions or variables declarations here

    // methods, equivalent to specific functions of your class objects
    void setup(float _x, float _y, float _w, float _h, string _side, bool _ctr, ofVec4f _pVerts);
    // setup method, use this to setup your object's initial state
    void update();  // update method, used to refresh your objects properties
    void draw();    // draw method, this where you'll do the object's drawing
    ofVec4f getVerts();


    // variables
    float x;        // position
    float y;
    
    float w;
    float h;
    
    string side;
    
    ofColor clr;
    bool center;
    
    ofVec2f v1;
    ofVec2f v2;
    ofVec2f v3;
    ofVec2f v4;
    
    ofVec4f prevVerts;

    
    Shape();  // constructor - used to initialize an object, if no properties are passed the program sets them to the default value
    private: // place private functions or variables declarations here
    
    void createVerts();
    ofColor setColor();
    
}; // don't forget the semicolon!


#endif /* shape_hpp */
