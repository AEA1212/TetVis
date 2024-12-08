#pragma once 
#include <raylib.h>
#include <vector>

extern const Color darkGrey; //extern can be shared across files
extern const Color green;
extern const Color red;
extern const Color orange;
extern const Color yellow;
extern const Color purple;
extern const Color cyan;
extern const Color  blue;
extern const Color lightBlue;
extern const Color darkBlue;


std::vector<Color> GetCellColors();