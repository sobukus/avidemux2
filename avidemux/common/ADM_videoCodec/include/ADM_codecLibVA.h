/**
        \file FFLIBVA
 *      \brief wrapper around ffmpeg wrapper around libva
 */
#ifdef USE_LIBVA
#include "X11/Xlib.h"
#include "va/va.h"

#include <BVector.h>
/**
 * \class decoderFFLIBVA
 */
class decoderFFLIBVA:public decoderFF
{
protected:
protected:
                    bool alive;
                    int b_age;
                    int ip_age[2];
                    ADMImage *scratch;
                    bool     decode_status;
                    VAContextID libva;
#if 0
                    BVector <xvba_render_state *> freeQueue;
                    BVector <xvba_render_state *> allQueue;
                    void     *xvba;

                    ADMImage *xvba_copy;
                    uint64_t xvba_pts;

                    bool     destroying;
                    int      decodedCount;
#endif
public:     // Callbacks
                    int     getBuffer(AVCodecContext *avctx, AVFrame *pic);
                    void    releaseBuffer(struct AVCodecContext *avctx, AVFrame *pic);
                    void    goOn( const AVFrame *d,int type);   
                    
public:
            // public API
                    decoderFFLIBVA (uint32_t w, uint32_t h,uint32_t fcc, uint32_t extraDataLen, uint8_t *extraData,uint32_t bpp);
                    ~decoderFFLIBVA();
    virtual bool uncompress (ADMCompressedImage * in, ADMImage * out);

    virtual bool dontcopy (void)
                      {
                        return 0; // We cannot use ffmpeg internal buffer, they dont exist!
                      }

    virtual bool bFramePossible (void)
      {
        return 1;
      }
    virtual const char *getDecoderName(void) {return "LIBVA";}
    virtual bool  initializedOk(void)  {return alive;};
};
#endif