const uint8_t arr_input_image[3072] =  { 154,177,187,126,137,136,105,104, 95,102,101, 99,125,131,139,155,166,180,172,190,210,180,199,214,142,156,156,111,120,110,106,107, 98,109,104,102,123,121,117,127,129,127,181,188,189,217,226,229,209,211,211,166,167,162,164,165,156,158,160,148,116,117,103,102,101, 83, 95, 95, 76, 90, 89, 79, 72, 70, 69, 60, 60, 61, 56, 57, 54, 77, 78, 72, 94, 96, 84, 91, 95, 71, 87, 90, 71, 79, 81, 70,140,160,169,145,153,154,125,125,118,124,129,132,150,161,173,152,164,175,174,188,200,178,189,196,134,139,137,110,111,102,133,127,120,163,156,156,192,192,187,218,219,215,240,241,238,245,246,245,241,242,239,238,239,235,234,235,229,226,227,220,142,143,136, 96, 97, 85, 99,101, 84, 95, 96, 87, 89, 89, 86, 80, 81, 77, 65, 67, 60, 84, 86, 76, 92, 95, 80, 96, 99, 78, 77, 80, 62, 71, 73, 61,140,155,164,139,146,149,115,115,112,147,153,159,138,150,162,132,145,154,170,184,190,178,189,192,171,176,175,192,195,189,219,218,217,234,233,238,229,237,235,239,245,242,244,244,242,246,242,241,232,231,227,225,226,222,235,235,232,243,243,242,177,177,178,101,102, 97,101,103, 92, 88, 89, 82,103,103, 99, 94, 95, 86, 65, 67, 54, 83, 86, 70, 90, 93, 75, 79, 82, 64, 68, 70, 55, 67, 69, 55,136,147,155,137,142,146,122,121,121,132,133,139,151,157,167,181,193,198,203,222,224,208,227,230,208,223,225,203,219,217,179,194,198,169,184,196,164,186,190,125,141,143,178,182,185,240,236,238,231,230,226,211,212,207,195,195,196,201,200,204,183,183,192,121,123,124, 91, 94, 87, 94, 97, 92, 91, 94, 88, 77, 80, 66, 69, 72, 55, 97,100, 80, 88, 91, 70, 76, 78, 64, 64, 66, 53, 71, 73, 59,129,137,144,141,146,152,136,139,142,186,186,190,215,220,227,202,216,223,164,188,195,150,178,185,138,162,169,119,146,150, 94,122,133,108,137,154,108,139,147, 32, 52, 60,130,138,145,241,239,245,236,235,233,235,236,233,211,211,213,195,194,200,133,134,146,125,128,131,102,107,101, 98,104,100, 88, 92, 84, 80, 82, 66, 90, 93, 73, 94, 97, 74, 69, 73, 50, 71, 73, 60, 68, 70, 57, 87, 89, 74,136,144,149,136,149,165,127,148,164,153,172,181,138,160,173,120,141,161, 93,115,138, 98,118,139,103,120,137, 96,116,131, 86,108,125,119,143,158, 97,119,123, 46, 59, 66,117,122,131,203,206,212,228,231,232,233,236,236,236,240,237,237,240,237,165,170,171,126,125,117,124,132,122, 92,102,102, 88, 87, 82, 78, 76, 64, 87, 86, 70, 98, 99, 77, 76, 77, 55, 67, 69, 57, 81, 83, 71, 91, 93, 81,146,154,172,124,138,168, 88,109,139, 85,105,120, 87,110,124, 84,103,119, 75, 90,108, 78, 92,106, 69, 85, 92, 53, 72, 78, 40, 61, 66, 54, 80, 84, 65, 89, 97, 85, 94,105,117,118,125,144,145,148,175,178,181,213,217,219,232,236,234,239,244,238,180,184,178,128,121,102,115,118,104, 83, 92, 95, 74, 71, 69, 71, 68, 56, 86, 85, 69, 86, 85, 64, 90, 90, 69, 83, 85, 72, 77, 79, 67, 81, 83, 71,162,172,192,110,125,154, 63, 77,106, 73, 82, 99, 58, 71, 82, 46, 57, 60, 47, 55, 58, 31, 42, 46, 15, 33, 38, 19, 40, 43, 39, 63, 65, 63, 93, 99, 92,125,146,121,133,149, 88, 86, 92,120,119,119,139,142,145,154,158,162,199,203,203,235,240,237,209,209,199,192,177,151,146,137,121,108,110,112,101, 97, 93, 99, 97, 83, 97, 96, 79, 73, 72, 53, 79, 79, 60, 94, 96, 82, 83, 85, 71, 74, 76, 62,127,137,138, 70, 90,102, 37, 52, 67, 34, 39, 56, 47, 54, 67, 85, 91, 92,129,132,136,104,111,127, 73, 90,116, 94,114,139,125,149,172,138,168,194,115,151,183,120,131,150, 58, 55, 62, 67, 70, 73,108,112,119,177,180,186,188,191,194,233,237,237,208,203,193,149,121, 94,183,160,142,169,164,158,113,110, 96, 89, 87, 69, 84, 82, 65, 65, 63, 47, 56, 55, 40, 88, 91, 76, 81, 84, 69, 63, 66, 51,71, 75, 69, 74, 98,108, 72, 93,112, 81, 87,110,122,129,147,161,167,175,158,159,178,128,134,169, 93,111,149, 98,119,157,128,152,188,133,164,201,104,138,176,119,125,146, 54, 52, 61, 37, 48, 56, 75, 82, 92,192,194,203,226,229,235,232,237,239,199,187,183,109, 66, 46,148,112, 92,192,183,164,158,156,130,104,104, 82, 69, 68, 50, 75, 73, 59, 80, 79, 66, 88, 91, 73, 67, 70, 52, 56, 59, 41,49, 46, 49, 98,122,144,105,129,165,123,132,165,148,158,179,143,151,166,114,115,148,108,113,155, 95,112,146,101,123,155,125,151,181,128,160,192,101,131,167,118,122,144, 66, 67, 81, 35, 55, 70, 77, 88,103,190,193,202,226,229,234,232,235,239,211,195,197,141, 92, 75,156,115, 91,194,183,152,203,200,163,174,172,146, 96, 95, 76, 72, 70, 59,102,101, 92, 99,102, 84, 93, 96, 77, 79, 82, 63,59, 58, 67,103,121,144, 89,113,143,112,131,159,138,154,177,130,143,166,123,132,161,121,130,162,108,122,152,107,127,155,117,146,171,125,160,185,103,132,161,116,124,148, 78, 86,107, 41, 66, 89, 80, 97,120,189,199,205,224,230,224,233,232,235,213,198,201,146,103, 81,165,127, 97,190,176,139,184,173,129,193,183,150,175,169,147,123,122,115,111,113,109,103,106, 88, 92, 93, 75, 95, 95, 79,84, 88,100,104,123,146, 81,105,132, 89,117,147,118,147,179,113,139,172,114,137,171,105,125,159,100,121,154,104,131,162,113,149,178,135,174,199,125,151,169,124,133,152, 72, 81,103, 42, 64, 91, 89,106,129,191,202,205,222,229,220,230,229,232,215,203,204,145,106, 83,153,116, 84,191,174,137,191,175,131,179,162,127,184,172,145,185,179,161,146,144,130,102,102, 85, 80, 79, 64, 86, 84, 72, 83, 89,103, 99,118,142, 71, 92,119, 88,114,141,105,133,161, 99,125,154, 89,111,141, 94,112,141,107,123,148,128,148,172,142,167,189,163,190,208,160,178,184,151,158,165,106,112,129, 65, 78,104, 89,101,119,188,198,199,220,227,221,227,229,230,216,208,207,161,124,100,159,121, 90,188,169,133,203,184,140,197,176,139,181,163,129,180,167,133,194,185,154,162,157,137, 86, 81, 67, 65, 61, 52,83, 85, 97,103,116,136, 86,100,119,117,129,142,157,167,177,169,175,186,172,176,188,161,162,172,153,152,157,162,163,167,201,204,207,230,235,236,232,240,239,220,224,223,180,183,190,145,150,168,159,168,176,206,215,213,224,231,227,225,230,230,215,211,207,169,135,110,165,127, 96,190,168,133,208,186,142,195,176,135,200,183,141,188,173,131,183,169,130,189,178,151,166,158,137, 86, 83, 69,146,142,148,180,184,195,154,157,168,181,183,186,219,220,221,243,241,243,246,240,244,233,227,228,226,222,218,227,224,219,239,235,230,251,247,244,254,253,253,237,238,233,171,172,169,195,194,199,227,232,231,222,230,226,223,231,229,220,228,226,214,214,208,172,140,114,164,127, 95,188,163,129,210,190,144,196,184,136,200,188,143,181,168,126,185,171,131,186,172,135,187,178,147,146,144,122,197,188,188,240,237,242,231,228,230,242,243,244,240,243,244,242,244,245,248,247,250,251,251,252,250,253,252,252,253,252,250,251,250,247,246,246,251,248,248,230,231,224,206,208,199,215,214,210,218,221,216,217,223,220,217,224,224,216,225,223,212,213,207,169,141,115,162,125, 94,182,154,120,207,188,140,198,188,137,202,188,145,168,149,116,137,116, 87,196,176,136,186,173,134,156,152,123,206,199,199,252,245,249,251,247,246,251,251,249,249,250,249,250,251,250,252,252,251,250,251,250,248,248,248,248,247,247,249,249,249,243,246,244,249,249,246,229,232,226,218,224,217,214,221,215,215,219,219,215,219,221,214,219,221,216,221,222,212,210,208,166,145,120,161,125, 93,182,150,114,208,186,137,205,184,140,210,181,147,179,141,119,136, 93, 78,175,142,113,203,181,141,166,154,122,219,214,217,251,248,254,241,241,243,240,240,239,233,233,233,222,221,222,216,216,216,209,209,211,205,205,209,200,200,204,195,195,198,185,185,188,175,174,175,171,172,173,184,190,188,197,205,204,213,218,224,221,224,230,218,222,224,218,223,220,214,210,204,179,158,128,160,123, 87,174,141,102,206,184,131,206,184,137,208,178,140,193,154,126,167,123,101,166,132,102,202,179,137,181,167,133,139,136,144,136,141,156,119,124,133,107,109,113,109,108,113,102,101,107, 79, 78, 84, 76, 76, 83, 94, 97,105,111,117,124,118,120,128,107,102,112, 69, 65, 71, 55, 53, 59, 84, 86, 90, 87, 91, 95,101,104,114,134,137,144,162,166,168,195,200,195,213,207,196,192,166,133,177,138,101,177,144,105,201,181,127,204,185,133,209,185,138,216,186,146,201,168,133,196,167,130,205,185,137,199,185,147,70, 71, 86, 86, 99,125, 85, 96,113, 36, 38, 48, 67, 66, 76, 87, 85, 95, 52, 50, 60, 48, 48, 57, 86, 94, 99,105,119,122, 88, 92, 99,155,146,156,155,148,155,145,141,147,147,146,151,114,116,120, 76, 79, 85, 56, 60, 65, 72, 75, 77,155,159,158,214,202,196,198,165,135,205,163,130,199,166,133,202,183,134,202,184,133,204,184,135,211,189,143,208,184,141,210,186,143,208,189,137,204,189,147,155,160,180,162,182,217,152,169,193, 48, 51, 66, 92, 90,105, 94, 92,107, 61, 58, 74, 55, 56, 65,124,138,136,141,163,158,131,139,139,231,219,224,241,232,233,230,225,225,228,226,225,224,225,223,216,221,215,194,199,197,163,166,171,173,176,185,190,174,177,158,122, 98,160,114, 90,126, 90, 68,180,160,120,211,192,146,206,189,142,213,197,149,211,194,146,212,192,142,210,193,134,210,194,145,162,166,182,124,142,173,110,127,149, 47, 50, 65, 87, 84, 99, 75, 72, 88, 62, 59, 75, 63, 63, 70,119,128,123,126,142,135,103,109,106,158,148,151,141,135,138,126,123,123,139,137,137,154,154,155,165,168,162,137,140,136,159,160,163,181,180,193,129,105,112,111, 68, 52,108, 62, 47, 72, 38, 24, 98, 79, 55,135,120, 92,150,134,102,165,151,117,174,161,125,189,172,130,194,180,133,204,190,152,149,147,158, 58, 63, 83, 29, 39, 55, 31, 34, 46, 41, 38, 51, 41, 39, 52, 37, 35, 48, 37, 36, 46, 50, 52, 57, 56, 57, 64,104,106,114,152,154,164,127,128,141, 92, 93,101, 73, 74, 82, 67, 66, 80, 41, 42, 48,  8, 10,  7, 60, 59, 58,170,166,172, 75, 49, 55, 71, 34, 33, 57, 27, 26, 48, 27, 23, 38, 27, 26, 37, 28, 30, 48, 32, 25, 53, 38, 28, 56, 45, 35, 69, 56, 40, 97, 87, 72,176,170,160,174,170,183, 95, 95,116, 57, 63, 81, 61, 65, 79, 64, 66, 80, 66, 69, 82, 65, 67, 81, 71, 75, 92, 71, 80,100, 97,106,127,168,177,198,181,187,208,167,162,181, 85, 84, 94, 35, 38, 47, 59, 65, 79, 33, 41, 50, 11, 19, 17, 16, 21, 18,128,128,134, 85, 81, 96, 59, 55, 72, 74, 71, 89, 79, 77, 95, 89, 89,104, 71, 65, 73, 52, 38, 37, 32, 18, 14, 24, 15, 13, 19, 13, 14, 44, 40, 44,155,154,161,156,149,165,151,150,174,153,158,179,160,165,182,164,168,184,166,170,186,164,169,184,167,169,187,162,163,184,153,157,174,149,149,165,150,141,160,132,121,142, 51, 48, 59,  9, 16, 23, 47, 60, 73, 33, 48, 58, 12, 25, 27, 10, 21, 20, 59, 65, 74, 90,100,119, 88, 99,123, 96,101,127,106,106,134, 99, 98,121, 55, 51, 61, 64, 51, 51, 49, 37, 33, 25, 20, 21, 39, 40, 53, 34, 35, 51, 89, 91,107,167,159,172,148,145,166,102,104,123,124,126,140,147,148,160,142,143,155,125,126,139,125,118,131,129,116,126,156,149,152,182,166,165,155,128,135,121,109,128, 73, 71, 83, 61, 67, 75, 64, 75, 89, 37, 51, 65, 37, 50, 57, 13, 24, 29, 39, 46, 59, 84, 91,108, 85, 90,107, 84, 83,102, 96, 87,109, 91, 85,106, 62, 60, 72, 71, 61, 62, 43, 32, 30, 25, 22, 26, 62, 67, 85, 56, 60, 79, 88, 90,107,174,164,170,141,137,150, 44, 46, 56, 43, 41, 48, 57, 51, 57, 52, 46, 53, 44, 37, 44, 48, 37, 46, 79, 69, 75,173,172,168,217,202,194,166,137,137, 97, 92,108, 79, 80, 90, 96, 99,107, 75, 78, 95, 82, 90,109,125,135,148, 37, 43, 54, 43, 46, 65, 79, 80,100, 73, 74, 92, 72, 70, 89, 84, 78, 98, 87, 85,105, 94, 93,106, 72, 64, 67, 43, 34, 33, 34, 33, 37,103,108,123, 95, 98,111,124,123,133,164,155,160,141,139,152,115,119,132,113,113,121,116,108,117,114,105,115,113,108,118,116,112,124,124,123,134,149,156,159,160,156,156,142,128,133, 98,100,116, 40, 44, 56, 21, 23, 35, 55, 56, 74,108,114,132,119,126,140, 46, 49, 61, 45, 44, 60, 69, 71, 92, 71, 74, 96, 69, 71, 92, 75, 76, 96, 79, 82,101,118,121,135, 86, 81, 87, 85, 78, 78, 31, 27, 29, 77, 77, 84, 68, 66, 73, 94, 88, 94,175,167,166,156,154,160,154,160,170,147,153,163,155,153,165,161,154,171,160,163,180,167,173,186,165,165,174,152,152,160,163,162,170,164,163,172,133,138,152, 61, 67, 81, 40, 45, 59, 60, 66, 81, 81, 89,102,100,109,119, 65, 69, 78, 59, 60, 67, 62, 64, 77, 51, 53, 69, 44, 43, 57, 39, 36, 47, 43, 44, 57,102,108,122, 55, 56, 64, 32, 26, 29, 23, 14, 14, 42, 34, 36, 61, 53, 57, 93, 83, 91,165,154,128,156,152,130,159,161,142,131,130,127, 94, 88, 95,102, 92,104,108,107,120,128,129,137,154,149,152,156,151,154,182,177,179,179,175,179,125,129,135, 83, 89, 95, 88, 93, 99, 63, 69, 75, 43, 51, 61, 75, 83, 94, 58, 62, 71, 45, 47, 52, 35, 37, 44, 21, 22, 30, 14, 12, 18, 11,  6,  9, 14, 13, 20, 59, 64, 77, 49, 49, 58, 54, 48, 52, 81, 72, 73,103, 93, 96,123,114,120,131,121,131,163,148,120,158,148,122,163,156,133,145,135,125, 43, 32, 32, 19,  9, 12, 20, 14, 19, 74, 68, 70,134,125,122,119,110,107,110,101, 99, 99, 93, 91, 61, 63, 62, 27, 31, 30, 18, 21, 20, 17, 20, 21, 25, 34, 42, 29, 37, 48, 16, 20, 28,  5,  6, 11,  6,  6, 11, 10,  9, 12, 25, 22, 22, 51, 45, 42, 68, 64, 67, 90, 90,101,116,113,122,134,127,133,140,130,136,143,133,139,143,134,142,143,133,144,};

const int ref_labels[1] = {
    9
};