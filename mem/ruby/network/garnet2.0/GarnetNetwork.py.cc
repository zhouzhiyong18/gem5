#include "sim/init.hh"

namespace {

const std::uint8_t data_m5_objects_GarnetNetwork[] = {
    120,156,173,86,91,111,220,68,20,30,239,253,150,75,147,42,
    42,69,208,121,0,177,148,102,183,77,1,161,8,33,72,67,
    81,164,54,84,78,43,218,125,25,121,237,217,93,111,199,158,
    149,103,54,205,242,90,158,248,65,252,1,126,24,156,115,108,
    239,21,149,60,100,29,159,248,124,51,62,62,231,59,23,219,
    103,217,175,8,231,143,112,154,63,65,4,240,231,48,197,216,
    203,236,202,73,175,10,76,21,88,84,100,189,34,115,80,47,
    50,85,98,81,153,245,202,169,94,98,170,194,162,42,235,85,
    65,47,51,89,100,3,135,5,21,246,7,99,239,25,123,211,
    171,177,160,202,100,149,208,218,28,173,179,160,206,100,153,208,
    198,28,109,176,160,201,46,218,45,112,39,252,7,126,109,7,
    174,44,138,251,233,101,19,132,59,237,207,206,165,125,167,147,
    183,11,240,196,51,161,239,234,169,149,73,10,110,129,120,162,
    180,255,86,6,191,246,199,210,183,132,252,226,37,177,180,217,
    221,254,50,15,39,200,195,95,32,36,99,61,7,217,232,21,
    144,6,8,91,150,216,184,140,68,64,236,239,11,172,87,33,
    164,138,161,67,192,136,212,114,164,130,193,34,82,95,66,106,
    132,52,114,164,142,17,35,210,92,178,220,36,164,69,200,22,
    147,219,44,104,17,178,67,200,46,147,183,88,176,69,200,94,
    110,7,246,236,16,178,207,220,139,246,46,50,83,194,32,190,
    2,17,201,168,155,0,79,221,56,13,181,59,164,192,143,58,
    15,187,43,20,116,70,163,16,25,48,135,32,226,105,212,151,
    9,215,3,158,232,119,134,135,3,126,116,202,219,145,52,163,
    174,213,201,212,116,59,157,47,185,213,19,173,244,112,22,226,
    3,205,103,120,91,106,138,135,49,144,63,240,124,201,7,42,
    180,220,132,191,75,192,120,127,102,165,9,75,249,238,203,48,
    177,83,79,113,127,228,197,177,84,134,79,224,145,57,152,153,
    50,28,54,246,167,131,129,76,210,245,192,179,30,95,187,51,
    196,52,111,236,244,109,162,214,119,154,47,96,211,195,99,254,
    155,12,135,35,123,216,247,140,12,248,75,175,175,228,3,254,
    232,152,191,126,243,128,31,29,243,39,83,99,117,100,238,98,
    9,196,184,152,123,195,7,222,84,89,30,233,0,76,237,47,
    5,188,132,135,47,254,206,156,201,22,15,149,188,148,138,7,
    210,11,176,8,185,29,37,192,163,86,65,251,54,86,103,13,
    132,16,177,23,73,33,108,131,20,176,51,85,168,34,85,118,
    54,145,132,251,87,87,98,4,70,100,98,203,160,190,240,18,
    47,178,88,175,103,177,37,43,144,52,129,233,178,21,80,94,
    1,250,248,200,98,255,196,161,192,52,8,76,3,1,151,190,
    17,192,144,184,4,15,237,254,130,54,2,145,96,113,233,111,
    224,72,39,226,183,0,79,160,187,194,120,40,60,53,212,73,
    104,71,17,121,122,162,181,34,215,158,122,202,72,187,55,167,
    79,16,61,130,232,161,80,158,162,254,156,84,188,241,252,213,
    179,103,212,186,203,251,62,2,61,45,85,145,83,39,22,212,
    97,165,46,132,57,38,103,67,21,116,95,127,247,173,120,254,
    243,197,89,247,218,117,63,153,81,179,124,142,118,48,229,21,
    7,143,189,249,81,135,35,253,111,15,214,231,198,89,94,232,
    155,3,100,244,159,3,4,26,188,87,194,105,55,174,208,12,
    113,112,88,166,170,172,177,113,29,39,73,54,52,230,96,35,
    159,45,205,37,176,133,243,36,29,20,208,242,85,108,121,100,
    204,98,47,174,59,103,58,31,158,3,235,251,97,20,152,251,
    88,88,167,216,181,137,84,158,13,117,12,253,206,181,29,65,
    103,109,180,185,185,126,63,223,93,153,46,235,171,215,235,27,
    28,223,46,22,154,139,149,238,98,240,182,158,117,136,175,60,
    99,92,108,7,23,33,23,235,221,22,240,45,18,80,95,64,
    219,200,216,186,219,8,47,124,17,122,32,50,95,68,238,11,
    153,68,16,17,227,222,89,169,184,27,41,59,76,216,215,104,
    231,246,188,236,42,133,29,167,5,165,150,158,212,173,233,109,
    233,11,109,179,204,78,255,183,204,224,133,59,174,229,47,172,
    218,18,56,47,182,6,150,16,241,137,244,19,77,233,227,40,
    173,31,136,40,221,133,229,114,67,249,111,55,55,83,235,126,
    140,98,53,163,238,39,40,48,137,238,167,40,238,221,124,114,
    144,138,159,208,206,246,34,57,89,90,206,201,77,170,143,232,
    155,206,4,7,177,161,9,140,90,162,175,102,52,251,64,209,
    244,185,97,58,153,89,151,62,71,14,86,215,150,62,87,92,
    172,83,123,103,117,125,229,203,197,197,188,211,184,162,226,33,
    39,111,54,110,138,227,251,244,13,244,195,189,60,254,134,211,
    112,118,241,40,28,236,28,108,253,11,155,109,128,2,
};

EmbeddedPython embedded_m5_objects_GarnetNetwork(
    "m5/objects/GarnetNetwork.py",
    "/home/zhouzhiyong/gem5/src/mem/ruby/network/garnet2.0/GarnetNetwork.py",
    "m5.objects.GarnetNetwork",
    data_m5_objects_GarnetNetwork,
    1070,
    2614);

} // anonymous namespace
