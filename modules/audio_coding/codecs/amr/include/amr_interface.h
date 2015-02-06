#ifndef WEBRTC_MODULES_AUDIO_CODING_CODECS_AMR_INTERFACE_AMR_INTERFACE_H_
#define WEBRTC_MODULES_AUDIO_CODING_CODECS_AMR_INTERFACE_AMR_INTERFACE_H_

#include "webrtc/typedefs.h"

struct AMR_encinst_t_;
struct AMR_decinst_t_;

typedef struct AMR_encinst_t_ AMREncInst;
typedef struct AMR_decinst_t_ AMRDecInst;

#define AMR_SAMPLE_SHORT_LEN 160
#define	AMR_FRAME_BYTE_LEN 13

#ifdef __cplusplus
extern "C" {
#endif

int16_t WebRtcAmr_CreateEnc(AMREncInst**);
int16_t WebRtcAmr_CreateDecoder(AMRDecInst**);
int16_t WebRtcAmr_EncoderInit(AMREncInst*,int16_t);
int16_t WebRtcAmr_DecoderInit(AMRDecInst*);
int16_t WebRtcAmr_Encode(AMREncInst*,int16_t*,int16_t,int16_t*,int16_t);
int16_t WebRtcAmr_Decode(AMRDecInst*,int16_t*,int16_t,int16_t*,int16_t*);
int16_t WebRtcAmr_FreeEnc(AMREncInst*);
int16_t WebRtcAmr_FreeDecoder(AMRDecInst*);
int16_t WebRtcAmr_EncodeBitmode(AMREncInst*,int);
int16_t WebRtcAmr_DecodeBitmode(AMRDecInst*,int);
int16_t WebRtcAmr_DecodePlc(AMRDecInst*,int16_t*,int16_t);

#ifdef __cplusplus
}  // extern "C"
#endif

#endif // WEBRTC_MODULES_AUDIO_CODING_CODECS_AMR_INTERFACE_AMR_INTERFACE_H_