from Tkinter import *
root = Tk()

import Tkinter, Tkconstants, tkFileDialog
import subprocess,threading
from tkMessageBox import *

root.title ('GUI for SymPIC configuration')

sympic_exec_name='../sympic'
root.geometry('700x602')
def on_configure(event):
	canvas.configure(scrollregion=canvas.bbox('all'))
canvas = Canvas(root,width=510,height=600);canvas.pack(side=LEFT)
scrollbar = Scrollbar(root, command=canvas.yview)
scrollbar.pack(side=LEFT, fill='y')
canvas.configure(yscrollcommand = scrollbar.set)
canvas.bind('<Configure>', on_configure)
frame = Frame(canvas)
canvas.create_window((0,0), window=frame, anchor='nw')
#frame1 = Frame (root)
#frame.pack (side=LEFT)
curfile=''
cfglst= []
entrylst=[] 
newentrylst=[]
def reset_scrollregion(event):
	canvas.configure(scrollregion=canvas.bbox('all'))
frame.bind ('<Configure>',reset_scrollregion)
def parse_oneline (s1):
	for i in xrange (len(s1)):
		if s1 [i] == ' ':
			return s1 [0:i], s1 [i+1:]
	return s1,''

def parse_file (s1):
	s1arr=s1.split ('\n')
	global entrylst
	global cfglst
	for strs in s1arr:
		if (strs == ''):
			continue
		var,val = parse_oneline (strs)
		cfglst.append (val)
		l = Label (frame, text = var)
		w = 0
		if len(val)>0 and val[0] == '(':
    			w = Text (frame, width=25,height=1)
			w . insert(END, val)
			entrylst.append((var,w,l,1))
		else:
			w = Entry(frame, width=25)
			w . insert(0, val)
			entrylst.append((var,w,l,0))

def get_file_fun (mode=True):
	global curfile
	if (mode):
		curfile=tkFileDialog.askopenfilename(title = 'Select file',filetypes = (('scheme configuration files','*.ss *.scm'),('all files','*.*')))
	else:
		curfile=tkFileDialog.asksaveasfilename(title = 'Select file',filetypes = (('scheme configuration files','*.ss *.scm'),('all files','*.*')))
def load_file ():
	s1=''
	print curfile
	try:
		with open(curfile) as file:
			try:
				s1=subprocess.check_output ([sympic_exec_name,'interp_cfg.ss'], stdin=file)
			except subprocess.CalledProcessError as e:
				s1=e.output
				pass
	except IOError as e:
		print 'Can not open file:'+curfile
		return 0
	parse_file (s1)
	#file.close ()
	return 0
def save_file ():
	if (curfile == ()):
		return 0
	try:
		with open (curfile,'w') as file:
			file.write('(defmacro many-define lst (cons \'begin (map (lambda (x) (cons \'define x)) lst)))\n(many-define \n')
			for i in entrylst:
				file.write ('(')
				file.write(i [0])
				file.write (' ')
				if i [3] == 0:
					file.write (i[1].get())
				else:
					file.write (i[1].get('1.0',END))
				file.write (')\n')
			file.write (')\n')
	except IOError as e:
		print 'Can not write file:'+curfile
	return 0
def save_as_fun ():
	get_file_fun (False)
	save_file ()

def load_fun ():
	get_file_fun (True)
	if (curfile == () or curfile == ''):
		return 0
	remove_but ()
	load_file ()
	redraw_but ()
def save_fun ():
	if curfile == '' or curfile == ():
		get_file_fun (False)
	if (curfile == ()):
		return 0
	save_file ()
def remove_but ():
	global entrylst
	global cfglst
	numitem = len (entrylst)
	for i in xrange (numitem):
		entrylst [i] [2] . destroy ()
		entrylst [i] [1] . destroy ()
	entrylst = []
	cfglst = []
	
def redraw_but ():
	global entrylst
	numitem=len (entrylst)
	print numitem
	for i in xrange (numitem):
		entrylst [i][2] . grid (row = i, column = 0)
		entrylst [i][1] . grid (row = i, column = 1)

	
b1=Button (text='save',width=8,height=1,command=save_fun)
b1.place (x=580,y=500)
b2=Button (text='save as',width=8,height=1,command=save_as_fun)
b2.place (x=580,y=530)
b3=Button (text='load',width=8,height=1,command=load_fun)
b3.place (x=580,y=470)

