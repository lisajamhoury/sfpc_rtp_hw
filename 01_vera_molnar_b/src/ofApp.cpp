#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    imageTaken = false;
    width = 712/2;
    height = 1316/2;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(214,217,224);
    ofColor leftClr(169,15,19);
    ofColor rightClr(50,5,8);
    
    float xAmount = 20;
    float yAmount = 10;
    
//    float amtX = ofMap(mouseX, 0, width, 0.0, 2.0);
//    float amtY = ofMap(mouseY, 0, width, 0.0, 2.0);
//    std::cout << amtX << ", " << amtY << endl;
    
    float amtX = 0.75;
    float amtY = 1.10;

    float shapeW = width/xAmount * amtX;
    float shapeH = height/yAmount * amtY;
    
    ofSeedRandom(111*1000);
    
//    float amt = ofMap(mouseX, 0, width, 0.0, 30.0);
//    std::cout << amt << endl;


    float rXOffset = 4.9;
    
    int counter = 0;
    
    for (int i = 0; i < 10; i++ ) {
//        float multi = ofMap(mouseX, 0, width, 0, 1.0);
        //float yNOffset = ofNoise(counter*0.1 + mouseX*0.1) * 100;
//        float yNOffset = ofNoise(counter*multi + 100*0.1) * 100;
//        counter++;
//        std:cout << multi << endl;
        
        for (int j = 0; j < 20; j++) {
            float x = ofMap(j, 0, xAmount, 0, width);
            float y = ofMap(i, 0, yAmount, 0.03*height, height);
            
            // random Y offset changes Y location randomly
            float rYOffset;
            
            // Threshold for Y variance
//             float yOffThresh = ofMap(mouseX, 0, width, 0.0, 0.5);
            float yOffThresh = 0.32;
//            std::cout << yOffThresh << endl;
            // random H offset changes height of shape randomly
            float rHOffset;
            
            // If X is on left
            if (x < width/2) {
                ofSetColor(leftClr);
                rYOffset = ofRandom(0.0, yOffThresh*shapeH);
            } else {
                ofSetColor(rightClr);
                rYOffset = ofRandom(yOffThresh*shapeH, 2*yOffThresh*shapeH);
            }
            
            // If y is on the top half
            if (y < height/2) {
//                rYOffset *=-1;
            }
            
            
            rHOffset = ofRandom(0.10);

            ofVec2f v1(x+ofRandom(-rXOffset,rXOffset), y-rYOffset);
            ofVec2f v2(x+ofRandom(-rXOffset,rXOffset)+shapeW, y-rYOffset);
            ofVec2f v3(x+ofRandom(-rXOffset,rXOffset)+shapeW, y-rYOffset-rHOffset+shapeH);
            ofVec2f v4(x+ofRandom(-rXOffset,rXOffset), y-rYOffset-rHOffset+shapeH);
            

            ofSetRectMode(OF_RECTMODE_CENTER);
            ofBeginShape();
            
            ofVertex(v1);
            ofVertex(v2);
            ofVertex(v3);
            ofVertex(v4);
            
            ofEndShape(true);
            
            
        }
        
    }
    
    if (!imageTaken) {
        ofImage image;
        takeScreenShot(width,height);
        imageTaken = true;
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if (key == OF_KEY_RETURN) {
        takeScreenShot(width,height);
        std::cout << "return pressed" << endl;
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

