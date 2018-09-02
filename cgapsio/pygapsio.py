import struct
#import numpy as np

GAPS_IO_GlobalTypeLen=[4,8,2,4,8,2,4,8,16,16,16,1,1]
def get_type_from_int(inp):
	if inp==0:
		return numpy.int32
	elif inp==1:
		return numpy.int64
	elif inp==2:
		return numpy.int16
	elif inp==3:
		return numpy.uint32
	elif inp==4:
		return numpy.uint64
	elif inp==5:
		return numpy.uint16
	elif inp==6:
		return numpy.float32
	elif inp==7:
		return numpy.float64
	elif inp==8:
		return numpy.float128
	elif inp==9:
		return numpy.float128
	elif inp==10:
		return numpy.float128
	elif inp==11:
		return numpy.int8
	elif inp==12:
		return numpy.uint8

def readi64(fp):
	l1=struct.unpack('i', fp.read(4))[0]
	l2=struct.unpack('i', fp.read(4))[0]
	return l1+l2*(1<<32)
def writei64(fp,l1):
	array([l1]).tofile(fp)
def GAPS_IO_GetType(filename):
	fp=open(filename,"rb")
	version=readi64(fp)
	tp=readi64(fp)
	fp.close()
	return tp
def GAPS_IO_GetDim(filename):
	fp=open(filename,"rb")
	version=readi64(fp)
	tp=readi64(fp)
	#print tp
	numdim=readi64(fp)
	allblockver=range(numdim+1)
	alldimver=range(numdim)
	if version==0:
		alldimver=range(numdim+1)
	numperstep=1
	for i in xrange(numdim):
		alldimver[i]=readi64(fp)
		numperstep*=alldimver[i]
	for i in xrange(numdim):
		t1=1
		if version==1:
			t1=readi64(fp)
		allblockver[i]=t1
		numperstep*=allblockver[i]
	numdimall=numdim
	if version==1:
		numdimall=2*numdim
	datahead=8*(3+numdimall)
	#print(version,tp,numdim,alldimver)
	fp.seek(0,2)
	allfilelen=fp.tell()
	numtimestep=(allfilelen-datahead)/numperstep/GAPS_IO_GlobalTypeLen[tp]
	fp.close();
	allblockver[numdim]=numtimestep
	if version==0:
		alldimver[numdim]=numtimestep
	alldimver.reverse()
	allblockver.reverse()
	alldatalen=numperstep*numtimestep
	if version==0:
		return alldimver
	else:
		return append(allblockver,alldimver)

def cdr(lst):
	lst.remove(lst[0])
	return lst
def GAPS_IO_Load_Position(filename,locarray):
	dimarr=GAPS_IO_GetDim(filename)
	locarray.reverse()
	dimarr.reverse()
	tp=GAPS_IO_GetType(filename)
	tplen=GAPS_IO_GlobalTypeLen[tp]
	allblklen=tplen
	allpos=0
	for i in xrange(len(locarray)):
		allpos=allpos+allblklen*locarray[i]
		allblklen=allblklen*dimarr[i]
	fp=open(filename,"rb")
	version=readi64(fp)
	tp=readi64(fp)
	numdim=readi64(fp)
	dimlen=numdim
	if version==1:
		dimlen=2*numdim
	datahead=8*(3+dimlen)
	fp.seek(datahead + allpos)
	ret=numpy.fromfile(fp,dtype=get_type_from_int(tp),count=1)
	return ret[0]

def GAPS_IO_Load_Positions_3D(filename,lastnum):
	dimarr=GAPS_IO_GetDim(filename)
	dimarr.reverse()
	fp=open(filename,"rb")
	version=readi64(fp)
	tp=readi64(fp)
	tplen=GAPS_IO_GlobalTypeLen[tp]
	numdim=readi64(fp)
	dimlen=numdim
	if version==1:
		dimlen=2*numdim
	datahead=8*(3+dimlen)
	eledim=dimarr[0]
	cdim=dimarr[1:]
	zmax=cdim[2]
	ymax=cdim[1]
	xmax=cdim[0]
	frt=zeros([zmax,ymax,xmax])
	for z in xrange(zmax):
		for y in xrange(ymax):
			for x in xrange(xmax):
				offsetlen=((x+y*xmax+z*xmax*ymax)*eledim+lastnum)*tplen
				fp.seek(datahead+offsetlen)
				frt[z,y,x]=struct.unpack('d',fp.read(8))[0]
	return frt
	


def GAPS_IO_Load_TimeStep(filename,timestep):
	fp=open(filename,"rb")
	version=readi64(fp)
	if version>1:
		print "Error: unknown version"
		raise Exception(version)
	tp=readi64(fp)
	numdim=readi64(fp)
	numperstep=1
	alldimver=range(numdim)
	allblkver=range(numdim)
	for i in xrange(numdim):
		alldimver[i]=readi64(fp)
		numperstep*=alldimver[i]
	for i in xrange(numdim):
		if version==1:
			allblkver[i]=readi64(fp)
		else:
			allblkver[i]=1
		numperstep*=allblkver[i]

	dimlen=numdim
	if version==1:
		dimlen=2*numdim
	datahead=8*(3+dimlen)
	fp.seek(0,2)
	allfilelen=fp.tell()
	numtimestep=(allfilelen-datahead)/numperstep/GAPS_IO_GlobalTypeLen[tp]
	alldimver.reverse()
	allblkver.reverse()
	alldatalen=numperstep*numtimestep
	if(timestep<numtimestep):
		fp.seek(datahead+timestep*numperstep*GAPS_IO_GlobalTypeLen[tp])
	else:
		print "error, no such time step"
		raise Exception(timestep,numtimestep);
	#ret=zeros(alldimver)
	ret=numpy.fromfile(fp,dtype=get_type_from_int(tp),count=numperstep)
	fp.close()
	if version==0:
		return reshape(ret,alldimver)
	elif version==1:
		return reshape(ret,append(allblkver,alldimver))

