#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
//
//    float lerpNum = ofLerp(0,100,.5);
//    cout << lerpNum << endl;
//
    ofSetFrameRate(60);
    timer = 0;
    imgCounter = 0;
    started = false;
    
    ofDirectory dir;
    dir.listDir("lisa/2016");
    for (int i = 0; i < dir.size(); i++){
        ofImage img;
        images.push_back(img);
        images.back().load(dir.getPath(i));
        cout << "loaded " << i << " of " << dir.size() << endl;
        
        ofRectangle targetDim(0,0,640,480);
        ofRectangle imageDim(0,0,images.back().getWidth(),
                             images.back().getHeight());
        
        targetDim.scaleTo(imageDim);
        
        images.back().crop(targetDim.x, targetDim.y, targetDim.width, targetDim.height);
        images.back().resize(640,480);
        
    }
    
    
    // allocate the new average image
    average.allocate(640,480, OF_IMAGE_COLOR);
    
//    for (int i = 0; i < 640; i++){
//        for (int j = 0; j < 480; j++){
//
//            // average:
//            // (1) add all values up
//            float sumRed = 0;
//            float sumBlue = 0;
//            float sumGreen = 0;
//            for (int k = 0; k < images.size(); k++){
//                ofColor color = images[k].getColor(i,j);
//                sumRed += color.r;
//
//                sumGreen += color.g;
//                 sumBlue += color.b;
//            }
//            // (2) divide
//            sumRed /= (float)images.size();
//            sumBlue /= (float)images.size();
//            sumGreen /= (float)images.size();
//            average.setColor(i,j, ofColor(sumRed, sumGreen, sumBlue));
//
//
//        }
//    }
//
//    average.update();

    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    // every second add a new photo
    if (ofGetFrameNum() - timer == 5.0) {
        
        if (imgCounter >= images.size()) {
            cout << "done" << endl;
            return;
        }
        
        ss.take();
        timer = ofGetFrameNum();
        
//        ofImage img;
        imagesToAvg.push_back(images[imgCounter]);
        
 
            imgCounter++;
        
        
        if (!started) started = true;
        
    }
    
//    float spacesAvail = 100.0;
    
    
    // number of spaces
    int n, sum = 0;
    
    n = imagesToAvg.size();

    for (int i = 1; i < n; ++i) {
        sum += i;
    }

//    cout << "Sum = " << sum << endl;
    
//    float multiple = spacesAvail / imagesToAvg.size();
    float multiplier = 0.0;
    // average the photos
    for (int i = 0; i < 640; i++){
        for (int j = 0; j < 480; j++){

            // average:
            // (1) add all values up
            float sumRed = 0;
            float sumBlue = 0;
            float sumGreen = 0;
            
            for (int k = 0; k < imagesToAvg.size(); k++){
                
               int index = imagesToAvg.size() - k - 1;
            
//            float mult = ofLerp(0, index*10.0, 0.5);
            float mult = 10.0;
                               
               ofColor color = imagesToAvg[index].getColor(i,j);
//               sumRed += (color.r * mult);
//               sumGreen += (color.g * mult);
//               sumBlue += (color.b * mult);
//                multiplier+=mult;
                
                sumRed += color.r * index;
                sumGreen += color.g * index;
                sumBlue += color.b * index;
            }
            // (2) divide
//            sumRed /= multiplier*float(imagesToAvg.size());
//            sumBlue /= multiplier*float(imagesToAvg.size());
//            sumGreen /= multiplier*float(imagesToAvg.size());
            
                      sumRed /= (float)sum;
                        sumBlue /= (float)sum;
                        sumGreen /= (float)sum;
            average.setColor(i,j, ofColor(sumRed, sumGreen, sumBlue));


        }
    }

    average.update();
    
    
    
    // the new photo is 50% of the new image
    
    // the older photos are lerped at 50%
    
    
    

}

//--------------------------------------------------------------
void ofApp::draw(){

//    if (started) imgagesToAvg.back().draw(0,0);

    
        average.draw(0,0);
    
//    ss.run();
    
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
