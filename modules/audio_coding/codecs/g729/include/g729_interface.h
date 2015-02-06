#ifndef WEBRTC_MODULES_AUDIO_CODING_CODECS_G729_MAIN_INTERFACE_G729_H_
#define WEBRTC_MODULES_AUDIO_CODING_CODECS_G729_MAIN_INTERFACE_G729_H_

#include "webrtc/typedefs.h"


// forward declaration
struct G729_encinst_t_;
struct G729_decinst_t_;

typedef struct G729_encinst_t_ G729EncInst;
typedef struct G729_decinst_t_ G729DecInst;

#define G729_SAMPLE_SHORT_LEN 80
#define	G729_FRAME_BYTE_LEN 10

#ifdef __cplusplus
extern "C" {
#endif


int16_t WebRtcG729_CreateEnc(G729EncInst**);
int16_t WebRtcG729_CreateDecoder(G729DecInst**);

int16_t WebRtcG729_EncoderInit(G729EncInst*,int16_t);
int16_t WebRtcG729_DecoderInit(G729DecInst*);

int16_t WebRtcG729_Encode(G729EncInst*,int16_t*,int16_t,int16_t*);
int16_t WebRtcG729_Decode(G729DecInst*,int16_t*,int16_t,int16_t*,int16_t*);

int16_t WebRtcG729_FreeEnc(G729EncInst*);
int16_t WebRtcG729_FreeDecoder(G729DecInst*);

#ifdef __cplusplus
}
#endif

#endif