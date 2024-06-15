import numpy as np
import h5py
with h5py.File('GOLD_XYZ_OSC.0001_1024.hdf5', 'r') as f:
    print(type(f))
    print(f.keys()) #For printing keys.
    print(type(f['X']))
    print(f['X'])
    print(f['X'][2555903,0,1])