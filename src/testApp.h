#pragma once

#include "ofMain.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
   
    int bpp =3;
    
    ofEasyCam cam;
    ofMesh mesh;
    ofImage img;
    ofVideoPlayer myPlayer_taiwan;
    ofVideoPlayer myPlayer_newyork;
    
     //ofPixels vidPixels;
    int z=0;
    static vector<char * > pixel;
    //unsigned char * pixels_tw;
    //unsigned char * pixels_ny;
    int myTime=0;
    int kk=0;
    int pointSize=6;
    float angle=0;
    int tw_frame=0;
    int ny_frame=0;
    int time_dis=5;
    float* AllPixel = new float[50000];
};
