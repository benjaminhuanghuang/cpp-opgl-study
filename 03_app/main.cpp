#include "../include/glfw_app.hpp"

using namespace lynda;

struct MyApp : App {

  MyApp() : App() {}

    virtual void onDraw(){
    }
    
    virtual void onMouseMove(int x, int y){
        cout << x << " " << y << endl;
    }
    virtual void onMouseDown(int button, int action){
        if (action==GLFW_PRESS) cout << "mouse pressed" <<endl;
        if (action==GLFW_RELEASE) cout << "mouse released" <<endl;
    }
    virtual void onKeyDown(int key, int action){
        cout << (unsigned char)key << endl;
    }
};


int main(){

  MyApp app;
  app.start();

  return 0;
}
