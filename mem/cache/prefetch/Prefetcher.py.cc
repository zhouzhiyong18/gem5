#include "sim/init.hh"

namespace {

const std::uint8_t data_m5_objects_Prefetcher[] = {
    120,156,197,92,91,140,36,215,89,62,221,51,59,59,215,157,
    203,206,244,236,125,203,246,38,59,118,236,217,139,237,205,38,
    4,59,187,179,54,89,105,47,147,154,181,29,111,8,69,117,
    87,205,116,141,187,187,218,85,213,187,51,150,3,33,137,16,
    151,72,240,136,80,8,72,72,132,39,148,23,46,226,41,18,
    66,130,23,4,47,128,120,0,94,144,252,192,19,111,60,32,
    243,127,255,185,212,233,238,170,158,49,30,139,93,111,185,250,
    175,115,78,157,203,255,127,255,237,156,106,8,245,103,140,254,
    125,149,254,165,47,84,133,8,232,191,138,104,9,241,72,221,
    85,204,93,85,222,85,69,107,76,180,199,197,227,113,81,81,
    79,142,153,50,19,116,55,38,194,227,98,187,34,130,113,241,
    125,33,190,39,196,187,143,39,69,112,76,132,227,76,157,48,
    212,41,17,28,23,225,20,83,39,13,117,90,4,83,154,58,
    109,168,51,34,152,17,225,12,83,103,13,117,86,4,115,154,
    122,194,80,231,68,48,175,169,11,134,122,66,4,139,154,186,
    100,168,243,34,56,41,194,121,166,46,27,234,130,8,86,116,
    127,107,134,186,40,130,85,221,194,41,67,93,18,193,105,17,
    158,100,234,25,67,93,22,193,89,93,246,156,161,174,136,224,
    188,166,94,48,212,154,8,46,138,112,145,169,142,161,174,138,
    224,25,17,46,51,245,89,67,61,37,130,231,116,11,151,12,
    245,180,8,62,167,169,159,55,212,51,34,184,172,169,107,134,
    122,86,4,207,107,234,11,134,122,78,4,95,16,225,36,83,
    95,52,212,243,34,120,73,151,93,55,212,11,34,184,34,182,
    214,174,18,207,68,31,211,159,181,10,221,101,184,188,32,111,
    231,232,178,209,138,27,239,133,193,195,250,110,216,200,152,242,
    181,119,54,55,147,184,30,190,241,36,236,100,13,205,125,168,
    112,27,220,119,134,46,161,16,143,43,224,65,122,213,227,42,
    56,10,55,99,194,221,90,35,222,20,13,176,234,56,253,195,
    143,159,67,165,139,116,249,176,42,62,20,194,163,155,10,223,
    208,117,140,111,170,104,105,139,187,244,96,13,85,51,92,226,
    250,110,54,77,255,239,38,225,118,152,53,154,97,146,29,163,
    159,29,191,29,166,107,104,60,195,37,13,91,219,46,110,92,
    174,56,67,151,86,148,102,15,183,31,112,57,244,156,47,233,
    21,186,212,123,81,43,184,242,141,155,55,188,251,111,108,221,
    189,210,14,219,87,26,62,181,124,69,191,227,202,166,121,217,
    122,119,63,155,164,58,158,23,117,162,204,243,94,70,35,19,
    60,19,83,244,183,81,81,195,195,187,55,240,236,77,12,81,
    136,93,33,146,219,98,239,6,223,87,196,157,111,173,137,111,
    243,120,119,171,98,119,12,11,179,59,174,202,201,159,52,27,
    223,171,138,202,251,39,197,59,29,97,207,196,49,61,42,151,
    239,198,245,248,118,194,108,99,195,90,47,63,8,120,169,120,
    209,120,254,221,9,61,61,152,173,35,152,132,36,220,161,73,
    13,147,155,104,100,82,77,194,66,101,190,34,23,66,206,19,
    222,229,121,188,102,158,215,142,131,94,139,126,186,120,230,206,
    234,30,124,186,190,184,24,220,117,84,198,107,39,42,83,199,
    178,19,96,75,63,13,243,114,134,99,199,52,199,206,85,44,
    142,37,118,13,199,0,138,196,180,143,9,236,38,128,148,223,
    171,240,205,24,110,118,170,226,241,113,136,216,46,193,219,180,
    216,157,1,64,210,10,17,136,129,56,199,196,19,0,74,16,
    231,153,184,0,88,32,196,4,101,73,83,198,0,155,160,156,
    180,40,147,76,89,182,40,83,76,89,177,40,211,76,169,105,
    10,189,110,21,168,10,226,170,245,186,89,166,156,18,59,52,
    168,211,0,88,200,224,25,5,176,128,143,121,190,57,199,5,
    206,43,136,37,80,32,33,93,196,162,204,107,105,46,152,246,
    58,77,233,122,179,233,98,49,179,9,201,100,143,238,221,78,
    159,161,219,173,125,98,133,182,147,53,163,212,201,133,211,169,
    135,173,184,179,147,58,89,156,158,196,204,3,87,156,52,250,
    32,116,162,142,83,223,207,194,52,117,136,254,176,211,218,119,
    58,113,22,109,239,219,181,227,142,211,142,210,148,10,161,71,
    15,138,158,39,161,31,164,233,217,178,199,79,147,8,239,120,
    182,236,121,224,103,190,227,55,26,33,191,229,249,178,98,81,
    39,205,146,94,35,139,232,222,148,254,106,94,58,107,134,78,
    211,79,130,167,126,18,14,84,13,159,132,201,190,170,228,172,
    209,24,157,221,94,154,169,113,61,159,126,142,26,121,43,13,
    157,39,81,146,245,252,150,67,83,154,112,243,206,118,156,152,
    166,162,206,78,163,170,176,165,170,177,101,217,96,11,65,10,
    0,163,194,58,93,35,5,202,101,199,33,119,33,128,32,149,
    43,214,237,134,157,192,194,131,41,224,65,248,84,34,199,17,
    128,130,198,157,183,209,72,149,65,129,81,113,76,253,227,158,
    19,220,139,189,23,84,231,239,124,235,162,6,195,10,35,97,
    21,131,145,247,24,210,251,211,226,157,189,179,252,124,140,10,
    47,136,111,87,161,53,8,48,169,64,229,253,47,138,119,242,
    170,199,152,102,77,2,143,17,72,233,101,173,122,234,98,180,
    238,2,46,139,26,129,178,69,9,101,12,148,247,0,104,157,
    48,73,89,227,200,25,98,21,210,170,115,43,60,147,159,18,
    174,106,84,231,155,168,60,205,179,179,80,57,79,255,78,84,
    120,125,241,46,188,135,213,227,207,227,197,172,10,50,214,6,
    233,5,145,177,90,165,89,249,110,69,116,184,111,31,50,78,
    17,90,189,87,17,201,235,92,96,44,47,240,33,43,22,234,
    250,135,82,193,86,197,15,170,57,159,0,47,31,176,108,248,
    201,78,175,77,67,115,218,224,205,122,232,196,219,206,86,212,
    150,92,225,100,251,221,48,226,241,66,64,186,152,40,86,164,
    178,116,211,127,18,58,126,230,180,66,159,126,197,157,208,9,
    91,33,26,147,147,143,81,70,41,4,200,239,52,66,230,55,
    211,50,255,122,68,173,191,145,36,113,194,51,221,10,59,46,
    24,155,81,221,90,5,92,82,174,167,244,191,238,196,167,228,
    89,224,93,139,87,253,205,36,110,51,19,212,243,197,153,167,
    191,75,244,207,8,159,97,225,235,7,46,142,100,88,232,117,
    75,52,171,60,229,207,20,77,185,63,48,227,82,213,159,198,
    5,232,231,2,227,220,21,92,150,48,98,35,194,238,249,79,
    173,66,217,130,208,234,156,16,29,139,173,204,26,204,192,26,
    12,53,23,86,133,11,205,202,54,4,122,200,55,143,146,94,
    40,37,191,78,24,233,211,162,98,234,26,123,123,94,147,160,
    153,236,51,8,217,230,254,237,168,19,220,15,179,102,28,240,
    203,240,60,220,235,210,162,167,44,88,155,126,226,183,121,145,
    165,34,225,91,34,210,4,49,91,248,157,125,254,127,74,79,
    241,255,187,68,199,210,241,168,188,86,212,9,61,104,21,126,
    119,29,74,70,254,68,7,111,199,113,139,223,241,166,223,74,
    67,70,196,184,227,1,127,245,61,116,8,15,129,238,89,97,
    232,7,208,14,250,30,28,156,45,137,220,244,244,136,40,97,
    61,195,170,244,210,208,83,32,238,25,16,151,48,195,252,12,
    177,119,47,154,53,116,196,209,24,63,152,132,215,80,249,69,
    1,227,135,255,86,167,42,243,213,149,177,149,234,82,69,255,
    157,101,251,116,170,10,243,104,234,248,212,196,68,133,167,239,
    126,175,149,69,163,172,36,180,106,91,73,1,91,244,176,146,
    198,69,120,76,236,78,192,142,128,173,196,246,17,25,17,44,
    177,108,17,130,95,11,186,223,198,43,201,138,96,245,117,43,
    73,252,125,128,77,174,51,211,181,201,62,110,115,33,44,12,
    20,224,153,70,203,79,83,247,146,80,86,239,219,36,44,113,
    194,204,195,51,193,68,187,173,35,152,97,12,166,35,148,137,
    171,103,56,131,18,249,122,47,236,133,193,168,233,251,137,40,
    52,50,5,140,76,76,226,4,188,237,221,73,204,32,96,155,
    38,113,74,83,198,181,49,57,109,81,164,49,57,195,148,89,
    203,152,156,179,40,210,152,60,161,41,243,218,152,92,176,202,
    72,99,114,145,41,75,48,35,149,221,120,18,75,200,83,255,
    21,116,255,92,241,18,190,207,227,166,53,140,160,100,217,128,
    187,231,19,130,54,246,217,104,217,129,6,165,223,65,190,170,
    105,132,66,233,115,96,57,127,47,106,247,218,78,167,215,174,
    195,66,218,118,100,115,86,225,116,227,112,229,200,236,242,181,
    254,97,131,138,204,36,135,48,168,147,182,124,152,106,233,101,
    224,201,251,61,63,109,14,86,102,219,47,108,251,157,64,153,
    102,60,138,59,113,231,114,38,139,146,97,25,244,58,129,79,
    0,109,117,236,5,52,216,137,227,174,195,83,66,102,45,41,
    187,168,29,117,104,184,86,141,36,164,54,210,140,213,229,35,
    127,39,127,235,211,40,107,58,155,27,24,141,154,37,116,89,
    246,64,106,88,31,184,71,172,68,192,231,239,176,30,214,141,
    57,250,15,143,186,225,119,160,52,178,102,18,103,89,139,70,
    22,132,176,236,208,28,13,13,246,40,181,218,35,60,102,241,
    194,239,92,44,214,215,150,135,69,204,133,29,224,98,133,220,
    47,225,2,25,115,49,129,46,48,128,81,176,37,23,153,65,
    150,39,73,130,236,58,184,196,223,243,12,48,234,30,123,24,
    174,167,186,229,89,11,227,66,14,89,49,168,102,120,141,44,
    194,118,212,34,77,228,94,213,34,45,97,62,197,204,115,41,
    154,27,243,58,238,154,154,178,12,160,163,231,196,107,196,157,
    44,137,91,212,3,61,159,71,129,7,144,140,158,150,14,133,
    7,244,23,40,11,140,101,188,173,46,205,76,85,24,35,182,
    178,36,10,70,58,162,127,61,26,98,63,25,70,76,104,68,
    152,177,202,76,106,79,85,82,166,180,252,207,89,101,102,44,
    212,32,247,117,65,35,194,162,85,102,78,187,178,68,57,137,
    232,22,25,219,228,88,74,79,149,128,3,8,236,190,57,2,
    56,82,158,12,0,7,214,44,61,101,137,57,173,213,54,61,
    35,19,145,12,201,39,36,84,28,199,129,225,243,168,73,186,
    180,25,183,130,225,50,194,180,18,117,10,91,97,196,217,202,
    252,132,229,204,122,10,156,34,183,199,33,182,72,34,130,39,
    44,21,155,101,15,12,220,144,173,144,194,75,37,113,109,197,
    241,123,189,174,147,249,245,86,200,64,113,43,77,227,70,68,
    188,252,36,202,88,192,6,11,129,15,225,214,181,125,152,84,
    78,20,56,112,158,3,135,220,99,82,88,251,220,72,254,42,
    27,210,98,131,159,41,172,13,55,236,182,252,6,219,211,78,
    55,110,69,141,253,181,90,129,240,230,34,11,153,113,95,237,
    23,222,73,37,161,152,0,150,167,140,231,84,254,230,135,81,
    71,254,128,104,167,152,175,252,39,15,200,195,108,200,170,252,
    211,199,4,176,24,51,110,112,200,9,22,144,28,175,23,5,
    108,192,5,225,78,18,134,108,30,33,28,99,141,101,147,135,
    194,239,118,9,132,227,182,187,201,198,85,146,23,241,212,112,
    143,64,100,193,147,191,61,32,178,99,19,218,60,170,170,235,
    216,172,20,89,66,236,157,209,106,253,96,171,40,23,86,182,
    138,56,22,233,142,144,140,140,223,9,201,168,106,149,122,16,
    123,20,217,73,69,208,237,62,16,71,99,106,162,255,63,22,
    131,134,16,196,239,46,33,124,66,166,216,253,176,77,204,93,
    48,115,147,122,230,186,149,79,50,115,160,216,48,55,197,148,
    105,4,181,37,210,17,180,133,179,136,201,33,235,64,55,132,
    125,98,44,71,183,99,136,201,145,5,4,156,154,209,70,144,
    105,211,0,156,164,204,105,44,91,210,61,153,71,120,76,197,
    234,100,153,69,100,31,84,172,174,176,39,203,186,39,39,185,
    39,39,117,24,207,238,201,178,142,228,173,138,221,83,200,85,
    224,213,139,200,85,236,140,35,73,129,167,167,173,55,158,98,
    202,25,77,89,65,202,2,148,179,86,153,51,76,57,103,81,
    206,50,229,60,184,15,60,231,110,97,250,63,87,204,125,145,
    90,63,175,205,11,72,108,152,129,13,175,221,96,11,42,103,
    68,133,150,218,162,208,11,237,60,2,38,72,12,125,174,8,
    29,135,11,51,178,160,185,125,182,33,216,144,100,39,141,129,
    69,6,241,137,158,94,146,220,21,238,1,191,37,32,24,123,
    198,207,8,106,58,10,112,47,23,98,101,113,217,211,150,222,
    49,166,89,16,201,8,69,196,110,230,231,251,198,93,143,50,
    51,104,61,87,164,77,122,29,106,148,83,39,175,112,60,160,
    116,162,180,124,56,155,170,31,119,194,140,61,23,169,229,214,
    203,230,172,180,94,122,181,124,94,202,43,189,60,114,142,202,
    59,9,94,136,254,231,227,143,63,102,93,187,213,140,182,51,
    231,137,223,234,73,60,10,113,11,117,117,170,111,10,100,128,
    19,230,56,50,73,252,238,13,57,99,78,102,52,58,85,103,
    109,211,63,179,86,212,51,189,86,86,47,236,96,45,185,34,
    153,21,161,223,182,125,200,91,135,192,79,231,105,51,236,56,
    61,233,52,20,181,178,118,225,64,128,101,54,150,168,183,5,
    83,24,34,208,205,60,169,35,21,19,176,146,123,171,147,70,
    59,157,48,224,212,132,41,33,153,125,73,169,71,189,158,74,
    55,162,228,86,152,229,140,17,186,240,39,24,112,77,11,145,
    170,163,148,165,251,80,203,209,61,247,45,82,169,103,237,178,
    195,186,149,53,115,159,233,174,165,32,131,140,144,235,229,25,
    104,80,236,238,65,22,56,102,26,117,131,129,129,206,247,81,
    229,224,78,247,209,6,186,155,157,235,123,58,220,65,247,203,
    198,134,129,217,159,130,245,60,201,122,60,63,8,180,120,62,
    130,8,94,139,106,245,133,103,12,183,240,140,201,213,53,163,
    200,31,46,153,135,232,151,30,255,81,232,75,32,238,159,160,
    242,237,92,95,42,23,97,162,178,194,119,179,252,107,202,250,
    107,63,185,208,247,44,91,5,67,16,23,249,89,47,9,73,
    72,155,163,20,173,123,36,138,182,207,159,56,134,232,65,48,
    169,227,9,150,126,37,141,43,99,8,228,55,236,206,113,90,
    127,1,57,50,168,192,19,150,150,93,66,170,29,42,112,222,
    82,162,178,39,11,150,166,156,182,20,109,77,191,119,70,40,
    109,186,170,41,203,208,133,50,219,85,220,147,85,221,147,26,
    247,164,102,105,86,211,147,85,75,185,158,133,174,85,202,245,
    156,166,156,25,86,165,109,76,240,165,98,85,154,234,5,242,
    72,231,52,97,208,177,62,185,57,172,79,128,125,12,165,140,
    67,13,191,213,232,181,84,60,128,93,19,211,82,196,172,127,
    129,87,255,131,80,195,181,121,252,34,167,210,32,149,80,38,
    215,174,94,127,133,195,94,165,202,200,84,148,218,80,26,156,
    151,202,84,208,64,105,247,45,72,44,84,158,139,12,143,251,
    142,86,150,37,202,104,160,58,71,68,202,85,80,81,233,98,
    45,156,162,152,175,188,58,22,105,57,252,87,174,126,233,198,
    128,242,30,24,126,191,41,240,108,217,184,251,138,229,106,218,
    114,15,217,151,77,29,248,115,228,216,209,26,132,196,9,166,
    30,219,54,159,137,249,178,35,37,253,223,95,231,113,22,120,
    190,196,88,164,123,123,86,196,39,85,117,62,122,61,253,114,
    105,29,68,75,162,14,85,11,247,186,45,210,250,212,99,184,
    180,62,194,248,122,18,15,163,18,161,125,222,186,219,201,110,
    178,62,200,229,129,153,157,221,66,60,189,118,131,1,60,127,
    140,213,117,223,69,3,171,125,244,62,21,227,34,113,198,90,
    107,176,128,116,72,191,133,94,252,2,46,172,42,47,22,20,
    44,210,152,238,47,162,244,179,5,165,11,116,230,130,210,140,
    125,10,17,93,82,171,52,160,20,79,14,61,201,21,163,226,
    33,4,168,60,93,134,25,39,59,63,84,107,80,117,58,67,
    37,10,250,202,105,143,86,76,197,206,219,170,49,95,120,75,
    17,98,105,205,130,23,22,57,10,165,8,236,252,7,161,118,
    198,228,249,138,169,50,37,120,136,103,60,149,37,138,241,237,
    235,195,170,241,119,68,185,106,36,85,132,208,252,24,194,110,
    164,14,73,53,226,158,119,192,97,199,219,4,66,109,184,206,
    176,147,55,167,60,63,21,58,155,213,161,179,41,212,34,85,
    20,46,242,166,144,25,117,3,37,52,171,93,204,89,43,134,
    54,151,199,208,88,172,126,5,221,188,124,24,5,227,61,185,
    14,111,13,58,230,250,171,55,164,27,133,31,175,94,187,206,
    160,165,4,255,239,95,103,55,229,38,71,46,10,161,113,167,
    21,215,253,150,142,79,57,58,25,200,120,111,65,253,122,57,
    160,149,180,192,22,124,57,180,149,212,58,32,200,149,225,130,
    32,172,187,143,203,7,184,236,225,242,203,184,124,71,99,145,
    196,19,160,128,124,141,167,94,227,233,215,24,92,25,0,142,
    203,35,170,148,3,200,11,35,106,125,54,129,45,48,202,127,
    107,21,172,165,41,143,73,107,217,154,208,249,63,186,99,107,
    248,22,103,28,238,251,93,229,235,221,247,213,38,147,33,97,
    249,230,129,118,164,137,78,131,135,39,181,73,55,166,55,72,
    77,105,202,49,157,190,154,102,202,140,37,59,179,154,98,135,
    166,101,45,147,154,58,193,20,41,95,28,170,193,54,209,227,
    44,95,50,179,53,199,242,181,88,100,110,218,49,155,21,216,
    145,121,12,70,82,86,132,178,14,87,53,101,85,199,93,78,
    89,181,78,91,22,228,138,101,26,158,209,148,115,216,34,154,
    199,102,206,97,163,104,112,81,153,143,160,92,192,38,209,224,
    25,166,92,132,188,115,214,229,215,48,211,215,138,229,93,38,
    135,188,182,223,53,42,162,173,86,11,89,212,47,82,173,13,
    212,64,14,92,238,172,234,33,208,92,223,31,72,250,24,79,
    55,34,121,231,93,6,50,124,254,179,116,185,23,181,163,76,
    59,193,108,213,80,13,184,237,14,2,218,177,243,210,55,174,
    124,131,204,204,109,231,234,139,136,147,24,199,27,169,175,76,
    26,71,55,24,24,232,23,9,179,12,251,58,107,195,41,60,
    203,19,55,89,66,9,94,239,221,230,208,168,244,165,201,22,
    121,18,38,114,20,190,211,140,51,231,131,184,19,186,223,21,
    106,11,202,48,130,69,38,231,133,109,86,52,89,202,112,3,
    31,115,212,171,208,200,27,44,94,104,221,94,46,135,188,193,
    250,156,31,44,199,186,193,226,6,156,83,100,240,111,229,177,
    40,30,62,210,127,219,62,2,48,100,249,238,236,112,252,195,
    239,200,5,164,255,72,65,167,180,84,9,39,21,118,154,170,
    173,159,30,216,86,218,246,91,173,17,141,181,226,167,185,133,
    57,208,150,73,41,30,190,95,7,53,113,248,238,252,231,235,
    233,171,220,150,76,189,54,137,99,225,1,196,159,96,118,62,
    42,107,226,16,189,136,196,71,99,130,67,135,27,251,141,150,
    100,57,42,28,118,99,88,253,97,18,197,1,123,32,47,95,
    237,164,233,87,114,86,86,73,83,41,149,108,102,183,187,189,
    76,202,15,18,165,17,218,151,113,87,167,238,119,130,167,81,
    144,53,215,156,145,234,143,117,219,55,181,182,114,161,148,57,
    62,194,242,232,73,25,150,1,19,78,229,72,121,148,202,16,
    109,146,64,121,16,40,153,190,133,62,176,64,166,223,122,173,
    21,61,28,176,181,217,20,29,42,84,174,38,159,43,42,94,
    16,251,249,37,161,156,1,172,160,167,249,216,178,88,209,57,
    90,153,162,71,166,154,230,183,130,106,5,143,78,153,183,113,
    194,153,24,100,160,77,126,93,193,179,9,195,23,60,239,204,
    21,94,67,18,144,235,84,251,35,248,221,241,246,54,193,119,
    87,5,219,61,197,32,71,97,14,64,143,44,84,6,140,107,
    219,136,94,42,50,163,75,255,162,52,123,105,183,238,111,222,
    31,149,15,67,95,15,48,18,38,88,17,15,110,20,250,225,
    255,93,241,61,107,204,24,135,236,24,19,180,214,150,140,210,
    113,135,73,146,97,214,88,116,253,118,183,125,20,203,128,81,
    125,177,162,54,17,106,75,108,182,194,114,114,39,108,101,254,
    70,156,36,161,12,246,80,205,32,226,141,197,156,23,73,135,
    45,176,63,59,112,114,7,35,121,19,86,36,207,24,100,38,
    146,103,98,123,38,146,55,163,203,76,235,52,153,52,200,200,
    8,59,1,243,75,218,91,225,60,71,221,230,249,70,198,246,
    22,172,156,26,153,92,75,188,198,139,249,78,34,78,96,255,
    8,131,248,82,241,26,7,152,13,146,95,51,29,136,68,171,
    249,144,192,144,34,132,134,237,42,233,23,132,173,248,185,230,
    80,244,133,171,200,216,139,140,154,241,73,0,196,141,8,161,
    101,29,105,18,96,113,239,197,79,177,67,93,197,226,218,126,
    250,158,10,197,17,66,251,28,255,144,47,97,3,229,218,245,
    155,28,130,43,53,61,164,189,241,29,161,118,45,20,218,27,
    229,70,6,108,159,18,35,67,78,3,239,28,44,181,44,184,
    76,225,174,158,2,165,193,17,12,57,52,142,60,200,136,195,
    180,38,202,128,198,188,249,137,137,177,162,51,104,191,63,38,
    115,15,13,15,56,80,43,166,84,185,30,56,101,202,124,54,
    206,17,24,239,181,138,10,110,246,199,223,139,3,10,140,117,
    119,54,54,31,125,38,88,247,71,159,90,14,216,188,100,0,
    113,44,4,113,114,8,145,185,213,244,19,96,223,143,52,246,
    5,141,110,118,20,147,142,81,34,247,144,206,10,123,119,20,
    249,157,224,224,187,212,235,157,94,203,79,182,56,227,114,187,
    183,189,29,38,71,187,95,224,48,224,55,97,129,159,241,70,
    15,4,191,105,13,126,179,7,131,159,122,203,146,78,90,44,
    91,239,93,182,82,29,242,189,43,150,55,58,252,222,21,253,
    94,59,141,177,218,255,222,85,203,87,61,176,133,83,150,27,
    107,90,56,173,60,89,98,87,222,110,254,199,152,254,151,138,
    217,53,210,203,232,169,180,90,157,23,210,108,95,233,207,63,
    216,113,123,43,228,172,226,167,17,14,17,114,62,123,216,93,
    204,15,195,192,216,118,178,176,221,141,19,114,48,85,190,142,
    29,79,71,28,156,234,149,176,92,26,235,207,18,63,234,64,
    146,122,228,192,186,191,47,134,242,255,3,41,132,254,242,69,
    112,62,34,238,223,87,249,128,184,127,95,89,185,191,226,70,
    225,112,177,29,52,136,2,100,225,45,149,232,59,91,155,47,
    221,186,191,161,146,17,23,203,198,191,185,117,101,107,211,161,
    130,41,111,223,40,223,239,145,151,123,189,124,128,155,205,253,
    52,106,248,173,151,178,248,165,45,62,53,213,195,154,221,146,
    107,201,198,26,7,44,56,45,90,62,246,67,55,51,162,43,
    121,61,180,162,91,180,218,136,15,213,149,3,155,81,93,89,
    59,123,56,5,204,161,74,121,76,162,217,235,200,163,10,188,
    75,139,147,5,122,209,61,44,186,242,181,222,53,58,181,239,
    97,73,244,242,252,80,193,114,37,236,12,149,45,72,35,244,
    39,15,12,171,89,214,3,124,35,37,173,108,177,75,31,41,
    207,116,12,63,211,30,38,166,166,155,122,195,5,6,19,30,
    151,203,10,22,116,248,18,235,142,67,54,90,88,240,179,49,
    73,0,170,143,129,119,155,98,56,251,81,232,156,85,251,77,
    149,60,142,59,49,244,155,119,83,108,181,162,246,129,209,93,
    115,108,123,121,208,152,169,88,7,182,229,190,31,128,172,220,
    191,152,51,246,15,112,249,77,113,52,219,10,255,148,234,252,
    106,197,28,223,165,113,92,82,227,56,180,175,84,124,12,221,
    140,7,73,157,113,99,135,33,138,200,74,39,194,161,18,121,
    202,42,31,218,31,226,194,22,237,31,28,209,248,224,191,253,
    70,69,29,168,82,182,208,146,94,169,3,28,235,59,131,227,
    41,138,190,231,198,166,180,119,248,132,50,136,99,202,187,211,
    27,80,255,28,77,66,11,20,165,149,168,55,30,28,224,195,
    251,214,159,212,28,157,61,24,29,225,138,51,67,184,191,39,
    148,117,202,243,231,254,248,136,22,3,83,240,91,88,140,5,
    209,23,33,145,203,130,206,221,126,184,57,106,69,254,238,192,
    21,57,26,131,212,246,198,141,127,62,171,83,133,182,137,122,
    66,31,57,55,148,121,203,50,157,64,122,100,32,43,146,155,
    165,236,165,179,219,248,23,24,220,233,98,222,168,199,93,152,
    118,156,77,199,90,145,161,182,238,164,228,173,240,190,129,94,
    23,202,128,21,101,61,196,9,208,237,237,52,204,162,160,175,
    116,66,198,94,48,162,52,239,59,7,219,109,113,179,62,118,
    197,68,112,232,169,220,215,222,217,68,56,86,37,30,130,232,
    171,98,104,175,190,101,168,112,28,192,117,17,75,125,79,198,
    0,0,10,28,3,208,33,88,182,144,148,223,188,19,33,122,
    202,41,130,82,215,94,246,49,117,112,78,52,253,169,48,137,
    14,36,91,6,159,59,126,43,141,229,57,159,78,184,195,219,
    246,244,94,201,193,63,107,209,122,184,158,187,239,84,169,213,
    146,167,153,154,126,107,91,27,31,186,47,220,100,55,78,35,
    110,114,240,143,238,2,14,52,113,151,50,164,124,184,157,254,
    190,196,29,156,58,71,24,242,141,124,3,37,185,159,254,190,
    60,247,20,205,235,117,43,157,14,187,52,31,19,251,186,48,
    65,113,154,93,249,216,151,71,239,117,157,86,184,157,97,85,
    228,72,183,147,184,109,53,53,248,135,155,62,116,52,3,40,
    206,204,72,218,123,143,127,49,179,153,95,117,63,240,248,57,
    7,98,147,68,70,189,225,97,226,20,17,7,59,0,6,114,
    6,61,172,161,52,200,242,195,13,48,110,244,4,122,106,166,
    61,185,255,148,145,156,71,225,201,147,75,138,188,48,64,230,
    22,177,241,96,168,130,12,18,31,5,182,65,132,127,183,162,
    228,200,62,150,180,100,14,39,77,141,25,51,163,202,33,158,
    173,219,15,31,190,49,10,239,234,159,9,222,245,71,31,9,
    131,32,255,238,95,137,242,99,163,105,61,142,249,228,144,131,
    66,231,153,127,251,184,82,231,89,164,43,202,186,125,192,55,
    76,113,44,173,195,25,74,107,171,112,132,143,181,48,70,216,
    187,235,148,65,168,91,227,205,58,56,154,119,63,234,172,247,
    239,67,150,91,173,124,195,188,186,233,117,231,81,83,137,62,
    208,139,147,177,125,231,250,82,146,213,122,188,103,164,11,224,
    152,134,135,209,146,188,31,22,174,130,26,179,114,191,37,99,
    67,180,243,145,122,214,72,229,126,44,249,86,227,58,220,209,
    109,73,17,50,67,243,186,141,35,137,7,97,77,127,50,160,
    112,13,67,74,22,124,20,222,223,26,21,3,58,119,4,49,
    160,41,139,5,117,196,39,212,187,89,177,83,103,142,153,114,
    134,111,38,173,157,58,214,182,131,124,167,206,162,126,139,81,
    182,75,250,45,11,253,49,160,225,183,156,212,111,89,226,183,
    216,91,19,204,91,236,99,35,83,214,70,215,154,166,212,116,
    196,103,21,194,131,64,170,251,55,66,69,7,138,132,167,139,
    44,167,167,227,39,58,243,100,182,61,227,163,46,191,46,84,
    24,122,84,10,158,143,133,220,120,133,195,53,35,146,240,172,
    105,244,1,215,88,111,162,100,189,13,222,45,201,197,23,214,
    42,12,175,140,216,133,84,210,204,1,187,144,74,106,241,254,
    185,107,55,94,190,249,10,243,126,233,136,245,254,76,41,119,
    13,157,12,192,135,217,56,109,49,114,135,105,127,37,14,185,
    29,176,101,116,160,198,213,145,67,43,235,155,168,202,204,91,
    105,180,199,13,119,48,17,247,9,224,156,135,73,64,101,100,
    184,86,6,236,250,161,53,9,145,44,55,159,200,209,187,69,
    79,29,140,101,239,26,252,1,143,18,111,38,252,90,137,101,
    176,56,229,210,120,249,210,20,237,8,61,63,162,96,225,206,
    208,203,35,42,140,222,224,85,86,171,32,10,129,124,145,78,
    93,234,233,31,200,175,159,43,47,34,131,39,159,47,47,48,
    24,203,120,190,188,104,65,231,176,128,106,174,113,84,199,139,
    177,196,90,147,216,233,255,254,181,213,143,142,66,55,0,178,
    254,18,204,244,154,40,222,11,106,199,55,230,171,163,168,28,
    100,234,251,70,157,75,94,5,225,215,93,234,122,65,160,96,
    81,12,125,175,206,149,223,12,250,255,249,134,27,127,153,72,
    71,202,242,15,183,217,131,176,190,248,50,243,233,231,30,102,
    198,191,85,196,192,135,219,198,250,5,246,168,190,208,246,143,
    84,231,95,241,178,42,47,52,251,217,155,119,223,28,165,244,
    255,75,140,84,250,242,243,108,59,246,39,52,236,29,135,146,
    98,239,56,52,101,6,142,199,27,51,212,28,143,55,110,247,
    156,222,95,104,220,238,121,93,198,118,178,143,171,36,138,84,
    253,1,111,58,220,93,224,47,83,158,132,78,135,150,95,214,
    90,254,56,146,49,97,141,181,252,138,210,224,242,35,149,143,
    79,129,3,225,106,184,255,44,202,125,241,110,180,13,109,253,
    79,66,197,231,248,96,93,95,66,160,17,242,87,32,250,114,
    39,188,181,79,2,172,35,133,94,166,193,95,233,171,156,246,
    234,202,114,60,168,54,167,194,7,12,112,88,23,235,50,121,
    206,167,6,249,136,255,210,112,185,173,91,183,101,42,163,192,
    136,215,219,128,37,12,185,127,43,212,193,151,82,205,43,49,
    144,45,139,210,172,59,151,249,164,89,119,174,116,64,214,157,
    203,52,244,167,161,142,105,188,248,25,113,184,79,67,101,227,
    234,179,92,96,230,177,252,27,81,16,194,195,126,150,139,83,
    214,54,74,108,110,20,126,55,138,157,105,136,225,209,126,55,
    10,157,28,248,122,150,213,25,165,50,82,76,143,253,57,169,
    211,98,148,89,128,80,140,11,181,103,249,248,124,230,145,88,
    219,27,176,18,216,123,231,227,125,189,70,241,67,0,189,225,
    73,163,215,48,116,149,186,212,161,255,1,205,7,147,68,111,
    226,182,220,171,124,15,4,47,190,41,62,99,40,133,230,198,
    138,121,60,122,59,132,44,83,176,23,238,95,142,8,137,1,
    45,255,81,17,253,159,139,154,31,203,83,16,248,18,66,81,
    26,226,1,127,4,140,55,183,181,95,93,239,255,130,27,17,
    186,248,4,147,60,234,138,95,73,188,183,207,3,162,31,42,
    88,188,222,247,77,89,151,79,42,156,237,47,209,119,0,22,
    179,122,161,255,249,224,247,35,80,4,108,37,159,243,23,227,
    248,43,80,252,201,38,254,78,11,127,249,129,63,92,192,167,
    49,249,244,9,111,154,151,145,230,31,26,33,225,72,51,239,
    93,64,138,70,134,160,57,240,140,128,49,71,86,216,147,101,
    147,133,229,136,103,242,8,86,132,167,236,43,242,195,168,175,
    193,190,100,31,110,186,66,127,171,11,124,173,205,214,174,214,
    142,215,206,214,86,233,250,92,109,141,254,127,153,238,150,107,
    147,181,23,107,227,181,99,181,153,90,173,54,93,187,84,59,
    254,191,64,33,136,124,
};

EmbeddedPython embedded_m5_objects_Prefetcher(
    "m5/objects/Prefetcher.py",
    "/home/zhouzhiyong/gem5/src/mem/cache/prefetch/Prefetcher.py",
    "m5.objects.Prefetcher",
    data_m5_objects_Prefetcher,
    6902,
    23061);

} // anonymous namespace
