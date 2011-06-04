/*
 * $Id$
 *
 * Serial Wire Debug Open Library.
 * External Handlers Definition File.
 *
 * Copyright (C) 2010-2011, Tomasz Boleslaw CEDRO (http://www.tomek.cedro.info)
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. Neither the name of the Tomasz Boleslaw CEDRO nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
 * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
 * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.*
 *
 * Written by Tomasz Boleslaw CEDRO <cederom@tlen.pl>, 2010-2011;
 *
 */

/** \file libswd_externs.c Template for driver bridge between libswd and your application. */

#include <libswd.h>
#include <stdlib.h>

int swd_drv_mosi_8(swd_ctx_t *swdctx, swd_cmd_t *cmd, char *data, int bits, int nLSBfirst){
 if (data==NULL) return SWD_ERROR_NULLPOINTER;
 if (bits<0 && bits>8) return SWD_ERROR_PARAM;
 if (nLSBfirst!=0 && nLSBfirst!=1) return SWD_ERROR_PARAM;

 // Your code goes here...

 return bits;
}


int swd_drv_mosi_32(swd_ctx_t *swdctx, swd_cmd_t *cmd, int *data, int bits, int nLSBfirst){
 if (data==NULL) return SWD_ERROR_NULLPOINTER;
 if (bits<0 && bits>8) return SWD_ERROR_PARAM;
 if (nLSBfirst!=0 && nLSBfirst!=1) return SWD_ERROR_PARAM;

 // Your code goes here...

 return bits;
}

int swd_drv_miso_8(swd_ctx_t *swdctx, swd_cmd_t *cmd, char *data, int bits, int nLSBfirst){
 if (data==NULL) return SWD_ERROR_NULLPOINTER;
 if (bits<0 && bits>8) return SWD_ERROR_PARAM;
 if (nLSBfirst!=0 && nLSBfirst!=1) return SWD_ERROR_PARAM;

 // Your code goes here...
 
 return bits;
}

int swd_drv_miso_32(swd_ctx_t *swdctx, swd_cmd_t *cmd, int *data, int bits, int nLSBfirst){
 if (data==NULL) return SWD_ERROR_NULLPOINTER;
 if (bits<0 && bits>8) return SWD_ERROR_PARAM;
 if (nLSBfirst!=0 && nLSBfirst!=1) return SWD_ERROR_PARAM;

 // Your code goes here...

 return bits;
}


/* This function sets interface buffers to MOSI direction.
 * Master Output Slave Input - SWD Write operation.
 * bits specify how many clock cycles must be used. */
int swd_drv_mosi_trn(swd_ctx_t *swdctx, int bits){
 if (bits<SWD_TURNROUND_MIN_VAL && bits>SWD_TURNROUND_MAX_VAL)
  return SWD_ERROR_TURNAROUND; 

 // Your code goes here...

 return bits;
}

int swd_drv_miso_trn(swd_ctx_t *swdctx, int bits){
 if (bits<SWD_TURNROUND_MIN_VAL && bits>SWD_TURNROUND_MAX_VAL)
  return SWD_ERROR_TURNAROUND; 

 // Your code goes here...

 return bits;
}


/** Set debug level according to caller's application settings.
 * \params *swdctx swd context to work on.
 * \params loglevel caller's application log level to be converted.
 * \return SWD_OK on success, of error code on failure.
 */
int swd_log_level_inherit(swd_ctx_t *swdctx, int loglevel){
 if (swdctx==NULL){
  // log(LOG_LEVEL_DEBUG, "swd_log_level_inherit(): SWD Context not (yet) initialized...\n");
  return SWD_OK;
 }

 swd_loglevel_t new_swdlevel;
 switch (loglevel){
  // Your code goes here...
  default:
   new_swdlevel=SWD_LOGLEVEL_NORMAL;
 }

 int res=swd_log_level_set(swdctx, new_swdlevel);
 if (res<0) {
  // Your error routine goes here...
  // return URJ_ERROR_SYNTAX;
 } else return SWD_OK;
}