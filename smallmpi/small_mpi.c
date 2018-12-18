#include <stdio.h>
#include <mpi.h>

#define PS_MPI_INT MPI_INT

#define PS_MPI_DOUBLE MPI_DOUBLE

#define PS_MPI_FLOAT MPI_FLOAT

#define PS_MPI_LONG MPI_LONG

#define PS_MPI_LONG_LONG MPI_LONG_LONG

#define PS_MPI_COMM_WORLD MPI_COMM_WORLD

typedef MPI_Comm PS_MPI_Comm;

typedef MPI_Datatype PS_MPI_Datatype;

typedef MPI_Request PS_MPI_Request;

typedef MPI_Status PS_MPI_Status;
int  PS_MPI_Abort (MPI_Comm  comm ,int  errorcode ){
	return  	MPI_Abort ( comm , errorcode ) ;}
int  PS_MPI_Barrier (MPI_Comm  comm ){
	return  	MPI_Barrier ( comm ) ;}
int  PS_MPI_Bcast (void *  buffer ,int  count ,MPI_Datatype  datatype ,int  root ,MPI_Comm  comm ){
	return  	MPI_Bcast ( buffer , count , datatype , root , comm ) ;}
int  PS_MPI_Comm_rank (MPI_Comm  comm ,int *  rank ){
	return  	MPI_Comm_rank ( comm , rank ) ;}
int  PS_MPI_Comm_size (MPI_Comm  comm ,int *  size ){
	return  	MPI_Comm_size ( comm , size ) ;}
int  PS_MPI_Finalize (){
	return  	MPI_Finalize (  ) ;}
int  PS_MPI_Gather (void *  sendbuf ,int  sendcount ,MPI_Datatype  sendtype ,void *  recvbuf ,int  recvcount ,MPI_Datatype  recvtype ,int  root ,MPI_Comm  comm ){
	return  	MPI_Gather ( sendbuf , sendcount , sendtype , recvbuf , recvcount , recvtype , root , comm ) ;}
int  PS_MPI_Get_processor_name (char *  name ,int *  resultlen ){
	return  	MPI_Get_processor_name ( name , resultlen ) ;}
int  PS_MPI_Init (int *  argc ,char * * *  argv ){
	return  	MPI_Init ( argc , argv ) ;}
int  PS_MPI_Isend (void *  buf ,int  count ,MPI_Datatype  datatype ,int  dest ,int  tag ,MPI_Comm  comm ,MPI_Request *  request ){
	return  	MPI_Isend ( buf , count , datatype , dest , tag , comm , request ) ;}
int  PS_MPI_Recv (void *  buf ,int  count ,MPI_Datatype  datatype ,int  source ,int  tag ,MPI_Comm  comm ,MPI_Status *  status ){
	PS_MPI_Status  s0 ;
	if (  	(  ! status )  ){  
		(status = 	& ( s0 ));

	}else{
		0;

	 }
	return  	MPI_Recv ( buf , count , datatype , source , tag , comm , status ) ;}
int  PS_MPI_Reduce (void *  buf ,void *  recvbuf ,int  count ,MPI_Datatype  datatype ,MPI_Op  op ,int  root ,MPI_Comm  comm ){
	return  	MPI_Reduce ( buf , recvbuf , count , datatype , op , root , comm ) ;}
int  PS_MPI_Sendrecv (void *  sendbuf ,int  sendcount ,MPI_Datatype  sendtype ,int  dest ,int  sendtag ,void *  recvbuf ,int  recvcount ,MPI_Datatype  recvtype ,int  source ,int  recvtag ,MPI_Comm  comm ,MPI_Status *  status ){
	PS_MPI_Status  s0 ;
	if (  	(  ! status )  ){  
		(status = 	& ( s0 ));

	}else{
		0;

	 }
	return  	MPI_Sendrecv ( sendbuf , sendcount , sendtype , dest , sendtag , recvbuf , recvcount , recvtype , source , recvtag , comm , status ) ;}
int  PS_MPI_Wait (MPI_Request *  request ,MPI_Status *  status ){
	PS_MPI_Status  s0 ;
	if (  	(  ! status )  ){  
		(status = 	& ( s0 ));

	}else{
		0;

	 }
	return  	MPI_Wait ( request , status ) ;}
