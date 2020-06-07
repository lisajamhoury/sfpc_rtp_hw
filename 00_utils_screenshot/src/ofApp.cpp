#include "ofApp.h"
#include "screenshot.hpp"

//--------------------------------------------------------------
void ofApp::setup(){
    
    randSeed = ofRandom(20000.0);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(0);
    
    ofSeedRandom(randSeed);
    ofSetColor(255);
    ofDrawCircle(ofRandom(0,ofGetWidth()), ofRandom(0,ofGetHeight()), 10);
    
    // leave this at the end of draw loop to
    // take ss once the screen is drawn
    screenshot.run();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    // use the return key to take additional
    // screenshots at will
    if (key == OF_KEY_RETURN) {
        screenshot.take();
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

