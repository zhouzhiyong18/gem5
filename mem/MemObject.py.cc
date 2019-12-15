#include "sim/init.hh"

namespace {

const std::uint8_t data_m5_objects_MemObject[] = {
    120,156,157,80,193,74,196,48,16,157,180,221,69,5,65,111,
    34,136,215,224,161,61,41,30,68,68,241,224,97,21,90,15,
    218,75,104,147,145,174,54,118,105,82,216,61,235,127,175,51,
    169,171,120,53,201,60,50,201,75,222,155,209,240,61,98,138,
    43,10,119,66,96,104,9,104,1,172,128,82,128,48,17,160,
    128,23,1,38,134,79,128,15,128,231,50,2,147,64,33,39,
    68,159,175,105,72,65,59,191,75,112,211,118,250,13,205,67,
    253,138,218,251,109,58,153,161,29,51,189,145,99,242,53,203,
    29,18,32,176,10,137,210,167,24,67,153,176,122,57,129,188,
    144,17,93,231,76,118,251,4,22,109,70,161,186,240,89,218,
    52,114,202,162,91,4,74,189,87,22,149,242,59,33,177,157,
    25,90,78,19,38,172,22,24,54,143,253,128,129,93,213,206,
    247,21,185,99,182,94,46,85,131,149,193,94,178,181,95,112,
    199,4,245,48,111,77,246,116,126,166,102,183,197,29,203,103,
    63,229,164,139,85,48,199,60,199,86,166,130,231,189,228,110,
    250,3,118,124,154,142,102,93,250,167,45,57,108,10,251,135,
    102,40,225,98,44,241,242,136,31,113,155,246,162,47,233,17,
    94,63,
};

EmbeddedPython embedded_m5_objects_MemObject(
    "m5/objects/MemObject.py",
    "/home/zhouzhiyong/gem5/src/mem/MemObject.py",
    "m5.objects.MemObject",
    data_m5_objects_MemObject,
    274,
    461);

} // anonymous namespace
