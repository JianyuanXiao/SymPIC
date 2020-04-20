	#ifndef   GAPS_IO_LIB_VERS_0001    
		
#define GAPS_IO_LIB_VERS_0001
#include <stdint.h>
#include <unistd.h>
#include <sys/types.h>
typedef struct { 	int64_t  version ;
	int64_t  type ;
	int64_t  dim ;
	int64_t *  pdimarray ;
	int64_t *  pblockarray ;
	int64_t  numperstep ;
	FILE *  pfile ;
	char *  prefix ;
	int64_t *  locations ;
	int64_t  block_len ;
	int64_t  num_block_current_proc ;
	int64_t  time_step_current ;
	int64_t  num_block_all_reduce_group ;
	int  num_reduce_proc ;
	int  cur_rank ;
	int  send_to_proc ;
	int  real_rank ;
} Gaps_IO_DataFile;
typedef enum {GAPS_IO_CONST_INT32,GAPS_IO_INT64,GAPS_IO_INT16,GAPS_IO_UINT32,GAPS_IO_UINT64,GAPS_IO_UINT16,GAPS_IO_FLOAT32,GAPS_IO_FLOAT64,GAPS_IO_INT128,GAPS_IO_UINT128,GAPS_IO_FLOAT128,GAPS_IO_INT8,GAPS_IO_UINT8} Gaps_IO_Type;

extern int* GAPS_IO_GlobalTypeLen;int  GAPS_IO_TruncateFile (Gaps_IO_DataFile *  pOutfile ,int64_t  NumSteps ,int64_t  NumData );
int  GAPS_IO_DeleteDataInfo (Gaps_IO_DataFile *  pOutfile );
int  GAPS_IO_DataNumStepsAndResidue (Gaps_IO_DataFile *  pOutfile ,int64_t *  pNumsteps ,int64_t *  pResidue );
int  GAPS_IO_FWriteALL (Gaps_IO_DataFile *  pOutfile ,void *  pData ,int64_t  NumData );
int64_t  GAPS_IO_FWrite (Gaps_IO_DataFile *  pOutfile ,void *  pData ,int64_t  NumData );
int  GAPS_IO_FRead (Gaps_IO_DataFile *  pOutfile ,void *  pData ,int64_t  NumData );
int  GAPS_IO_InitIFile (Gaps_IO_DataFile *  pOutfile ,char *  pName );
int  GAPS_IO_InitIFileV2 (Gaps_IO_DataFile *  pOutfile ,char *  pName ,char *  pNamePrefix ,int  rank );
int  GAPS_IO_FileGotoBegin (Gaps_IO_DataFile *  pOutfile );
int  GAPS_IO_InitIFilePointer (Gaps_IO_DataFile *  pOutfile ,FILE *  fp );
int  GAPS_IO_GetTypeLen (int  type );
int  GAPS_IO_InitOFile (Gaps_IO_DataFile *  pOutfile ,char *  pName );
int  GAPS_IO_InitOFile_with_TimeStep (Gaps_IO_DataFile *  pOutfile ,char *  pName ,int64_t  timestep );
int  GAPS_IO_InitOFile_with_TimeStepV2_withrank (Gaps_IO_DataFile *  pOutfile ,char *  pName ,char *  pNamePrefix ,int64_t  timestep ,long  rank );
int  GAPS_IO_InitOFile_with_TimeStepV2 (Gaps_IO_DataFile *  pOutfile ,char *  pName ,char *  pNamePrefix ,int64_t  timestep );
int  GAPS_IO_DataSeek (Gaps_IO_DataFile *  pOutfile ,int64_t  Step ,int64_t  Offset );
int  GAPS_IO_FileFlush (Gaps_IO_DataFile *  pOutfile );
int  GAPS_IO_InitDataInfo (Gaps_IO_DataFile *  pOutfile ,int64_t  Type ,int64_t  Dim ,int64_t *  pDimarray );
int  GAPS_IO_InitDataInfoV1 (Gaps_IO_DataFile *  pOutfile ,int64_t  Type ,int64_t  Dim ,int64_t *  pDimarray ,int64_t *  pBlockarray );
int  GAPS_IO_InitDataInfoV2 (Gaps_IO_DataFile *  pOutfile ,char *  Prefix ,int64_t  Type ,int64_t  Dim ,int64_t *  pDimarray ,int64_t *  pBlockarray ,int64_t *  pLocationarray ,int64_t  Num_block_current_proc ,int64_t  time_step_current );
int  GAPS_IO_SetNumReduceProc (Gaps_IO_DataFile *  pOutfile ,int  Num_reduce_proc );

	#else
		
	 #endif
