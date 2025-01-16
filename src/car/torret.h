#ifndef TORRET_H
#define TORRET_H

void Torret_Setup();
void Torret_Loop();

#ifdef TORRET_ENABLED
void Torret_Main_Setup();
void Torret_Main_Loop();
#endif // TORRET_ENABLED

#endif // TORRET_H

