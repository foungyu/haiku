#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
	myPlayer_taiwan.loadMovie("taiwan.mov");
    myPlayer_taiwan.play();
    myPlayer_taiwan.setLoopState(OF_LOOP_NORMAL);
	
    myPlayer_newyork.loadMovie("newyork.mov");
    myPlayer_newyork.play();
    myPlayer_newyork.setLoopState(OF_LOOP_NORMAL);
	
    
    mesh.setMode(OF_PRIMITIVE_POINTS);
 
}

//--------------------------------------------------------------
void testApp::update(){
    
}

//--------------------------------------------------------------
void testApp::draw(){
    //ny_frame+=time_dis;
    //tw_frame+=time_dis;
    myPlayer_taiwan.update();
    myPlayer_newyork.update();
    //ofBackgroundGradient(ofColor::gray, ofColor::black, OF_GRADIENT_CIRCULAR);
	ofBackground(0,0,0);
    angle+=0.2;
	// even points can overlap with each other, let's avoid that
	cam.begin();
	ofScale(0.8, -0.8, 0.8); // flip the y axis and zoom in a bit
	//ofRotateX(angle);
	ofTranslate(-myPlayer_taiwan.width*pointSize/4, -myPlayer_taiwan.height*pointSize/4);
    
    
    
    int skip=5;
    int bpp=3;
    int layer=0;
    for(int layer=0;layer<7;layer++){
        
       /* int f=tw_frame+layer*time_dis;
        if(f>myPlayer_taiwan.getTotalNumFrames()){
            f-=myPlayer_taiwan.getTotalNumFrames();
        }
        myPlayer_taiwan.setFrame(f);
        myPlayer_taiwan.update();*/
        unsigned char * pixels_tw = myPlayer_taiwan.getPixels();
       // pixel.push_back(pixels_tw);
    for (int x = 0; x < myPlayer_taiwan.width; x+=skip){
        for (int y = 0; y < myPlayer_taiwan.height; y+=skip){
            float cRed;
            float cGreen;
            float cBlue;
            cRed = pixels_tw[(y*myPlayer_taiwan.width+x)*bpp+0];
            cGreen = pixels_tw[(y*myPlayer_taiwan.width+x)*bpp+1];
            cBlue = pixels_tw[(y*myPlayer_taiwan.width+x)*bpp+2];
            ofColor cur;
            cur.r=cRed;
            cur.g=cGreen;
            cur.b=cBlue;
            cur.a=100;
            if(cRed!=0&&cGreen!=0&&cBlue!=0){
            float z = ofMap(cur.r, 0, 255, -300, 300);
            mesh.addColor(cur);
            ofVec3f pos(x*(pointSize/2), y*(pointSize/2),layer*50+(cur.r+cur.g+cur.b)/2);
            mesh.addVertex(pos);
            }
        }
    }
    }
    for(int layer=0;layer<7;layer++){
        /*int f=ny_frame+layer*time_dis;
        if(f>myPlayer_newyork.getTotalNumFrames()){
            f-=myPlayer_newyork.getTotalNumFrames();
        }
        myPlayer_newyork.setFrame(f);
        myPlayer_newyork.update();*/

         unsigned char * pixels_ny = myPlayer_newyork.getPixels();
        for (int x = 0; x < myPlayer_newyork.width; x+=skip){
            for (int y = 0; y < myPlayer_newyork.height; y+=skip){
                float cRed;
                float cGreen;
                float cBlue;
                cRed = pixels_ny[(y*myPlayer_newyork.width+x)*bpp+0];
                cGreen = pixels_ny[(y*myPlayer_newyork.width+x)*bpp+1];
                cBlue = pixels_ny[(y*myPlayer_newyork.width+x)*bpp+2];
                ofColor cur;
                cur.r=cRed;
                cur.g=cGreen;
                cur.b=cBlue;
                cur.a=100;
                if(cRed!=0&&cGreen!=0&&cBlue!=0){

                float z = ofMap(cur.r, 0, 255, -300, 300);
                mesh.addColor(cur);
                ofVec3f pos(x*(pointSize/2),y*(pointSize/2),-(layer*50+(cur.r+cur.g+cur.b)/2));
                mesh.addVertex(pos);
                }
            }
        }
    }
    
    mesh.draw();
    mesh.clear();
	cam.end();
    
	glEnable(GL_DEPTH_TEST);
    glEnable(GL_POINT_SMOOTH); // use circular points instead of square points
	glPointSize(pointSize*2); // make the points bigger
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){
    
}