#!/usr/bin/python3

import sys
from hashTable import autograder as hashTable_autograder
from edgelist import autograder as edgelist_autograder
from mst import autograder as mst_autograder
from solveMaze import autograder as solveMaze_autograder
from findCycle import autograder as findCycle_autograder
from matChainMul import autograder as matChainMul_autograder

total = 0

if len( sys.argv ) > 1:

    import tarfile, os, shutil

    with tarfile.open(sys.argv[1]) as tarball:
        def is_within_directory(directory, target):

            abs_directory = os.path.abspath(directory)
            abs_target = os.path.abspath(target)

            prefix = os.path.commonprefix([abs_directory, abs_target])

            return prefix == abs_directory

        def safe_extract(tar, path=".", members=None, *, numeric_owner=False):

            for member in tar.getmembers():
                member_path = os.path.join(path, member.name)
                if not is_within_directory(path, member_path):
                    raise Exception("Attempted Path Traversal in Tar File")

            tar.extractall(path, members, numeric_owner=numeric_owner) 


        safe_extract(tarball, "tar_test")

    total += hashTable_autograder.grade_hashTable ( path="tar_test/hashTable/", verbose=True )
    total += edgelist_autograder.grade_edgelist ( path="tar_test/edgelist/", verbose=True )
    total += mst_autograder.grade_mst ( path="tar_test/mst/", verbose=True )
    total += solveMaze_autograder.grade_solveMaze ( path="tar_test/solveMaze/", verbose=True )
    total += findCycle_autograder.grade_findCycle ( path="tar_test/findCycle/", verbose=True )
    total += matChainMul_autograder.grade_matChainMul ( path="tar_test/matChainMul/", verbose=True )

    shutil.rmtree("tar_test")

else:

    total += hashTable_autograder.grade_hashTable ( path="hashTable/", verbose=True )
    total += edgelist_autograder.grade_edgelist ( path="edgelist/", verbose=True )
    total += mst_autograder.grade_mst ( path="mst/", verbose=True )
    total += solveMaze_autograder.grade_solveMaze ( path="solveMaze/", verbose=True )
    total += findCycle_autograder.grade_findCycle ( path="findCycle/", verbose=True )
    total += matChainMul_autograder.grade_matChainMul ( path="matChainMul/", verbose=True )

print ("Score on assignment: {} out of 150.".format(total))