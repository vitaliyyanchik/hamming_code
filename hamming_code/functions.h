#ifndef FUNCTIONS_H
#define FUNCTIONS_H

int ControlBitesCounter(int inform_bits);
void CalculateControlBites(int control_bits, int all_bits, short* code);
void PrintCode(short* code, int all_bits);
void EnterSequence(short* code, int all_bits);
void CustomCode(short* code, int inform_bits);

#endif //FUNCTIONS_H
