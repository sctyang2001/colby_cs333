# Scottie YANG Miaoyi
# This program is a simple ppmIO file for filter.
# May 11, 2022
#
# From Bruce Maxwell: A simple PPM library for reading and writing color PPMs

import sys
from threading import Thread as th
import numpy as np
import concurrent.futures
import time

NUM_THREAD = 1
class PPM(th):

    def __init__(self, filename=None):
        self.rows = 0
        self.cols = 0
        self.colors = 255
        self.data = []
        self.source = filename

        if filename != None:
            self.read(filename)

    def read( self, filename):
        try:
            fp = open( filename, "rb" ) # open the file as a binary file

            s = ""
            c = fp.read(1)
            while c != b"\n":
                s += str(c)
                c = fp.read(1)

            if s == b'P'b'6':
                print("PPM Magic number")

            c = fp.read(1)
            while c == b"#":
                while c != b"\n":
                    c = fp.read(1)
                c = fp.read(1)

            s = ""
            while c != b"\n":
                s += c.decode("utf-8")
                c = fp.read(1)

            words = s.split()
            self.cols = int(words[0])
            self.rows = int(words[1])
            #self.colors = int(words[2])

            print("Rows %d  Cols %d  Colors %d" % (self.rows, self.cols, self.colors))
            self.data = bytearray(fp.read()) # read the rest of it

            fp.close()

        except:
            print("Unable to process file %s" % (filename))
            return None


    def write( self, filename ):
        fp = open(filename, "wb")
        s = "P6\n%d %d %d\n" % (self.cols, self.rows, self.colors)
        fp.write( bytearray(s, encoding='utf-8' ) )
        fp.write( self.data )
        fp.close()

    def get( self, row, col ):
        index = 3 * (row * self.cols + col)
        return [self.data[index+0], self.data[index+1], self.data[index+2]]


    def set( self, row, col, r, g, b ):
        index = 3 * (row * self.cols + col)
        self.data[index+0] = r
        self.data[index+1] = g
        self.data[index+2] = b

    def process(self, data, index):
        split = np.array_split(data, NUM_THREAD)
        for i in range(split[index]):
            if split[index][i] > 128:
                data[i + len(split) * index] = int((split[index][i] + 220) / 2)
            else:
                split[i + len(split) * index] = int((split[index][i] + 30) / 2)

def main(argv):
    if len(argv) < 2:
        print("Usage: python3 <image filename>")
        exit()

    start = time.time()

    print("Reading image", argv[1])
    ppm = PPM(argv[1])

    with concurrent.futures.ThreadPoolExecutor(max_workers=NUM_THREAD) as executor:
        executor.map(ppm.process, ppm.data, range(NUM_THREAD))

    end = time.time()
    ppm.write("output.ppm")
    print("Time: %f" % (end - start))


if __name__ == "__main__":
    main(sys.argv)