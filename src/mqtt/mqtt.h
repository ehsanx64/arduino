#ifndef MQTT_H
#define MQTT_H

void Mqtt_Setup();
void Mqtt_Loop();

#ifdef MQTT_ENABLED
void Mqtt_Callback(const MQTT::Publish& pub);
void Mqtt_setBrokerIp();
void Mqtt_HandleColorTopic(String payload);
#endif

#endif
