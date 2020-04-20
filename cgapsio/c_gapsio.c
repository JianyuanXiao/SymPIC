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
	char *prefix ;
	int64_t *locations ;
	int64_t block_len ;
	int64_t num_block_current_proc ;
	int64_t time_step_current ;
	int64_t num_block_all_reduce_group ;
	int num_reduce_proc ;
	int cur_rank ;
	int send_to_proc ;
	int real_rank ;
} Gaps_IO_DataFile;
typedef enum {GAPS_IO_CONST_INT32,GAPS_IO_INT64,GAPS_IO_INT16,GAPS_IO_UINT32,GAPS_IO_UINT64,GAPS_IO_UINT16,GAPS_IO_FLOAT32,GAPS_IO_FLOAT64,GAPS_IO_INT128,GAPS_IO_UINT128,GAPS_IO_FLOAT128,GAPS_IO_INT8,GAPS_IO_UINT8} Gaps_IO_Type;
#include <mpi.h>

static int GAPS_IO_GlobalTypeLen[]= {4,8,2,4,8,2,4,8,16,16,16,1,1};
int GAPS_IO_SetNumReduceProc(Gaps_IO_DataFile *pOutfile,int Num_reduce_proc) {
	((pOutfile)->num_reduce_proc = Num_reduce_proc);
	int cur_rank ;
	MPI_Comm_rank(MPI_COMM_WORLD, & (cur_rank));
	((pOutfile)->cur_rank = cur_rank);
	((pOutfile)->real_rank = (cur_rank / Num_reduce_proc));
	((pOutfile)->send_to_proc = ((cur_rank / Num_reduce_proc) * Num_reduce_proc));
	return 0 ;
}
int GAPS_IO_InitDataInfoV2(Gaps_IO_DataFile *pOutfile,char *Prefix,int64_t Type,int64_t Dim,int64_t *pDimarray,int64_t *pBlockarray,int64_t *pLocationarray,int64_t Num_block_current_proc,int64_t time_step_current) {
	GAPS_IO_InitDataInfoV1(pOutfile, Type, Dim, pDimarray, pBlockarray);
	((pOutfile)->num_reduce_proc = 0);
	((pOutfile)->cur_rank = 0);
	((pOutfile)->send_to_proc = 0);
	((pOutfile)->real_rank = 0);
	((pOutfile)->prefix = malloc(512));
	strncpy((pOutfile)->prefix, Prefix, 512);
	((pOutfile)->version = 2);
	int64_t numlocations = 1 ;
	int64_t block_len = 1 ;
	{
		long i ;
		for((i = 0) ; (i < Dim) ; (i = (i + 1))) {
			(block_len = (block_len * (pDimarray)[i]));
		}
	}
	((pOutfile)->locations = malloc((Num_block_current_proc * sizeof(int64_t))));
	{
		long i ;
		for((i = 0) ; (i < Num_block_current_proc) ; (i = (i + 1))) {
			(((pOutfile)->locations)[i] = (pLocationarray)[i]);
		}
	}
	((pOutfile)->block_len = block_len);
	((pOutfile)->num_block_current_proc = Num_block_current_proc);
	((pOutfile)->time_step_current = time_step_current);
	return 0 ;
}
int GAPS_IO_InitDataInfoV1(Gaps_IO_DataFile *pOutfile,int64_t Type,int64_t Dim,int64_t *pDimarray,int64_t *pBlockarray) {
	((pOutfile)->dim = Dim);
	size_t dimarrlen = (sizeof(int64_t) * Dim) ;
	((pOutfile)->pdimarray = malloc(dimarrlen));
	((pOutfile)->pblockarray = malloc(dimarrlen));
	((pOutfile)->num_reduce_proc = 0);
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
	((pOutfile)->num_reduce_proc = 0);
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
	char *prefix = (pthis)->prefix ;
	int64_t *locations = (pthis)->locations ;
	int64_t block_len = (pthis)->block_len ;
	int64_t num_block_current_proc = (pthis)->num_block_current_proc ;
	int64_t time_step_current = (pthis)->time_step_current ;
	int64_t num_block_all_reduce_group = (pthis)->num_block_all_reduce_group ;
	int num_reduce_proc = (pthis)->num_reduce_proc ;
	int cur_rank = (pthis)->cur_rank ;
	int send_to_proc = (pthis)->send_to_proc ;
	int real_rank = (pthis)->real_rank ;
	if(((version < 2) || ((cur_rank == send_to_proc) || (! num_reduce_proc)))) {
		if((version >= 2)) {
			fflush(pfile);
		} else {
			{
				MPI_File_sync((((MPI_File *)pfile))[0]);
			}
		}
	} else {
		0;
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
	char *prefix = (pthis)->prefix ;
	int64_t *locations = (pthis)->locations ;
	int64_t block_len = (pthis)->block_len ;
	int64_t num_block_current_proc = (pthis)->num_block_current_proc ;
	int64_t time_step_current = (pthis)->time_step_current ;
	int64_t num_block_all_reduce_group = (pthis)->num_block_all_reduce_group ;
	int num_reduce_proc = (pthis)->num_reduce_proc ;
	int cur_rank = (pthis)->cur_rank ;
	int send_to_proc = (pthis)->send_to_proc ;
	int real_rank = (pthis)->real_rank ;
	long ret = ((((version < 2) || ((cur_rank == send_to_proc) || (! num_reduce_proc))))?((((version >= 2))?(fseek(pfile, (((GAPS_IO_GlobalTypeLen)[type] * (Offset + (Step * (((version < 2))?(numperstep):((((num_reduce_proc)?(num_block_all_reduce_group):(num_block_current_proc)) * block_len)))))) + (sizeof(int64_t) * (3 + ((((version == 0))?(1):(2)) * dim)))), SEEK_SET)):(MPI_File_seek((((MPI_File *)pfile))[0], (((GAPS_IO_GlobalTypeLen)[type] * (Offset + (Step * (((version < 2))?(numperstep):((((num_reduce_proc)?(num_block_all_reduce_group):(num_block_current_proc)) * block_len)))))) + (sizeof(int64_t) * (3 + ((((version == 0))?(1):(2)) * dim)))), MPI_SEEK_SET)))):(0)) ;
	assert((ret == 0));
	return 0 ;
}
int GAPS_IO_InitOFile_with_TimeStepV2(Gaps_IO_DataFile *pthis,char *pName,char *pNamePrefix,int64_t timestep) {
	int64_t version = (pthis)->version ;
	int64_t type = (pthis)->type ;
	int64_t dim = (pthis)->dim ;
	int64_t *pdimarray = (pthis)->pdimarray ;
	int64_t *pblockarray = (pthis)->pblockarray ;
	int64_t numperstep = (pthis)->numperstep ;
	FILE *pfile = (pthis)->pfile ;
	char *prefix = (pthis)->prefix ;
	int64_t *locations = (pthis)->locations ;
	int64_t block_len = (pthis)->block_len ;
	int64_t num_block_current_proc = (pthis)->num_block_current_proc ;
	int64_t time_step_current = (pthis)->time_step_current ;
	int64_t num_block_all_reduce_group = (pthis)->num_block_all_reduce_group ;
	int num_reduce_proc = (pthis)->num_reduce_proc ;
	int cur_rank = (pthis)->cur_rank ;
	int send_to_proc = (pthis)->send_to_proc ;
	int real_rank = (pthis)->real_rank ;
	int rank = 0 ;
	MPI_Comm_rank(MPI_COMM_WORLD, & (rank));
	if(num_reduce_proc) {
		(rank = (rank / num_reduce_proc));
	} else {
		0;
	}
	return GAPS_IO_InitOFile_with_TimeStepV2_withrank(pthis, pName, pNamePrefix, timestep, rank) ;
}
int GAPS_IO_InitOFile_with_TimeStepV2_withrank(Gaps_IO_DataFile *pthis,char *pName,char *pNamePrefix,int64_t timestep,long rank) {
	int64_t version = (pthis)->version ;
	int64_t type = (pthis)->type ;
	int64_t dim = (pthis)->dim ;
	int64_t *pdimarray = (pthis)->pdimarray ;
	int64_t *pblockarray = (pthis)->pblockarray ;
	int64_t numperstep = (pthis)->numperstep ;
	FILE *pfile = (pthis)->pfile ;
	char *prefix = (pthis)->prefix ;
	int64_t *locations = (pthis)->locations ;
	int64_t block_len = (pthis)->block_len ;
	int64_t num_block_current_proc = (pthis)->num_block_current_proc ;
	int64_t time_step_current = (pthis)->time_step_current ;
	int64_t num_block_all_reduce_group = (pthis)->num_block_all_reduce_group ;
	int num_reduce_proc = (pthis)->num_reduce_proc ;
	int cur_rank = (pthis)->cur_rank ;
	int send_to_proc = (pthis)->send_to_proc ;
	int real_rank = (pthis)->real_rank ;
	const size_t max_len = 512 ;
	char pNameReal [max_len];
	if((version > 1)) {
		int ret = snprintf(pNameReal, max_len, "%s%s_PROC_%ld", pNamePrefix, pName, rank) ;
		if((ret > (max_len - 2))) {
			fprintf(stderr, "rank %d Error: Maximum length of one file is 510\n", rank);
			assert(0);
		} else {
			0;
		}
	} else {
		0;
	}
	if(((version < 2) || ((cur_rank == send_to_proc) || (! num_reduce_proc)))) {
		if((timestep != -1)) {
			(pfile = (((version >= 2))?(fopen((((version < 2))?(pName):(pNameReal)), "r+")):(({
				MPI_File *fp = malloc(sizeof(MPI_File)) ;
				int ret = MPI_File_open(MPI_COMM_WORLD, (((version < 2))?(pName):(pNameReal)), MPI_MODE_RDWR, MPI_INFO_NULL, fp) ;
				if(ret) {
					free(fp);
					(fp = NULL);
				} else {
					0;
				}
				fp;
			}))));
		} else {
			(pfile = (((version >= 2))?(fopen((((version < 2))?(pName):(pNameReal)), "w+")):(({
				MPI_File *fp = malloc(sizeof(MPI_File)) ;
				int ret = MPI_File_open(MPI_COMM_WORLD, (((version < 2))?(pName):(pNameReal)), (MPI_MODE_RDWR | MPI_MODE_CREATE), MPI_INFO_NULL, fp) ;
				MPI_File_set_size((fp)[0], 0);
				if(ret) {
					free(fp);
					(fp = NULL);
				} else {
					0;
				}
				fp;
			}))));
		}
		assert(pfile);
	} else {
		0;
	}
	((pthis)->pfile = pfile);
	if((version > 1)) {
		snprintf(pNameReal, max_len, "%s%s_META_%d", pNamePrefix, pName, rank);
		if(((version < 2) || ((cur_rank == send_to_proc) || (! num_reduce_proc)))) {
			{
				FILE *fp = fopen(pNameReal, "w+") ;
				fwrite(locations, sizeof(int64_t), num_block_current_proc, fp);
				((pthis)->num_block_all_reduce_group = num_block_current_proc);
				{
					long n ;
					for((n = (cur_rank + 1)) ; (n < (num_reduce_proc * (real_rank + 1))) ; (n = (n + 1))) {
						int num_proc ;
						MPI_Comm_size(MPI_COMM_WORLD, & (num_proc));
						if((n >= num_proc)) {
							break;
						} else {
							0;
						}
						int64_t nxt_size ;
						MPI_Status s1 ;
						MPI_Recv(& (nxt_size), 1, MPI_INT64_T, n, n, MPI_COMM_WORLD, & (s1));
						((pthis)->num_block_all_reduce_group = ((pthis)->num_block_all_reduce_group + nxt_size));
						int64_t *meta_offs = malloc((sizeof(int64_t) * nxt_size)) ;
						MPI_Recv(meta_offs, nxt_size, MPI_INT64_T, n, n, MPI_COMM_WORLD, & (s1));
						fwrite(meta_offs, sizeof(int64_t), nxt_size, fp);
						free(meta_offs);
					}
				}
				fclose(fp);
			}
		} else {
			{
				MPI_Send(& (num_block_current_proc), 1, MPI_INT64_T, send_to_proc, cur_rank, MPI_COMM_WORLD);
				MPI_Send(locations, num_block_current_proc, MPI_INT64_T, send_to_proc, cur_rank, MPI_COMM_WORLD);
			}
		}
	} else {
		0;
	}
	if((timestep != -1)) {
		GAPS_IO_DataSeek(pthis, timestep, 0);
	} else {
		if(((0 == rank) || (version == 2))) {
			if(((version < 2) || ((cur_rank == send_to_proc) || (! num_reduce_proc)))) {
				assert((1 == (((version >= 2))?(fwrite(& (version), sizeof(int64_t), 1, pfile)):(({
					MPI_Datatype mdt = (((sizeof(int64_t) == 1))?(MPI_CHAR):((((sizeof(int64_t) == 2))?(MPI_SHORT):((((sizeof(int64_t) == 4))?(MPI_INT):((((sizeof(int64_t) == 8))?(MPI_LONG_LONG):(({
						fprintf(stderr, "unknown type length %d\n", sizeof(int64_t));
						assert(0);
						0;
					}))))))))) ;
					MPI_Status stat ;
					int64_t readed = 0 ;
					int mpi_rdd ;
					int64_t cnt = 1 ;
					int64_t cur_rd = 0 ;
					for(0 ; (cur_rd < cnt) ; (cur_rd = (cur_rd + 134217728))) {
						if(((cur_rd + 134217728) < cnt)) {
							(mpi_rdd = 134217728);
						} else {
							(mpi_rdd = (cnt - cur_rd));
						}
						MPI_File_write((((MPI_File *)pfile))[0], (((void *)& (version)) + (cur_rd * sizeof(int64_t))), mpi_rdd, mdt, & (stat));
						MPI_Get_count(& (stat), mdt, & (mpi_rdd));
						(readed = (readed + mpi_rdd));
					}
					readed;
				})))));
				assert((1 == (((version >= 2))?(fwrite(& (type), sizeof(int64_t), 1, pfile)):(({
					MPI_Datatype mdt = (((sizeof(int64_t) == 1))?(MPI_CHAR):((((sizeof(int64_t) == 2))?(MPI_SHORT):((((sizeof(int64_t) == 4))?(MPI_INT):((((sizeof(int64_t) == 8))?(MPI_LONG_LONG):(({
						fprintf(stderr, "unknown type length %d\n", sizeof(int64_t));
						assert(0);
						0;
					}))))))))) ;
					MPI_Status stat ;
					int64_t readed = 0 ;
					int mpi_rdd ;
					int64_t cnt = 1 ;
					int64_t cur_rd = 0 ;
					for(0 ; (cur_rd < cnt) ; (cur_rd = (cur_rd + 134217728))) {
						if(((cur_rd + 134217728) < cnt)) {
							(mpi_rdd = 134217728);
						} else {
							(mpi_rdd = (cnt - cur_rd));
						}
						MPI_File_write((((MPI_File *)pfile))[0], (((void *)& (type)) + (cur_rd * sizeof(int64_t))), mpi_rdd, mdt, & (stat));
						MPI_Get_count(& (stat), mdt, & (mpi_rdd));
						(readed = (readed + mpi_rdd));
					}
					readed;
				})))));
				assert((1 == (((version >= 2))?(fwrite(& (dim), sizeof(int64_t), 1, pfile)):(({
					MPI_Datatype mdt = (((sizeof(int64_t) == 1))?(MPI_CHAR):((((sizeof(int64_t) == 2))?(MPI_SHORT):((((sizeof(int64_t) == 4))?(MPI_INT):((((sizeof(int64_t) == 8))?(MPI_LONG_LONG):(({
						fprintf(stderr, "unknown type length %d\n", sizeof(int64_t));
						assert(0);
						0;
					}))))))))) ;
					MPI_Status stat ;
					int64_t readed = 0 ;
					int mpi_rdd ;
					int64_t cnt = 1 ;
					int64_t cur_rd = 0 ;
					for(0 ; (cur_rd < cnt) ; (cur_rd = (cur_rd + 134217728))) {
						if(((cur_rd + 134217728) < cnt)) {
							(mpi_rdd = 134217728);
						} else {
							(mpi_rdd = (cnt - cur_rd));
						}
						MPI_File_write((((MPI_File *)pfile))[0], (((void *)& (dim)) + (cur_rd * sizeof(int64_t))), mpi_rdd, mdt, & (stat));
						MPI_Get_count(& (stat), mdt, & (mpi_rdd));
						(readed = (readed + mpi_rdd));
					}
					readed;
				})))));
				assert((dim == (((version >= 2))?(fwrite(pdimarray, sizeof(int64_t), dim, pfile)):(({
					MPI_Datatype mdt = (((sizeof(int64_t) == 1))?(MPI_CHAR):((((sizeof(int64_t) == 2))?(MPI_SHORT):((((sizeof(int64_t) == 4))?(MPI_INT):((((sizeof(int64_t) == 8))?(MPI_LONG_LONG):(({
						fprintf(stderr, "unknown type length %d\n", sizeof(int64_t));
						assert(0);
						0;
					}))))))))) ;
					MPI_Status stat ;
					int64_t readed = 0 ;
					int mpi_rdd ;
					int64_t cnt = dim ;
					int64_t cur_rd = 0 ;
					for(0 ; (cur_rd < cnt) ; (cur_rd = (cur_rd + 134217728))) {
						if(((cur_rd + 134217728) < cnt)) {
							(mpi_rdd = 134217728);
						} else {
							(mpi_rdd = (cnt - cur_rd));
						}
						MPI_File_write((((MPI_File *)pfile))[0], (((void *)pdimarray) + (cur_rd * sizeof(int64_t))), mpi_rdd, mdt, & (stat));
						MPI_Get_count(& (stat), mdt, & (mpi_rdd));
						(readed = (readed + mpi_rdd));
					}
					readed;
				})))));
				if((version >= 1)) {
					assert((dim == (((version >= 2))?(fwrite(pblockarray, sizeof(int64_t), dim, pfile)):(({
						MPI_Datatype mdt = (((sizeof(int64_t) == 1))?(MPI_CHAR):((((sizeof(int64_t) == 2))?(MPI_SHORT):((((sizeof(int64_t) == 4))?(MPI_INT):((((sizeof(int64_t) == 8))?(MPI_LONG_LONG):(({
							fprintf(stderr, "unknown type length %d\n", sizeof(int64_t));
							assert(0);
							0;
						}))))))))) ;
						MPI_Status stat ;
						int64_t readed = 0 ;
						int mpi_rdd ;
						int64_t cnt = dim ;
						int64_t cur_rd = 0 ;
						for(0 ; (cur_rd < cnt) ; (cur_rd = (cur_rd + 134217728))) {
							if(((cur_rd + 134217728) < cnt)) {
								(mpi_rdd = 134217728);
							} else {
								(mpi_rdd = (cnt - cur_rd));
							}
							MPI_File_write((((MPI_File *)pfile))[0], (((void *)pblockarray) + (cur_rd * sizeof(int64_t))), mpi_rdd, mdt, & (stat));
							MPI_Get_count(& (stat), mdt, & (mpi_rdd));
							(readed = (readed + mpi_rdd));
						}
						readed;
					})))));
				} else {
					0;
				}
			} else {
				0;
			}
		} else {
			0;
		}
	}
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
	char *prefix = (pthis)->prefix ;
	int64_t *locations = (pthis)->locations ;
	int64_t block_len = (pthis)->block_len ;
	int64_t num_block_current_proc = (pthis)->num_block_current_proc ;
	int64_t time_step_current = (pthis)->time_step_current ;
	int64_t num_block_all_reduce_group = (pthis)->num_block_all_reduce_group ;
	int num_reduce_proc = (pthis)->num_reduce_proc ;
	int cur_rank = (pthis)->cur_rank ;
	int send_to_proc = (pthis)->send_to_proc ;
	int real_rank = (pthis)->real_rank ;
	return GAPS_IO_InitOFile_with_TimeStepV2(pthis, pName, "", timestep) ;
}
int GAPS_IO_InitOFile(Gaps_IO_DataFile *pthis,char *pName) {
	int64_t version = (pthis)->version ;
	int64_t type = (pthis)->type ;
	int64_t dim = (pthis)->dim ;
	int64_t *pdimarray = (pthis)->pdimarray ;
	int64_t *pblockarray = (pthis)->pblockarray ;
	int64_t numperstep = (pthis)->numperstep ;
	FILE *pfile = (pthis)->pfile ;
	char *prefix = (pthis)->prefix ;
	int64_t *locations = (pthis)->locations ;
	int64_t block_len = (pthis)->block_len ;
	int64_t num_block_current_proc = (pthis)->num_block_current_proc ;
	int64_t time_step_current = (pthis)->time_step_current ;
	int64_t num_block_all_reduce_group = (pthis)->num_block_all_reduce_group ;
	int num_reduce_proc = (pthis)->num_reduce_proc ;
	int cur_rank = (pthis)->cur_rank ;
	int send_to_proc = (pthis)->send_to_proc ;
	int real_rank = (pthis)->real_rank ;
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
	char *prefix = (pthis)->prefix ;
	int64_t *locations = (pthis)->locations ;
	int64_t block_len = (pthis)->block_len ;
	int64_t num_block_current_proc = (pthis)->num_block_current_proc ;
	int64_t time_step_current = (pthis)->time_step_current ;
	int64_t num_block_all_reduce_group = (pthis)->num_block_all_reduce_group ;
	int num_reduce_proc = (pthis)->num_reduce_proc ;
	int cur_rank = (pthis)->cur_rank ;
	int send_to_proc = (pthis)->send_to_proc ;
	int real_rank = (pthis)->real_rank ;
	(pfile = fp);
	((pthis)->pfile = pfile);
	assert((1 == (((version >= 2))?(fread(& (version), sizeof(int64_t), 1, pfile)):(({
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
	})))));
	assert(((version == 0) || ((version == 1) || (version == 2))));
	((pthis)->version = version);
	assert((1 == (((version >= 2))?(fread(& (type), sizeof(int64_t), 1, pfile)):(({
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
	})))));
	assert(((type * sizeof(int)) < sizeof(GAPS_IO_GlobalTypeLen)));
	((pthis)->type = type);
	assert((1 == (((version >= 2))?(fread(& (dim), sizeof(int64_t), 1, pfile)):(({
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
	})))));
	((pthis)->dim = dim);
	(pdimarray = malloc((dim * sizeof(int64_t))));
	assert(pdimarray);
	(pblockarray = malloc((dim * sizeof(int64_t))));
	assert(pblockarray);
	assert((dim == (((version >= 2))?(fread(pdimarray, sizeof(int64_t), dim, pfile)):(({
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
	})))));
	((pthis)->pdimarray = pdimarray);
	if((version >= 1)) {
		assert((dim == (((version >= 2))?(fread(pblockarray, sizeof(int64_t), dim, pfile)):(({
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
		})))));
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
	char *prefix = (pthis)->prefix ;
	int64_t *locations = (pthis)->locations ;
	int64_t block_len = (pthis)->block_len ;
	int64_t num_block_current_proc = (pthis)->num_block_current_proc ;
	int64_t time_step_current = (pthis)->time_step_current ;
	int64_t num_block_all_reduce_group = (pthis)->num_block_all_reduce_group ;
	int num_reduce_proc = (pthis)->num_reduce_proc ;
	int cur_rank = (pthis)->cur_rank ;
	int send_to_proc = (pthis)->send_to_proc ;
	int real_rank = (pthis)->real_rank ;
	return (((version >= 2))?(fseek(pfile, ((3 + ((((version == 0))?(1):(2)) * dim)) * sizeof(int64_t)), SEEK_SET)):(MPI_File_seek((((MPI_File *)pfile))[0], ((3 + ((((version == 0))?(1):(2)) * dim)) * sizeof(int64_t)), MPI_SEEK_SET))) ;
}
int GAPS_IO_InitIFileV2(Gaps_IO_DataFile *pthis,char *pName,char *pNamePrefix,int rank) {
	int64_t version = (pthis)->version ;
	int64_t type = (pthis)->type ;
	int64_t dim = (pthis)->dim ;
	int64_t *pdimarray = (pthis)->pdimarray ;
	int64_t *pblockarray = (pthis)->pblockarray ;
	int64_t numperstep = (pthis)->numperstep ;
	FILE *pfile = (pthis)->pfile ;
	char *prefix = (pthis)->prefix ;
	int64_t *locations = (pthis)->locations ;
	int64_t block_len = (pthis)->block_len ;
	int64_t num_block_current_proc = (pthis)->num_block_current_proc ;
	int64_t time_step_current = (pthis)->time_step_current ;
	int64_t num_block_all_reduce_group = (pthis)->num_block_all_reduce_group ;
	int num_reduce_proc = (pthis)->num_reduce_proc ;
	int cur_rank = (pthis)->cur_rank ;
	int send_to_proc = (pthis)->send_to_proc ;
	int real_rank = (pthis)->real_rank ;
	((pthis)->version = 2);
	const size_t max_len = 512 ;
	char pNameReal [max_len];
	int ret = snprintf(pNameReal, max_len, "%s%s_PROC_%d", pNamePrefix, pName, rank) ;
	if((ret > (max_len - 2))) {
		fprintf(stderr, "rank %d Error: Maximum length of one file is 510\n", rank);
		assert(0);
	} else {
		0;
	}
	(pfile = (((version >= 2))?(fopen(pNameReal, "r+")):(({
		MPI_File *fp = malloc(sizeof(MPI_File)) ;
		int ret = MPI_File_open(MPI_COMM_WORLD, pNameReal, MPI_MODE_RDWR, MPI_INFO_NULL, fp) ;
		if(ret) {
			free(fp);
			(fp = NULL);
		} else {
			0;
		}
		fp;
	}))));
	assert(pfile);
	(ret = GAPS_IO_InitIFilePointer(pthis, pfile));
	(ret = snprintf(pNameReal, max_len, "%s%s_META_%d", pNamePrefix, pName, rank));
	(pfile = fopen(pNameReal, "r"));
	assert(pfile);
	fseek(pfile, 0, SEEK_END);
	long num_end = ftell(pfile) ;
	((pthis)->num_block_current_proc = (num_end / sizeof(int64_t)));
	((pthis)->num_block_all_reduce_group = (pthis)->num_block_current_proc);
	fseek(pfile, 0, SEEK_SET);
	((pthis)->locations = malloc(num_end));
	fread((pthis)->locations, 1, num_end, pfile);
	fclose(pfile);
	int64_t blklen = 1 ;
	{
		long i ;
		for((i = 0) ; (i < (pthis)->dim) ; (i = (i + 1))) {
			(blklen = (blklen * ((pthis)->pdimarray)[i]));
		}
	}
	((pthis)->block_len = blklen);
	((pthis)->time_step_current = 0);
}
int GAPS_IO_InitIFile(Gaps_IO_DataFile *pthis,char *pName) {
	int64_t version = (pthis)->version ;
	int64_t type = (pthis)->type ;
	int64_t dim = (pthis)->dim ;
	int64_t *pdimarray = (pthis)->pdimarray ;
	int64_t *pblockarray = (pthis)->pblockarray ;
	int64_t numperstep = (pthis)->numperstep ;
	FILE *pfile = (pthis)->pfile ;
	char *prefix = (pthis)->prefix ;
	int64_t *locations = (pthis)->locations ;
	int64_t block_len = (pthis)->block_len ;
	int64_t num_block_current_proc = (pthis)->num_block_current_proc ;
	int64_t time_step_current = (pthis)->time_step_current ;
	int64_t num_block_all_reduce_group = (pthis)->num_block_all_reduce_group ;
	int num_reduce_proc = (pthis)->num_reduce_proc ;
	int cur_rank = (pthis)->cur_rank ;
	int send_to_proc = (pthis)->send_to_proc ;
	int real_rank = (pthis)->real_rank ;
	(version = 0);
	((pthis)->version = 0);
	(pfile = (((version >= 2))?(fopen(pName, "r")):(({
		MPI_File *fp = malloc(sizeof(MPI_File)) ;
		int ret = MPI_File_open(MPI_COMM_WORLD, pName, MPI_MODE_RDONLY, MPI_INFO_NULL, fp) ;
		if(ret) {
			free(fp);
			(fp = NULL);
		} else {
			0;
		}
		fp;
	}))));
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
	char *prefix = (pthis)->prefix ;
	int64_t *locations = (pthis)->locations ;
	int64_t block_len = (pthis)->block_len ;
	int64_t num_block_current_proc = (pthis)->num_block_current_proc ;
	int64_t time_step_current = (pthis)->time_step_current ;
	int64_t num_block_all_reduce_group = (pthis)->num_block_all_reduce_group ;
	int num_reduce_proc = (pthis)->num_reduce_proc ;
	int cur_rank = (pthis)->cur_rank ;
	int send_to_proc = (pthis)->send_to_proc ;
	int real_rank = (pthis)->real_rank ;
	if((NumData < 0)) {
		(NumData = (((version < 2))?(numperstep):((((num_reduce_proc)?(num_block_all_reduce_group):(num_block_current_proc)) * block_len))));
	} else {
		0;
	}
	return (((version >= 2))?(fread(pData, (GAPS_IO_GlobalTypeLen)[type], NumData, pfile)):(({
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
	}))) ;
}
int64_t GAPS_IO_FWrite(Gaps_IO_DataFile *pthis,void *pData,int64_t NumData) {
	int64_t version = (pthis)->version ;
	int64_t type = (pthis)->type ;
	int64_t dim = (pthis)->dim ;
	int64_t *pdimarray = (pthis)->pdimarray ;
	int64_t *pblockarray = (pthis)->pblockarray ;
	int64_t numperstep = (pthis)->numperstep ;
	FILE *pfile = (pthis)->pfile ;
	char *prefix = (pthis)->prefix ;
	int64_t *locations = (pthis)->locations ;
	int64_t block_len = (pthis)->block_len ;
	int64_t num_block_current_proc = (pthis)->num_block_current_proc ;
	int64_t time_step_current = (pthis)->time_step_current ;
	int64_t num_block_all_reduce_group = (pthis)->num_block_all_reduce_group ;
	int num_reduce_proc = (pthis)->num_reduce_proc ;
	int cur_rank = (pthis)->cur_rank ;
	int send_to_proc = (pthis)->send_to_proc ;
	int real_rank = (pthis)->real_rank ;
	if((NumData < 0)) {
		(NumData = (((version < 2))?(numperstep):((((num_reduce_proc)?(num_block_all_reduce_group):(num_block_current_proc)) * block_len))));
	} else {
		0;
	}
	return ((((version < 2) || ((cur_rank == send_to_proc) || (! num_reduce_proc))))?((((version >= 2))?(fwrite(pData, (GAPS_IO_GlobalTypeLen)[type], NumData, pfile)):(({
		MPI_Datatype mdt = ((((GAPS_IO_GlobalTypeLen)[type] == 1))?(MPI_CHAR):(((((GAPS_IO_GlobalTypeLen)[type] == 2))?(MPI_SHORT):(((((GAPS_IO_GlobalTypeLen)[type] == 4))?(MPI_INT):(((((GAPS_IO_GlobalTypeLen)[type] == 8))?(MPI_LONG_LONG):(({
			fprintf(stderr, "unknown type length %d\n", (GAPS_IO_GlobalTypeLen)[type]);
			assert(0);
			0;
		}))))))))) ;
		MPI_Status stat ;
		int64_t readed = 0 ;
		int mpi_rdd ;
		int64_t cnt = NumData ;
		int64_t cur_rd = 0 ;
		for(0 ; (cur_rd < cnt) ; (cur_rd = (cur_rd + 134217728))) {
			if(((cur_rd + 134217728) < cnt)) {
				(mpi_rdd = 134217728);
			} else {
				(mpi_rdd = (cnt - cur_rd));
			}
			MPI_File_write((((MPI_File *)pfile))[0], (((void *)pData) + (cur_rd * (GAPS_IO_GlobalTypeLen)[type])), mpi_rdd, mdt, & (stat));
			MPI_Get_count(& (stat), mdt, & (mpi_rdd));
			(readed = (readed + mpi_rdd));
		}
		readed;
	})))):(0)) ;
}
int GAPS_IO_FWriteALL(Gaps_IO_DataFile *pthis,void *pData,int64_t NumData) {
	int64_t version = (pthis)->version ;
	int64_t type = (pthis)->type ;
	int64_t dim = (pthis)->dim ;
	int64_t *pdimarray = (pthis)->pdimarray ;
	int64_t *pblockarray = (pthis)->pblockarray ;
	int64_t numperstep = (pthis)->numperstep ;
	FILE *pfile = (pthis)->pfile ;
	char *prefix = (pthis)->prefix ;
	int64_t *locations = (pthis)->locations ;
	int64_t block_len = (pthis)->block_len ;
	int64_t num_block_current_proc = (pthis)->num_block_current_proc ;
	int64_t time_step_current = (pthis)->time_step_current ;
	int64_t num_block_all_reduce_group = (pthis)->num_block_all_reduce_group ;
	int num_reduce_proc = (pthis)->num_reduce_proc ;
	int cur_rank = (pthis)->cur_rank ;
	int send_to_proc = (pthis)->send_to_proc ;
	int real_rank = (pthis)->real_rank ;
	if((NumData < 0)) {
		(NumData = (((version < 2))?(numperstep):((((num_reduce_proc)?(num_block_all_reduce_group):(num_block_current_proc)) * block_len))));
	} else {
		0;
	}
	return (((version >= 2))?(fwrite(pData, (GAPS_IO_GlobalTypeLen)[type], NumData, pfile)):(({
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
	}))) ;
}
int GAPS_IO_DataNumStepsAndResidue(Gaps_IO_DataFile *pthis,int64_t *pNumsteps,int64_t *pResidue) {
	int64_t version = (pthis)->version ;
	int64_t type = (pthis)->type ;
	int64_t dim = (pthis)->dim ;
	int64_t *pdimarray = (pthis)->pdimarray ;
	int64_t *pblockarray = (pthis)->pblockarray ;
	int64_t numperstep = (pthis)->numperstep ;
	FILE *pfile = (pthis)->pfile ;
	char *prefix = (pthis)->prefix ;
	int64_t *locations = (pthis)->locations ;
	int64_t block_len = (pthis)->block_len ;
	int64_t num_block_current_proc = (pthis)->num_block_current_proc ;
	int64_t time_step_current = (pthis)->time_step_current ;
	int64_t num_block_all_reduce_group = (pthis)->num_block_all_reduce_group ;
	int num_reduce_proc = (pthis)->num_reduce_proc ;
	int cur_rank = (pthis)->cur_rank ;
	int send_to_proc = (pthis)->send_to_proc ;
	int real_rank = (pthis)->real_rank ;
	long end_pos = (((version == 2))?(({
		long cur_pos = ftell(pfile) ;
		assert((cur_pos >= 0));
		assert((0 == fseek(pfile, 0, SEEK_END)));
		long end_pos = ftell(pfile) ;
		assert((end_pos > 0));
		fseek(pfile, cur_pos, SEEK_SET);
		end_pos;
	})):(({
		MPI_Offset end_pos ;
		MPI_File_get_size((((MPI_File *)pfile))[0], & (end_pos));
		end_pos;
	}))) ;
	(end_pos = ((end_pos - ((((((version == 0))?(1):(2)) * dim) + 3) * (GAPS_IO_GlobalTypeLen)[type])) / (GAPS_IO_GlobalTypeLen)[type]));
	((pNumsteps)[0] = (end_pos / (((version < 2))?(numperstep):((((num_reduce_proc)?(num_block_all_reduce_group):(num_block_current_proc)) * block_len)))));
	((pResidue)[0] = (end_pos % (((version < 2))?(numperstep):((((num_reduce_proc)?(num_block_all_reduce_group):(num_block_current_proc)) * block_len)))));
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
	char *prefix = (pthis)->prefix ;
	int64_t *locations = (pthis)->locations ;
	int64_t block_len = (pthis)->block_len ;
	int64_t num_block_current_proc = (pthis)->num_block_current_proc ;
	int64_t time_step_current = (pthis)->time_step_current ;
	int64_t num_block_all_reduce_group = (pthis)->num_block_all_reduce_group ;
	int num_reduce_proc = (pthis)->num_reduce_proc ;
	int cur_rank = (pthis)->cur_rank ;
	int send_to_proc = (pthis)->send_to_proc ;
	int real_rank = (pthis)->real_rank ;
	if(((version < 2) || ((cur_rank == send_to_proc) || (! num_reduce_proc)))) {
		if(pfile) {
			if((version >= 2)) {
				fclose(pfile);
			} else {
				if((version <= 1)) {
					MPI_File_close(((MPI_File *)pfile));
					free(pfile);
				} else {
					fclose(pfile);
				}
			}
		} else {
			0;
		}
	} else {
		0;
	}
	free(pdimarray);
	free(pblockarray);
	if((version > 1)) {
		free(locations);
	} else {
		0;
	}
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
	char *prefix = (pthis)->prefix ;
	int64_t *locations = (pthis)->locations ;
	int64_t block_len = (pthis)->block_len ;
	int64_t num_block_current_proc = (pthis)->num_block_current_proc ;
	int64_t time_step_current = (pthis)->time_step_current ;
	int64_t num_block_all_reduce_group = (pthis)->num_block_all_reduce_group ;
	int num_reduce_proc = (pthis)->num_reduce_proc ;
	int cur_rank = (pthis)->cur_rank ;
	int send_to_proc = (pthis)->send_to_proc ;
	int real_rank = (pthis)->real_rank ;
	if((NumData < 0)) {
		(NumData = (((version < 2))?(numperstep):((((num_reduce_proc)?(num_block_all_reduce_group):(num_block_current_proc)) * block_len))));
	} else {
		0;
	}
	return ((((version < 2) || ((cur_rank == send_to_proc) || (! num_reduce_proc))))?((((version >= 2))?(ftruncate(fileno(pfile), ((NumSteps * (NumData * (GAPS_IO_GlobalTypeLen)[type])) + (sizeof(int64_t) * (3 + ((((version == 0))?(1):(2)) * dim)))))):((((version <= 1))?(MPI_File_set_size((((MPI_File *)pfile))[0], ((NumSteps * (NumData * (GAPS_IO_GlobalTypeLen)[type])) + (sizeof(int64_t) * (3 + ((((version == 0))?(1):(2)) * dim)))))):(ftruncate(fileno(pfile), ((NumSteps * (NumData * (GAPS_IO_GlobalTypeLen)[type])) + (sizeof(int64_t) * (3 + ((((version == 0))?(1):(2)) * dim)))))))))):(0)) ;
}
