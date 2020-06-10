#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    int w    = 200;
    int h    = 200;
    
//    typeClr3 = ofColor(54, 20, 65); // purple
//    typeClr2 = ofColor(1, 74, 24); // green
//    typeClr1 = ofColor(205, 43, 22); // red


    ofPixels red, green;
    red.allocate(w, h, OF_IMAGE_COLOR_ALPHA);
    red.setColor(ofColor(1, 74, 24));
//    red.setColor(ofColor::red);
    
    green.allocate(w, h, OF_IMAGE_COLOR_ALPHA);
    green.setColor(ofColor(205, 43, 22));
//    green.setColor(ofColor::green);

    img1.setFromPixels(red);
    img2.setFromPixels(green);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
//        ofBackground(39, 23, 19); // this matters
//    ofBackground(0);
////    img1.draw(0,0);//red image
////    img2.draw(100,100);//green image
//
//        ofEnableBlendMode(OF_BLENDMODE_ADD);
//        img1.draw(0,0);//red image
//        img2.draw(100,100);//green image
//    ofDisableAlphaBlending();
    
    ofBackground(230); // this matters
    img1.draw(0,0);//red image
    img2.draw(100,100);//green image
    
    //            ofBackground(0); // this matters
    ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
    img1.draw(0,0);//red image
    img2.draw(100,100);//green image
    ofDisableAlphaBlending();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
