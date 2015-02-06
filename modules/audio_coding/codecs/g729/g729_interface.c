#include "encoder.h"
#include "decoder.h"
#include "g729_interface.h"

int16_t WebRtcG729_CreateEnc(G729EncInst** enc_inst)
{
	bcg729EncoderChannelContextStruct* context = initBcg729EncoderChannel();
	if (context != NULL)
	{
		*enc_inst = (G729EncInst*)context;
		return 0;
	}
	else
	{
		return -1;
	}
}

int16_t WebRtcG729_CreateDecoder(G729DecInst** dec_inst)
{
	bcg729DecoderChannelContextStruct* context = initBcg729DecoderChannel();
	if (context != NULL)
	{
		*dec_inst = (G729DecInst*)context;
		return 0;
	}
	else
	{
		return -1;
	}
}

int16_t WebRtcG729_EncoderInit(G729EncInst* enc_inst,int16_t mode)
{
	return 0;
}

int16_t WebRtcG729_DecoderInit(G729DecInst* dec_inst)
{
	return 0;
}

int16_t WebRtcG729_Encode(G729EncInst* enc_inst,int16_t* sample,int16_t sampleLen,int16_t* encoded)
{
	unsigned char* charEncoded = (unsigned char*)encoded;
	int16_t iter               = sampleLen/(G729_SAMPLE_SHORT_LEN);
	while(iter > 0)
	{
		bcg729Encoder((bcg729EncoderChannelContextStruct*)enc_inst,sample,charEncoded);
		sample      += G729_SAMPLE_SHORT_LEN;
		charEncoded += G729_FRAME_BYTE_LEN;
		iter--;
	}
	return G729_FRAME_BYTE_LEN*iter;
}

int16_t WebRtcG729_Decode(G729DecInst* dec_inst,int16_t* encoded,int16_t len,int16_t* decoded,int16_t* speechType)
{
	unsigned char* charEncoded = (unsigned char*)encoded;
	int16_t iter               = len/G729_FRAME_BYTE_LEN;
	*speechType                = 1;
	while(iter > 0)
	{
		bcg729Decoder((bcg729DecoderChannelContextStruct*)dec_inst,charEncoded,0,decoded);
		charEncoded += G729_FRAME_BYTE_LEN;
		decoded     += G729_SAMPLE_SHORT_LEN;
		iter--;
	}
	return G729_SAMPLE_SHORT_LEN*iter;
}

int16_t WebRtcG729_FreeEnc(G729EncInst* enc_inst)
{
    closeBcg729EncoderChannel((bcg729EncoderChannelContextStruct*)enc_inst);
	return 0;
}

int16_t WebRtcG729_FreeDecoder(G729DecInst* dec_inst)
{
    closeBcg729DecoderChannel((bcg729DecoderChannelContextStruct*)dec_inst);
	return 0;
}
