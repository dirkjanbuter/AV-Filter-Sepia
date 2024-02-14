#include "main.h"

static int _w = 0;
static int _h = 0;
static int _framecount = 0;

static int _s = 0;
static int _sizebytes = 0;
static unsigned char *_oi;

void sepia() {
    int x, y;

    for(y = 0; y < _h; y++) {
        for(x = 0; x < _w; x++) {
            unsigned char r = _oi[(y*_w+x)*4+1];
            unsigned char g = _oi[(y*_w+x)*4+2];
            unsigned char b = _oi[(y*_w+x)*4+3];

            int or = (int)(((float)r * .393f) + ((float)g *.769f) + ((float)b * .189f));
            int og = (int)(((float)r * .349f) + ((float)g *.686f) + ((float)b * .168f));
            int ob  = (int)(((float)r * .272f) + ((float)g *.534f) + ((float)b * .131f));

            if(or > 255) or = 255;
            if(og > 255) og = 255;
            if(ob > 255) ob = 255;

            _oi[(y*_w+x)*4+1] = or;
            _oi[(y*_w+x)*4+2] = og;
            _oi[(y*_w+x)*4+3] = ob;
         }
    }
}

int filterstep(unsigned char *buffer, int w, int h, unsigned color, char *text, int64_t framecount)
{
    _w = w;
    _h = h;
    _framecount = framecount;

    _s = _w * _h;
    _sizebytes = _s * 4;

    _oi = buffer;

    sepia();

    return 1;
}
