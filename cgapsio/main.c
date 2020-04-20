#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mpi.h>
#include <cgapsio.h>
int main(int argc,char * * argv) {
	MPI_Init(& (argc), & (argv));
	Gaps_IO_DataFile gi ;
	Gaps_IO_DataFile *pgi = & (gi) ;
	Gaps_IO_DataFile go ;
	Gaps_IO_DataFile *pgo = & (go) ;
	if((argc < 3)) {
		fprintf(stderr, "Usage: %s infile outfile\n", (argv)[0]);
		return 0 ;
	} else {
		0;
	}
	GAPS_IO_InitIFile(pgi, (argv)[1]);
	if((1 == (pgi)->version)) {
		int64_t version = pgi->version ;
		int64_t type = pgi->type ;
		int64_t dim = pgi->dim ;
		int64_t *pdimarray = pgi->pdimarray ;
		int64_t *pblockarray = pgi->pblockarray ;
		int64_t numperstep = pgi->numperstep ;
		int typelen = GAPS_IO_GetTypeLen(type) ;
		char *ptmpdata = malloc((numperstep * typelen)) ;
		int64_t *poutlen = malloc((sizeof(int64_t) * dim)) ;
		int64_t oneblock_len = 1 ;
		int64_t numblocks = 1 ;
		{
			long g ;
			for((g = 0) ; (g < dim) ; (g = (g + 1))) {
				((poutlen)[g] = ((pdimarray)[g] * (pblockarray)[g]));
				(oneblock_len = (oneblock_len * (pdimarray)[g]));
				(numblocks = (numblocks * (pblockarray)[g]));
			}
		}
		GAPS_IO_InitDataInfo(pgo, type, dim, poutlen);
		GAPS_IO_InitOFile(pgo, (argv)[2]);
		char *ptmpdata_block = malloc((typelen * oneblock_len)) ;
		int64_t numsteps = 0 ;
		int64_t numresd = 0 ;
		GAPS_IO_DataNumStepsAndResidue(pgi, & (numsteps), & (numresd));
		GAPS_IO_FileGotoBegin(pgi);
		GAPS_IO_FileGotoBegin(pgo);
		int64_t *pblkid = malloc((sizeof(int64_t) * dim)) ;
		int64_t *plocalid = malloc((sizeof(int64_t) * dim)) ;
		int64_t *pallid = malloc((sizeof(int64_t) * dim)) ;
		int64_t *palldim = malloc((sizeof(int64_t) * dim)) ;
		char *min_env_str = "GAPS_IO_MIN_TIME_STEP" ;
		char *max_env_str = "GAPS_IO_MAX_TIME_STEP" ;
		char *min_numt = getenv(min_env_str) ;
		char *max_numt = getenv(max_env_str) ;
		long t_min = 0 ;
		long t_max = numsteps ;
		if(min_numt) {
			sscanf(min_numt, "%ld", & (t_min));
		} else {
			0;
		}
		(t_min = ((t_min + numsteps) % numsteps));
		if(max_numt) {
			sscanf(max_numt, "%ld", & (t_max));
		} else {
			0;
		}
		(t_max = (((t_max + (numsteps + -1)) % numsteps) + 1));
		GAPS_IO_DataSeek(pgi, t_min, 0);
		{
			long t ;
			for((t = t_min) ; (t < t_max) ; (t = (t + 1))) {
				{
					long b ;
					for((b = 0) ; (b < numblocks) ; (b = (b + 1))) {
						GAPS_IO_FRead(pgi, ptmpdata_block, oneblock_len);
						{
							long l ;
							for((l = 0) ; (l < oneblock_len) ; (l = (l + 1))) {
								{
									long gid = l ;
									{
										long tmpids ;
										for((tmpids = 0) ; (tmpids < dim) ; (tmpids = (tmpids + 1))) {
											((plocalid)[tmpids] = (gid % (pdimarray)[tmpids]));
											(gid = (gid / (pdimarray)[tmpids]));
										}
									}
								}{
									long gid = b ;
									{
										long tmpids ;
										for((tmpids = 0) ; (tmpids < dim) ; (tmpids = (tmpids + 1))) {
											((pblkid)[tmpids] = (gid % (pblockarray)[tmpids]));
											(gid = (gid / (pblockarray)[tmpids]));
										}
									}
								}{
									long a ;
									for((a = 0) ; (a < dim) ; (a = (a + 1))) {
										((pallid)[a] = ((plocalid)[a] + ((pdimarray)[a] * (pblkid)[a])));
										((palldim)[a] = ((pdimarray)[a] * (pblockarray)[a]));
									}
								}
								int64_t local_id = ({
									int64_t gid = 0 ;
									int64_t stride_len = 1 ;
									{
										long tmpids ;
										for((tmpids = 0) ; (tmpids < dim) ; (tmpids = (tmpids + 1))) {
											(gid = (gid + ((plocalid)[tmpids] * stride_len)));
											(stride_len = (stride_len * (pdimarray)[tmpids]));
										}
									} gid;
								}) ;
								int64_t global_id = ({
									int64_t gid = 0 ;
									int64_t stride_len = 1 ;
									{
										long tmpids ;
										for((tmpids = 0) ; (tmpids < dim) ; (tmpids = (tmpids + 1))) {
											(gid = (gid + ((pallid)[tmpids] * stride_len)));
											(stride_len = (stride_len * (palldim)[tmpids]));
										}
									} gid;
								}) ;
								memcpy((ptmpdata + (global_id * typelen)), (ptmpdata_block + (local_id * typelen)), typelen);
							}
						}
					}
				}
				fprintf(stderr, "t=%d done\n", t);
				GAPS_IO_DataSeek(pgo, t, 0);
				GAPS_IO_FWrite(pgo, ptmpdata, numperstep);
			}
		}
		free(pblkid);
		free(plocalid);
		free(pallid);
		free(palldim);
		GAPS_IO_DeleteDataInfo(pgo);
	} else {
		fprintf(stderr, "File %s is version 0\n", (argv)[1]);
		long numstep = 0 ;
		long resd = 0 ;
		GAPS_IO_DataNumStepsAndResidue(pgi, & (numstep), & (resd));
		fprintf(stdout, "%d time steps\n", numstep);
	}
	GAPS_IO_DeleteDataInfo(pgi);
	MPI_Finalize();
}
