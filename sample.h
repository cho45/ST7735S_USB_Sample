const uint8_t sample[] = {9,198,9,198,9,165,9,133,9,69,9,68,9,36,9,36,9,69,9,101,9,102,9,103,17,135,17,168,17,136,17,135,17,199,17,198,17,166,17,166,17,166,17,167,17,168,17,168,25,200,17,231,17,230,17,230,17,231,25,200,25,201,25,201,34,9,34,8,34,41,42,41,42,40,42,72,50,104,58,167,66,199,74,230,91,70,107,231,140,137,157,42,181,236,206,109,17,198,17,198,17,165,17,133,17,101,9,68,9,68,9,68,1,36,9,101,9,134,9,134,9,134,17,167,25,200,25,232,17,199,17,199,17,199,17,199,17,199,17,200,25,200,25,200,25,232,26,8,26,39,18,7,17,231,17,231,25,233,34,10,34,9,34,9,34,41,34,73,42,73,42,104,50,137,58,200,67,8,75,39,91,135,116,40,140,169,157,74,181,204,198,77,17,198,17,198,17,198,17,166,17,133,17,100,9,68,9,68,1,67,1,100,9,133,9,165,9,165,17,165,17,198,25,231,17,199,17,200,17,232,17,232,17,232,17,232,25,233,25,233,34,9,26,40,26,72,18,71,18,7,17,231,26,8,34,41,34,73,34,73,42,73,42,106,42,138,50,170,58,202,67,10,75,41,83,105,91,201,116,74,132,202,149,75,173,172,182,12,25,198,25,198,25,198,25,166,25,165,17,133,17,100,9,100,9,101,1,100,9,133,9,165,17,230,17,230,17,230,17,198,25,200,25,232,26,9,18,8,17,232,18,8,26,9,34,41,42,73,42,138,34,169,34,169,26,136,26,104,34,39,34,40,34,72,34,73,34,73,34,105,42,137,42,169,50,202,59,10,75,106,83,170,100,10,116,138,132,235,149,75,165,171,173,203,25,231,25,199,25,198,25,166,25,134,17,134,17,134,17,102,17,134,9,135,9,135,9,167,17,199,25,231,25,231,25,232,25,200,25,233,26,9,18,8,18,8,26,40,34,41,34,105,50,171,50,235,51,43,51,107,59,107,51,73,50,232,42,167,42,168,42,169,42,136,42,169,42,201,50,234,59,42,67,75,83,171,91,235,108,108,124,204,133,44,149,108,157,172,165,203,25,231,25,231,25,199,25,166,25,166,25,166,25,166,17,167,17,167,17,168,17,167,9,134,17,134,25,231,25,231,25,199,25,200,25,233,26,8,26,40,26,40,26,104,34,137,42,170,59,12,59,76,67,172,84,45,92,109,92,76,84,10,75,202,67,105,59,73,59,41,59,41,59,42,59,74,67,139,75,203,92,12,100,108,116,205,133,45,141,108,149,172,157,204,157,235,25,231,25,231,25,231,25,198,25,198,25,198,25,198,25,199,17,199,17,198,17,166,25,198,42,103,67,9,58,167,33,229,25,199,25,200,25,230,26,6,34,70,34,136,42,202,50,235,59,76,75,172,92,45,108,206,125,46,125,110,125,109,125,77,108,204,100,140,92,75,84,11,84,11,83,235,84,11,92,43,108,173,125,13,133,109,141,173,149,237,158,13,166,44,166,44,25,231,26,7,26,7,26,6,34,6,25,230,25,198,25,198,25,199,17,166,17,165,42,71,91,172,132,175,107,235,66,134,25,166,25,166,25,164,33,228,34,37,42,167,50,233,51,11,67,141,83,237,108,173,133,78,149,238,158,79,166,144,166,177,166,112,150,47,141,174,133,109,125,45,117,13,116,237,125,13,125,45,141,142,149,238,158,46,166,110,174,142,174,141,174,141,26,39,26,38,34,70,34,38,25,229,25,197,25,230,25,198,25,199,25,166,25,166,74,234,116,13,107,203,132,76,99,105,17,67,33,197,66,134,91,72,108,10,108,141,51,41,51,75,75,205,92,45,141,110,190,144,215,146,199,80,166,174,191,146,191,81,191,49,191,17,182,241,174,144,166,79,158,15,158,14,166,47,166,79,174,110,174,174,182,206,182,238,190,237,182,206,26,71,17,230,26,5,26,6,26,6,34,6,25,230,25,198,25,166,25,134,17,36,66,169,116,13,156,239,198,51,140,108,50,5,74,232,173,177,214,245,149,45,108,107,83,236,51,42,75,204,100,108,165,174,206,240,223,112,207,79,183,15,191,80,199,112,207,112,207,145,207,113,207,113,199,49,199,49,199,17,190,207,190,239,190,239,199,15,199,47,199,47,199,46,199,46,26,8,17,231,34,72,26,7,25,230,25,198,17,133,25,167,25,134,25,102,41,231,33,132,74,134,173,47,165,13,123,200,115,169,165,80,190,49,206,178,182,16,108,75,50,232,59,41,59,73,116,140,174,14,215,15,215,46,207,46,207,144,199,144,207,111,207,143,215,176,215,176,215,176,215,177,215,145,215,145,207,112,215,112,215,112,215,112,215,112,215,112,207,79,207,79,17,167,17,167,25,232,17,133,25,166,34,39,17,165,25,134,17,101,33,198,8,226,33,130,107,104,189,239,198,14,156,169,132,8,181,208,214,178,215,20,157,78,66,230,42,102,50,200,83,170,166,17,223,115,231,145,215,14,198,236,207,79,199,46,215,175,223,175,223,208,223,240,231,240,231,209,223,209,223,177,223,209,223,177,223,177,223,177,223,177,223,177,223,145,215,113,17,103,9,70,17,102,25,134,75,11,100,14,58,201,17,100,33,229,17,66,33,194,165,143,223,51,223,16,239,78,239,79,214,111,181,109,140,137,124,106,83,71,42,35,50,135,34,37,83,105,198,179,247,246,247,244,223,144,207,14,207,80,207,79,223,143,223,175,223,175,223,208,231,240,231,241,239,241,239,241,231,242,231,242,239,210,239,243,239,243,239,211,239,211,231,179,17,37,33,199,50,72,83,108,149,83,165,180,91,172,17,67,9,66,0,192,91,105,206,212,223,83,223,48,223,13,230,237,247,48,222,112,124,40,75,5,67,7,25,195,33,196,50,69,74,230,165,142,215,83,223,146,207,48,198,206,198,206,215,47,215,111,215,143,223,143,223,175,223,176,231,208,231,208,231,209,239,242,239,242,239,243,239,244,247,244,247,245,247,245,239,245,33,163,83,40,99,202,132,206,165,210,141,16,83,74,17,99,17,100,0,194,33,197,132,143,149,14,107,135,156,234,214,78,238,175,205,236,124,40,66,197,34,69,9,67,33,197,66,134,74,165,91,37,132,234,166,13,174,77,182,142,215,48,239,210,223,112,223,144,223,144,223,176,231,176,231,209,231,209,231,177,231,209,239,178,239,179,239,212,239,213,247,214,247,214,247,246,58,164,108,9,99,233,116,107,124,108,83,72,58,135,25,100,9,3,83,75,124,143,58,69,41,129,41,96,74,33,173,10,205,235,189,137,132,72,66,229,50,103,25,165,66,135,115,170,173,143,107,198,116,104,141,75,133,10,141,75,174,13,198,175,207,15,207,47,207,80,215,112,223,176,223,208,223,177,223,177,231,209,231,210,239,210,239,212,239,213,239,214,247,214,239,213,75,103,108,107,116,171,124,204,75,5,50,36,66,200,50,6,33,196,198,246,231,215,132,170,50,0,41,192,66,98,173,140,206,75,206,74,189,204,123,232,66,38,49,165,66,37,214,212,239,213,214,241,132,170,141,12,116,73,91,199,124,138,149,108,174,45,182,142,199,17,207,113,215,177,199,79,207,112,207,112,223,177,223,176,223,176,239,242,239,212,231,180,239,245,247,245,83,201,100,42,157,239,231,247,182,145,108,8,74,231,74,232,50,36,124,108,157,173,149,74,140,201,74,162,107,167,222,242,239,111,222,171,231,47,173,43,82,101,49,66,41,96,140,138,247,212,239,211,132,104,124,41,99,200,91,167,108,74,116,138,133,10,149,140,166,47,174,144,191,16,182,206,191,15,199,48,199,47,198,238,215,111,215,112,215,49,231,180,231,179,223,114,116,142,108,75,166,15,247,247,239,244,182,141,132,202,116,10,91,105,50,3,74,228,190,144,255,245,124,38,115,166,206,80,247,113,247,79,247,144,222,175,107,69,49,128,123,199,148,201,190,12,231,113,173,172,214,242,190,113,124,105,108,42,91,168,99,232,108,41,116,139,133,12,157,238,149,172,149,172,157,237,157,204,198,207,215,80,206,239,206,240,215,50,215,114,223,114,149,113,149,111,166,13,223,177,239,242,239,243,215,81,174,15,165,112,99,136,83,5,182,47,206,207,107,195,82,194,189,206,247,82,255,178,255,144,255,177,165,10,115,133,247,148,230,241,165,72,231,48,206,143,247,246,214,243,91,70,91,103,66,165,75,6,75,6,91,170,108,76,133,12,108,73,108,40,133,11,157,141,207,18,182,110,173,236,182,111,182,80,198,209,207,50,182,48,174,47,174,11,231,241,255,244,247,244,255,245,231,147,215,51,148,235,198,113,255,248,181,236,190,77,190,13,165,10,255,180,255,179,255,211,255,178,222,143,197,205,255,246,239,81,140,69,231,48,156,234,156,203,124,9,49,194,58,36,66,134,66,134,50,36,74,232,91,138,91,202,58,197,66,229,116,107,174,17,174,16,157,141,132,202,140,235,157,110,157,174,173,239,207,17,190,174,173,233,231,208,255,244,239,212,255,246,247,245,239,212,182,13,206,177,231,147,223,48,255,244,223,16,181,139,255,84,255,213,255,146,247,81,230,208,181,107,222,175,189,203,115,97,231,49,131,230,99,37,90,230,58,4,49,228,132,110,124,77,58,102,58,70,58,135,58,166,33,194,42,36,99,170,132,173,116,42,174,17,140,236,75,6,99,234,116,75,141,46,231,177,215,46,190,105,231,143,255,244,255,247,255,249,255,248,255,247,223,17,214,239,231,80,239,143,239,176,198,76,206,77,247,17,255,213,247,82,255,114,230,209,156,136,173,74,173,72,173,39,247,178,156,201,115,168,115,137,74,135,58,37,165,146,165,146,82,231,58,102,58,102,58,101,42,3,50,36,91,73,74,231,91,105,173,177,132,141,42,4,50,70,75,73,116,109,215,46,215,13,215,12,239,208,255,244,255,247,255,216,255,217,255,247,255,246,231,48,231,78,231,110,231,77,206,75,255,145,255,210,255,146,255,245,255,244,247,115,181,139,148,134,181,137,231,14,247,145,181,139,123,199,123,235,82,134,66,101,132,109,124,76,58,68,66,134,74,199,58,101,42,3,50,36,82,232,74,167,107,203,107,202,74,231,33,196,25,132,58,135,75,41,223,79,247,242,231,80,231,80,255,243,255,244,255,247,255,249,255,249,255,247,247,179,231,111,223,12,222,203,231,45,255,175,255,240,255,176,255,242,247,145,239,81,189,171,156,199,173,137,198,42,239,111,214,206,132,38,132,41,91,38,74,164,116,42,99,168,74,197,74,166,66,165,58,67,41,226,74,166,66,133,91,72,124,44,91,72,83,7,41,228,42,38,50,135,58,167,214,239,198,141,181,204,222,240,255,244,255,244,255,212,255,247,255,249,255,248,255,244,247,178,239,111,239,110,247,142,255,207,255,239,255,175,255,240,239,112,222,239,181,139,148,168,173,106,165,38,206,172,231,79,165,40,140,169,99,102,83,5,124,74,107,201,66,132,83,7,91,39,83,6,74,196,74,133,91,39,90,230,99,104,107,201,99,136,66,199,50,102,58,167,67,41,231,114,190,13,148,169,181,172,247,178,255,243,255,211,255,212,255,246,255,246,255,245,255,211,255,179,255,210,255,207,255,207,255,208,255,208,247,208,239,143,214,206,181,170,148,169,173,75,165,40,198,75,247,208,181,233,140,200,107,166,91,70,132,107,115,233,82,230,82,231,74,166,173,209,165,111,91,5,214,212,115,201,148,172,182,16,116,41,66,230,58,166,67,39,75,72,247,245,231,147,198,46,181,171,214,206,255,209,255,243,247,210,255,211,255,244,255,244,255,211,255,212,255,211,255,176,247,143,255,177,255,242,247,208,255,241,223,14,190,44,156,234,165,11,181,172,206,109,247,208,190,10,157,9,115,198,91,70,132,107,107,169,99,72,82,199,115,202,148,204,239,183,181,207,157,13,115,199,157,44,198,145,116,40,66,164,66,230,83,136,58,230,215,49,247,245,247,243,223,14,206,172,222,238,231,48,239,81,247,178,255,242,255,242,255,242,255,211,255,211,255,178,255,145,255,179,255,244,255,210,255,242,231,111,206,174,173,108,165,12,181,172,206,142,247,176,190,43,173,140,124,40,99,70,132,140,99,136,99,72,74,101,181,177,214,244,198,113,181,206,91,3,115,166,132,104,165,75,140,202,99,168,83,39,67,39,42,100,198,174,215,79,247,241,247,241,231,111,214,206,206,141,223,16,247,177,247,242,255,242,255,242,255,210,255,210,255,210,255,211,255,212,255,245,255,178,255,242,239,143,222,238,198,45,181,107,181,139,222,207,247,176,198,43,173,140,132,73,115,232,148,204,115,232,115,233,115,201,132,107,149,11,214,209,247,213,140,72,140,104,156,201,165,75,165,141,116,10,75,7,58,166,50,133,215,108,199,11,223,142,247,241,255,243,239,145,223,14,231,112,247,242,247,243,255,244,255,244,255,242,255,209,255,209,255,210,255,212,255,213,255,211,255,209,247,207,231,45,214,205,189,202,198,10,239,111,255,241,198,43,173,75,148,170,157,11,148,234,165,142,231,118,206,212,157,45,107,165,247,245,223,18,132,39,157,10,165,43,181,173,148,203,91,39,58,102,50,102,83,106,215,108,207,11,223,141,239,207,247,241,247,241,231,110,239,143,255,243,255,244,255,246,255,246,255,243,255,209,255,177,255,210,255,179,255,212,255,244,255,211,255,240,231,77,231,13,198,10,198,42,239,112,255,241,206,76,173,107,165,75,190,13,140,168,124,72,214,243,173,174,99,100,140,103,189,236,206,143,165,42,181,205,165,75,173,174,124,41,66,134,41,229,41,229,99,204,198,238,207,14,223,110,239,175,247,239,255,239,247,207,247,176,247,179,255,246,255,248,255,247,255,213,255,243,255,210,255,177,255,209,255,244,255,214,255,214,255,211,255,177,230,238,198,11,181,106,247,145,255,242,206,140,173,137,190,13,165,75,132,137,91,101,124,105,165,141,115,229,156,199,214,109,214,141,190,11,181,204,165,108,149,12,83,71,33,195,25,131,66,169,58,103,173,203,198,174,231,111,239,174,247,206,255,239,255,240,255,177,255,212,255,247,255,248,255,248,255,214,255,245,255,211,255,177,255,209,255,243,255,214,255,182,255,180,255,145,231,14,206,76,173,73,239,81,255,241,214,204,173,168,190,44,198,80,140,171,99,167,124,138,181,205,156,233,206,44,255,243,239,80,198,12,173,171,157,76,132,203,33,226,42,4,83,73,50,38,74,232,140,134,173,170,222,237,247,143,255,207,255,239,255,208,255,177,255,212,255,246,255,248,255,248,255,247,255,246,255,212,255,210,255,241,255,242,255,213,255,214,255,179,247,145,239,46,222,204,181,136,239,79,247,175,231,45,198,42,206,109,239,85,148,204,124,9,173,174,255,246,214,142,214,76,239,15,230,238,206,45,132,71,132,170,83,39,25,129,116,109,149,80,33,162,83,71,173,73,181,106,206,75,239,78,255,208,255,208,255,144,255,145,255,180,255,214,255,247,255,248,255,247,255,214,255,213,255,244,255,241,255,210,255,213,255,213,255,211,247,145,239,78,239,45,206,42,239,79,255,208,247,142,214,172,206,109,247,117,189,208,148,138,157,10,239,114,206,76,239,47,255,177,230,239,173,74,115,199,124,10,74,231,66,133,58,100,83,39,99,168,124,107,239,81,230,207,222,141,239,14,255,143,255,144,255,144,255,145,255,147,255,180,255,246,255,247,255,247,255,214,255,214,255,246,255,211,255,211,255,213,255,246,255,244,255,177,247,143,247,142,222,204,247,111,255,241,255,176,230,236,198,11,222,177,230,243,156,169,165,9,239,48,230,238,255,112,255,112,206,13,140,39,123,232,107,201,50,3,74,198,41,226,107,233,190,113,132,171,255,179,255,178,255,145,255,80,255,112,255,176,255,177,255,112,255,146,255,179,255,213,255,247,255,247,247,183,255,215,255,248,255,182,255,214,255,215,255,246,255,245,255,211,255,208,255,176,247,112,247,113,255,243,255,209,247,143,214,75,189,139,214,46,206,45,222,141,247,47,255,145,247,48,230,207,172,233,107,36,181,175,148,205,58,36,74,198,91,104,149,13,157,77,74,228,231,15,247,145,255,210,255,177,255,144,255,209,255,177,255,112,255,210,255,178,255,179,255,245,255,246,255,182,255,183,255,249,255,185,255,218,255,217,255,215,255,214,255,244,255,242,255,210,255,179,255,148,255,181,255,212,255,208,231,13,189,137,197,169,230,172,247,46,255,79,255,112,247,16,205,236,181,75,140,105,115,167,115,233,116,10,124,107,99,136,124,42,116,9,66,164,222,205,231,47,247,112,255,177,255,177,255,176,255,208,255,209,255,242,255,177,255,178,255,244,255,246,255,214,255,183,255,217,255,219,255,220,255,218,255,184,255,215,255,246,255,245,255,245,255,150,255,216,255,216,255,214,247,80,239,45,222,172,230,204,247,77,255,142,255,208,247,47,247,80,172,232,173,75,148,137,99,69,140,171,108,9,66,196,74,230,116,43,124,43,116,11,165,168,214,204,247,176,247,176,239,111,247,143,255,176,247,143,255,208,255,208,255,209,255,211,255,244,255,246,255,215,255,185,255,220,255,253,255,251,255,250,255,217,255,249,255,248,255,248,255,218,255,186,255,219,255,249,255,179,247,111,247,111,255,110,255,110,255,142,255,175,255,79,222,141,181,105,140,70,132,38,115,230,115,231,74,196,66,164,140,238,149,15,99,170,74,200,182,74,206,237,231,143,239,176,247,175,247,175,255,207,255,239,255,240,255,208,255,208,255,209,255,179,255,180,255,149,255,151,255,218,255,251,255,251,255,250,255,251,255,251,255,251,255,251,255,221,255,221,255,253,255,250,255,181,255,145,255,144,255,143,255,175,255,142,255,110,230,237,214,107,189,201,165,40,173,74,99,131,99,133,124,106,141,13,140,206,132,174,116,77,8,225,215,78,215,111,231,176,239,240,247,208,247,175,247,174,255,239,255,239,255,239,255,208,255,209,255,178,255,178,255,147,255,148,255,214,255,248,255,248,255,249,255,251,255,252,255,253,255,221,255,221,255,221,255,253,255,218,255,149,255,147,255,147,255,113,255,145,255,111,247,78,239,12,230,235,214,138,198,42,206,108,190,13,157,75,124,73,99,168,66,133,58,133,91,105,17,65,231,242,231,241,239,240,247,240,247,207,239,174,247,142,247,174,247,174,255,174,255,175,255,176,255,176,255,145,255,145,255,146,255,179,255,212,255,214,255,216,255,218,255,219,255,220,255,221,255,188,255,188,255,219,255,184,247,117,255,116,255,147,255,114,255,113,255,79,255,111,247,109,247,109,239,76,222,235,222,237,198,44,165,107,107,166,83,5,66,165,42,2,74,230,66,231,239,242,239,242,247,241,247,240,247,207,247,207,255,174,255,206,247,142,247,110,247,78,247,78,247,78,255,111,255,111,255,111,255,144,255,145,255,179,255,213,255,216,255,218,255,251,255,252,255,219,255,218,255,217,255,183,255,117,255,180,255,180,255,146,255,145,255,112,255,111,247,77,247,109,247,109,231,44,239,46,222,206,198,12,173,140,157,12,132,171,124,106,141,45,133,14,239,211,247,243,255,242,247,241,247,175,255,207,255,207,255,207,255,175,255,142,247,46,239,13,239,13,247,45,255,110,255,142,247,77,247,78,247,113,255,147,255,181,255,215,255,249,255,251,255,250,255,216,255,215,255,181,255,148,255,147,255,210,255,177,255,145,255,112,255,111,255,77,255,109,255,141,239,44,247,46,230,205,214,141,214,143,181,205,157,76,149,44,124,170,67,5,247,212,255,243,255,243,255,209,255,175,255,174,255,174,255,175,255,175,255,143,247,78,247,78,247,77,255,109,255,109,255,141,247,45,247,46,247,80,255,113,255,146,255,179,255,214,255,248,255,248,255,182,255,180,255,179,255,115,255,113,255,144,255,142,255,111,255,111,255,111,255,78,255,111,255,111,247,13,247,46,239,13,230,237,206,43,173,105,165,74,132,201,124,136,83,102,247,211,247,210,247,177,255,176,255,175,255,142,255,174,255,174,255,110,255,142,255,143,255,142,255,142,255,141,255,108,255,76,255,110,255,78,255,79,255,144,255,145,255,146,255,180,255,214,255,247,255,181,255,147,255,179,255,114,255,80,255,110,255,109,255,142,255,110,255,78,247,13,247,46,255,79,247,46,255,111,247,78,239,45,230,236,231,78,198,109,149,9,182,47,182,114};
const uint8_t sample_w = 48;
const uint8_t sample_h = 48;
