
#include "local_header.h"
int  PS_MPI_Abort (MPI_Comm  comm ,int  errorcode )
;
int  PS_MPI_Barrier (MPI_Comm  comm )
;
int  PS_MPI_Bcast (void *  buffer ,int  count ,MPI_Datatype  datatype ,int  root ,MPI_Comm  comm )
;
int  PS_MPI_Comm_rank (MPI_Comm  comm ,int *  rank )
;
int  PS_MPI_Comm_size (MPI_Comm  comm ,int *  size )
;
int  PS_MPI_Finalize ()
;
int  PS_MPI_Gather (void *  sendbuf ,int  sendcount ,MPI_Datatype  sendtype ,void *  recvbuf ,int  recvcount ,MPI_Datatype  recvtype ,int  root ,MPI_Comm  comm )
;
int  PS_MPI_Get_processor_name (char *  name ,int *  resultlen )
;
int  PS_MPI_Init (int *  argc ,char * * *  argv )
;
int  PS_MPI_Send (void *  buf ,int  count ,MPI_Datatype  datatype ,int  dest ,int  tag ,MPI_Comm  comm )
;
int  PS_MPI_Isend (void *  buf ,int  count ,MPI_Datatype  datatype ,int  dest ,int  tag ,MPI_Comm  comm ,MPI_Request *  request )
;
int  PS_MPI_Recv (void *  buf ,int  count ,MPI_Datatype  datatype ,int  source ,int  tag ,MPI_Comm  comm ,MPI_Status *  status )
;
int  PS_MPI_Reduce (void *  buf ,void *  recvbuf ,int  count ,MPI_Datatype  datatype ,MPI_Op  op ,int  root ,MPI_Comm  comm )
;
int  PS_MPI_Sendrecv (void *  sendbuf ,int  sendcount ,MPI_Datatype  sendtype ,int  dest ,int  sendtag ,void *  recvbuf ,int  recvcount ,MPI_Datatype  recvtype ,int  source ,int  recvtag ,MPI_Comm  comm ,MPI_Status *  status )
;
int  PS_MPI_Wait (MPI_Request *  request ,MPI_Status *  status )
;

#include "local_header.h"