def run_background_subprocess ():
	subprocess.call ([sympic_exec_name,curfile])
global_run_thread = threading.Thread(name='worker', target=run_background_subprocess)
def run_fun ():
	global global_run_thread
	if curfile == '' or curfile == ():
		save_as_fun ()
	if curfile == '' or curfile == ():
		print 'Error: file not set'
	else:
		if global_run_thread.isAlive ():
			#print 'Running'
			showinfo ('Ok','SymPIC is running!')
		else:
			global_run_thread = threading.Thread(name='worker', target=run_background_subprocess)
			global_run_thread.start ()
	return
		
	
	
	
b4=Button (text='run',width=8,height=1,command=run_fun)
b4.place (x=580,y=560)
l=Label(frame,text="XMAX")
w = Entry(frame,width=25)
entrylst.append (('XMAX',w,l,0))
cfglst.append('4')
w.insert(0,cfglst[0])
l=Label(frame,text="YMAX")
w = Entry(frame,width=25)
entrylst.append (('YMAX',w,l,0))
cfglst.append('4')
w.insert(0,cfglst[1])
l=Label(frame,text="ZMAX")
w = Entry(frame,width=25)
entrylst.append (('ZMAX',w,l,0))
cfglst.append('4')
w.insert(0,cfglst[2])
l=Label(frame,text="NUM_PROCESS")
w = Entry(frame,width=25)
entrylst.append (('NUM_PROCESS',w,l,0))
cfglst.append('4')
w.insert(0,cfglst[3])
l=Label(frame,text="NUM_RUNTIME")
w = Entry(frame,width=25)
entrylst.append (('NUM_RUNTIME',w,l,0))
cfglst.append('3')
w.insert(0,cfglst[4])
l=Label(frame,text="NUM_MAX_RUNTIME")
w = Entry(frame,width=25)
entrylst.append (('NUM_MAX_RUNTIME',w,l,0))
cfglst.append('3')
w.insert(0,cfglst[5])
l=Label(frame,text="NUM_N_HILBERT")
w = Entry(frame,width=25)
entrylst.append (('NUM_N_HILBERT',w,l,0))
cfglst.append('1')
w.insert(0,cfglst[6])
l=Label(frame,text="NUM_N_HILBERT_DIMENSION")
w = Entry(frame,width=25)
entrylst.append (('NUM_N_HILBERT_DIMENSION',w,l,0))
cfglst.append('2')
w.insert(0,cfglst[7])
l=Label(frame,text="HILBERT_DIR")
w = Entry(frame,width=25)
entrylst.append (('HILBERT_DIR',w,l,0))
cfglst.append('0')
w.insert(0,cfglst[8])
l=Label(frame,text="NUM_TIMESTEP")
w = Entry(frame,width=25)
entrylst.append (('NUM_TIMESTEP',w,l,0))
cfglst.append('100')
w.insert(0,cfglst[9])
l=Label(frame,text="DELTAT")
w = Entry(frame,width=25)
entrylst.append (('DELTAT',w,l,0))
cfglst.append('0')
w.insert(0,cfglst[10])
l=Label(frame,text="NUM_DUMP_TIMESTEP")
w = Entry(frame,width=25)
entrylst.append (('NUM_DUMP_TIMESTEP',w,l,0))
cfglst.append('10')
w.insert(0,cfglst[11])
l=Label(frame,text="NUM_SPEC")
w = Entry(frame,width=25)
entrylst.append (('NUM_SPEC',w,l,0))
cfglst.append('0')
w.insert(0,cfglst[12])
l=Label(frame,text="USE_NP_BOUNDARY")
w = Entry(frame,width=25)
entrylst.append (('USE_NP_BOUNDARY',w,l,0))
cfglst.append('0')
w.insert(0,cfglst[13])
l=Label(frame,text="USE_NON_UNI_DENSITY")
w = Entry(frame,width=25)
entrylst.append (('USE_NON_UNI_DENSITY',w,l,0))
cfglst.append('0')
w.insert(0,cfglst[14])
l=Label(frame,text="USE_NON_UNI_TEMPERATURE")
w = Entry(frame,width=25)
entrylst.append (('USE_NON_UNI_TEMPERATURE',w,l,0))
cfglst.append('0')
w.insert(0,cfglst[15])
l=Label(frame,text="USE_INIT_EXT_EB")
w = Entry(frame,width=25)
entrylst.append (('USE_INIT_EXT_EB',w,l,0))
cfglst.append('0')
w.insert(0,cfglst[16])
l=Label(frame,text="USE_INIT_EB0")
w = Entry(frame,width=25)
entrylst.append (('USE_INIT_EB0',w,l,0))
cfglst.append('0')
w.insert(0,cfglst[17])
l=Label(frame,text="USE_FILTER")
w = Entry(frame,width=25)
entrylst.append (('USE_FILTER',w,l,0))
cfglst.append('0')
w.insert(0,cfglst[18])
l=Label(frame,text="USE_CHECKPOINT")
w = Entry(frame,width=25)
entrylst.append (('USE_CHECKPOINT',w,l,0))
cfglst.append('0')
w.insert(0,cfglst[19])
l=Label(frame,text="USE_INIT_V0")
w = Entry(frame,width=25)
entrylst.append (('USE_INIT_V0',w,l,0))
cfglst.append('0')
w.insert(0,cfglst[20])
l=Label(frame,text="USE_KGM")
w = Entry(frame,width=25)
entrylst.append (('USE_KGM',w,l,0))
cfglst.append('0')
w.insert(0,cfglst[21])
l=Label(frame,text="CAL_FUN_ONE_PARA")
w = Text(frame,width=25,height=1)
entrylst.append (('CAL_FUN_ONE_PARA',w,l,1))
cfglst.append('(lambda x x)')
w.insert(END,cfglst[22])
l=Label(frame,text="USE_TORI")
w = Entry(frame,width=25)
entrylst.append (('USE_TORI',w,l,0))
cfglst.append('0')
w.insert(0,cfglst[23])
l=Label(frame,text="USE_PROFILE")
w = Entry(frame,width=25)
entrylst.append (('USE_PROFILE',w,l,0))
cfglst.append('0')
w.insert(0,cfglst[24])
l=Label(frame,text="USE_DM")
w = Entry(frame,width=25)
entrylst.append (('USE_DM',w,l,0))
cfglst.append('0')
w.insert(0,cfglst[25])
l=Label(frame,text="USE_LHCD_INPUT")
w = Entry(frame,width=25)
entrylst.append (('USE_LHCD_INPUT',w,l,0))
cfglst.append('0')
w.insert(0,cfglst[26])
l=Label(frame,text="NUM_CHECKPOINT_TIMESTEP")
w = Entry(frame,width=25)
entrylst.append (('NUM_CHECKPOINT_TIMESTEP',w,l,0))
cfglst.append('0')
w.insert(0,cfglst[27])
l=Label(frame,text="USE_NON_UNI_CACHE_DIST")
w = Entry(frame,width=25)
entrylst.append (('USE_NON_UNI_CACHE_DIST',w,l,0))
cfglst.append('0')
w.insert(0,cfglst[28])
l=Label(frame,text="GET_DEV_TYPE")
w = Text(frame,width=25,height=1)
entrylst.append (('GET_DEV_TYPE',w,l,1))
cfglst.append('(lambda x x)')
w.insert(END,cfglst[29])
l=Label(frame,text="GET_DEV_ID")
w = Text(frame,width=25,height=1)
entrylst.append (('GET_DEV_ID',w,l,1))
cfglst.append('(lambda x x)')
w.insert(END,cfglst[30])
l=Label(frame,text="GET_NUM_LOCAL_THREAD_FROM_GLOBAL_TID")
w = Text(frame,width=25,height=1)
entrylst.append (('GET_NUM_LOCAL_THREAD_FROM_GLOBAL_TID',w,l,1))
cfglst.append('(lambda x x)')
w.insert(END,cfglst[31])
l=Label(frame,text="GET_MASS")
w = Text(frame,width=25,height=1)
entrylst.append (('GET_MASS',w,l,1))
cfglst.append('(lambda x x)')
w.insert(END,cfglst[32])
l=Label(frame,text="GET_NPM")
w = Text(frame,width=25,height=1)
entrylst.append (('GET_NPM',w,l,1))
cfglst.append('(lambda x x)')
w.insert(END,cfglst[33])
l=Label(frame,text="GET_CHARGE")
w = Text(frame,width=25,height=1)
entrylst.append (('GET_CHARGE',w,l,1))
cfglst.append('(lambda x x)')
w.insert(END,cfglst[34])
l=Label(frame,text="GET_GRID_CACHE_LEN")
w = Text(frame,width=25,height=1)
entrylst.append (('GET_GRID_CACHE_LEN',w,l,1))
cfglst.append('(lambda x x)')
w.insert(END,cfglst[35])
l=Label(frame,text="GET_CU_CACHE_LEN")
w = Text(frame,width=25,height=1)
entrylst.append (('GET_CU_CACHE_LEN',w,l,1))
cfglst.append('(lambda x x)')
w.insert(END,cfglst[36])
l=Label(frame,text="GET_INIT_LOAD")
w = Text(frame,width=25,height=1)
entrylst.append (('GET_INIT_LOAD',w,l,1))
cfglst.append('(lambda x x)')
w.insert(END,cfglst[37])
l=Label(frame,text="GET_NON_UNI_CACHE_DIST")
w = Text(frame,width=25,height=1)
entrylst.append (('GET_NON_UNI_CACHE_DIST',w,l,1))
cfglst.append('(lambda x 0)')
w.insert(END,cfglst[38])
l=Label(frame,text="GET_INIT_DENSITY_DIST")
w = Text(frame,width=25,height=1)
entrylst.append (('GET_INIT_DENSITY_DIST',w,l,1))
cfglst.append('(lambda x x)')
w.insert(END,cfglst[39])
l=Label(frame,text="GET_INIT_TEMPERATURE_DIST")
w = Text(frame,width=25,height=1)
entrylst.append (('GET_INIT_TEMPERATURE_DIST',w,l,1))
cfglst.append('(lambda x x)')
w.insert(END,cfglst[40])
l=Label(frame,text="GET_INIT_E")
w = Text(frame,width=25,height=1)
entrylst.append (('GET_INIT_E',w,l,1))
cfglst.append('(lambda x x)')
w.insert(END,cfglst[41])
l=Label(frame,text="GET_INIT_B")
w = Text(frame,width=25,height=1)
entrylst.append (('GET_INIT_B',w,l,1))
cfglst.append('(lambda x x)')
w.insert(END,cfglst[42])
l=Label(frame,text="GET_INIT_E0")
w = Text(frame,width=25,height=1)
entrylst.append (('GET_INIT_E0',w,l,1))
cfglst.append('(lambda x x)')
w.insert(END,cfglst[43])
l=Label(frame,text="GET_INIT_B0")
w = Text(frame,width=25,height=1)
entrylst.append (('GET_INIT_B0',w,l,1))
cfglst.append('(lambda x x)')
w.insert(END,cfglst[44])
l=Label(frame,text="GET_INIT_VT")
w = Text(frame,width=25,height=1)
entrylst.append (('GET_INIT_VT',w,l,1))
cfglst.append('(lambda x x)')
w.insert(END,cfglst[45])
l=Label(frame,text="GET_INIT_V0_x")
w = Text(frame,width=25,height=1)
entrylst.append (('GET_INIT_V0_x',w,l,1))
cfglst.append('(lambda x x)')
w.insert(END,cfglst[46])
l=Label(frame,text="GET_INIT_V0_y")
w = Text(frame,width=25,height=1)
entrylst.append (('GET_INIT_V0_y',w,l,1))
cfglst.append('(lambda x x)')
w.insert(END,cfglst[47])
l=Label(frame,text="GET_INIT_V0_z")
w = Text(frame,width=25,height=1)
entrylst.append (('GET_INIT_V0_z',w,l,1))
cfglst.append('(lambda x x)')
w.insert(END,cfglst[48])
l=Label(frame,text="GET_INIT_FILTER_E")
w = Text(frame,width=25,height=1)
entrylst.append (('GET_INIT_FILTER_E',w,l,1))
cfglst.append('(lambda x x)')
w.insert(END,cfglst[49])
l=Label(frame,text="GET_INIT_FILTER_KROOK")
w = Text(frame,width=25,height=1)
entrylst.append (('GET_INIT_FILTER_KROOK',w,l,1))
cfglst.append('(lambda x x)')
w.insert(END,cfglst[50])
l=Label(frame,text="GET_INIT_FILTER_B")
w = Text(frame,width=25,height=1)
entrylst.append (('GET_INIT_FILTER_B',w,l,1))
cfglst.append('(lambda x x)')
w.insert(END,cfglst[51])
l=Label(frame,text="GET_VAR")
w = Text(frame,width=25,height=1)
entrylst.append (('GET_VAR',w,l,1))
cfglst.append('(lambda x x)')
w.insert(END,cfglst[52])

redraw_but ()
mainloop()
