#include <Arduino.h>
#include <pstring.h>

void test(){
    Serial.println("==================================");
    Serial.printf("Initial memory: Heap:%d,PSRAM:%d\n",ESP.getFreeHeap(),ESP.getFreePsram());
    Pstring::pstring str1;
    for (size_t i = 0; i < 50000; i++){
        str1 += esp_random();
    };
    Serial.printf("After Pstring operation: Heap:%d,PSRAM:%d\n",ESP.getFreeHeap(),ESP.getFreePsram());
    std::string str2;
    for (size_t i = 0; i < 50000; i++){
        str2 += esp_random();
    };
    Serial.printf("After std::string operation: Heap:%d,PSRAM:%d\n",ESP.getFreeHeap(),ESP.getFreePsram());
};

void setup(){
    Serial.begin(115200);
    delay(5000);
    test();
    Serial.printf("After free: Heap:%d,PSRAM:%d\n",ESP.getFreeHeap(),ESP.getFreePsram());
    Serial.println("==================================");
};

//Useless
void loop(){

};