def drawfile_xy(fname,i0):
	i=i0
	while(True):
		tEC1=GAPS_IO_Load_TimeStep(fname,i)
		clf();
		#imshow(sqrt(tEC1[0,:,:,2]**2+tEC1[0,:,:,0]**2))
		#imshow(tEC1[0,:,:,1],vmin=-60,vmax=60)
		#imshow(tEC1[0,:,:,1])
		imshow(tEC1[0,1:-2,1:-2,1])
		colorbar();
		draw();
		time.sleep(0.05);
		i+=2
def drawfile(fname,i0):
	i=i0
	while(True):
		tEC1=GAPS_IO_Load_TimeStep(fname,i)
		clf();
		imshow(sqrt(tEC1[:,0,:,2]**2+tEC1[:,0,:,0]**2))
		#imshow(tEC1[0,:,:,1],vmin=-60,vmax=60)
		#imshow(tEC1[0,:,:,1])
		#imshow(tEC1[0,1:-2,1:-2,2])
		colorbar();
		draw();
		time.sleep(0.05);
		i+=2
def drawene(fname,i0):
	i=i0
	while(True):
		tEC1=GAPS_IO_Load_TimeStep(fname,i)
		clf();
		#imshow(sqrt(tEC1[:,0,:,1]**2+tEC1[:,0,:,0]**2))
		imshow(tEC1[0,:,:,1])
		colorbar();
		draw();
		time.sleep(0.05);
		i+=1

def GAPS_IO_Load(filename):
	fp=open(filename,"rb")
	version=readi64(fp)
	tp=readi64(fp)
	#print tp
	numdim=readi64(fp)
	allblockver=range(numdim+1)
	alldimver=range(numdim)
	if version==0:
		alldimver=range(numdim+1)
	numperstep=1
	for i in xrange(numdim):
		alldimver[i]=readi64(fp)
		numperstep*=alldimver[i]
	for i in xrange(numdim):
		t1=1
		if version==1:
			t1=readi64(fp)
		allblockver[i]=t1
		numperstep*=allblockver[i]
	numdimall=numdim
	if version==1:
		numdimall=2*numdim
	datahead=8*(3+numdimall)
	#print(version,tp,numdim,alldimver)
	fp.seek(0,2)
	allfilelen=fp.tell()
	numtimestep=(allfilelen-datahead)/numperstep/GAPS_IO_GlobalTypeLen[tp]
	allblockver[numdim]=numtimestep
	if version==0:
		alldimver[numdim]=numtimestep
	alldimver.reverse()
	allblockver.reverse()
	alldatalen=numperstep*numtimestep
	#print(alldatalen)
	fp.seek(datahead)
	#ret=zeros(alldimver)
	ret=numpy.fromfile(fp,dtype=get_type_from_int(tp),count=alldatalen)
	fp.close()
	if version==0:
		return reshape(ret,alldimver)
	else:
		return reshape(ret,append(allblockver,alldimver))
def cdr(lst):
	lst.remove(lst[0])
	return lst
def GAPS_IO_GetNumTimesteps(filename):
	fp=open(filename,"rb")
	version=readi64(fp)
	tp=readi64(fp)
	#print tp
	numdim=readi64(fp)
	allblockver=range(numdim+1)
	alldimver=range(numdim)
	if version==0:
		alldimver=range(numdim+1)
	numperstep=1
	for i in xrange(numdim):
		alldimver[i]=readi64(fp)
		numperstep*=alldimver[i]
	for i in xrange(numdim):
		t1=1
		if version==1:
			t1=readi64(fp)
		allblockver[i]=t1
		numperstep*=allblockver[i]
	numdimall=numdim
	if version==1:
		numdimall=2*numdim
	datahead=8*(3+numdimall)
	#print(version,tp,numdim,alldimver)
	fp.seek(0,2)
	allfilelen=fp.tell()
	numtimestep=(allfilelen-datahead)/numperstep/GAPS_IO_GlobalTypeLen[tp]
	fp.close()
	return numtimestep
def GAPS_IO_Save(filename,data,dtype=7,version=0):
	fp=open(filename,"wb")
	#print tp
	numdim=len(shape(data))-1
	if version==1:
		numdim=(len(shape(data))-1)/2
	allblockver=array(range(numdim+1))
	alldimver=range(numdim)
	if version==0:
		alldimver=list(shape(data))
		alldimver=cdr(alldimver)
		alldimver.reverse()
		allblockver[:]=1
	else:
		alldimver=list(shape(data))[-numdim:]
		alldimver.reverse()
		allblockver=list(shape(data))[:(numdim+1)]
		allblockver.reverse()
	writei64(fp,version)
	writei64(fp,dtype)
	writei64(fp,numdim)
	numperstep=1
	for i in xrange(numdim):
		writei64(fp,alldimver[i])
		numperstep*=alldimver[i]
	for i in xrange(numdim):
		#t1=1
		#allblockver[i]=t1
		if(version==1):
			writei64(fp,allblockver[i])
		numperstep*=allblockver[i]
	numdimall=numdim
	if version==1:
		numdimall=2*numdim
	datahead=8*(3+numdimall)
	#print(version,tp,numdim,alldimver)
	data.tofile(fp)
