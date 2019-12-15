#include "sim/init.hh"

namespace {

const std::uint8_t data_m5_objects_SerialLink[] = {
    120,156,157,83,75,111,211,64,16,30,39,77,218,164,41,45,
    225,33,110,152,155,139,80,130,80,169,56,32,68,65,8,85,
    106,75,149,180,8,122,177,54,222,73,236,118,253,192,187,129,
    134,107,249,23,252,88,152,25,183,212,21,156,176,227,201,206,
    236,60,190,157,111,54,130,203,167,73,223,107,250,236,22,9,
    77,63,15,12,192,17,175,26,96,60,72,27,112,210,0,79,
    55,1,27,48,245,64,47,193,15,128,11,128,207,39,77,208,
    45,24,7,109,10,76,126,209,19,120,180,114,44,30,87,203,
    53,18,111,77,30,157,161,254,48,57,197,200,185,46,89,198,
    88,38,202,236,37,217,89,84,7,241,134,65,252,36,129,0,
    39,30,67,161,186,132,134,202,224,18,131,185,160,117,11,176,
    13,132,133,215,203,128,43,112,218,97,68,132,227,130,112,118,
    107,150,182,88,86,197,210,3,189,12,122,69,44,107,128,183,
    224,116,29,112,3,102,84,165,35,198,219,87,129,93,208,171,
    98,233,139,229,142,88,122,98,185,11,163,113,192,39,26,53,
    24,105,159,68,138,233,208,202,105,66,67,199,25,196,177,149,
    3,26,245,21,253,34,47,157,93,37,117,95,89,135,165,232,
    201,6,135,250,36,142,98,244,179,121,58,161,141,124,234,151,
    248,101,142,214,89,223,229,254,100,62,157,98,105,31,253,195,
    201,22,121,102,177,230,229,184,113,79,51,107,31,94,122,27,
    229,48,139,22,236,238,226,196,250,53,116,118,64,62,59,90,
    83,26,235,151,42,155,85,137,10,69,170,139,203,124,62,139,
    233,31,235,33,9,179,104,119,72,28,252,65,81,168,82,25,
    131,134,74,101,148,33,201,108,162,177,22,40,141,240,3,117,
    166,6,226,226,127,75,180,139,55,237,46,101,121,63,25,90,
    127,92,32,106,206,132,42,138,111,166,171,101,171,146,249,127,
    101,179,28,189,25,220,227,241,90,33,17,134,153,74,49,12,
    101,178,194,48,205,245,220,176,186,196,14,139,2,197,30,157,
    159,135,49,42,77,13,235,92,241,115,72,116,184,22,159,143,
    53,113,171,136,146,13,158,233,84,84,241,57,36,148,169,212,
    59,38,132,179,12,181,40,68,91,104,147,239,40,89,153,158,
    74,91,38,109,175,34,66,162,53,26,181,112,60,10,31,233,
    14,228,101,149,173,115,73,199,136,169,168,52,99,246,49,205,
    203,133,148,175,40,146,13,154,129,80,218,45,27,199,187,153,
    219,222,18,196,220,158,80,90,18,240,53,186,22,50,99,147,
    121,98,244,240,211,139,237,112,255,221,120,119,200,211,122,125,
    247,6,197,66,6,249,25,123,223,39,209,246,248,237,209,219,
    151,183,231,117,154,253,198,65,32,157,100,20,233,243,1,179,
    149,90,247,160,210,114,185,211,118,112,227,138,143,188,171,43,
    242,63,144,164,173,47,43,22,95,61,225,40,46,223,245,54,
    90,191,1,155,76,39,228,
};

EmbeddedPython embedded_m5_objects_SerialLink(
    "m5/objects/SerialLink.py",
    "/home/zhouzhiyong/gem5/src/mem/SerialLink.py",
    "m5.objects.SerialLink",
    data_m5_objects_SerialLink,
    647,
    1201);

} // anonymous namespace