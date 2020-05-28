#include "ofApp.h"
#include "shape.hpp"


//--------------------------------------------------------------
void ofApp::setup(){
    //original artwork
    //https://fineartmultiple.com/vera-molnar-trapeze-r/
    
    imageTaken = false;

    canvasWidth = 356;
    canvasHeight = 658;
    
    
    ofSetVerticalSync(true);


    gui.setup(); // most of the time you don't need a name
//    gui.add(filled.setup("fill", true));
    gui.add(multX.setup("shape width", 0.76, 0.0, 2.0));
    gui.add(multY.setup("shape height", 1.10, 0.0, 2.0));
    gui.add(canvasHAmt.setup("canvas height", 0.045, 0.0, 1.0));
    gui.add(rXOffs.setup("rand x off", 4.0, 0.0, 10.0));
    gui.add(rYOffs.setup("rand y off", 0.275, 0.0, 0.50));
    gui.add(rHOffs.setup("rand h off", 0.10, 0.0, 0.50));

    bHide = true;

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(214,217,224);

    //    float amtX = ofMap(mouseX, 0, width, 0.0, 2.0);
    //    float amtY = ofMap(mouseY, 0, width, 0.0, 2.0);
    //    std::cout << amtX << ", " << amtY << endl;
    //    float amt = ofMap(mouseX, 0, width, 0.0, 30.0);
    //    std::cout << amt << endl;
    
    float xAmount = 20;
    float yAmount = 10;
    
//    float amtX = 0.75;
//    float amtY = 1.10;

    float shapeW = canvasWidth/xAmount * multX;
    float shapeH = canvasHeight/yAmount * multY;
    
//    int counter = 1;
    
    ofSeedRandom(111*1000);
    
//    Shape previousShape;
    bool center = false;
    
    ofVec4f prevVerts = ofVec4f();
    
    for (int i = 0; i < 10; i++ ) {
        
        for (int j = 0; j < 20; j++) {
            float x = ofMap(j, 0, xAmount, 0, canvasWidth);
            float y = ofMap(i, 0, yAmount, canvasHAmt*canvasHeight, canvasHeight);
            
            string side;
            
            if (x < canvasWidth/2) {
                side = "L";
            } else {
                side = "R";
            }
  
            Shape shape;
            
//          std::cout << rYOffs << endl;
            
            shape.setup(x, y, shapeW, shapeH, side, center, prevVerts, rXOffs, rYOffs, rHOffs);
            shape.draw();
            
            // check if it's a center left square
            // this is used to control space in center btw colors
            if (x > canvasWidth/2-shapeW*2 && x < canvasWidth/2 ) {
                center = true;
                prevVerts = shape.getVerts();
            } else {
                center = false;
            }
            
        }
        
    }
    
    if (!imageTaken) {
        ofImage image;
        takeScreenShot(canvasWidth,canvasHeight);
        imageTaken = true;
    }
    
    if(!bHide){
        gui.draw();
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if (key == OF_KEY_RETURN) {
        takeScreenShot(canvasWidth,canvasHeight);
        std::cout << "return pressed" << endl;
    }
    
    if(key == 'h'){
        bHide = !bHide;
    }
    
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}

void ofApp::takeScreenShot(float imgW, float imgH) {
    ofImage image;
    image.grabScreen(0,0,imgW,imgH);
    string str = "images/devImg";
    str += ofToString(ofGetTimestampString()) + ".jpg";
    image.saveImage(str);
    std::cout << "ss taken" << endl;
}

