#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/types.h>
typedef struct {
	int64_t version ;
	int64_t type ;
	int64_t dim ;
	int64_t *pdimarray ;
	int64_t *pblockarray ;
	int64_t numperstep ;
	FILE *pfile ;
} Gaps_IO_DataFile;
typedef enum {GAPS_IO_CONST_INT32,GAPS_IO_INT64,GAPS_IO_INT16,GAPS_IO_UINT32,GAPS_IO_UINT64,GAPS_IO_UINT16,GAPS_IO_FLOAT32,GAPS_IO_FLOAT64,GAPS_IO_INT128,GAPS_IO_UINT128,GAPS_IO_FLOAT128,GAPS_IO_INT8,GAPS_IO_UINT8} Gaps_IO_Type;
#include <mpi.h>

static int GAPS_IO_GlobalTypeLen[]= {4,8,2,4,8,2,4,8,16,16,16,1,1};
int GAPS_IO_InitDataInfoV1(Gaps_IO_DataFile *pOutfile,int64_t Type,int64_t Dim,int64_t *pDimarray,int64_t *pBlockarray) {
	((pOutfile)->dim = Dim);
	size_t dimarrlen = (sizeof(int64_t) * Dim) ;
	((pOutfile)->pdimarray = malloc(dimarrlen));
	((pOutfile)->pblockarray = malloc(dimarrlen));
	((pOutfile)->version = 1);
	if(((pOutfile)->pdimarray == NULL)) {
		fprintf(stderr, "Error: unable to allocate the memory\n");
		return -1 ;
	} else {
		0;
	}
	memcpy((pOutfile)->pdimarray, pDimarray, dimarrlen);
	memcpy((pOutfile)->pblockarray, pBlockarray, dimarrlen);
	((pOutfile)->type = Type);
	int64_t alll = 1 ;
	long g = 0 ;
	for(g=0 ; (g < Dim) ; g++) {
		(alll = (alll * ((pDimarray)[g] * (pBlockarray)[g])));
	}
	((pOutfile)->numperstep = alll);
	return 0 ;
}
int GAPS_IO_InitDataInfo(Gaps_IO_DataFile *pOutfile,int64_t Type,int64_t Dim,int64_t *pDimarray) {
	((pOutfile)->dim = Dim);
	size_t dimarrlen = (sizeof(int64_t) * Dim) ;
	((pOutfile)->pdimarray = malloc(dimarrlen));
	((pOutfile)->pblockarray = malloc(dimarrlen));
	((pOutfile)->version = 0);
	if((((pOutfile)->pdimarray == NULL) || ((pOutfile)->pblockarray == NULL))) {
		fprintf(stderr, "Error: unable to allocate the memory\n");
		return -1 ;
	} else {
		0;
	}
	memcpy((pOutfile)->pdimarray, pDimarray, dimarrlen);
	{
		long i ;
		for((i = 0) ; (i < Dim) ; (i = (i + 1))) {
			(((pOutfile)->pblockarray)[i] = 1);
		}
	}
	((pOutfile)->type = Type);
	int64_t alll = 1 ;
	long g = 0 ;
	for(g=0 ; (g < Dim) ; g++) {
		(alll = (alll * (pDimarray)[g]));
	}
	((pOutfile)->numperstep = alll);
	return 0 ;
}
int GAPS_IO_FileFlush(Gaps_IO_DataFile *pthis) {
	int64_t version = (pthis)->version ;
	int64_t type = (pthis)->type ;
	int64_t dim = (pthis)->dim ;
	int64_t *pdimarray = (pthis)->pdimarray ;
	int64_t *pblockarray = (pthis)->pblockarray ;
	int64_t numperstep = (pthis)->numperstep ;
	FILE *pfile = (pthis)->pfile ;
	{
		MPI_File_sync((((MPI_File *)pfile))[0]);
	}
	return 0 ;
}
int GAPS_IO_DataSeek(Gaps_IO_DataFile *pthis,int64_t Step,int64_t Offset) {
	int64_t version = (pthis)->version ;
	int64_t type = (pthis)->type ;
	int64_t dim = (pthis)->dim ;
	int64_t *pdimarray = (pthis)->pdimarray ;
	int64_t *pblockarray = (pthis)->pblockarray ;
	int64_t numperstep = (pthis)->numperstep ;
	FILE *pfile = (pthis)->pfile ;
	assert((0 == MPI_File_seek((((MPI_File *)pfile))[0], (((GAPS_IO_GlobalTypeLen)[type] * (Offset + (Step * numperstep))) + (sizeof(int64_t) * (3 + ((((version == 0))?(1):(2)) * dim)))), MPI_SEEK_SET)));
	return 0 ;
}
int GAPS_IO_InitOFile_with_TimeStep(Gaps_IO_DataFile *pthis,char *pName,int64_t timestep) {
	int64_t version = (pthis)->version ;
	int64_t type = (pthis)->type ;
	int64_t dim = (pthis)->dim ;
	int64_t *pdimarray = (pthis)->pdimarray ;
	int64_t *pblockarray = (pthis)->pblockarray ;
	int64_t numperstep = (pthis)->numperstep ;
	FILE *pfile = (pthis)->pfile ;
	if((timestep != -1)) {
		(pfile = ({
			MPI_File *fp = malloc(sizeof(MPI_File)) ;
			int ret = MPI_File_open(MPI_COMM_WORLD, pName, MPI_MODE_RDWR, MPI_INFO_NULL, fp) ;
			if(ret) {
				free(fp);
				(fp = NULL);
			} else {
				0;
			}
			fp;
		}));
	} else {
		(pfile = ({
			MPI_File *fp = malloc(sizeof(MPI_File)) ;
			int ret = MPI_File_open(MPI_COMM_WORLD, pName, (MPI_MODE_RDWR | MPI_MODE_CREATE), MPI_INFO_NULL, fp) ;
			MPI_File_set_size((fp)[0], 0);
			if(ret) {
				fprintf(stderr,"ret=%d\n",ret);
				free(fp);
				(fp = NULL);
			} else {
				0;
			}
			fp;
		}));
	}
	assert(pfile);
	((pthis)->pfile = pfile);
	int rank ;
	if((timestep != -1)) {
		GAPS_IO_DataSeek(pthis, timestep, 0);
	} else {
		MPI_Comm_rank(MPI_COMM_WORLD, & (rank));
		if((0 == rank)) {
			assert((1 == ({
				MPI_Datatype mdt = (((sizeof(int64_t) == 1))?(MPI_CHAR):((((sizeof(int64_t) == 2))?(MPI_SHORT):((((sizeof(int64_t) == 4))?(MPI_INT):((((sizeof(int64_t) == 8))?(MPI_LONG_LONG):(({
					fprintf(stderr, "unknown type length %d\n", sizeof(int64_t));
					assert(0);
					0;
				}))))))))) ;
				MPI_Status stat ;
				int readed ;
				MPI_File_write((((MPI_File *)pfile))[0], & (version), 1, mdt, & (stat));
				MPI_Get_count(& (stat), mdt, & (readed));
				readed;
			})));
			assert((1 == ({
				MPI_Datatype mdt = (((sizeof(int64_t) == 1))?(MPI_CHAR):((((sizeof(int64_t) == 2))?(MPI_SHORT):((((sizeof(int64_t) == 4))?(MPI_INT):((((sizeof(int64_t) == 8))?(MPI_LONG_LONG):(({
					fprintf(stderr, "unknown type length %d\n", sizeof(int64_t));
					assert(0);
					0;
				}))))))))) ;
				MPI_Status stat ;
				int readed ;
				MPI_File_write((((MPI_File *)pfile))[0], & (type), 1, mdt, & (stat));
				MPI_Get_count(& (stat), mdt, & (readed));
				readed;
			})));
			assert((1 == ({
				MPI_Datatype mdt = (((sizeof(int64_t) == 1))?(MPI_CHAR):((((sizeof(int64_t) == 2))?(MPI_SHORT):((((sizeof(int64_t) == 4))?(MPI_INT):((((sizeof(int64_t) == 8))?(MPI_LONG_LONG):(({
					fprintf(stderr, "unknown type length %d\n", sizeof(int64_t));
					assert(0);
					0;
				}))))))))) ;
				MPI_Status stat ;
				int readed ;
				MPI_File_write((((MPI_File *)pfile))[0], & (dim), 1, mdt, & (stat));
				MPI_Get_count(& (stat), mdt, & (readed));
				readed;
			})));
			assert((dim == ({
				MPI_Datatype mdt = (((sizeof(int64_t) == 1))?(MPI_CHAR):((((sizeof(int64_t) == 2))?(MPI_SHORT):((((sizeof(int64_t) == 4))?(MPI_INT):((((sizeof(int64_t) == 8))?(MPI_LONG_LONG):(({
					fprintf(stderr, "unknown type length %d\n", sizeof(int64_t));
					assert(0);
					0;
				}))))))))) ;
				MPI_Status stat ;
				int readed ;
				MPI_File_write((((MPI_File *)pfile))[0], pdimarray, dim, mdt, & (stat));
				MPI_Get_count(& (stat), mdt, & (readed));
				readed;
			})));
			if((version == 1)) {
				assert((dim == ({
					MPI_Datatype mdt = (((sizeof(int64_t) == 1))?(MPI_CHAR):((((sizeof(int64_t) == 2))?(MPI_SHORT):((((sizeof(int64_t) == 4))?(MPI_INT):((((sizeof(int64_t) == 8))?(MPI_LONG_LONG):(({
						fprintf(stderr, "unknown type length %d\n", sizeof(int64_t));
						assert(0);
						0;
					}))))))))) ;
					MPI_Status stat ;
					int readed ;
					MPI_File_write((((MPI_File *)pfile))[0], pblockarray, dim, mdt, & (stat));
					MPI_Get_count(& (stat), mdt, & (readed));
					readed;
				})));
			} else {
				0;
			}
		} else {
			0;
		}
	}
	return 0 ;
}
int GAPS_IO_InitOFile(Gaps_IO_DataFile *pthis,char *pName) {
	int64_t version = (pthis)->version ;
	int64_t type = (pthis)->type ;
	int64_t dim = (pthis)->dim ;
	int64_t *pdimarray = (pthis)->pdimarray ;
	int64_t *pblockarray = (pthis)->pblockarray ;
	int64_t numperstep = (pthis)->numperstep ;
	FILE *pfile = (pthis)->pfile ;
	return GAPS_IO_InitOFile_with_TimeStep(pthis, pName, -1) ;
}
int GAPS_IO_GetTypeLen(int type) {
	assert(((type * sizeof(int)) < sizeof(GAPS_IO_GlobalTypeLen)));
	return (GAPS_IO_GlobalTypeLen)[type] ;
}
int GAPS_IO_InitIFilePointer(Gaps_IO_DataFile *pthis,FILE *fp) {
	int64_t version = (pthis)->version ;
	int64_t type = (pthis)->type ;
	int64_t dim = (pthis)->dim ;
	int64_t *pdimarray = (pthis)->pdimarray ;
	int64_t *pblockarray = (pthis)->pblockarray ;
	int64_t numperstep = (pthis)->numperstep ;
	FILE *pfile = (pthis)->pfile ;
	(pfile = fp);
	((pthis)->pfile = pfile);
	assert((1 == ({
		MPI_Datatype mdt = (((sizeof(int64_t) == 1))?(MPI_CHAR):((((sizeof(int64_t) == 2))?(MPI_SHORT):((((sizeof(int64_t) == 4))?(MPI_INT):((((sizeof(int64_t) == 8))?(MPI_LONG_LONG):(({
			fprintf(stderr, "unknown type length %d\n", sizeof(int64_t));
			assert(0);
			0;
		}))))))))) ;
		MPI_Status stat ;
		int readed ;
		MPI_File_read((((MPI_File *)pfile))[0], & (version), 1, mdt, & (stat));
		MPI_Get_count(& (stat), mdt, & (readed));
		readed;
	})));
	assert(((version == 0) || (version == 1)));
	((pthis)->version = version);
	assert((1 == ({
		MPI_Datatype mdt = (((sizeof(int64_t) == 1))?(MPI_CHAR):((((sizeof(int64_t) == 2))?(MPI_SHORT):((((sizeof(int64_t) == 4))?(MPI_INT):((((sizeof(int64_t) == 8))?(MPI_LONG_LONG):(({
			fprintf(stderr, "unknown type length %d\n", sizeof(int64_t));
			assert(0);
			0;
		}))))))))) ;
		MPI_Status stat ;
		int readed ;
		MPI_File_read((((MPI_File *)pfile))[0], & (type), 1, mdt, & (stat));
		MPI_Get_count(& (stat), mdt, & (readed));
		readed;
	})));
	assert(((type * sizeof(int)) < sizeof(GAPS_IO_GlobalTypeLen)));
	((pthis)->type = type);
	assert((1 == ({
		MPI_Datatype mdt = (((sizeof(int64_t) == 1))?(MPI_CHAR):((((sizeof(int64_t) == 2))?(MPI_SHORT):((((sizeof(int64_t) == 4))?(MPI_INT):((((sizeof(int64_t) == 8))?(MPI_LONG_LONG):(({
			fprintf(stderr, "unknown type length %d\n", sizeof(int64_t));
			assert(0);
			0;
		}))))))))) ;
		MPI_Status stat ;
		int readed ;
		MPI_File_read((((MPI_File *)pfile))[0], & (dim), 1, mdt, & (stat));
		MPI_Get_count(& (stat), mdt, & (readed));
		readed;
	})));
	((pthis)->dim = dim);
	(pdimarray = malloc((dim * sizeof(int64_t))));
	assert(pdimarray);
	(pblockarray = malloc((dim * sizeof(int64_t))));
	assert(pblockarray);
	assert((dim == ({
		MPI_Datatype mdt = (((sizeof(int64_t) == 1))?(MPI_CHAR):((((sizeof(int64_t) == 2))?(MPI_SHORT):((((sizeof(int64_t) == 4))?(MPI_INT):((((sizeof(int64_t) == 8))?(MPI_LONG_LONG):(({
			fprintf(stderr, "unknown type length %d\n", sizeof(int64_t));
			assert(0);
			0;
		}))))))))) ;
		MPI_Status stat ;
		int readed ;
		MPI_File_read((((MPI_File *)pfile))[0], pdimarray, dim, mdt, & (stat));
		MPI_Get_count(& (stat), mdt, & (readed));
		readed;
	})));
	((pthis)->pdimarray = pdimarray);
	if((version == 1)) {
		assert((dim == ({
			MPI_Datatype mdt = (((sizeof(int64_t) == 1))?(MPI_CHAR):((((sizeof(int64_t) == 2))?(MPI_SHORT):((((sizeof(int64_t) == 4))?(MPI_INT):((((sizeof(int64_t) == 8))?(MPI_LONG_LONG):(({
				fprintf(stderr, "unknown type length %d\n", sizeof(int64_t));
				assert(0);
				0;
			}))))))))) ;
			MPI_Status stat ;
			int readed ;
			MPI_File_read((((MPI_File *)pfile))[0], pblockarray, dim, mdt, & (stat));
			MPI_Get_count(& (stat), mdt, & (readed));
			readed;
		})));
	} else {
		{
			long i ;
			for((i = 0) ; (i < dim) ; (i = (i + 1))) {
				((pblockarray)[i] = 1);
			}
		}
	}
	((pthis)->pblockarray = pblockarray);
	(numperstep = 1);
	long i = 0 ;
	for(i=0 ; i<dim ; i++) {
		(numperstep = (numperstep * ((pdimarray)[i] * (pblockarray)[i])));
		assert((numperstep > 0));
	}
	((pthis)->numperstep = numperstep);
	return 0 ;
}
int GAPS_IO_FileGotoBegin(Gaps_IO_DataFile *pthis) {
	int64_t version = (pthis)->version ;
	int64_t type = (pthis)->type ;
	int64_t dim = (pthis)->dim ;
	int64_t *pdimarray = (pthis)->pdimarray ;
	int64_t *pblockarray = (pthis)->pblockarray ;
	int64_t numperstep = (pthis)->numperstep ;
	FILE *pfile = (pthis)->pfile ;
	return MPI_File_seek((((MPI_File *)pfile))[0], ((3 + ((((version == 0))?(1):(2)) * dim)) * sizeof(int64_t)), MPI_SEEK_SET) ;
}
int GAPS_IO_InitIFile(Gaps_IO_DataFile *pthis,char *pName) {
	int64_t version = (pthis)->version ;
	int64_t type = (pthis)->type ;
	int64_t dim = (pthis)->dim ;
	int64_t *pdimarray = (pthis)->pdimarray ;
	int64_t *pblockarray = (pthis)->pblockarray ;
	int64_t numperstep = (pthis)->numperstep ;
	FILE *pfile = (pthis)->pfile ;
	(pfile = ({
		MPI_File *fp = malloc(sizeof(MPI_File)) ;
		int ret = MPI_File_open(MPI_COMM_WORLD, pName, MPI_MODE_RDWR, MPI_INFO_NULL, fp) ;
		if(ret) {
			free(fp);
			(fp = NULL);
		} else {
			0;
		}
		fp;
	}));
	assert(pfile);
	return GAPS_IO_InitIFilePointer(pthis, pfile) ;
}
int GAPS_IO_FRead(Gaps_IO_DataFile *pthis,void *pData,int64_t NumData) {
	int64_t version = (pthis)->version ;
	int64_t type = (pthis)->type ;
	int64_t dim = (pthis)->dim ;
	int64_t *pdimarray = (pthis)->pdimarray ;
	int64_t *pblockarray = (pthis)->pblockarray ;
	int64_t numperstep = (pthis)->numperstep ;
	FILE *pfile = (pthis)->pfile ;
	if((NumData < 0)) {
		(NumData = numperstep);
	} else {
		0;
	}
	return ({
		MPI_Datatype mdt = ((((GAPS_IO_GlobalTypeLen)[type] == 1))?(MPI_CHAR):(((((GAPS_IO_GlobalTypeLen)[type] == 2))?(MPI_SHORT):(((((GAPS_IO_GlobalTypeLen)[type] == 4))?(MPI_INT):(((((GAPS_IO_GlobalTypeLen)[type] == 8))?(MPI_LONG_LONG):(({
			fprintf(stderr, "unknown type length %d\n", (GAPS_IO_GlobalTypeLen)[type]);
			assert(0);
			0;
		}))))))))) ;
		MPI_Status stat ;
		int readed ;
		MPI_File_read((((MPI_File *)pfile))[0], pData, NumData, mdt, & (stat));
		MPI_Get_count(& (stat), mdt, & (readed));
		readed;
	}) ;
}
int GAPS_IO_FWrite(Gaps_IO_DataFile *pthis,void *pData,int64_t NumData) {
	int64_t version = (pthis)->version ;
	int64_t type = (pthis)->type ;
	int64_t dim = (pthis)->dim ;
	int64_t *pdimarray = (pthis)->pdimarray ;
	int64_t *pblockarray = (pthis)->pblockarray ;
	int64_t numperstep = (pthis)->numperstep ;
	FILE *pfile = (pthis)->pfile ;
	if((NumData < 0)) {
		(NumData = numperstep);
	} else {
		0;
	}
	return ({
		MPI_Datatype mdt = ((((GAPS_IO_GlobalTypeLen)[type] == 1))?(MPI_CHAR):(((((GAPS_IO_GlobalTypeLen)[type] == 2))?(MPI_SHORT):(((((GAPS_IO_GlobalTypeLen)[type] == 4))?(MPI_INT):(((((GAPS_IO_GlobalTypeLen)[type] == 8))?(MPI_LONG_LONG):(({
			fprintf(stderr, "unknown type length %d\n", (GAPS_IO_GlobalTypeLen)[type]);
			assert(0);
			0;
		}))))))))) ;
		MPI_Status stat ;
		int readed ;
		MPI_File_write((((MPI_File *)pfile))[0], pData, NumData, mdt, & (stat));
		MPI_Get_count(& (stat), mdt, & (readed));
		readed;
	}) ;
}
int GAPS_IO_FWriteALL(Gaps_IO_DataFile *pthis,void *pData,int64_t NumData) {
	int64_t version = (pthis)->version ;
	int64_t type = (pthis)->type ;
	int64_t dim = (pthis)->dim ;
	int64_t *pdimarray = (pthis)->pdimarray ;
	int64_t *pblockarray = (pthis)->pblockarray ;
	int64_t numperstep = (pthis)->numperstep ;
	FILE *pfile = (pthis)->pfile ;
	if((NumData < 0)) {
		(NumData = numperstep);
	} else {
		0;
	}
	return ({
		MPI_Datatype mdt = ((((GAPS_IO_GlobalTypeLen)[type] == 1))?(MPI_CHAR):(((((GAPS_IO_GlobalTypeLen)[type] == 2))?(MPI_SHORT):(((((GAPS_IO_GlobalTypeLen)[type] == 4))?(MPI_INT):(((((GAPS_IO_GlobalTypeLen)[type] == 8))?(MPI_LONG_LONG):(({
			fprintf(stderr, "unknown type length %d\n", (GAPS_IO_GlobalTypeLen)[type]);
			assert(0);
			0;
		}))))))))) ;
		MPI_Status stat ;
		int readed ;
		MPI_File_write_all((((MPI_File *)pfile))[0], pData, NumData, mdt, & (stat));
		MPI_Get_count(& (stat), mdt, & (readed));
		readed;
	}) ;
}
int GAPS_IO_DataNumStepsAndResidue(Gaps_IO_DataFile *pthis,int64_t *pNumsteps,int64_t *pResidue) {
	int64_t version = (pthis)->version ;
	int64_t type = (pthis)->type ;
	int64_t dim = (pthis)->dim ;
	int64_t *pdimarray = (pthis)->pdimarray ;
	int64_t *pblockarray = (pthis)->pblockarray ;
	int64_t numperstep = (pthis)->numperstep ;
	FILE *pfile = (pthis)->pfile ;
	MPI_Offset end_pos ;
	MPI_File_get_size((((MPI_File *)pfile))[0], & (end_pos));
	(end_pos = ((end_pos - ((((((version == 0))?(1):(2)) * dim) + 3) * (GAPS_IO_GlobalTypeLen)[type])) / (GAPS_IO_GlobalTypeLen)[type]));
	((pNumsteps)[0] = (end_pos / numperstep));
	((pResidue)[0] = (end_pos % numperstep));
	return 0 ;
}
int GAPS_IO_DeleteDataInfo(Gaps_IO_DataFile *pthis) {
	int64_t version = (pthis)->version ;
	int64_t type = (pthis)->type ;
	int64_t dim = (pthis)->dim ;
	int64_t *pdimarray = (pthis)->pdimarray ;
	int64_t *pblockarray = (pthis)->pblockarray ;
	int64_t numperstep = (pthis)->numperstep ;
	FILE *pfile = (pthis)->pfile ;
	if(pfile) {
		MPI_File_close(((MPI_File *)pfile));
		free(pfile);
	} else {
		0;
	}
	free(pdimarray);
	return 0 ;
}
int GAPS_IO_TruncateFile(Gaps_IO_DataFile *pthis,int64_t NumSteps,int64_t NumData) {
	int64_t version = (pthis)->version ;
	int64_t type = (pthis)->type ;
	int64_t dim = (pthis)->dim ;
	int64_t *pdimarray = (pthis)->pdimarray ;
	int64_t *pblockarray = (pthis)->pblockarray ;
	int64_t numperstep = (pthis)->numperstep ;
	FILE *pfile = (pthis)->pfile ;
	if((NumData < 0)) {
		(NumData = numperstep);
	} else {
		0;
	}
	return MPI_File_set_size((((MPI_File *)pfile))[0], ((NumSteps * (NumData * (GAPS_IO_GlobalTypeLen)[type])) + (sizeof(int64_t) * (3 + ((((version == 0))?(1):(2)) * dim))))) ;
}
