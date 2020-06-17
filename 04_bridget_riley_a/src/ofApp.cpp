#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(255);
    ofSetColor(0);
  
    
//    ofSetColor(0x000000);
//    ofNoFill();
//
//    int spacing = 50;
//    ofBeginShape();
//    for(int x=0; x<ofGetWidth(); x+= spacing) {
//        ofCurveVertex(x, ofGetHeight()/2 + ofGetHeight() * 0.3f * sin(x*0.01f + ofGetFrameNum() * 0.02f));
//    }
//    ofEndShape(false);
    float origX = 300;
    float origY = 100;
    float w = ofGetWidth()/20;
    float h = ofGetHeight()*0.75;

//    ofPolyline line;
//
//    line.addVertex(origX,origY);
//    line.addVertex(origX+w,origY);
//    line.addVertex(origX+w,origY+h);
//    line.addVertex(origX,origY+h);
//    line.close();
//    line.draw();
//
//    ofBeginShape();
//        for( int i = 0; i < line.getVertices().size(); i++) {
//            ofVertex(line.getVertices().at(i).x, line.getVertices().at(i).y);
//        }
//    ofEndShape();
  
//    ofBeginShape();
//        ofCurveVertex(origX,origY);
//        ofCurveVertex(origX+w,origY);
//        ofCurveVertex(origX+w,origY+h);
//        ofCurveVertex(origX,origY+h);
//
//    ofEndShape();
  
//    ofNoFill();
//    ofBeginShape();
//    ofCurveVertex(500, 250);
//    ofCurveVertex(300, 250);
//    ofCurveVertex(250, 250);
//    ofCurveVertex(250, 300);
//    ofCurveVertex(250, 500);
//    ofEndShape();
    
    
    
    
    cout << mouseX << ", " << mouseY << endl;
    
    ofPolyline line;
    
    for (int i = 0; i < 30; i++){
        
        float x =
        float y = 
        line.addVertex(x, y);
        
    }
    
    
//    ofPolyline line;
//    line.addVertex(156, 356);
//      line.addVertex(156, 162);
//      line.bezierTo(152, 100, 191, 95, 243, 95);
//    line.addVertex(296, 95);
    
//    line.addVertex(500, 250);
//    line.addVertex(300, 250);
//    line.bezierTo(250, 250);
//    line.addVertex(250, 300);
//    line.addVertex(250, 500);
//    line.addVertex(ofPoint(200, 400));
//    line.bezierTo(100, 100, 800, 100, 700, 400);
//    line.addVertex(ofPoint(400, 200));
    
//    float cx = ofGetWidth()/2;
//    float cy = 200;
//    float step = TWO_PI / 60;
//    for (float i = 0.0; i < TWO_PI; i+=step) {
//
//
//        if(i == 0.0) {
//            line.addVertex(cx + (400*cos(i)), cy+400, 400 * sin(i));
//        } else {
//            line.bezierTo( cx - (200*cos(i)), cy-100, 400 * sin(i),
//                           cx + (200*cos(i)), cy+600, 400 * sin(i),
//                           cx + (400*cos(i)), cy+400, 400 * sin(i));
//        }
//    }
    
    line.draw();
    
//        ofBeginShape();
//            for( int i = 0; i < line.getVertices().size(); i++) {
//                ofVertex(line.getVertices().at(i).x, line.getVertices().at(i).y);
//            }
//        ofEndShape();
    
    
    screenshot.run();
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
