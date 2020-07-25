#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    model.loadModel("models/anklehang.obj", 20);
    
    ofSetSmoothLighting(true);
    pointLight.setDiffuseColor( ofFloatColor(.85, .85, .55) );
    pointLight.setSpecularColor( ofFloatColor(1.f, 1.f, 1.f));

    pointLight2.setDiffuseColor( ofFloatColor( 238.f/255.f, 57.f/255.f, 135.f/255.f ));
    pointLight2.setSpecularColor(ofFloatColor(.8f, .8f, .9f));

    pointLight3.setDiffuseColor( ofFloatColor(19.f/255.f,94.f/255.f,77.f/255.f) );
    pointLight3.setSpecularColor( ofFloatColor(18.f/255.f,150.f/255.f,135.f/255.f) );

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    ofBackground(50, 50, 50, 0);
    ofSetColor(255, 255, 255, 255);
    
    ofEnableLighting();
    pointLight.enable();
    pointLight2.enable();
    pointLight3.enable();

    light.enable();
cam.begin();
    model.setPosition(ofGetWidth()*2/6, (float)ofGetHeight() * 0.5 , 0);
    model.draw(OF_MESH_FILL); //same as model.drawFaces();
    model.setPosition(ofGetWidth()*3/6, (float)ofGetHeight() * 0.5 , 0);
    model.draw(OF_MESH_POINTS); // same as model.drawVertices();
    model.setPosition(ofGetWidth()*4/6, (float)ofGetHeight() * 0.5 , 0);
    model.draw(OF_MESH_WIREFRAME); // same as model.drawWireframe();
    
//    model.setRotation(0,90,0,1,0);
//    model.setScale(0.5, 0.5, 0.5);
//    model.setPosition(ofGetWidth()*2/6, (float)ofGetHeight() * 0.75 , 0);
//    model.drawFaces();
    
//    model.setRotation(0, 0, 1, 0, 0);
//    model.setRotation(1, 0, 0, 1, 0);
//    model.setRotation(2, 0, 0, 0, 1);
    cam.end();
    
    ss.run();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    ss.take();

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
