#include "config.h"
#include "src/app.h"

#define APP

void setup() {
#ifdef APP
    App_Setup();
#endif  
}  

void loop() {
#ifdef APP
    App_Loop();
#endif  
}
